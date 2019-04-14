# Custom Company Database
Mixly provides functions for everyone who want to create their own library. They can write their own company's products library available to users.Writting library only needs the most basic programming knowledge, understand the rules of the company library.

### A complete catalog for company library
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%931.png)
In this directory, it is not all the files are required, depending on the company's library may be.
Here will be described for each directory.

### block和generator
There is respectively a JS file in block and generator folder, usually with the same name, such as xxx.js. 
block / xxx.js file defines the appearance of your custom graphic module.
generator / xxx.js file defines a graphical each module corresponding Arduino code. For example, the following figure is the "delay" graphical look and the corresponding module Arduino Code:
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%932.png)

block and generator directory is usually necessary, thus ensuring block / xxx.js and generator / xxx.js correctness is key to the success of the company customized libraries.
Such as "delay" in two parts JS code module are as follows:

![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%933.png)
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%934.png)


There are plenty of examples in  blockly / blocks and blockly / generators / arduino directory , the basic method includes all types of custom graphical module. If you want a better understanding of the code, you can access Google's blockly source more in-depth study.
### hardware
The hardware catalog is not required directory, usually company uses its own Arduino board (ie, the official Arduino IDE no board we need), it needs hardware catalog, which contains some with hardware-related information, such as the board information , pin information, and so on. Therefore, more professional and technical personnel to customize this directory. Finally, a company name (eg xxx) named folder form, copy directly to the next hardware directory.

### xxx
xxx directory is your own Arduino libraries, xxx generally named with the company, which contains some .cpp and .h files, this directory is not required, usually in the generated code in #include <xxx.h> needed.
### companypin
Companypin directory defines the company pin correspondence between the company required the board, the directory is non-essential, usually when the new Arduino board requires the company to use.
It's an example of Lubot MK below:
![]
(https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%935.png)

We want to define a new pin correspondence relationship this board, first create subfolders lubot (usually named after the company name), and then create pin.js file, open the file in companypin pin.js directory, the pin is defined as follows shown (including digital pin, pin analog, PWM pin interrupt pins and Serial choices and default baud rate):
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%936.png)
### language
If you want a company library supports multiple languages, you need language directory, this is non-essential.
First create subfolders xxx (usually named after the company name), and then a multi-lingual document xxx folder in the language directory. As shown below: namely, English, Spanish, Simplified Chinese, Traditional Chinese. It defines some JS constants in .js files in these multi-lingual.
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%937.png)

The following explains how to define the JS file, or to "delay" module, for example, the following are in English, Spanish, Simplified Chinese, Traditional Chinese corresponding way:

![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%938.png)
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%939.png)
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9310.png)
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9311.png)

Let's look at how to define the corresponding text in the language file.

![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9312.png)
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9313.png)
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9314.png)
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9315.png)

Finally, in reference to block / xxx.js file can be:
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9316.png)
### media

Under media directory is some media files, mostly images of this catalog are non-essential. When the module is required only if you need the image folder. For example, the following modules can be embedded inside a picture:
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9317.png)

All media files in the media / xxx can, xxx is a sub-folder, usually named after the company
### xxx.xml
xxx.xml file is a very important document, it is essential, usually named after the company. In this file defines all modules need to be rendered, and the entire library path related files (ie those mentioned earlier file directory).
The following is an example of empty, it can be modified based on this example.

![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9318.png)

### Import library
Open Mixly, click import library, find xxx.xml.

![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%AC%E5%8F%B8%E5%BA%9319.png)

Click open and then finished.