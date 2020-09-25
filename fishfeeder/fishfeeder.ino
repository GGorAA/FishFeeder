// --------------------------Settings-------------------------- //

#define SERVO_PIN 6             // Servo pin
#define SERVO_ANGLE_CLOSED 0    // Angle, which is considered "closed". Well, when the food tank door is closed.
#define SERVO_ANGLE_OPEN 5      // Angle, to which servo will turn to open door, from which food will drop into aquarium
#define SERVO_DIRECTION NORMAL  // Direction, in which servo works. Available values: NORMAL REVERSE

#define FEED_FREQUENCY 172800000  // Feed frequency
#define FEED_WAIT_TIME 10         // Time, which servo will wait until it turns back to "closed" angle

// --------------------------Includes-------------------------- //

#include "MorsDuino.h"    // Morse code generator
#include "ServoSmooth.h"  // Servo

// --------------------------Main variables-------------------------- //

/*
 * Objects
 */
ServoSmooth mainFeederServo(180);  // Servo object
MorsDuinoLed arduinoLed(13);       // Built-in Arduino LED object

/*
 * Variables
 */
unsigned long timePassedSinceLastFeed;  // Stores time in milliseconds since last feed

// --------------------------Code-------------------------- //

void setup() {
    // Setting up servo
    mainFeederServo.attach(SERVO_PIN, SERVO_ANGLE_CLOSED);  // Attach the servo and move it to starting angle
    mainFeederServo.smoothStart();                          // Make movement to starting angle smooth
    arduinoLed.displayString("strt");                       // Display starting morse code on built-in Arduino LED
}

void loop() {
    if (timePassedSinceLastFeed >= FEED_FREQUENCY) {  // If the time has come
        timePassedSinceLastFeed = millis();           // Reset timer

        feed();  // Start feeding procedure
    }
}

void feed() {
    arduinoLed.displayChar('f');
    mainFeederServo.setTargetDeg(SERVO_ANGLE_OPEN);  // Open the feeding door
    int timer = millis();                            // Start timer
    while (timer >= FEED_WAIT_TIME)
        ;                                              // Wait until timer goes to the end
    mainFeederServo.setTargetDeg(SERVO_ANGLE_CLOSED);  // Close the feeding door
}