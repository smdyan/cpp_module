#include "Span.hpp"

Span::Span(unsigned int n_ints) : _n_capacity(n_ints)
{
	_vector.reserve(n_ints);
	_n_size = 0;
}

Span::Span(int first, int last, int jump)
{
	int tmp;
	if( last < first)
	{
		tmp = last;
		last = first;
		first = tmp;
	}

	_n_capacity = (last - first) / jump;
	_vector.reserve(_n_capacity);
	for (int i = first; i < last; i += jump)
		_vector.push_back(i);
	_n_size = _n_capacity;
}

Span::Span(Span const &ref)
{
	*this = ref;
}

Span::~Span()
{}

Span const &Span::operator=(Span const &ref)
{
	if( this == &ref)
		return *this;
	this->_n_capacity = ref.getNInts();
	this->_vector = ref.getVector();
	this->_n_size = this->_vector.size();
	return (*this);
}

unsigned int Span::getNInts(void) const
{
	return (_n_capacity);
}

unsigned int Span::getNContents(void) const
{
	return (_n_size);
}

std::vector<int> Span::getVector(void) const
{
	return (_vector);
}

void Span::addNumber(unsigned int n)
{
	if ( _n_size >= _n_capacity )
		throw(std::out_of_range("Cannot add any more elements"));
	_vector.push_back(n);
	_n_size++;
}

int Span::longestSpan(void)
{
	if (_n_size <= 1)
		throw(std::out_of_range("Not enough elements for a span"));
	std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	int span = *max - *min;
	return (span);
}

int Span::shortestSpan(void)
{
	if ( _n_size <= 1 )
		throw(std::out_of_range("Not enough elements for a span"));
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	int span = *max;

	std::vector<int> v = _vector;
	std::sort(v.begin(), v.end());
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (i && std::abs(v[i] - v[i - 1]) < span)
			span = std::abs(v[i] - v[i - 1]);
	}
	return (span);
}

std::ostream & operator<<( std::ostream & o, Span const & rhs)
{
	std::cout << "Span contents: ";
	for (unsigned int i = 0; i < rhs.getNContents(); i++)
		std::cout << (rhs.getVector())[i] << " ";
	std::cout << std::endl;
	return (o);
}