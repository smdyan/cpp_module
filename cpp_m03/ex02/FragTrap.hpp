#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap();
	FragTrap(const std::string& name);
	~FragTrap();
	FragTrap(const FragTrap& obj);
	FragTrap& operator=(const FragTrap& obj);

	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif
