#include "HumanB.hpp"

HumanB::HumanB(std::string init_name){
    weapon = NULL;
    name = init_name;}

HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon &weap){
    weapon = &weap;}

void HumanB::attack(void){
    if (weapon)
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with no weapon" << std::endl;
    }