
#include "Zombie.hpp"

Zombie::Zombie(std::string init_name)
{
    name = init_name;
}

Zombie::Zombie()
{}

Zombie::~Zombie()
{
    std::cout << "R.I.P. " << this->name << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}