��          �               �     �     �     �     �     �  	   �       -     *   5  *   `  k   �  k   �  /   c     �     �     �     �  X   �  6   "  B   Y  U   �  	   �  Q   �  3   N  �  �  .  F  �  u     �	     �	     

     
     
  	   !
     +
  -   1
  *   _
  *   �
  k   �
  k   !  /   �     �     �     �     �  X   �  6   L  B   �  U   �  	     Q   &  3   x  �  �  .  p   ... ESP8266 系列 Eep32 系列 Esp32 FAQ Micro:bit MixGo Mixly 支持使用哪些语言进行编程？ Mixly 支持在哪些操作系统编程？ Mixly 支持给哪些硬件进行编程？ Mixly本身采用图形化编程，但实际是将图形化程序转化为代码后再上传到开发板。 Mixly软件不支持在安卓手机、安卓平板、苹果手机、苹果平板等移动设备上运行。 Mixly软件也不支持在树莓派上运行。 NodeMCU Ruilong Esp8266 Board Wemos D1 arduino 系列 arduino系列板子，点击上传后出现`avrdude: stk500v2_ReceiveMessage(): timeout` 下面是用户常见的一些问题及解决方案。 同一个库在995上可以使用，但在996、997上使用不了 因此，从代码上来说，Mixly支持Arduino C语言, microPython 语言编程。 掌控板 早期版本 Mixly0.995支持在Windows XP上运行，后期版本不再支持。 目前Mixly软件支持在WIN7/10,MacOS上运行。 解决方法：按下列可能方法依次检查。 - 方法1： 板子下拉框中选的板子型号和实际计算机连接的板子型号不对； - 方法2： 串口下拉框选择不对，可通过设备管理器查看板子对应的是哪个串口； - 方法3： 板子与电脑接口松动。可尝试拔了板子，再重新插上； - 方法4： 数据线坏了，可尝试换数据线； - 方法5： 板子换了，可尝试换新板子； 解决方法：这是由于blockly核心升级导致的，新版的blockly不再向前兼容。可采用如下二种方法： - 方法1：采用>=998版本； - 方法2：将旧版库里block/XX.js中全局替换appendTitle为appendField，将generator/XX.js中全局替换getTitleValue为getFieldValue Project-Id-Version: Mixly Wiki 0.999
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2019-04-15 19:08+0800
PO-Revision-Date: YEAR-MO-DA HO:MI+ZONE
Last-Translator: FULL NAME <EMAIL@ADDRESS>
Language: en
Language-Team: en <LL@li.org>
Plural-Forms: nplurals=2; plural=(n != 1)
MIME-Version: 1.0
Content-Type: text/plain; charset=utf-8
Content-Transfer-Encoding: 8bit
Generated-By: Babel 2.6.0
 ... ESP8266 系列 Eep32 系列 Esp32 FAQ Micro:bit MixGo Mixly 支持使用哪些语言进行编程？ Mixly 支持在哪些操作系统编程？ Mixly 支持给哪些硬件进行编程？ Mixly本身采用图形化编程，但实际是将图形化程序转化为代码后再上传到开发板。 Mixly软件不支持在安卓手机、安卓平板、苹果手机、苹果平板等移动设备上运行。 Mixly软件也不支持在树莓派上运行。 NodeMCU Ruilong Esp8266 Board Wemos D1 arduino 系列 arduino系列板子，点击上传后出现`avrdude: stk500v2_ReceiveMessage(): timeout` 下面是用户常见的一些问题及解决方案。 同一个库在995上可以使用，但在996、997上使用不了 因此，从代码上来说，Mixly支持Arduino C语言, microPython 语言编程。 掌控板 早期版本 Mixly0.995支持在Windows XP上运行，后期版本不再支持。 目前Mixly软件支持在WIN7/10,MacOS上运行。 解决方法：按下列可能方法依次检查。 - 方法1： 板子下拉框中选的板子型号和实际计算机连接的板子型号不对； - 方法2： 串口下拉框选择不对，可通过设备管理器查看板子对应的是哪个串口； - 方法3： 板子与电脑接口松动。可尝试拔了板子，再重新插上； - 方法4： 数据线坏了，可尝试换数据线； - 方法5： 板子换了，可尝试换新板子； 解决方法：这是由于blockly核心升级导致的，新版的blockly不再向前兼容。可采用如下二种方法： - 方法1：采用>=998版本； - 方法2：将旧版库里block/XX.js中全局替换appendTitle为appendField，将generator/XX.js中全局替换getTitleValue为getFieldValue 