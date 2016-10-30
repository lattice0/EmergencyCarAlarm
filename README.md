This is an emergency car alarm, it's not a professional one, it's just an alarm to use while I'm building a better one. It uses 2 arduinos, one RC transmitter and one RC receiver of any kind, and a PIR motion sensor.

How it works?

Basically, your car will send packets every x milliseconds either to tell everything is ok or to tell a motion inside your can ocurred. If a motion ocurred, your computer will receive the alert and start ringing, waking you up. If they try to disable the battery of your car, your computer will stop receiving the packets saying that everything is ok, and you wake you up as well.


My setup:

I used 2 arduino pro's (not pro mini) that can be found on aliexpress, 2 xbee pro 900mhz for long range communication between my car in the street and my PC at home, and one PIR motion sensor from sparkfun. Below you'll find my setup, but any setup with just a TX-only for your can, RX-only for your PC, any motion sensor and any arduino will work.

Arduino pro - https://pt.aliexpress.com/item/Mini-Leonardo-Pro-Micro-ATmega32U4-5V-16MHz-Module-For-Arduino-Best-Quality/32284746884.html
PIR motion sensor - https://www.sparkfun.com/products/13285
xbee pro 900mhz - https://www.sparkfun.com/products/9097
