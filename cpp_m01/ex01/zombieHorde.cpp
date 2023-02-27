
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *ptr = new Zombie[N];
    Zombie  temp(name);
    int i = 0;
    while (i < N)
    {
        ptr[i] = temp;
        i++;
    }
    return (ptr);
}