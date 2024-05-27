#include "Form.hpp"

Form::Form(const std::string& n, int exgr, int sigr) : Name(n), exec_grade(exgr), sign_grade(sigr){
	if (exec_grade < 1 || sign_grade < 1) {
		throw GradeTooHighException();
	}
	if (exec_grade > 150 || sign_grade > 150) {
		throw GradeTooLowException();
	}
};

Form::Form(const Form& src) : Name(src.Name), exec_grade(src.exec_grade), sign_grade(src.sign_grade){
}

Form::~Form() {
}

Form& Form::operator=( const Form& rhs ) {
    if ( this != &rhs )
    {
        exec_grade = rhs.get_exec_grade();
        sign_grade = rhs.get_sign_grade();
    }
    return *this;
}

std::string Form::get_name() const {
	return Name;
}

int Form::get_exec_grade() const {
	return exec_grade;
}

int Form::get_sign_grade() const {
	return sign_grade;
}


void Form::beSigned(const Bureaucrat& brc) {
	if (brc.get_grade() <= sign_grade)
		sign = 1;
	else
		throw GradeTooLowException();
}


std::ostream& operator<<( std::ostream& o, const Form& rhs ) {
	o << "-------------------- Form Info --------------------" << std::endl;
	o << "|     Form Name : " << rhs.get_name() << std::endl
	  << "| Required grade to sign : " << rhs.get_sign_grade() << std::endl
	  << "| Required grade to exec : " << rhs.get_exec_grade() << std::endl
	  << "-------------------- Form Info --------------------" << std::endl;
    return o;
}