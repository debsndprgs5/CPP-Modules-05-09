#include "Converter.hpp"

ScalarConverter::ScalarConverter( void ) {
	this->_c = '\0';
	this->_n = 0;
	this->_f = 0.0f;
	this->_db = 0.0;
}

ScalarConverter::ScalarConverter( const ScalarConverter& src ) {
	*this = src;
}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& rhs ) {
	if ( this != &rhs ) {
		this->_n = rhs.get_int();
		this->_f = rhs.get_float();
		this->_c = rhs.get_char();
	}
	return *this;
}

char ScalarConverter::get_char(void) const {
	return this->_c;
}

void	ScalarConverter::set_char(char c) {
	this->_c = c;
}

int ScalarConverter::get_int(void) const {
	return this->_n;
}

void	ScalarConverter::set_int(int n) {
	this->_n = n;
}

float ScalarConverter::get_float(void) const {
	return this->_f;
}

void	ScalarConverter::set_float(float f) {
	this->_f = f;
}

double ScalarConverter::get_double(void) const {
	return this->_db;
}

void	ScalarConverter::set_double(double db) {
	this->_db = db;
}

std::string ScalarConverter::get_str(void) const {
	return this->_str;
}

void	ScalarConverter::set_str(std::string str) {
	this->_str = str;
	set_type();
	if ( get_type() == NONE ) {
        throw ScalarConverter::ConverterException();
    }
}

e_type ScalarConverter::get_type(void) const {
	return this->_type;
}

void	ScalarConverter::set_type(void) {
	if ( is_char() ) {
		this->_type = CHAR;
	} else if ( is_int() ) {
		this->_type = INT;
	} else if ( is_float() ) {
		this->_type = FLOAT;
	} else if ( is_double() ) {
		this->_type = DOUBLE;
	} else if ( is_literals() ) {
		this->_type = LITERALS;
	} else {
		this->_type = NONE;
	}
}

/* 
is a char if :
printable, only length = 1, is alphanumeric
*/

bool ScalarConverter::is_char(void) const {
	return (_str.length() == 1 && std::isalpha(_str[0]) && std::isprint(_str[0]));
}

/*
is an int if is a digit and that's kinda it
*/

bool ScalarConverter::is_int(void) const {
	int	j = 0;
	if ( _str[j] == '-' || _str[j] == '+')
		j++;
	for (int i(j); i < (int) _str.length(); i++) {
		if (!std::isdigit(_str[i]))
			return false;
	}
	return true;
}

/*
is a float if : 
last char is f, index[length - 2] and index[0] aren't a dot,
but it needs a SINGLE dot and that every character in the string is a
digit.
*/

bool ScalarConverter::is_float(void) const {
	if (_str[_str.length() - 1] != 'f' || _str.find('.') == std::string::npos
		|| _str.find('.') == 0 || _str.find('.') == _str.length() - 2)
		return false;
	int found = 0;
	int j = 0;
	if (_str[j] == '-' || _str[j] == '+')
		j++;
	for (int i(j); i < (int) _str.length() - 1; i++)
	{
		if (_str[i] == '.')
			found++;
		if ((!std::isdigit(_str[i]) && _str[i] != '.') || found > 1)
			return false;
	}
	return true;
}

/* 
is a double if :
doesnt start/end with a dot, (needs to be in the middle),
no more than one dot obviously
everything needs to be digits aswell
very similar to float but without 'f' termination
*/

bool ScalarConverter::is_double(void) const {
	if (_str.find('.') == std::string::npos || _str.find('.') == 0 
		|| _str.find('.') == _str.length() - 1)
		return false;
	int j = 0;
	int found = 0;
	if (_str[j] == '-' || _str[j] == '+')
		j++;
	for (int i(j); i < (int) _str.length(); i++) {
		if (_str[i] == '.')
			found++;
		if ((!std::isdigit(_str[i]) && _str[i] != '.' ) || found > 1)
			return false;
	}

	return true;
}

/*
Since we have to handle the following literals,
they are so if they're in the list :
+inf, +inff
-inf, -inff
nan, nanf
*/

