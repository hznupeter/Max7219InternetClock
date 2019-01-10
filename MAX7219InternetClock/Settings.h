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
#define DHTTYPE DHT11
char auth[] = "28d8a803d36046d3ab8681476******";//授权码
String APIKEY = "wactucc9uy******"; //心知天气API
String city = "Hangzhou";
char ssid[] = "Maker Space";//wifi名称
char pass[] = "20140***";//wifi密码
String marqueeMessage = "Have A Good Day";//问候语
boolean IS_24HOUR = true; // 24/12小时制
int displayScrollSpeed = 30; // 字符滚动速度
boolean ring = true; //是否整点提醒
BlynkTimer timer;
String  daily_json;
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
// CLK -> D5 (SCK) GPIO14
// CS  -> D6 GPIO12
// DIN -> D7 (MOSI)GPIO13
const int pinCS = 12; //max7219 CS 
const int pinBuzzer = 4;//蜂鸣器管脚,D2
const int pinDHT = 5; //DHT11传感器连接管脚D1
int displayIntensity = 1;  //默认亮度(1 - 15)
long timeDisplayTurnsOn = 21600; // 每天开机时间，自00:00起计算秒数
long timeDisplayTurnsOff = 82800; //每天关机时间，自00:00起计算秒数
long AlarmTime;
DHT dht(pinDHT, DHTTYPE);
Max72xxPanel matrix = Max72xxPanel(pinCS, 4, 1);
