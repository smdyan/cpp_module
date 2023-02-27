
#include "Zombie.hpp"

int main(void)
{
	Zombie* ptr;

	ptr = zombieHorde(10, "droid");
	int	n = 0;
	while (n < 10)
	{
		std::cout << n + 1 << " ";
		ptr[n].announce();
		n++;
	}

	delete[] ptr;
	return (0);
}
