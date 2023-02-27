#ifndef ITER_HPP
#define ITER_HPP

template< typename T >
void iter(T* array, int len, void f(T const &ref))
{
    int i = 0;
    while( i < len)
    {
        f(array[i]);
        i++;
    }
}

template< typename T >
void	display(T const &ref)
{
	std::cout << ref << std::endl;
}

#endif
