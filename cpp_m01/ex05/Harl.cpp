
#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void ){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \
I really do!" << std::endl;}

void Harl::info( void ){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon \
in my burger! If you did, I wouldn't be asking for more!" << std::endl;}

void Harl::warning( void ){
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years \
whereas you started working here since last month." << std::endl;}

void Harl::error( void ){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;}

void    Harl::complain( std::string level )
{
    const struct {std::string lvl_name; void (Harl::*lvl_func)(void);} lvl_map[4] = {
        {"debug", &Harl::debug},
        {"info", &Harl::info},
        {"warning", &Harl::warning},
        {"error", &Harl::error}
    };

    int i(0);
    while (i < 4)
    {
        if (lvl_map[i].lvl_name == level)
        {
            (this->*(lvl_map[i].lvl_func))();
            i = 4;
        }
        i++;
    }
}