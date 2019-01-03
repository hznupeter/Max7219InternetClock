#include "Settings.h"
void Display() { //显示内容
  //Serial.println(1);
  if (millis() < 5000)  {//开机画面
    scrollMessage(marqueeMessage);
  }
  else if ((minute() == 59 || minute() == 30) && second() == 0) { //显示日期，天气，温湿度，每隔半小时
    Blynk.virtualWrite(V2, "https://api.seniverse.com/v3/weather/daily.json?key=" + APIKEY + "&location=" + city + "&language=en&unit=c&start=0&days=5");
    String currentDate = String(year());
    currentDate += (month() < 10) ? "-0" + String(month()) : "-" + String(month());
    currentDate += (day() < 10) ? "-0" + String(day()) : "-" + String(day());
    String weatherInfo = "  " + city + "  Weather:" + today.text_day;
    weatherInfo += "  High:" + String(today.temp_high) + "C" ;
    weatherInfo += "  Low:" + String(today.temp_low) + "C";
    weatherInfo += "  Temp:" + String(Temperature) + "C";
    weatherInfo += "  Humidity:" + String(Humidity) + "%";
    scrollMessage(currentDate + weatherInfo);
  }
  else if (second() == 0) { //当秒钟为0时，读取温湿度值，即每分钟读取一次
    Humidity = dht.readHumidity();
    while (isnan(Humidity) || Humidity > 100)
      Humidity = dht.readHumidity();
    Temperature = dht.readTemperature(); //摄氏度
    while (isnan(Temperature) || Temperature > 100)
      Temperature = dht.readTemperature(); //摄氏度
    long currentTime = hour() * 60 * 60 + minute() * 60 + second();
    if (currentTime == timeDisplayTurnsOn && !displayOn) {//如果当前时间等于设定的开机时间，且当前屏幕没有开，则开启显示
      enableDisplay(true);
    }
    if (currentTime == timeDisplayTurnsOff && displayOn) { //如果当前时间等于设定的关机时间，且当前屏幕开了，则关闭显示
      enableDisplay(false);
    }
    if (currentTime == AlarmTime) { //如果当前时间等于设定的闹钟时间
      AlarmClock();
    }
  }
  else if (minute() == 0 && second() == 0) { //当分钟为0，秒钟为0时，显示整点问候，整点报时
    scrollMessage(marqueeMessage);
    if (ring && displayOn) //手机端如果设置整点报时，且屏幕点亮时才整点报时
      onTimeAlarm();
  }
  else { //显示时间
    Serial.println("show time");
    String currentTime = "" ;
    String colon = (second() % 2 == 0) ? ":" : " ";//时钟分割点
    if (IS_24HOUR) {//24小时制
      currentTime += (hour() < 10) ? "0" + String(hour()) : String(hour()) + colon;
      currentTime += (minute() < 10) ? "0" + String(minute()) :  String(minute());
    }
    else {//12小时制
      currentTime += (hour() % 12 < 10) ? "0" + String(hour() % 12) : String(hour() % 12)  ;
      currentTime += colon;
      currentTime += (minute() < 10) ? "0" + String(minute()) :  String(minute());
    }
    centerPrint(currentTime);
  }
}
void AlarmClock ()//闹钟铃声
{
  tone(pinBuzzer, 415, 500);
  delay(500 * 1.3);
  tone(pinBuzzer, 466, 500);
  delay(500 * 1.3);
  tone(pinBuzzer, 370, 1000);
  delay(1000 * 1.3);
  noTone(pinBuzzer);
}
void onTimeAlarm ()//整点报时铃声
{
  tone(pinBuzzer, 415, 500);
  delay(500 * 1.3);
  tone(pinBuzzer, 466, 500);
  delay(500 * 1.3);
  tone(pinBuzzer, 370, 1000);
  delay(1000 * 1.3);
  noTone(pinBuzzer);
}
BLYNK_CONNECTED() {
  rtc.begin();//连上后同步时间
}
void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  int cnt = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (cnt++ >= 10) {
      WiFi.beginSmartConfig();
      while (1) {
        delay(1000);
        if (WiFi.smartConfigDone()) {
          Serial.println();
          Serial.println("SmartConfig: Success");
          break;
        }
        Serial.print("|");
      }
    }
  }
  WiFi.printDiag(Serial);
  Blynk.config(auth, IPAddress(116, 62, 49, 166), 8080);
  matrix.fillScreen(LOW); //黑屏
  matrix.setIntensity(displayIntensity);//设置亮度
  for (int i = 0; i < 4; i++) {//设置显示方向
    matrix.setRotation(i, 3);
    matrix.setPosition(i, 3 - i, 0);
  }
  Blynk.virtualWrite(V2, "https://api.seniverse.com/v3/weather/daily.json?key=" + APIKEY + "&location=" + city + "&language=en&unit=c&start=0&days=5");
  setSyncInterval(10 * 60); // 设置同步间隔时间，10分钟
  timer.setInterval(1000L, Display);//每隔1s，运行Display函数
  //  Humidity = dht.readHumidity();
  //  while (isnan(Humidity) || Humidity > 100)
  //    Humidity = dht.readHumidity();
  //  Temperature = dht.readTemperature();
  //  while (isnan(Temperature) || Temperature > 100)
  //    Temperature = dht.readTemperature();
  Serial.println(Temperature);
}
void enableDisplay(boolean enable) {//开启显示
  displayOn = enable;
  if (enable) {
    matrix.shutdown(false);
    matrix.fillScreen(LOW); // 黑屏
  } else {
    matrix.shutdown(true);
  }
}

