#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
#include <sstream>
#include <math.h>
#include <ctype.h>

int	ft_isprint(int c);

class Conversion
{
	private:
		std::string	str;
		char		char_res;
		long		int_res;
		float		float_res;
		double		double_res;
		int			prec;
		bool		is_inf;
		bool		is_pos;
		
		char	get_str_type();

	public:
		Conversion();
		Conversion(const std::string& value);
		Conversion(const Conversion& other);
		~Conversion();
		Conversion& operator=(const Conversion& other);
		
		void	transformation();
		char	get_char() const;
		long	get_int() const;
		float	get_float() const;
		double	get_double() const;
		int		get_prec() const;
		bool	get_inf() const;
		bool	get_pos() const;
		std::string get_str() const;

		class InputException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Conversion& object);

#endif