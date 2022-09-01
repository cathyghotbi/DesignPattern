
#include <iostream>
#include <memory>

//-------------------------------------------------------------------------------------
class Animal
{
public:
  Animal()
  {
    std::cout << "Animal created.." << std::endl;
  }
  virtual void printName() = 0;
  virtual ~Animal()
  {
    std::cout << "Animal destructed.." << std::endl;
  }
};

class Cat : public Animal
{
public:
  Cat()
  {
    std::cout << "Cat created.." << std::endl;
  }
  void printName() override
  {
    std::cout << "cat" << std::endl;
  }
};

class Dog : public Animal
{
public:
  Dog()
  {
    std::cout << "Dog created.." << std::endl;
  }
  void printName() override
  {
    std::cout << "dog" << std::endl;
  }
};
//-------------------------------------------------------------------------------------
// Factory design pattern
class AnimalFactory : public Animal
{
public:
  static std::unique_ptr<Animal> createAnimal(int id)
  {
    std::unique_ptr<Animal> a;
    switch (id)
    {
      case 1:
      a = std::make_unique<Cat>();
      break;

      case 2:
      a = std::make_unique<Dog>();
      break;
    }    
    return a;  
  }
};
//-------------------------------------------------------------------------------------
int main() 
{
  // using factory method, Animal type is decided later on
  {
    std::unique_ptr<Animal> cat =  AnimalFactory::createAnimal(1);
    cat->printName();
  }
  std::cout << "------------------------" << std::endl;
  {
    std::unique_ptr<Animal> dog =  AnimalFactory::createAnimal(2);
    dog->printName();
  }
  std::cout << "------------------------" << std::endl;
  
  // using contrcutor, Animal type is decided here
  {
    std::unique_ptr<Animal> cat = std::make_unique<Cat>();
    cat->printName();
  }
  std::cout << "------------------------" << std::endl;
  {
    std::unique_ptr<Animal> dog = std::make_unique<Dog>();
    dog->printName();
  }
  std::cout << "------------------------" << std::endl;
  
  return 0;
}
//-------------------------------------------------------------------------------------
