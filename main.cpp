#include <iostream>

// A statement is a basic unit of computation in a C++ program
// Every C++ program is a collection of statements organized in a certain way

// Define function before you can use it
int addNumbers(int first_param, int second_param)
{
  int result = first_param + second_param;
  return result;
}

int getName()
{
  std::string full_name;

  std::cout << "Type in your full name : " << std::endl;
  // That's how we get text data with spaces
  std::getline(std::cin, full_name);

  std::cout << "Hello " << full_name << "!" << std::endl;

  return 0;
}

// C++ core language vs Standard library vs STL
// Standard library is an extension with reusable components
// STL is a collection of container types

int autoVariables()
{
  auto var1{12};
  auto var2{13.0};
  auto var3{14.0f};
  auto var4{15.0l};
  auto var5{'e'};

  // int modifier suffixes
  auto var6{123u};  // unsigned
  auto var7{123ul}; // unsigned long
  auto var8{123ll}; // long long

  std::cout << "var1 occupies : " << sizeof(var1) << " bytes" << std::endl;
  std::cout << "var2 occupies : " << sizeof(var2) << " bytes" << std::endl;
  std::cout << "var3 occupies : " << sizeof(var3) << " bytes" << std::endl;
  std::cout << "var4 occupies : " << sizeof(var4) << " bytes" << std::endl;
  std::cout << "var5 occupies : " << sizeof(var5) << " bytes" << std::endl;
  std::cout << "var6 occupies : " << sizeof(var6) << " bytes" << std::endl;
  std::cout << "var7 occupies : " << sizeof(var7) << " bytes" << std::endl;
  std::cout << "var8 occupies : " << sizeof(var8) << " bytes" << std::endl;

  return 0;
}

// Pointer to Char
int pointerToChar()
{
  // const is required
  const char *message{"Hello world!"};

  std::cout << "message: " << message << std::endl;

  // To allow further modification
  char message1[]{"Hello World!"};
  message1[0] = "B";
  std::cout << "message1 : " << message1 << std::endl;

  return 0;
}

int main()
{
  std::cout << "Hello World!" << std::endl;

  int first_number{5};
  int second_number{9};

  int sum = first_number + second_number;
  std::cout << "sum : " << sum << std::endl;
  // getName();
  // autoVariables();
  pointerToChar();

  return 0;
}
