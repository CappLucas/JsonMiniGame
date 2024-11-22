#include "Player.h"

void Player::loadJson(bool preset){
    std::ifstream jsonFile;
    
    if(preset){
        jsonFile.open(saveFolder/"Default.json");
    }else{
        jsonFile.open(saveFolder/"Save.json");
    }

    if(jsonFile.fail()){
        std::cout << "Save file not found. Loading default settings." << std::endl;
        name = "Hero";
        position.x = 0;
        position.y = 0;
        money = 0;
        health = 100;
        power = 100;
        enemiesKilled = 0;
        distanceTraveled = 0;
    }
    else{
        json jsonData;

        jsonFile >> jsonData;

        name = jsonData["Name"];
        position.x = jsonData["Position"]["x"];
        position.y = jsonData["Position"]["y"];
        money = jsonData["Money"];
        health = jsonData["Health"];
        power = jsonData["Power"];
        enemiesKilled = jsonData["EnemiesKilled"];
        distanceTraveled = jsonData["DistanceTraveled"];
    }
}

void Player::saveJson(){
    //make json formatted file, then dump the contents to a the save file
    json jsonData;

    jsonData["Name"] = name;
    jsonData["Position"]["x"] = position.x;
    jsonData["Position"]["y"] = position.y;
    jsonData["Money"] = money;
    jsonData["Health"] = health;
    jsonData["Power"] = power;
    jsonData["EnemiesKilled"] = enemiesKilled;
    jsonData["DistanceTraveled"] = distanceTraveled;


    //find path of json file
    std::ofstream jsonFile(saveFolder/"Save.json");

    if(jsonFile.is_open()){jsonFile << jsonData.dump(4);}
    else{std::cout << "Failed to save.";}
    
}
void Player::stats(){
    std::cout   << "\n----------- Hero ------------\n"
                << "\nMoney: " << money
                << "\nPower: " << power
                << "\nHealth: " << health
                << "\nPosition: " << position.x << ", " << position.y
                << "\nEnemies Killed: " << enemiesKilled 
                << "\nDistance Traveled: " << distanceTraveled
                << std::endl;
}
void Player::fightEnemy(int level){
    bool win = false;

    Enemy thief{"You have encountered a thief!","You stole the thief's life!", "You were shot!", 0};
    Enemy dog{"You have encountered a rabid dog!", "You kindly sent the dog to the animal shelter", "You got rabies!", 0};
    Enemy snake{"You have found a venomous snake!", "You stomped it's head.", "You got bit!", 0};

    Enemy easyEnemies[] = {thief, dog, snake};

    Enemy archer{"You have encountered a skilled archer!", "You shot em first!", "You got sniped!", 1};
    Enemy swordsman{"You have encountered a swordsman!", "You stabbed his heart!", "You lost your arm.",1};

    Enemy mediumEnemies[] = {archer, swordsman};

    Enemy gladiator{"You have encountered a gladiator!", "You got em!", "Bro said THIS IS SPARTA and shoved you down a hole.",3};
    Enemy lion{"You have encountered a lion!", "You got ate him for dinner with you family.", "You got eaten!", 3};
    
    Enemy hardEnemies[] = {gladiator, lion};

    Enemy lavaMonster{"You have encountered a lava monster!", "You brought him to the ocean.", "Your now part of a volcanoe.", 4};
    Enemy evilWizard{"You have encountered an evil wizard!", "You turned him into a chicken (you went to magic school).", "Your now a ladybug!", 5};
    
    Enemy harderEnemies[] = {lavaMonster,evilWizard};

    Enemy thanos{"You have encountered Thanos!", "You stole his stones and sent him to the shadow realm", "You were snapped into the next dimension (literally).", 10};
    Enemy doofenshmirtz{"You have stumbled across LEGENDARY Dr. Heinz Doofenshmirtz!!!!!!!!!!", "You found perry and foiled his evil plan! CURSE YOU PERRY THE PLATIPUS!", "You were killed by Doofenshmirtz and his Inexplicable Giant Floating Baby Head-Attract-Inator!!!!! What an honor!",10};
    doofenshmirtz.power = 1000000;
    doofenshmirtz.health = 1000000;
    doofenshmirtz.winMoney = 1000000;

    Enemy impossibleEnemies[] = {doofenshmirtz,thanos};

    //finds enemy to fight
    Enemy selected;
    switch(level){
        case 0:
            selected = easyEnemies[std::rand()%3];
            break;
        case 1:
            selected = mediumEnemies[std::rand()%2];
            break;
        case 2:
            selected = hardEnemies[std::rand()%2];
            break;
        case 3:
            selected = harderEnemies[std::rand()%2];
            break;
        case 4:
            selected = impossibleEnemies[std::rand()%2];
            break;
    }

    //asks the player if they want to fight or not.
    std::cout << selected.message << "\n\nHealth: " << selected.health << "\nPower: " << selected.power << "\n\nFight: Enter, Skip: Spacebar" << std::endl;

    std::string fightInput;
    fightInput = std::getchar();
    
    if(fightInput == " "){
        std::cout << "\nFight skipped";
        return;
    };

    int powerDifference = power - selected.power;
    int healthDifference = health - selected.health;

    //if player is stronger in both ways they win
    if(powerDifference > 0 && healthDifference > 0){
        win = true;
    }
    //if player is stronger in only on the might win
    else if(powerDifference > 0 || healthDifference > 0){
        if(powerDifference + healthDifference > 0){ // if the player has a greater total power give them the win, otherwise it's a 50/50
            win = true;
        }
        else{
            win = (std::rand()%100) < int((power/selected.power)*100);
        }
    }//if player is strong in neighter then they will lose
    else{
        win = false;
    }
    if(win){
        selected.printWin();
        power += selected.winHealth;
        health += selected.winPower;
        money += selected.winMoney;
    }
    else{
        selected.printLose();
        power -= selected.powerPunishment;
        health -= selected.healthPunishment;
        money -= selected.moneyPunishment;
    }
}

