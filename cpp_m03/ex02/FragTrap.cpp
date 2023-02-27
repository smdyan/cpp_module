#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string& name )
{
	std::cout << "FragTrap named constructor called" << std::endl;
	setName( name );
	setHitPoints( 100 );
	setEngPoints( 100 );
	setAtackDmg( 30 );
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	setName( obj.getName() );
	setHitPoints( obj.getHitPoints() );
	setEngPoints( obj.getEngPoints() );
	setAtackDmg( obj.getAtackDmg() );
	
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if( !getEngPoints() )
    {
        std::cout << "Empty energy. Can't attack anymore!" << std::endl;
        return ;
    }
	std::cout << "FragTrap "  << getName() << " attacks " << target << " causing " << getAtackDmg()
			   <<  " points of damage! " << std::endl;
	setEngPoints(getEngPoints() - 1);
    std::cout << "Energy points available: " << getEngPoints() << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five from " << getName() << std::endl;
}