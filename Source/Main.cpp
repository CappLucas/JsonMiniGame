

#include "Player.h"

#include <iostream>

int main()
{
  Player hero;

  std::cout << "Loading..." << std::endl;
  hero.loadJson();

  bool kill = false;
  while (!kill)
  {
    if (hero.getHealth() <= 0)
    {
      std::cout << "You died!\n\nGame Over." << std::endl;
      hero.loadJson(true);
    }
    std::cout << "\nExlore: 1"
              << "\nStats: 2"
              << "\nSave and quit: 3"
              << "\nNew game: 4"
              << "\n\nHealth: " << hero.getHealth() << "\n"
              << std::endl;

    int number;

    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (std::cin.fail())
    {
      std::cout << "\nEnter a number.\n" << std::endl;
      std::cin.clear();
      break;
    }
    switch (number)
    {
    case 1:
      hero.explore();
      break;
    case 2:
      hero.stats();
      break;
    case 3:

      hero.saveJson();
      kill = true;
      break;
    case 4:

      hero.loadJson(true);
      break;
    default:
      std::cout << "\nInvalid input.\n" << std::endl;
    }
  }
  hero.saveJson();
  return 0;
}
