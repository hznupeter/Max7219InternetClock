# Input and Ouput
In Mixly, there are four kinds of command: the I/O of control Pin (including digital signal and analog signal), Interrupt，Pulse length and ShiftOut.

![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/inout-en1.png)

### I/O

![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/inout-en2.0.png)

Mixly provides I/O commands as following: set pin's signal, digital input/output, analog input/output.
First, we can do physical connection by signal. If the signal is digital signal, you can choose digital input and output.
If analog signal, you are supposed to choose analog signal.

When you drag a block to the panel(the loop structure), you need to choose the pin number to match the physical connection.

![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/inout-en2.png)
### Interrupt
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/inout-en3.png)

Usually, the main loop is in order execution, however, sometimes you want to interrupt and to execute another more important instruction, under this circumstance, using interrupt instruction becomes more essential.
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/inout-en3.1.png)

There are three interrupt modes you can choose: RISING, FALLING, CHANGE.
- RISING means the electric level changes from low to high.
- FALLING means the electric level changes from high to low.
- CHANGE means the electric level changes from high to low or from low to high.

For example, when you are using RISING mode, as long as you let the electric level become high from low (by pressing button), the interrupt instruction will be executing right away. Interrupt instruction finished, the main function will be back to execute previous instructions.
### Pulse length
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/inout-en4.png)

### ShiftOut
![](https://github.com/xbed/Mixly_Arduino/blob/master/wiki_pic/inout-en5.png)