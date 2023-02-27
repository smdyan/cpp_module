#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
    std::string type;

public:
    Weapon();
    Weapon(std::string init_type);
    ~Weapon();
    const std::string& getType(void);
    void setType(std::string type);

};

#endif
