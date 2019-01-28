/**
 * BidirectionalMotor.h - Library for controlling regular DC motors through an H-Bridge such as the L293D
 * Created by Stephen A. Orr, January 27, 2019
 * Released into the public domain
 */

#ifndef BIDIRECTIONALMOTOR_H
#define BIDIRECTIONALMOTOR_H

#include "Arduino.h"

class BidirectionalMotor {
  public:
    BidirectionalMotor(int speedPin, int directionPin1, int directionPin2);
    void setSpeed(int speed);
    void setDirection(bool direction);
    void setMotor(int speed, bool direction);
    void drive();
  private:
    int _speedPin;
    int _directionPin1;
    int _directionPin2;
    int _speed;
    bool _direction;
};

#endif
