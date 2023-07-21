#include <iostream>

// A statement is a basic unit of computation in a C++ program
// Every C++ program is a collection of statements organized in a certain way

int helloWorld()
{
  std::cout << "Hello World!" << std::endl;

  int first_number{5};
  int second_number{9};

  int sum = first_number + second_number;
  std::cout << "sum : " << sum << std::endl;
  return 0;
}

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
  /*
  char message1[]{"Hello World!"};
  message1[0] = "B";
  std::cout << "message1 : " << message1 << std::endl;
  */
  return 0;
}

// Dynamic Memory Allocation

/*
  Initialize the pointer with dynamic memory
  Dynamically allocate memory at run time and make
  a pointer point to it.
*/

int allocateMemory()
{
  int *p_number{nullptr};
  /*
    Dynamically allocate space for a single int on the heap.
    This memory belongs to our program from now on. The system
    After this line executes, we will have a valid memory location
    allocated. The size of the allocated memory will be such that
    it can store the type pointed to by the pointer;
  */
  p_number = new int; // 'new' allocates memory in heap

  // Writing into dynamically allocated memory
  *p_number = 77;
  std::cout << "Dynamically allocating memory : " << std::endl
            << "*p_number : " << *p_number << std::endl;

  // Releasing and resetting
  delete p_number;
  p_number = nullptr; // don't forget

  /*
  It is also possible to initialize the pointer with a valid
  address up on declaration, not with a nullptr
  */
  int *p_number1{new int};     // contains junk value
  int *p_number2{new int(22)}; // use direct init
  int *p_number3{new int{23}}; // use uniform

  // Releasing and resetting
  delete p_number1;
  delete p_number2;
  delete p_number3;
  p_number1 = nullptr;
  p_number2 = nullptr;
  p_number3 = nullptr;

  // You can reuse pointers
  p_number1 = new int(81);
  // release memory again
  delete p_number1;
  p_number1 = nullptr;
  // BUT Never delete the same pointer twice!

  // Let's say we have a couple of pointers pointing to the same place
  int *p_number4{new int(87)};

  // Check for nullptr before use
  if (p_number4 != nullptr)
  {
    std::cout << "*p_number4 : " << *p_number4 << std::endl;
  }
  else
  {
    std::cout << "invalid memory access" << std::endl;
  }

  int *p_number5{p_number4};

  if (!(p_number4 == nullptr))
  {
    // Only use slave pointers when master pointer is valid
    std::cout << "p_number5 : " << p_number5 << " - "
              << *p_number5 << std::endl;
  }

  delete p_number4;    // release
  delete p_number5;    // release
  p_number4 = nullptr; // reset
  p_number5 = nullptr; // reset

  return 0;
}

// When new Fails
int memoryOverflow()
{
  // TRY CATCH

  try
  {
    for (size_t i{0}; i < 1000000; ++i)
    {
      int *data = new int[1000000000];
    }
  }
  catch (std::exception &ex)
  {
    std::cout << "Something went wrong : " << ex.what() << std::endl;
  }

  // NOTHROW
  for (size_t i{0}; i < 100; ++i)
  {
    int *data = new (std::nothrow) int[1000000000];

    if (data != nullptr)
    {
      std::cout << "Data allocated" << std::endl;
    }
    else
    {
      std::cout << "Data allocation failed" << std::endl;
    }
  }

  return 0;
}

// Null Pointer Safety
// Verbose nullptr check
int nullptrCheck()
{
  int *p_number{}; // initialized to nullptr

  if (!(p_number == nullptr))
  {
    std::cout << "p_number points to a valid address: " << p_number
              << std::endl
              << "p_number: " << *p_number << std::endl;
  }
  else
  {
    std::cout << "p_number points to an INVALID address." << std::endl;
  }

  // Compact nullptr check

  // No more nullptr:
  p_number = new int(7);

  if (p_number)
  {
    std::cout << "p_number points to a valid address: " << p_number
              << std::endl
              << "p_number: " << *p_number << std::endl;
  }
  else
  {
    std::cout << "p_number points to an INVALID address." << std::endl;
  }

  delete p_number;
  p_number = nullptr;

  // Calling delete on a nullptr is OK, don't overcheck

  return 0;
}

// Reassignment of stack address to active pointer
int memoryLeaks()
{
  int *p_number{new int{67}}; // Points to some address
  // Should delete and reset here
  int number{55}; // lives at another address
  p_number = &number;
  /*
    Now p_number points to the second address, but our
    program has lost access to that memory location.
    We lost the key to that piece of memory thought it's
    still there.
    Memory has been leaked.
  */

  // delete p_number;
  p_number = nullptr;

  /*
    The same is with pointers in local scopes.
    They can be accessed and must be released in the same
    scope.
  */
  return 0;
}

// Dynamically allocated arrays
int dynamicallyAllocatedArrays()
{
  size_t size{10};
  // Different ways you declare an array dynamically and
  // how they are initialized

  // salaries array will contain garbage values
  double *p_salaries{new double[size]};

  // all values initialized to 0
  int *p_students{
      new (std::nothrow) int[size]{}};

  /*
    Allocating memory space for an array of size
    double. First 5 will be 1, 2, 3, 4, 5, and the rest
    will be 0's.
  */
  double *p_scores{
      new (std::nothrow) double[size]{1, 2, 3, 4, 5}};

  // nullptr check and use the allocated array
  if (p_scores)
  {
    std::cout << "size of scores (a regular pointer): " << sizeof(p_scores)
              << std::endl
              << "======" << std::endl;

    // Print out elements, Can use regular array access notation,
    // or pointer arithmetic.
  }

  // Add []
  delete[] p_salaries;
  p_salaries = nullptr;
  delete[] p_students;
  p_students = nullptr;
  delete[] p_scores;
  p_scores = nullptr;

  // Static vs Dynamic arrays
  int scores[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "scores size : " << std::size(scores) << std::endl;
  for (auto s : scores)
  {
    std::cout << "value : " << s << std::endl;
  }

  return 0;
}

int main()
{
  // helloWorld();
  // getName();
  // autoVariables();
  // pointerToChar();
  // allocateMemory();
  // memoryOverflow();
  // nullptrCheck();
  // memoryLeaks();
  dynamicallyAllocatedArrays();

  return 0;
}
