#include "HumanA.hpp"

HumanA::HumanA(std::string init_name, Weapon &weap) : weapon(weap){
    name = init_name;}

HumanA::~HumanA(){}

void HumanA::attack(void){
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;}