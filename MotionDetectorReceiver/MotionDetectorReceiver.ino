#include <VirtualWire.h>

/**
 * Arduino-based RF receiver with LED indicators.
 * Paired with the Arduino-based motion detector
 * and RF transmitter part of this project.
 *
 * https://github.com/ruscoe/Arduino-Wireless-Motion-Detector
 */

// The strings to detect in transmissions from the motion detector.
// These strings indicate which motion detector is currently transmitting.
String zoneId1 = "zone1";
String zoneId2 = "zone2";

// Duration indicator LED should be lit after motion detection notification.
long detectionLightDuration = 3000; // Milliseconds.

// True when motion detected in zone 1.
boolean detectedZone1 = false;
// Time motion was last detected in zone 1.
long lastDetectionZone1 = 0;

// True when motion detected in zone 2.
boolean detectedZone2 = false;
// Time motion was last detected in zone 2.
long lastDetectionZone2 = 0;

// The Arduino output pin connected to the zone 1 LED.
int ledPinZone1 = 13;

// The Arduino output pin connected to the zone 2 LED.
int ledPinZone2 = 12;

// The Arduino input pin connected to the data pin of the RF receiver.
int rxPin = 3;

// Current time.
long now = 0; // Milliseconds.

void setup()
{  
  pinMode(ledPinZone1, OUTPUT);
  pinMode(ledPinZone2, OUTPUT);

  // Initialise the IO and ISR.
  vw_set_ptt_inverted(true); // Required for DR3100.
  vw_setup(2000); // Bits per second.
  vw_set_rx_pin(rxPin);
  vw_rx_start(); // Start the receiver PLL running.
}

void loop()
{
  now = millis();
  
  // Handle motion detection LED timeout.
  if (detectedZone1 && (now >= (lastDetectionZone1 + detectionLightDuration)))
  {
    detectedZone1 = false;
    digitalWrite(ledPinZone1, false);
  }

  if (detectedZone2 && (now >= (lastDetectionZone2 + detectionLightDuration)))
  {
    detectedZone2 = false;
    digitalWrite(ledPinZone2, false);
  }
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  // Get transmission from motion detector.
  if (vw_get_message(buf, &buflen))
  {
    String message = "";
    int i;
    
    for (i = 0; i < buflen; i++)
    {
      message += char(buf[i]);
    }

    if (message == zoneId1)
    {
      detectedZone1 = true;
      lastDetectionZone1 = now;
      digitalWrite(ledPinZone1, true);
    }
    else if (message == zoneId2)
    {
      detectedZone2 = true;
      lastDetectionZone2 = now;
      digitalWrite(ledPinZone2, true);
    }
  }
}
