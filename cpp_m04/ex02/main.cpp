#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define ALL 2
#define HALF ALL / 2

int	main( void )
{
	AAnimal	*a[ALL];

	for (int i = 0; i < HALF; i++)
	{
		a[i] = new Cat();
	}
	for (int i = HALF; i < ALL; i++)
	{
		a[i] = new Dog();
	}

	for (int i = 0; i < ALL; i++)
	{
		delete a[i];
	}
	std::cout << "------CHECK FOR COPY------" << std::endl;
	Cat *obj_a = new Cat();
	Cat *obj_a_copy = new Cat(*obj_a);
	Dog	*obj_b = new Dog();
	Dog *obj_b_copy = new Dog(*obj_b);

	delete obj_a;
	delete obj_b;
	obj_a_copy->makeSound();
	obj_b_copy->makeSound();
	delete obj_a_copy;
	delete obj_b_copy;
	// std::cout << "------CHECK FOR ABSTRACT------" << std::endl;
    //	AAnimal abs_obj;     // doesn't compile

}