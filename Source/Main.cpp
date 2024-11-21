
// using json = nlohmann::json;

// struct Cooridinate{
//     Cooridinate(float nX, float nY) : x(nX), y(nY){}

//     float x, y;

//     Cooridinate operator+(Cooridinate &coord){
//         return {coord.x + x, coord.y + y};
//     }
//     Cooridinate operator-(Cooridinate &coord){
//         return {coord.x - x, coord.y - y};
//     }
//     Cooridinate operator*(Cooridinate &coord){
//         return {coord.x * x, coord.y * y};
//     }
//     Cooridinate operator/(Cooridinate &coord){
//         return {coord.x / x, coord.y / y};
//     }
// };
// struct Enemy{
//     Enemy(){}
//     Enemy(std::string newMessage, std::string win, std::string lose, int newLevel) : message(newMessage), playerWinMessage(win), playerLoseMessage(lose), level(newLevel){
//         //           level randomness         +     level based start          
//         health = (std::rand()%((level+1)*200)) + (25 + level*25);
//         power = (std::rand()%((level+1)*200)) + (25 + level*25);
//     }

//     int level;

//     int health;
//     int power;

//     int healthPunishment = (level+1)*20;
//     int powerPunishment = (level+1)*20;
//     int moneyPunishment = (level+1)*20;

//     int winMoney = level*100 + std::rand()%((level+1)*100);
//     int winHealth = (level+1)*10;
//     int winPower = (level+1)*10;

//     std::string message;

//     std::string playerWinMessage;
//     std::string playerLoseMessage;

//     void printWin();
//     void printLose();
// };

// void Enemy::printWin(){
//     std::cout << playerWinMessage << std::endl;

//     std::cout << "Money + " , winMoney;
//     std::cout << "\nHealth + " , winHealth;
//     std::cout << "\nPower + " , winPower;
// }
// void Enemy::printLose(){
//     std::cout << playerLoseMessage << "\n\n";
        
//     std::cout << "\nMoney - " , moneyPunishment;
//     std::cout << "\nHealth - " , healthPunishment;
//     std::cout << "\nPower - " , powerPunishment;
// }

// //items the player can pick up.
// struct PickUp{
//     PickUp(){}
//     PickUp(std::string newMessage, int newHealthAffect, int newPowerAffect) : message(newMessage), healthAffect(newHealthAffect), powerAffect(newPowerAffect){}

//     int healthAffect;
//     int powerAffect;

//     std::string message;

//     void printAffect();

//     void printAll();
// };

// void PickUp::printAffect(){
//     if(powerAffect != 0 && healthAffect != 0){
//         std::cout << "Health "  << (healthAffect < 0 ? "- " : "+ ") << healthAffect;
//         std::cout << "\nPower "  << (powerAffect < 0 ? "- " : "+ ") << powerAffect;
//     }
//     else if(healthAffect != 0){
//         std::cout << "Health"  << (healthAffect < 0 ? " " : "+ ") << healthAffect;
//     }
//     else if(powerAffect != 0){
//         std::cout << "Power"  << (powerAffect < 0 ? " " : "+ ") << powerAffect;
//     }
//     else{
//         std::cout << "No Affect.";
//     }
// }

// void PickUp::printAll(){
//     std::cout << "\n" << message << "\n";
//     printAffect();
// }

// class Player{
//     public:
//         void loadJson(bool preset = false);
//         void saveJson();

//         void addEnemy(){enemiesKilled += 1;};

//         void addMoney(int add){money += add;};
//         void addPower(int add){power += power;};

//         void changeHealth(int add){health += add;};

//         void move(Cooridinate displacement){position + displacement;};

//         void setPosition(Cooridinate newPosition){position = newPosition;};

//         void stats();

//         void pickUpItem(PickUp &item);

//         void explore();
//         void fightEnemy(int level = 1);

//         int getHealth(){return health;}
//         int getPower(){return power;}
//     private:
//         int enemiesKilled = 0;
//         int money = 0;
//         int power = 0;
//         int health = 0;
//         Cooridinate position = {0,0};

//         std::string name = "";
        
//         float distanceTraveled = 0;
// };

// void Player::loadJson(bool preset){
//     std::ifstream jsonFile;
    
//     if(preset){
//         jsonFile.open("Save/Default.json");
//     }else{
//         jsonFile.open("Save/Save.json");
//     }

//     if(jsonFile.fail()){
//         std::cout << "Save file not found. Loading default settings." << std::endl;
//         name = "Hero";
//         position.x = 0;
//         position.y = 0;
//         money = 0;
//         health = 100;
//         power = 100;
//         enemiesKilled = 0;
//         distanceTraveled = 0;
//     }
//     else{
//         json jsonData;

//         jsonFile >> jsonData;

