#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int val = rand() % 3;

	if (val == 0)
		return (new A);
	else if (val == 1)
		return (new B);
	return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type C" << std::endl;
}

void identify(Base& p)
{
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "Type A!" << std::endl;		
	}
	catch (std::exception& e) {
		(void)e;
	}
	
	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "Type B!" << std::endl;		
	}
	catch (std::exception& e) {
		(void)e;
	}

	try {
		C b = dynamic_cast<C &>(p);
		std::cout << "Type C!" << std::endl;		
	}
	catch (std::exception& e) {
		(void)e;
	}
}

int main()
{
	srand(time(0));

	Base *a = generate();
	identify(a);
	identify(*a);
	delete a;
	return (0);
}