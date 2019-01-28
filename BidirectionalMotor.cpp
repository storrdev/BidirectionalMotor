/**
 * BidirectionalMotor.cpp - Library for controlling regular DC motors through an H-Bridge such as the L293D
 * Created by Stephen A. Orr, January 27, 2019
 * Released into the public domain
 */

#include "Arduino.h"
#include "BidirectionalMotor.h"

BidirectionalMotor::BidirectionalMotor(int speedPin, int directionPin1, int directionPin2) {
  pinMode(speedPin, OUTPUT);
  pinMode(directionPin1, OUTPUT);
  pinMode(directionPin2, OUTPUT);

  _speedPin = speedPin;
  _directionPin1 = directionPin1;
  _directionPin2 = directionPin2;

  _speed = 0;
  _direction = true;
}

void BidirectionalMotor::setSpeed(int speed) {
  _speed = speed;
}

void BidirectionalMotor::setDirection(bool direction) {
  _direction = direction;
}

void BidirectionalMotor::setMotor(int speed, bool direction) {
  _speed = speed;
  _direction = direction;
}

void BidirectionalMotor::drive() {
  analogWrite(_speedPin, _speed);
  digitalWrite(_directionPin1, ! _direction);
  digitalWrite(_directionPin2, _direction);
}

