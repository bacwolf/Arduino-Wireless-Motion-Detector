#include <VirtualWire.h>

/**
 * Arduino-based motion detector with RF transmitter.
 * Paired with the Arduino-based RF receiver part of this project.
 *
 * https://github.com/ruscoe/Arduino-Wireless-Motion-Detector
 */

// The Arduino input pin connected to the PIR sensor's output.
int pirPin = 8;

// The Arduino output pin connected to the data pin of the RF transmitter.
int txPin = 3;

// The Arduino output pin connected to the LED indicator.
int ledPin = 13;

// Time between transmissions when motion is detected.
long detectionCooldown = 3000l; // Milliseconds.

// Time of the last valid motion detection.
long lastDetection = 0;

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Initialise the IO and ISR.
  vw_set_ptt_inverted(true); // Required for DR3100.
  vw_setup(2000); // Bits per second.
  vw_set_tx_pin(txPin);
}

void loop()
{
  long now = millis();
  if (digitalRead(pirPin) == HIGH)
  {
    if (now > (lastDetection + detectionCooldown))
    {
      transmitMessage();
      lastDetection = now;
    }
  }
  delay(500);
}

/**
 * Transmit a string when motion is detected.
 * This string is interpreted by the receiver
 * to identify this motion detector.
 **/
void transmitMessage()
{
  // Identify this motion detector.
  const char *msg = "zone1";

  digitalWrite(ledPin, true); // Light an LED during transmission.
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Wait until the entire message is sent.
  digitalWrite(ledPin, false);
  delay(200);
}
