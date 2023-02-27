#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
private:
    std::string     m_name;
    unsigned int    m_hit_points;
    unsigned int    m_energy_points;
    unsigned int    m_attack_damage;

public:
    ClapTrap();
    ClapTrap( const std::string& name );
    ClapTrap( const ClapTrap& obj );
    ClapTrap& operator= ( const ClapTrap& num );
    ~ClapTrap();

    void attack( const std::string& target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

    std::string getName( void ) const;
    unsigned int getHitPoints( void ) const;
    unsigned int getEngPoints( void ) const;
    unsigned int getAtackDmg( void ) const;
    void setName( std::string name );
    void setHitPoints( unsigned int hit_points );
    void setEngPoints( unsigned int energy_points );
    void setAtackDmg( unsigned int attack_damage );

};

#endif
