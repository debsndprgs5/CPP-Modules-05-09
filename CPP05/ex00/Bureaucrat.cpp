#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& n, int gr) : Name(n), grade(gr) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
};

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : Name(src.Name), grade(src.grade) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
    if ( this != &rhs )
        grade = rhs.get_grade();
    return *this;
}

std::string Bureaucrat::get_name() const {
	return Name;
}

int Bureaucrat::get_grade() const {
	return grade;
}

void Bureaucrat::promote_crat() {
	if (grade == 1)
		throw GradeTooHighException();
	else
		grade--;
}
void Bureaucrat::demote_crat() {
	if (grade == 150)
		throw GradeTooLowException();
	else
		grade++;
}

std::ostream& operator<<( std::ostream& o, const Bureaucrat& rhs ) {
    o << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade();
    return o;
}