void Player::pickUpItem(PickUp &item){
    item.printAll();
    power += item.powerAffect;
    health += item.healthAffect;
}
void Player::explore(){
    //makes pickups with fairly randomized values.
    PickUp healthPotion{"You have found a health potion!", 25 + (std::rand()%50), 0};
    PickUp steak{"You have found a steak.", 25, 0};
    PickUp powerPotion{"You found a power potion!", 0, 50};
    PickUp spinich{"You found a spinich!", 0, 10 + std::rand()%20};
    PickUp lootBox{"You found a small a potion chest!", 25 + (std::rand()%50), 10 + std::rand()%20};

    PickUp goodMiddleItems[] = {healthPotion, steak, powerPotion, spinich, lootBox};

    PickUp peanutButter{"You accidentally age peanut butter, your allergic!!", -25 - (std::rand()%50), 0};
    PickUp spoiledEgg{"You accidentally ate a spoiled egg.", -10 - (std::rand()%20), 0};
    PickUp hole{"You sprained you ankle in a hole!", 0, -25 - (std::rand()%50)};
    PickUp nail{"You broke your pinky nail!",-10 - (std::rand()%20), -10 - (std::rand()%20)};

    PickUp badMiddleItems[] = {peanutButter, spoiledEgg, hole, nail};
    
    PickUp magicalWizard{"You have found the mythical wizard!!!", 500, 500};

    //moves a random distance and direction
    std::srand(std::time(0));
    Cooridinate direction = {float((std::rand()%3)-1), float((std::rand()%3)-1)};
    Cooridinate displacement = {float(std::rand()%20), float(std::rand()%20)}; 
    displacement = displacement*direction;
    position = position + displacement;

    //calculating distance with distance formula
    distanceTraveled += std::sqrt(std::pow(displacement.x, 2) + std::pow(displacement.x, 2));

    // 50% chance to encounter a monster
    int chance = std::rand()%100;

    if(chance > 70){//30% chance
        //fights easy and medium mobs
        fightEnemy(std::rand()%2);
    }
    else if(chance > 50){ //20% chance
        //fights hard or harder mobs
        fightEnemy(std::rand()%2 + 2);
    }
    else if(chance > 35){ //15% chance
        fightEnemy(4);
    }
    //lose health/power
    else if(chance > 10){ //25% chance
        PickUp selected = badMiddleItems[std::rand()%4];
        pickUpItem(selected);
    }
    //find ok loot/power // 10% chance
    else if(chance > 1){
        PickUp selected = goodMiddleItems[std::rand()%5];
        pickUpItem(selected);
    }
    //find super loot
    else if(chance <= 1){// 1% chance
        pickUpItem(magicalWizard);
    }
    std::cout << "\n" <<  std::endl;
}