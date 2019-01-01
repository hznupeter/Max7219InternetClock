#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ArduinoJson.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <SPI.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <pgmspace.h>
#define DHTTYPE DHT22
char auth[] = "4c77138d712c48d7a6f922cf3d7246ed";//授权码
String host = "api.seniverse.com";
String APIKEY = "wactucc9uyjz6lq7"; //心知天气API
String city = "Hangzhou";
String language = "en";
String marqueeMessage = "Have A Good Day";
boolean IS_24HOUR = true; // 24/12小时制
int displayScrollSpeed = 30; // 字符滚动速度
boolean ring = false; //是否整点提醒
BlynkTimer timer;
String  daily_json;
int displyType = 0;
int Humidity, Temperature;
struct daily_data {//气象信息结构体
  String date;//日期
  String text_day;//气象代码
  int temp_high;//最高温度
  int temp_low;//最低温度
};
struct daily_data  today;//初始化结构体，今天，明天，后天
WidgetRTC rtc;//创建rtc组件
DynamicJsonDocument doc;
int refresh = 0;
int spacer = 1;  // 字符间距
int width = 5 + spacer; // 字符宽度
boolean displayOn = true;
// MAX7219连线
// CLK -> D5 (SCK)
// CS  -> D6 GPIO12
// DIN -> D7 (MOSI)
const int pinCS = 12; //max7219 CS
const int pinBtn = 4;//按键/触发器管脚
const int pinBuzzer = 15;//蜂鸣器管脚
const int pinDHT = 5; //DHT11传感器连接管脚
int displayIntensity = 1;  //默认亮度(1 - 15)
long timeDisplayTurnsOn = 21600; // 每天开机时间，自00:00起计算秒数
long timeDisplayTurnsOff = 82800; //每天关机时间，自00:00起计算秒数
DHT dht(pinDHT, DHTTYPE);
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);
