#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include "Types.h"
#include "Pickup.h"
#include "Enemy.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>

class Player{
    public:
        void loadJson(bool preset = false);
        void saveJson();

        void addEnemy(){enemiesKilled += 1;};

        void addMoney(int add){money += add;};
        void addPower(int add){power += power;};

        void changeHealth(int add){health += add;};

        void move(Cooridinate displacement){position + displacement;};

        void setPosition(Cooridinate newPosition){position = newPosition;};

        void stats();

        void pickUpItem(PickUp &item);

        void explore();
        void fightEnemy(int level = 1);

        int getHealth(){return health;}
        int getPower(){return power;}
    private:
        int enemiesKilled = 0;
        int money = 0;
        int power = 0;
        int health = 0;
        Cooridinate position = {0,0};

        std::string name = "";
        
        float distanceTraveled = 0;
};

#endif