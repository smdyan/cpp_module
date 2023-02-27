
#include "MutantStack.hpp"

int main(void)
{
	{	
		std::cout << "*******************|Test the Stack using INT|********************\n";
		MutantStack<int> mstack;
		std::cout << "push(5)" << std::endl << "push(17)" << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top element: " << mstack.top() << std::endl;
		std::cout << "size before pop: " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "push(3, 5, 737 )" << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end() - 1;
		std::cout << "begin it= " << *it << std::endl;
		std::cout << "end ite=  " << *ite << std::endl;
		++it;
		std::cout << "++begin: " << *it << std::endl;
		std::cout << "end: " << *ite << std::endl;
		--it;
		std::cout << "--begin " << *it << std::endl;
		std::cout << "end " << *ite << std::endl;
		std::cout << "Content of the stack:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "size: " << mstack.size() << std::endl;
		MutantStack<int> mstack2(mstack);
		std::cout << "2top element: " << mstack2.top() << std::endl;
		MutantStack<int> mstack3;
		mstack3 = mstack;
		std::cout << "3top element: " << mstack3.top() << std::endl;
		std::stack<int> s(mstack);

	}

	{
		std::cout << "II*******************|Test the Stack using INT|********************\n";
		std::list<int> mstack;
		std::cout << "push(5)" << std::endl << "push(17)" << std::endl;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top element: " << mstack.back() << std::endl;
		std::cout << "size before pop: " << mstack.size() << std::endl;
		mstack.pop_back();
		std::cout << "size: " << mstack.size() << std::endl;
		std::cout << "push(3, 5, 737 )" << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = --mstack.end();
		std::cout << "begin it= " << *it << std::endl;
		std::cout << "end ite=  " << *ite << std::endl;
		++it;
		std::cout << "++begin: " << *it << std::endl;
		std::cout << "end: " << *ite << std::endl;
		--it;
		std::cout << "--begin " << *it << std::endl;
		std::cout << "end " << *ite << std::endl;
		std::cout << "Content of the stack:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "size: " << mstack.size() << std::endl;
	}

	{
		std::cout << "*******************|Test the Stack using STR|********************\n";
		MutantStack<std::string> mstack;
		std::cout << "push 2 elem" << std::endl;
		mstack.push("Bari");
		mstack.push("Mehdi");
		std::cout << "top elem: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "pop out... new top: " << mstack.top() << std::endl;
		std::cout << "size:" << mstack.size() << std::endl;
		std::cout << "push elem: " << std::endl;
		mstack.push("Mehdi");
		std::cout << mstack.top() << std::endl;
		std::cout << mstack.size() << std::endl;
		std::stack<std::string> s(mstack);
	}

	{
		std::cout << "II*******************|Test the Stack using STR|********************\n";
		std::list<std::string> mstack;
		std::cout << "push 2 elem" << std::endl;
		mstack.push_back("Bari");
		mstack.push_back("Mehdi");
		std::cout << "top elem: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "pop out... new top: " << mstack.back() << std::endl;
		std::cout << "size:" << mstack.size() << std::endl;
		std::cout << "push elem: " << std::endl;
		mstack.push_back("Mehdi");
		std::cout << mstack.back() << std::endl;
		std::cout << mstack.size() << std::endl;
	
	}
	return 0;

}