//         name = jsonData["Name"];
//         position.x = jsonData["Position"]["x"];
//         position.y = jsonData["Position"]["y"];
//         money = jsonData["Money"];
//         health = jsonData["Health"];
//         power = jsonData["Power"];
//         enemiesKilled = jsonData["EnemiesKilled"];
//         distanceTraveled = jsonData["DistanceTraveled"];
//     }
// }

// void Player::saveJson(){
//     //make json formatted file, then dump the contents to a the save file
//     json jsonData;

//     jsonData["Name"] = name;
//     jsonData["Position"]["x"] = position.x;
//     jsonData["Position"]["y"] = position.y;
//     jsonData["Money"] = money;
//     jsonData["Health"] = health;
//     jsonData["Power"] = power;
//     jsonData["EnemiesKilled"] = enemiesKilled;
//     jsonData["DistanceTraveled"] = distanceTraveled;

//     std::ofstream jsonFile("Save/Save.json");
//     jsonFile << jsonData.dump(4);
// }
// void Player::stats(){
//     std::cout   << "\n----------- Hero ------------\n"
//                 << "\nMoney: " << money
//                 << "\nPower: " << power
//                 << "\nHealth: " << health
//                 << "\nPosition: " << position.x << ", " << position.y
//                 << "\nEnemies Killed: " << enemiesKilled 
//                 << "\nDistance Traveled: " << distanceTraveled
//                 << std::endl;
// }
// void Player::fightEnemy(int level){
//     bool win = false;

//     Enemy thief{"You have encountered a thief!","You stole the thief's life!", "You were shot!", 0};
//     Enemy dog{"You have encountered a rabid dog!", "You kindly sent the dog to the animal shelter", "You got rabies!", 0};
//     Enemy snake{"You have found a venomous snake!", "You stomped it's head.", "You got bit!", 0};

//     Enemy easyEnemies[] = {thief, dog, snake};

//     Enemy archer{"You have encountered a skilled archer!", "You shot em first!", "You got sniped!", 1};
//     Enemy swordsman{"You have encountered a swordsman!", "You stabbed his heart!", "You lost your arm.",1};

//     Enemy mediumEnemies[] = {archer, swordsman};

//     Enemy gladiator{"You have encountered a gladiator!", "You got em!", "Bro said THIS IS SPARTA and shoved you down a hole.",3};
//     Enemy lion{"You have encountered a lion!", "You got ate him for dinner with you family.", "You got eaten!", 3};
    
//     Enemy hardEnemies[] = {gladiator, lion};

//     Enemy lavaMonster{"You have encountered a lava monster!", "You brought him to the ocean.", "Your now part of a volcanoe.", 4};
//     Enemy evilWizard{"You have encountered an evil wizard!", "You turned him into a chicken (you went to magic school).", "Your now a ladybug!", 5};
    
//     Enemy thanos{"You have encountered Thanos!", "You stole his stones and sent him to the shadow realm", "You were snapped into the next dimension (literally).", 10};
//     Enemy doofenshmirtz{"You have stumbled across LEGENDARY Dr. Heinz Doofenshmirtz!!!!!!!!!!", "You found perry and foiled his evil plan! CURSE YOU PERRY THE PLATIPUS!", "You were killed by Doofenshmirtz and his Inexplicable Giant Floating Baby Head-Attract-Inator!!!!! What an honor!",10};
//     doofenshmirtz.power = 1000000;
//     doofenshmirtz.health = 1000000;
//     doofenshmirtz.winMoney = 1000000;

//     Enemy impossibleEnemies[] = {lavaMonster,evilWizard,doofenshmirtz,thanos};

//     //finds enemy to fight
//     Enemy selected;
//     switch(level){
//         case 0:
//             selected = easyEnemies[std::rand()%3];
//             break;
//         case 1:
//             selected = mediumEnemies[std::rand()%2];
//             break;
//         case 2:
//             selected = hardEnemies[std::rand()%2];
//             break;
//         case 3:
//             selected = lavaMonster;
//             break;
//         case 4:
//             selected = evilWizard;
//             break;
//         case 5:
//             selected = doofenshmirtz;
//             break;
//         default:
//             selected = doofenshmirtz;
//     }

//     //asks the player if they want to fight or not.
//     std::cout << selected.message << "\n\nHealth: " << selected.health << "\nPower: " << selected.power << "\n\nFight: Enter, Skip: Spacebar" << std::endl;

//     std::string fightInput;
//     fightInput = std::getchar();
    
//     if(fightInput == " "){
//         std::cout << "\nFight skipped";
//         return;
//     };

//     //1% change to win against doofenshmirtz
//     if(selected.power == doofenshmirtz.power && std::rand()%100 != 1){
//         win = false;
//     }
//     else{
//         win = true;
//     }

//     int powerDifference = power - selected.power;
//     int healthDifference = health - selected.health;

