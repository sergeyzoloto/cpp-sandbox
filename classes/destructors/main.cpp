#include <iostream>
#include <string_view>

class Dog
{
public:
  Dog() = default;
  Dog(std::string_view name_param, std::string_view breed_param, int age_param);
  ~Dog();

private:
  std::string name;
  std::string breed;
  int *p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
  name = name_param;
  breed = breed_param;
  p_age = new int;
  *p_age = age_param;
  std::cout << "Dog constructor called for " << name << std::endl;
}

// Destructor never has params
Dog::~Dog() // ! ~ (tilde) destructor
{
  delete p_age;
  std::cout << "Dog destructor called for : " << name << std::endl;
}

void create_and_delete_dog()
{
  Dog *p_dog = new Dog("Fluffy", "Shepherd", 2);

  delete p_dog; // Causes for the destructor of Dog to be called
}

int main()
{

  create_and_delete_dog();

  std::cout << "Done!" << std::endl;
  return 0;
}