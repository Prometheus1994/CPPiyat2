#include <iostream>

class Animal
{
	public:
		virtual ~Animal() {}
};

class Dog : public Animal
{
};

class Cat : public Animal
{
};

int main()
{
	Animal *a = new Cat();
	Dog *d = dynamic_cast<Dog*>(a);
	Cat *c = dynamic_cast<Cat*>(a);

	if (d)
		std::cout << "a is a dog" << std::endl;
	else
		std::cout << "a is not a dog" << std::endl;

	if (c)
		std::cout << "a is a cat" << std::endl;
	else
		std::cout << "a is not a cat" << std::endl;
}