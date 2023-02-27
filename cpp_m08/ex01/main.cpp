
#include "Span.hpp"

int main(void)
{
	Span	sp0 = Span(5);
	sp0.addNumber(5);
	sp0.addNumber(3);
	sp0.addNumber(17);
	sp0.addNumber(9);
	sp0.addNumber(11);
	std::cout << "SP0:" << std::endl << sp0;
	std::cout << "Shortest span: " << sp0.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp0.longestSpan() << std::endl;

	Span	sp1(1, 10, 1);
	std::cout << "SP1:" << std::endl << sp1;
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp1.longestSpan() << std::endl;

	Span	sp2(1, 2000000, 10);
    std::cout << "SP2:" << std::endl;
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;

    std::cout << "SP3:" << std::endl;
	try
	{
		int source_a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> source(source_a, source_a + 9);
		Span sp3 = Span(3);
		sp3.addNumber(source.begin(), source.end());
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span	sp4(0);
	std::cout << "SP4: exeptions" << std::endl << sp4;
	try
	{
		sp4.addNumber(5);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		sp4.shortestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
    
	try
	{
		sp4.longestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}