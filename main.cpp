#include <iostream>

// A statement is a basic unit of computation in a C++ program
// Every C++ program is a collection of statements organized in a certain way

// Define function before you can use it
int addNumbers(int first_param, int second_param)
{
  int result = first_param + second_param;
  return result;
}

int main()
{
  std::cout << "Hello World!" << std::endl;

  int first_number{5};
  int second_number{9};

  int sum = first_number + second_number;
  std::cout << "sum : " << sum << std::endl;

  return 0;
}
