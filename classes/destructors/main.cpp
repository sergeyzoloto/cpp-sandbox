#include <iostream>
#include <string_view>

// * 'this' is an address in memory of the current object

class Dog
{
public:
  Dog() = default;
  Dog(std::string_view name_param, std::string_view breed_param, int age_param);
  ~Dog();

  void print_info()
  {
    std::cout << "Dog (" << this << ") : [ name : " << name
              << " breed : " << breed << " age : " << *p_age << "]" << std::endl;
  }

  Dog &set_name(std::string_view name)
  {
    // name = name; // wrong
    this->name = name;
    return *this;
  }
  Dog &set_breed(std::string_view breed)
  {
    this->breed = breed;
    return *this;
  }
  Dog &set_age(int age)
  {
    *(this->p_age) = age;
    return *this;
  }

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
  *p_age = age_param; // pointer
  // * this
  std::cout << "Dog constructor called for " << name << " at " << this << std::endl;
}

// Destructor never has params
Dog::~Dog() // ! ~ (tilde) destructor
{
  delete p_age;
  std::cout << "Dog destructor called for " << name << std::endl;
}

void create_and_delete_dog()
{
  Dog *p_dog = new Dog("Fluffy", "Shepherd", 2);

  delete p_dog; // Causes for the destructor of Dog to be called
}

int main()
{

  Dog dog1("Doggy1", "Shepherd", 2);
  dog1.print_info();

  dog1.set_name("Another Dog");
  dog1.set_breed("Another Breed");
  dog1.set_age(4);
  dog1.print_info();

  // Chained calls using pointers
  // dog1.set_dog_name("One More Dog")->set_dog_breed("Some Breed")->set_dog_age(4);

  // Chained calls using references
  dog1.set_name("One More Dog").set_breed("Some Breed").set_age(4);

  /*
  Dog dog2("Doggy2", "Shepherd", 3);
  Dog dog3("Doggy3", "Shepherd", 5);
  Dog dog4("Doggy4", "Shepherd", 1);
  */

  std::cout << "Done!" << std::endl;
  return 0;
}

/*
  Result:

  Dog constructor called for Doggy1
  Dog constructor called for Doggy2
  Dog constructor called for Doggy3
  Dog constructor called for Doggy4
  Done!
  Dog destructor called for Doggy4
  Dog destructor called for Doggy3
  Dog destructor called for Doggy2
  Dog destructor called for Doggy1
*/
