#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target ) : Form("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src ) : Form(src), target(src.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs ) {
    ( void )rhs;
    return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if ( executor.get_grade() > this->get_exec_grade() )
        throw Form::GradeTooLowException();
    else {
        static int  i;
        if ( i % 2 == 0 )
            std::cout << "* Very loud drilling noise *" << target << " has been robotomized ! Let's watch tiktok for a few hours !" << std::endl;
        else
            std::cout << "Robotomy failed! " << target << " has some neurons left, sadly... but is still alive" << std::endl;
        i++;
    }
}