BLYNK_WRITE(V0)//获取开机时间
{
  timeDisplayTurnsOn = param[0].asLong();
}

BLYNK_WRITE(V1)//获取关机时间
{
  timeDisplayTurnsOff = param[0].asLong();
}

BLYNK_WRITE(V2) {//获取天气预报数据
  daily_json = param.asStr();
  deserializeJson(doc, daily_json);
  JsonObject obj = doc.as<JsonObject>();
  today.date = obj["results"][0]["daily"][0]["date"].as<String>();
  today.text_day = obj["results"][0]["daily"][0]["text_day"].as<String>();//获取今天天气代码
  today.temp_high = obj["results"][0]["daily"][0]["high"];//获取今天天气温度
  today.temp_low = obj["results"][0]["daily"][0]["low"];//获取今天天气温度
  Serial.println(today.text_day);
  Serial.println(today.temp_high);
  Serial.println(today.temp_low);
}

BLYNK_WRITE(V3)//获取欢迎语
{
  marqueeMessage = param.asStr();
  Serial.println(marqueeMessage);
}

BLYNK_WRITE(V4)//获取及时消息
{
  scrollMessage(param.asStr());//显示及时消息
}

BLYNK_WRITE(V5)//获取24/12小时制
{
  switch (param.asInt())
  {
    case 1:
      IS_24HOUR = true;
      break;
    case 2:
      IS_24HOUR = false;
      break;
  }
}
BLYNK_WRITE(V6)//获取并设置亮度值
{
  displayIntensity = param.asInt();
  matrix.setIntensity(displayIntensity);
}
BLYNK_WRITE(V7)//获取是否整点报时
{
  ring = param.asInt();
}
BLYNK_WRITE(V8)//获取滚动速度
{
  switch (param.asInt())
  {
    case 1:
      displayScrollSpeed = 50;//慢速
      break;
    case 2:
      displayScrollSpeed = 40;//中速
      break;
    case 3:
      displayScrollSpeed = 25;//快速
      break;
  }
}
BLYNK_WRITE(V9)//获取闹钟时间
{
  AlarmTime = param[0].asLong();
}
void checkDisplay() {//检查是否要关闭显示

}
void scrollMessage(String msg) {//滚动显示文本
  msg += "";
  for ( int i = 0 ; i < width * msg.length() + matrix.width() - 1 - spacer; i++ ) {
    if (refresh == 1)
      i = 0;
    refresh = 0;
    matrix.fillScreen(LOW);
    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically
    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < msg.length() ) {
        matrix.drawChar(x, y, msg[letter], HIGH, LOW, 1);
      }
      letter--;
      x -= width;
    }
    matrix.write(); // Send bitmap to display
    delay(displayScrollSpeed);
  }
  matrix.setCursor(0, 0);
}
void centerPrint(String msg) {//居中显示
  matrix.fillScreen(LOW);
  int x = (matrix.width() - (msg.length() * width)) / 2;
  matrix.setCursor(x, 0);
  matrix.print(msg);
  matrix.write();
}
void loop() {
  Blynk.run();
  timer.run();
}
