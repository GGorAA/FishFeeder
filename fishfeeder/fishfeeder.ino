// --------------------------Settings-------------------------- //

#define SERVO_PIN 6             // Servo pin
#define SERVO_ANGLE_CLOSED 0    // Angle, which is considered "closed". Well, when the food tank door is closed.
#define SERVO_ANGLE_OPEN 5      // Angle, to which servo will turn to open door, from which food will drop into aquarium
#define SERVO_DIRECTION NORMAL  // Direction, in which servo works. Available values: NORMAL REVERSE

#define FEED_FREQUENCY 172800000  // Feed frequency
#define FEED_WAIT_TIME            // Time, which servo will wait until it turns back to "closed" angle

#define LIGHT_STRIP_LED_COUNT 30  // Amount of LEDs on light strip

// --------------------------Includes-------------------------- //

#include "FastLED.h"      // FastLED library for light strip
#include "MorsDuino.h"    // Morse code generator
#include "ServoSmooth.h"  // Servo

// --------------------------Main variables-------------------------- //

/*
 * Objects
 */
ServoSmooth mainFeederServo(180);        // Servo object
CRGB lightStrip[LIGHT_STRIP_LED_COUNT];  // LED strip object
MorsDuinoLed arduinoLed(13);             // Built-in Arduino LED object

/*
 * Variables
 */
unsigned long timePassedSinceLastFeed;  // Stores time in milliseconds since last feed

// --------------------------Code-------------------------- //

void setup() {
    // Setting up servo
    mainFeederServo.attach(SERVO_PIN, SERVO_ANGLE_CLOSED);  // Attach the servo and move it to starting angle
    mainFeederServo.smoothStart();                          // Make movement to starting angle smooth
    arduinoLed.displayString("strt");
}

void loop() {
    if (timePassedSinceLastFeed >= FEED_FREQUENCY) {
        timePassedSinceLastFeed = millis();  // Reset timer

        feed();  // Start feeding procedure
    }
}

void feed() {
    arduinoLed.displayChar('f');
    feedLightStripAnim();
    mainFeederServo.setTargetDeg(SERVO_ANGLE_OPEN);
}

void feedLightStripAnim() {
}