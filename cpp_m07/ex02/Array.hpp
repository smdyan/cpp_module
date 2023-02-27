#ifndef ARRAY_HPP
#define ARRAY_HPP

template< class T >
class Array
{
    private:
        T*              data;
        unsigned int    m_n;

    public:
        Array(): m_n(0)
        {
            data = NULL;
        };

        Array( unsigned int n): m_n(n)
        {
            data = new T[m_n];
        };

        Array( const Array& obj)
        {
            *this = obj;
        };

        ~Array()
        {
            delete []data;
        };

        Array& operator=( const Array& obj )
        {
            if( this == &obj)
                return *this;
            m_n = obj.size();
            data = new T[m_n];
            unsigned int i = 0;
            while(i < m_n)
            {
                data[i] = obj.data[i];
                i++;
            }
            return *this;
        };

        T& operator[](int i)
        {
            if( i < 0 || i >= static_cast<int>( m_n ) )
			{
				throw( std::exception() );
			}
			else
				return( *(data + i) );
        };

        T*  getT( void ) const
        {
            return data;
        }

        unsigned int size(void) const
        {
            return m_n;
        };

};

template< typename T >
std::ostream & operator<<(std::ostream & o, Array< T > const & ref)
{
	for (unsigned int i = 0; i < ref.size(); i++)
		std::cout << "T[" << i << "] : " << (ref.getT())[i] << std::endl;
	return (o);
};

#endif
