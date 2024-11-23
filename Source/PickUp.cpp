#include "PickUp.h"

void PickUp::printAffect()
{
  if (powerAffect != 0 && healthAffect != 0)
  {
    std::cout << "Health " << (healthAffect < 0 ? "- " : "+ ") << healthAffect;
    std::cout << "\nPower " << (powerAffect < 0 ? "- " : "+ ") << powerAffect;
  }
  else if (healthAffect != 0)
  {
    std::cout << "Health" << (healthAffect < 0 ? " " : "+ ") << healthAffect;
  }
  else if (powerAffect != 0)
  {
    std::cout << "Power" << (powerAffect < 0 ? " " : "+ ") << powerAffect;
  }
  else
  {
    std::cout << "No Affect.";
  }
}

void PickUp::printAll()
{
  std::cout << "\n" << message << "\n";
  printAffect();
}