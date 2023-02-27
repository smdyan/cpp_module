#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm> 
# include <vector>
# include <iterator>

typedef std::vector<int>::iterator my_iter;

class Span
{
	public:
		Span(unsigned int n_ints);
		~Span();
		Span(Span const & ref);
		Span const & operator=(Span const & ref);

		Span(int first, int last, int jump);

		unsigned int		getNInts( void ) const; 
		std::vector<int>	getVector( void ) const;
		unsigned int		getNContents(void) const;

		void	addNumber( unsigned int n );
		int		longestSpan( void );
		int		shortestSpan( void );

		template<typename T>
		void	addNumber(T start, T end)
		{
			int dist = std::distance(start, end);
			if (dist + this->_vector.size() > this->_n_capacity)
				throw( std::out_of_range( "Cannot add any more elements" ) );
			this->_vector.insert(this->_vector.end(), start, end);
		}

	private:
		unsigned int		_n_capacity;
		unsigned int		_n_size;
		std::vector<int>	_vector;
};

std::ostream & operator<<( std::ostream & o, Span const & rhs);

#endif