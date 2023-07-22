// * struct
/*
Another syntax to create classes in C++, but:
Class member variables are private by default,
while struct member values are public.
In all the rest meanings they are interchangeable.

Consider struct as an alternative to classes when
you don't have intensions to write methods for
a class, like a dictionary in Python or a JSON object in JS.
*/

#include <iostream>

class Dog
{
public:
  std::string m_name;
};

struct Cat
{
public:
  std::string m_name;
};

struct Point
{
  double x;
  double y;
};

void print_point(const Point &point)
{
  std::cout << "Point [ x: " << point.x << ", y : " << point.y << "]" << std::endl;
}

int main()
{
  Dog dog1;
  Cat cat1;

  dog1.m_name = "Fluffy"; // Compiler error
  cat1.m_name = "Juny";
  std::cout << dog1.m_name << std::endl;
  std::cout << cat1.m_name << std::endl;

  Point point1;
  point1.x = 10;
  point1.y = 55.5;

  print_point(point1);

  point1.x = 40.4;
  point1.y = 2.7;
  print_point(point1);

  return 0;
}