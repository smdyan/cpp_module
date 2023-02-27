
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap	a1( "man1" );
	ClapTrap	a( a1 );
	ClapTrap	b1( "man2" );
	ClapTrap	b( b1 );

	std::cout << "____ClapTrap____" << std::endl;
	a.attack("man2");
	b.takeDamage(3);
	b.beRepaired(2);
	std::cout << "assignment..." << std::endl;
	ClapTrap	c;
	c = b;
	int i = 10;
	while (i)
	{
		c.attack("man1");
		--i;
	}
	a.takeDamage(100);

	std::cout << "____ScavTrap____" << std::endl;

	ScavTrap f("batman");
	ScavTrap g("robin");

	g.getMode();
	f.attack(g.getName());
	g.takeDamage(f.getAtackDmg());
	g.guardGate();
	g.getMode();
	return (0);
}
