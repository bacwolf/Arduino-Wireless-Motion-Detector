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

* 1 x ATMEGA328 Microcontroller (COM-09061)
* 1 x 7805 Voltage Regulator (COM-00107)
* 2 x 10uF Electrolytic Decoupling Capacitor (COM-00523)
* 1 x 16MHz Crystal (COM-00536)
* 2 x 22pF Ceramic Capacitor (COM-08571)
* 1 x 315Mhz RF Transmitter (WRL-10535)
* 1 x PIR Sensor (SEN-08630)
* 1 x Green LED (COM-09650)
* 1 x 220 Ohm Resistor
* 1 x Toggle Switch (COM-00102)

### Receiver

* 1 x ATMEGA328 Microcontroller (COM-09061)
* 1 x 7805 Voltage Regulator (COM-00107)
* 2 x 10uF Electrolytic Decoupling Capacitor (COM-00523)
* 1 x 16MHz Crystal (COM-00536)
* 2 x 22pF Ceramic Capacitor (COM-08571)
* 1 x 315Mhz RF Receiver (WRL-10533)
* 2 x Red LED (COM-00533)
* 1 x 220 Ohm Resistor
* 1 x Toggle Switch (COM-00102)

License
-------

Released under the The MIT License.

http://www.opensource.org/licenses/mit-license.php
