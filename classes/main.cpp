#include <iostream>
#include "cylinder.h"

int main()
{

  Cylinder cylinder1; // Object
  std::cout << "volume : " << cylinder1.volume() << std::endl
            << "base_radius : " << cylinder1.get_base_radius() << std::endl;
  cylinder1.set_base_radius(2.0);
  std::cout << "base_radius : " << cylinder1.get_base_radius() << std::endl;

  return 0;
}