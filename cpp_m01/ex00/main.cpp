
#include "Zombie.hpp"

int main(void)
{
	std::cout << "Create a random chump:" << std::endl;
	randomChump("Stack_zombie");

	std::cout << "Create a new chump:" << std::endl;
	Zombie *man_ptr = newZombie("Heap_zombie");
	man_ptr->announce();
	delete man_ptr;
	
	return (0);
}
