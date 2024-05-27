#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public Form
{
private:
    std::string target;

    RobotomyRequestForm();

public:
    RobotomyRequestForm( const std::string& target );
    RobotomyRequestForm( const RobotomyRequestForm& src );
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=( const RobotomyRequestForm& rhs );
    
    void execute( const Bureaucrat& executor ) const;
};

#endif