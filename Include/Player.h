#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include "Enemy.h"
#include "Pickup.h"
#include "Types.h"


#include <cmath>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>


namespace fileSystem = std::filesystem;

class Player
{
public:
  void loadJson(bool preset = false);
  void saveJson();

  void addEnemy() { enemiesKilled += 1; };

  void addMoney(int add) { money += add; };
  void addPower(int add) { power += add; };

  void changeHealth(int add) { health += add; };

  void move(Cooridinate displacement) { position = position + displacement; };

  void setPosition(Cooridinate newPosition) { position = newPosition; };

  void stats();

  void pickUpItem(PickUp &item);

  void explore();
  void fightEnemy(int level = 1);

  int getHealth() { return health; }
  int getPower() { return power; }

private:
  int enemiesKilled = 0;
  int money = 0;
  int power = 0;
  int health = 0;
  Cooridinate position = {0, 0};

  std::string name = "";

  float distanceTraveled = 0;

  fileSystem::path executableFolder = fileSystem::current_path();
  fileSystem::path saveFolder = executableFolder / "Save";
};

#endif