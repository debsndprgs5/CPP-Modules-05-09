#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form(src), target(src.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    (void)rhs;
    return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if ( executor.get_grade() > this->get_exec_grade() )
        throw Form::GradeTooLowException();
    else {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox, the ultimate glorious leader of supreme interplanetary hegemony. (Glory to CPP)" << std::endl;
    }
}