Arduino Wireless Motion Detector
===========

Author: Dan Ruscoe (dan@ruscoe.org).

An Arduino project consisting of multiple motion detectors with RF transmitters and an RF receiver with indicator LEDs.

The receiver component uses LEDs to indicate which motion detector has detected motion.

Requirements
------------
* VirtualWire: http://www.airspayce.com/mikem/arduino/

Parts List
----------

SparkFun part numbers included where available.

### Transmitter

* 1 x ATMEGA328 Microcontroller ([COM-09061](https://www.sparkfun.com/products/9061))
* 1 x 7805 5V Voltage Regulator ([COM-00107](https://www.sparkfun.com/products/107))
* 2 x 10uF Electrolytic Decoupling Capacitor ([COM-00523](https://www.sparkfun.com/products/523))
* 1 x 16MHz Crystal ([COM-00536](https://www.sparkfun.com/products/536))
* 2 x 22pF Ceramic Capacitor ([COM-08571](https://www.sparkfun.com/products/8571))
* 1 x 315Mhz RF Transmitter ([WRL-10535](https://www.sparkfun.com/products/10535))
* 1 x PIR Sensor ([SEN-08630](https://www.sparkfun.com/products/8630))
* 1 x Green LED ([COM-09650](https://www.sparkfun.com/products/9650))
* 1 x 220 Ohm Resistor
* 1 x Toggle Switch ([COM-00102](https://www.sparkfun.com/products/102))

### Receiver

* 1 x ATMEGA328 Microcontroller ([COM-09061](https://www.sparkfun.com/products/9061))
* 1 x 7805 Voltage Regulator ([COM-00107](https://www.sparkfun.com/products/107))
* 2 x 10uF Electrolytic Decoupling Capacitor ([COM-00523](https://www.sparkfun.com/products/523))
* 1 x 16MHz Crystal ([COM-00536](https://www.sparkfun.com/products/536))
* 2 x 22pF Ceramic Capacitor ([COM-08571](https://www.sparkfun.com/products/8571))
* 1 x 315Mhz RF Receiver ([WRL-10535](https://www.sparkfun.com/products/10535))
* 2 x Red LED ([COM-00533](https://www.sparkfun.com/products/533))
* 1 x 220 Ohm Resistor
* 1 x Toggle Switch ([COM-00102](https://www.sparkfun.com/products/102))

License
-------

Released under the The MIT License.

http://www.opensource.org/licenses/mit-license.php
