/*
You can't have multiple definitions for the same name in your
entire C++ program, but for classes we can violate this rule a little
and let the same definition show up in multiple translation units.
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
public:
  // Constructor
  Person(const std::string &names_param, int age_param);

  void print_info() const
  {
    std::cout << "name : " << full_name " , age : " << age << std::endl;
  }

private:
  std::string full_name;
  int age;

public:
  // Static variable declaration
  static int person_count;
};

#endif // PERSON_H