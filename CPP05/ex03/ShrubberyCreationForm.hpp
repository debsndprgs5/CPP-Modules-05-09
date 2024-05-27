#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
private:
    std::string target;

    ShrubberyCreationForm();

public:
    ShrubberyCreationForm( const std::string& target );
    ShrubberyCreationForm( const ShrubberyCreationForm& src );
    ~ShrubberyCreationForm();

    ShrubberyCreationForm& operator=( const ShrubberyCreationForm& rhs );
    
    void execute( const Bureaucrat& executor ) const;
};

#endif