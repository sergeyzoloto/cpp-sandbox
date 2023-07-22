#include <iostream>
#include "cylinder.h"

int main()
{

  Cylinder cylinder1; // Object
  std::cout << "volume : " << cylinder1.volume() << std::endl
            << "base_radius : " << cylinder1.get_base_radius() << std::endl;
  cylinder1.set_base_radius(2.0);
  std::cout << "base_radius : " << cylinder1.get_base_radius() << std::endl;

  // Managing a stack object through pointers
  Cylinder *p_cylinder1 = &cylinder1;
  // ! -> Arrow pointer
  std::cout << "volume (p_cylinder1): " << p_cylinder1->volume() << std::endl;

  // Create a heap object through the new operator
  Cylinder *p_cylinder2 = new Cylinder(100, 2); // in Heap

  std::cout << "volume (p_cylinder2): " << p_cylinder2->volume() << std::endl;

  delete p_cylinder2;
  p_cylinder2 = nullptr;

  return 0;
}