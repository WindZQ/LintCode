#include <string>
#include <iostream>


class Toy
{
public:
    virtual void talk() const = 0;
};

class Dog : public Toy
{
    void talk() const
    {
        std::cout << "Wow" << std::endl;
    }
};

class Cat : public Toy
{
    void talk() const
    {
        std::cout << "Meow" << std::endl;
    }
};

class ToyFactory
{
public:
    Toy *getToy(std::string &type)
    {
        if(type == "Dog")
        {
            return new Dog();
        }
        else if(type == "Cat")
        {
            return new Cat();
        }
        return NULL;
    }
};
