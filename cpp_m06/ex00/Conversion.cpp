#include "Conversion.hpp"

Conversion::Conversion()
{
	this->str = "";
	this->char_res = 0;
	this->int_res = 0;
	this->float_res = 0;
	this->double_res = 0;
	this->prec = 0;
	this->is_inf = false;
	this->is_pos = true;
}

Conversion::Conversion(const std::string& value)
{
	this->str = value;
	this->char_res = 0;
	this->int_res = 0;
	this->float_res = 0;
	this->double_res = 0;
	this->prec = 0;
	this->is_inf = false;
	this->is_pos = true;
}

Conversion::Conversion(const Conversion& other)
{
	*this = other;
}

Conversion::~Conversion()
{}

Conversion& Conversion::operator=(const Conversion& other)
{
	if (this == &other)
		return (*this);
	this->str = other.str;
	this->char_res = other.char_res;
	this->int_res = other.int_res;
	this->float_res = other.float_res;
	this->double_res = other.double_res;
	this->prec = other.prec;
	this->is_inf = other.is_inf;
	this->is_pos = other.is_pos;
	return (*this);
}

char Conversion::get_str_type()
{
	if (this->str.length() == 1 && !isdigit(this->str[0]))
		return ('c');
	if (this->str == "-inff" || this->str == "+inff" || this->str == "nanf") 
	{
		this->is_inf = true;
		return ('f');
	}
	if (this->str == "-inf" || this->str == "+inf" || this->str == "nan")
	{
		this->is_inf = true;
		return ('d');
	}
	size_t len = this->str.length();
	for (size_t i = 0; i < len; i++)
	{
		if (i == 0 && (this->str[i] == '-'))
			continue;
		else if (str[i] == '.')
			this->prec = len - i - 1;
		else if ((i + 1) == len && this->str[i] == 'f')
			return ('f');
		else if (!isdigit(this->str[i]))
			return (0);
	}
	if (this->prec != 0)
		return ('d');
	return ('i');
}

void Conversion::transformation()
{
	char type = get_str_type();

	if (type == 'c')
	{
		this->char_res = this->str[0];
		this->int_res = static_cast<long>(this->str[0]);
		this->float_res = static_cast<float>(this->str[0]);
		this->double_res = static_cast<double>(this->str[0]);
	}
	else if (type == 'i')
	{
		this->int_res = atol(this->str.data());
		if (this->int_res < (-2147483647 - 1) || this->int_res > 2147483647)
			throw (std::overflow_error("Very big value! INT"));
		this->char_res = static_cast<char>(this->int_res);
		this->float_res = static_cast<float>(this->int_res);
		this->double_res = static_cast<double>(this->int_res);
	}
	else if (type == 'f')
	{
		if( prec )
			this->prec -= 1;
		if (this->is_inf)
			return ;
		this->str.pop_back();
		std::istringstream ss(this->str);
		if (!(ss >> this->float_res))
			throw (std::overflow_error("Very big value! FLOAT"));
		if ((this->float_res > 2147483647 || this->float_res < (-2147483647 - 1)) && !this->is_inf)
			this->is_pos = false;
		this->char_res = static_cast<char>(this->float_res);
		this->int_res = static_cast<long>(this->float_res);
		this->double_res = static_cast<double>(this->float_res);
	}
	else if (type == 'd')
	{
		if (this->is_inf)
			return ;
		std::istringstream ss(this->str);
		if (!(ss >> this->double_res))
			throw (std::overflow_error("Very big value! DOUBLE"));
		if ((this->double_res > 2147483647 || this->double_res < (-2147483647 - 1)) && !this->is_inf)
			this->is_pos = false;
		this->char_res = static_cast<char>(this->double_res);
		this->int_res = static_cast<long>(this->double_res);
		this->float_res = static_cast<float>(this->double_res);
	}
	else
		throw (InputException());
}

const char* Conversion::InputException::what() const throw()
{
	return ("Check input parameters!");
}

char Conversion::get_char() const
{
	return (this->char_res);
}

long Conversion::get_int() const
{
	return (this->int_res);
}

float Conversion::get_float() const
{
	return (this->float_res);
}

double Conversion::get_double() const
{
	return (this->double_res);
}

int Conversion::get_prec() const
{
	return (this->prec);
}

bool Conversion::get_inf() const
{
	return (this->is_inf);
}

bool Conversion::get_pos() const
{
	return (this->is_pos);
}

std::string Conversion::get_str() const
{
	return (this->str);
}

std::ostream& operator<<(std::ostream& out, const Conversion& object)
{
	if (object.get_pos() && !isnan(object.get_double()) && (object.get_double() != INFINITY) && (object.get_double() != INFINITY * (-1)))
	{
		if (object.get_inf())
			out << "char: impossible";
		else if (ft_isprint(object.get_int()))
			out << "char: " << object.get_char();
		else if (!ft_isprint(object.get_int()))
			out << "char: Non displayable";
		if (!object.get_inf())
			out << "\nint: " << object.get_int();
		else
			out << "\nint: impossible";
	}
	else
		out << "char: impossible\nint: impossible";
	if (!object.get_inf())
	{
		out << "\nfloat:  " << object.get_float();
		if ((!object.get_prec() && !object.get_inf()) || object.get_float() == object.get_int())
			std::cout << ".0";
		out << "f";
		out << "\ndouble: " << std::fixed << std::setprecision(object.get_prec()) << object.get_double();
		if (!object.get_prec() && !object.get_inf())
			std::cout << ".0";
	}
	else
	{
		out << "\nfloat:  " << atof(object.get_str().c_str()) << "f" << std::scientific;
		out << "\ndouble: " << std::fixed << std::setprecision(object.get_prec()) << atof(object.get_str().c_str());
	}
	
	return (out);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}