bool ScalarConverter::is_literals(void) const {
	if ( ( _impossible ) || ( _str.compare( "nan" ) == 0 ) || ( _str.compare( "nanf" ) == 0 )
		|| ( _str.compare( "+inf" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) 
		|| ( _str.compare( "-inf" ) == 0 ) || ( _str.compare( "-inff" ) == 0 ))
			return true;
	return false;
}

/*
Attempts to convert the string into various types and catch any exception
happening during the conversion. Therefore it catch's potential type conversion
impossibility.
*/

bool ScalarConverter::is_impossible(void) {
	std::istringstream iss(_str);
	iss.imbue(std::locale::classic()); // Ensure consistent numeric locale

	try {
		if (_type == INT) {
			long long value;
			iss >> value;
			if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
                throw std::out_of_range("Integer out of range");
			}
			_n = static_cast<int>(value);
		}	
		else if (_type == FLOAT) {
			double value;
			iss >> value;
			if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
                throw std::overflow_error("Float overflow");
            }
            _f = static_cast<float>(value);
		}
		else if (_type == DOUBLE) {
			iss >> _db;
		}
	} catch (std::exception &e) {
		_impossible = true;
		return true;
	}
	_impossible = false;
	return false;
}

void	ScalarConverter::print_char(void) const {
	if (this->is_literals() || (_c < 32) || (_n >= 127)) {
		std::cout << "Impossible";
	}
	else if (!std::isprint(this->_n)) {
		std::cout << "Non displayable";
	} 
	else {
		std::cout << "'" << get_char() << "'";
	}
	std::cout << std::endl;
}

void	ScalarConverter::print_int(void) const {
	if (this->is_literals() || (!std::isprint(_c) && (_c >= 127))) {
		std::cout << "Impossible";
	}
	else {
		std::cout << get_int();
	}
	std::cout << std::endl;
}

void	ScalarConverter::print_float(void) const {
	if (_str.compare( "nan" ) == 0 || _str.compare("nanf") == 0) 
	{
		std::cout << "nanf";
	} 
	else if (_str.compare("+inff") == 0 || _str.compare("+inf") == 0) {
		std::cout << "+inff";
	}
	else if (_str.compare("-inff") == 0 || _str.compare("-inf") == 0) {
		std::cout << "-inff";
	}
	else if (_impossible) {
		std::cout << "Impossible";
	}
	else {
		if (_f - static_cast<int> (_f) == 0) {
			std::cout << _f << ".0f";
		} else {
			std::cout << get_float() << "f";
		}
	}
	std::cout << std::endl;
}

void	ScalarConverter::print_double(void) const {
	if (_str.compare("nan") == 0 || _str.compare("nanf") == 0) {
		std::cout << "nan";
	}
	else if (_str.compare("+inff") == 0 || _str.compare("+inf") == 0) {
		std::cout << "+inf";
	}
	else if (_str.compare("-inff") == 0 || _str.compare("-inf") == 0) {
		std::cout << "-inf";
	}
	else if (_impossible) {
		std::cout << "Impossible";
	}
	else {
		if ( _db - static_cast<int> (_db) == 0) {
			std::cout << _db << ".0";
		}
		else {
			std::cout << get_double() << "f";
		}
	}
	std::cout << std::endl;
}

void	ScalarConverter::convert( void ) {
	if (is_impossible())
		return;
	switch (_type) {
	case CHAR:
		_c = _str[0];
		_n = static_cast<int>(_c);
		_f = static_cast<float>(_c);
		_db = static_cast<double>(_c);
		break;
	case INT:
		{
			std::istringstream iss(_str);
			iss >> _n;
			_f = static_cast<float>(_n);
			_db = static_cast<double>(_n);
			_c = static_cast<char>(_n);
		}
		break;
	case FLOAT:
		{
			std::istringstream iss(_str);
			iss >> _f;
			_n = static_cast<int>(_f);
			_db = static_cast<double>(_f);
			_c = static_cast<char>(_f);
		}
		break;
	case DOUBLE:
		{
			std::istringstream iss(_str);
			iss >> _db;
			_n = static_cast<int>(_db);
			_f = static_cast<float>(_db);
			_c = static_cast<char>(_db);
		}
		break;
	default:
		break;
	}
}

std::ostream&	operator<<( std::ostream& out, const ScalarConverter& rhs ) {
	out << "char: "; rhs.print_char();
	out << "int: "; rhs.print_int();
	out << "float: "; rhs.print_float();
	out << "double: "; rhs.print_double();
	return out;
}
