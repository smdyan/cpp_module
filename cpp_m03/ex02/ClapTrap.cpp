
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    m_name = "default";
    m_hit_points = 10;
    m_energy_points = 10;
    m_attack_damage = 0;
}

ClapTrap::ClapTrap( const std::string& name )
{
    std::cout << "ClapTrap named constructor called" << std::endl;
    m_name = name;
    m_hit_points = 10;
    m_energy_points = 10;
    m_attack_damage = 0;
}

ClapTrap::ClapTrap( const ClapTrap& obj )
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
   *this = obj;
}

ClapTrap& ClapTrap::operator= ( const ClapTrap& obj )
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if ( this == &obj )
        return *this;
    m_name = obj.getName();
    m_hit_points = obj.getHitPoints();
    m_energy_points = obj.getEngPoints();
    m_attack_damage = obj.getAtackDmg();
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack( const std::string& target )
{
    if( !m_energy_points )
    {
        std::cout << "ClapTrap empty energy. Can't attack anymore!" << std::endl;
        return ;
    }
    else if( !m_hit_points )
    {
        std::cout << "ClapTrap empty hit points. Can't attack anymore!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << m_name 
                << " attacks " << target 
                << ", causing " << m_attack_damage  
                << " points of damage!" << std::endl;
    m_energy_points--;
    std::cout << "Energy points available: " << m_energy_points << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if( !m_hit_points)
    {
        std::cout << "ClapTrap empty hit points. Trap desabled!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << m_name
                << " takes damage of " << amount 
                << " points" << std::endl;
    if( amount < m_hit_points)
        m_hit_points -= amount;
    else
        m_hit_points = 0;
    std::cout << "Hit points available: " << m_hit_points << std::endl;
}
void ClapTrap::beRepaired( unsigned int amount )
{
    if( !m_energy_points )
    {
        std::cout << "ClapTrap empty energy. Can't repare hit points!" << std::endl;
        return ;
    }
    else if( !m_hit_points )
    {
        std::cout << "ClapTrap empty hit points. Trap desabled!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << m_name
                << " repared of " << amount 
                << " points" << std::endl;
    m_hit_points += amount;
    m_energy_points--;
    std::cout << "Energy points available: " << m_energy_points << std::endl;
}

/* getters & setters*/
std::string ClapTrap::getName( void ) const
{
    return m_name;
}

unsigned int ClapTrap::getHitPoints( void ) const
{
    return m_hit_points;
}

unsigned int ClapTrap::getEngPoints( void ) const
{
    return m_energy_points;
}

unsigned int ClapTrap::getAtackDmg( void ) const
{
    return m_attack_damage;
}

void ClapTrap::setName( std::string name )
{
    m_name = name;
}

void ClapTrap::setHitPoints( unsigned int hit_points )
{
    m_hit_points = hit_points;
}

void ClapTrap::setEngPoints( unsigned int energy_points )
{
    m_energy_points = energy_points;
}

void ClapTrap::setAtackDmg( unsigned int attack_damage )
{
    m_attack_damage = attack_damage;
}