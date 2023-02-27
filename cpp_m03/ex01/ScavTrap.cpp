#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : m_gate_keeper_mode(false)
{
	std::cout << "ScarTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string& name ) : m_gate_keeper_mode(false)
{
	std::cout << "ScavTrap named constructor called" << std::endl;
	setName( name );
	setHitPoints( 100 );
	setEngPoints( 50 );
	setAtackDmg( 20 );
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	setName( obj.getName() );
	setHitPoints( obj.getHitPoints() );
	setEngPoints( obj.getEngPoints() );
	setAtackDmg( obj.getAtackDmg() );

	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if( !getEngPoints() )
    {
        std::cout << "Empty energy. Can't attack anymore!" << std::endl;
        return ;
    }
	std::cout << "ScavTrap "  << getName() << " attacks " << target << " causing " << getAtackDmg()
			   <<  " points of damage! " << std::endl;
	setEngPoints(getEngPoints() - 1);
    std::cout << "Energy points available: " << getEngPoints() << std::endl;
}

void ScavTrap::guardGate()
{
	m_gate_keeper_mode = true;
	std::cout << getName() << " goes guard gate" << std::endl;
}

void ScavTrap::getMode() const
{
	if (m_gate_keeper_mode)
		std::cout << getName() << " on a gate" << std::endl;
	else
		std::cout << getName() << " not on a gate" << std::endl;
}