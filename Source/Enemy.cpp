#include "Enemy.h"

void Enemy::printWin(){
    std::cout << playerWinMessage << std::endl;

    std::cout << "Money + " , winMoney;
    std::cout << "\nHealth + " , winHealth;
    std::cout << "\nPower + " , winPower;
}
void Enemy::printLose(){
    std::cout << playerLoseMessage << "\n\n";
        
    std::cout << "\nMoney - " , moneyPunishment;
    std::cout << "\nHealth - " , healthPunishment;
    std::cout << "\nPower - " , powerPunishment;
}