#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
using std::cout;

class Form;

class Bureaucrat {
private:
	const std::string Name;
	int grade;
public:
	Bureaucrat(const std::string& n, int gr);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	
	Bureaucrat& operator=(const Bureaucrat& rhs);
	
	std::string get_name() const;
	int get_grade() const;
	void promote_crat();
	void demote_crat();
	void signForm(Form& form);
    void executeForm( const Form& form ) const;  

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade too high";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade too low";
		}
	};
};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif