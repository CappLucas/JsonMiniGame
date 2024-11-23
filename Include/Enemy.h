#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>


struct Enemy
{
  Enemy() {}
  Enemy(std::string newMessage, std::string win, std::string lose, int newLevel)
      : message(newMessage), playerWinMessage(win), playerLoseMessage(lose),
        level(newLevel)
  {

    health = (std::rand() % ((level + 1) * 200)) + (25 + level * 25);
    power = (std::rand() % ((level + 1) * 200)) + (25 + level * 25);
  }

  int level;

  int health;
  int power;

  int healthPunishment = (level + 1) * 20;
  int powerPunishment = (level + 1) * 20;
  int moneyPunishment = (level + 1) * 20;

  int winMoney = level * 100 + std::rand() % ((level + 1) * 100);
  int winHealth = (level + 1) * 10;
  int winPower = (level + 1) * 10;

  std::string message;

  std::string playerWinMessage;
  std::string playerLoseMessage;

  void printWin();
  void printLose();
};

#endif