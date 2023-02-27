
#include "Harl.hpp"

int main(void)
{
	Harl client;
	
	client.complain("debug");
	client.complain("info");
	client.complain("warning");
	client.complain("error");
	
	return (0);
}
