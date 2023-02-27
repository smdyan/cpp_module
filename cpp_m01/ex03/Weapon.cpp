
#include "Weapon.hpp"

Weapon::Weapon(std::string init_type){
    type = init_type;}

Weapon::Weapon(){}

Weapon::~Weapon(){}

const std::string& Weapon::getType(void){
    const std::string &ref = type;
    return (ref);}

void Weapon::setType(std::string new_type){
    this->type = new_type;}