//     //if player is stronger in both ways they win
//     if(powerDifference > 0 && healthDifference > 0){
//         win = true;
//     }
//     //if player is stronger in only on the might win
//     else if(powerDifference > 0 || healthDifference > 0){
//         if(powerDifference + healthDifference > 0){ // if the player has a greater total power give them the win, otherwise it's a 50/50
//             win = true;
//         }
//         else{
//             win = (std::rand()%2) == 0;
//         }
//     }//if player is strong in neighter then they will lose
//     else{
//         win = false;
//     }
//     if(win){
//         selected.printWin();
//         power += selected.winHealth;
//         health += selected.winPower;
//         money += selected.winMoney;
//     }
//     else{
//         selected.printLose();
//         power -= selected.powerPunishment;
//         health -= selected.healthPunishment;
//         money -= selected.moneyPunishment;
//     }
// }

// void Player::pickUpItem(PickUp &item){
//     item.printAll();
//     power += item.powerAffect;
//     health += item.healthAffect;
// }
// void Player::explore(){
//     //makes pickups with fairly randomized values.
//     PickUp healthPotion{"You have found a health potion!", 25 + (std::rand()%50), 0};
//     PickUp steak{"You have found a steak.", 25, 0};
//     PickUp powerPotion{"You found a power potion!", 0, 50};
//     PickUp spinich{"You found a spinich!", 0, 10 + std::rand()%20};
//     PickUp lootBox{"You found a small a potion chest!", 25 + (std::rand()%50), 10 + std::rand()%20};

//     PickUp goodMiddleItems[] = {healthPotion, steak, powerPotion, spinich, lootBox};

//     PickUp peanutButter{"You accidentally age peanut butter, your allergic!!", -25 - (std::rand()%50), 0};
//     PickUp spoiledEgg{"You accidentally ate a spoiled egg.", -10 - (std::rand()%20), 0};
//     PickUp hole{"You sprained you ankle in a hole!", 0, -25 - (std::rand()%50)};
//     PickUp nail{"You broke your pinky nail!",-10 - (std::rand()%20), -10 - (std::rand()%20)};

//     PickUp badMiddleItems[] = {peanutButter, spoiledEgg, hole, nail};
    
//     PickUp magicalWizard{"You have found the mythical wizard!!!", 500, 500};

//     //moves a random distance and direction
//     std::srand(std::time(0));
//     Cooridinate direction = {float((std::rand()%3)-1), float((std::rand()%3)-1)};
//     Cooridinate displacement = {float(std::rand()%20), float(std::rand()%20)}; 
//     displacement = displacement*direction;
//     position = position + displacement;

//     //calculating distance with distance formula
//     distanceTraveled += std::sqrt(std::pow(displacement.x, 2) + std::pow(displacement.x, 2));

//     // 50% chance to encounter a monster
//     int chance = std::rand()%100;

//     if(chance > 50){//50% chance
//         //fights levels 0, 1
//         fightEnemy(std::rand()%2);
//     }
//     //lose health/power
//     else if(chance > 30){ //20% chance
//         PickUp selected = badMiddleItems[std::rand()%4];
//         pickUpItem(selected);
//     }
//     //fight big monster of level 2 or 3 or 5
//     else if(chance > 20){ //10% chance
//         fightEnemy(std::rand()%3 + 3);
//     }
//     //find ok loot/power // 15% chance
//     else if(chance > 5){
//         PickUp selected = goodMiddleItems[std::rand()%5];
//         pickUpItem(selected);
//     }
//     //find super loot
//     else if(chance <= 5){// 5% chance
//         pickUpItem(magicalWizard);
//     }
//     std::cout << "\n" <<  std::endl;
// }

#include "Player.h"

#include <iostream>

int main() {
    Player hero;

    std::cout << "Loading..." << std::endl;
    hero.loadJson();

    bool kill = false;
    while(!kill){
        if(hero.getHealth() <= 0){
            std::cout << "You died!\n\nGame Over." << std::endl;
            hero.loadJson(true);
        }
        std::cout   << "\nExlore: 1"
                    << "\nStats: 2"
                    << "\nSave and quit: 3"
                    << "\nNew game: 4"
                    << "\n\nHealth: " << hero.getHealth() << "\n"
                    << std::endl;
        
        int number;

        std::cin >> number;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if(std::cin.fail()){
            std::cout << "\nEnter a number.\n" << std::endl;
            std::cin.clear();
            break;
        }
        switch(number){
            case 1:
                hero.explore();
                break;
            case 2:
                hero.stats();
                break;
            case 3:
                //saves and ends program
                hero.saveJson();
                kill = true;
                break;
            case 4:
                //loads default
                hero.loadJson(true);
                break;
            default:
                std::cout << "\nInvalid input.\n" << std::endl;
        }
    }
    hero.saveJson();
    return 0;
}
