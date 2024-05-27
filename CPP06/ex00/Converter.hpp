#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <sstream>  
#include <cstdlib>  // For conversion functions
#include <stdexcept>
#include <limits>

enum e_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

class ScalarConverter {

private:
    char    _c;
    int     _n;
    float   _f;
    double  _db;

    bool    _impossible;

    std::string _str;
    e_type      _type;

public:
    ScalarConverter( void );
    ScalarConverter( const ScalarConverter& src );
    ~ScalarConverter( void );

    ScalarConverter& operator=( const ScalarConverter& rhs );

    char    get_char( void ) const;
    void    set_char( char c );

    int     get_int( void ) const;
    void    set_int( int n );

    float   get_float( void ) const;
    void    set_float( float f );

    double  get_double( void ) const;
    void    set_double( double d );

    void    convert( void );

    void    set_str( std::string str );
    std::string    get_str( void ) const;

    e_type  get_type( void ) const;
    void    set_type( void );

    bool    is_char( void ) const;
    bool    is_int( void ) const;
    bool    is_float( void ) const;
    bool    is_double( void ) const;

    bool    is_impossible( void );

    void    print_char( void ) const ;
    void    print_int( void ) const ;
    void    print_float( void ) const ;
    void    print_double( void ) const ;

    bool    is_literals( void ) const;

    class ConverterException : public std::exception {
        virtual const char* what() const throw() { return "Unknown type"; }
    };
};

std::ostream& operator<<( std::ostream& out, const ScalarConverter& rhs );

#endif // CONVERTER_HPP