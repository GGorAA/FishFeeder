// --------------------------Settings-------------------------- //

#define SERVO_PIN 6               // Servo pin
#define FEED_FREQUENCY 172800000  // Feed frequency
#define FEED_AMOUNT 5             // Angle, to which servo will turn to open door, from which food will drop into aquarium
#define LIGHT_STRIP_LED_COUNT 30  // Amount of LEDs on light strip

// --------------------------Includes-------------------------- //

#include "FastLED.h"      // FastLED library for light strip
#include "ServoSmooth.h"  // Servo

// --------------------------Main variables-------------------------- //

/*
 * Objects
 */
ServoSmooth mainFeederServo(180);
CRGB lightStrip[];

/*
 * Variables
 */

unsigned long timePassedSinceLastFeed;  // Stores time in milliseconds since last feed

// --------------------------Code-------------------------- //

void setup() {
    mainFeederServo.attach(SERVO_PIN, 0);  // Attach the servo and move it to starting angle
}

void loop() {
}