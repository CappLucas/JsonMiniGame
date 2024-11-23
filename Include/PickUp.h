#ifndef PICKUP_H
#define PICKUP_H

#pragma once

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

struct PickUp {
  PickUp() {}
  PickUp(std::string newMessage, int newHealthAffect, int newPowerAffect)
      : message(newMessage), healthAffect(newHealthAffect),
        powerAffect(newPowerAffect) {}

  int healthAffect;
  int powerAffect;

  std::string message;

  void printAffect();

  void printAll();
};

#endif