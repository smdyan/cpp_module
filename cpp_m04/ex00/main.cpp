#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "CHECK TYPE VALUE:" << std::endl;
	std::cout << "Dog: " << j->getType() << " " << std::endl;
	std::cout << "Cat: " << i->getType() << " " << std::endl;
	std::cout << "Animal: " << meta->getType() << " " << std::endl;
	std::cout << "CHECK MAKESOUND:" << std::endl;
	std::cout << "Dog: ";
	j->makeSound();
	std::cout << "Cat: ";
	i->makeSound();
	std::cout << "Animal: ";
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "------------------Wrong-Animal-------------------------" << std::endl;
	const WrongAnimal* wa = new WrongCat();
	wa->makeSound();
	delete wa;
	
}