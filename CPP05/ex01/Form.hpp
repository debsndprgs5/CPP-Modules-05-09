#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
using std::cout;

class Bureaucrat;

class Form {
private:
	const std::string Name;
	bool sign;
	int exec_grade;
	int sign_grade;
public:
	Form(const std::string& n, int exgr, int sigr);
	Form(const Form& src);
	~Form();
	
	Form& operator=(const Form& rhs);
	
	std::string get_name() const;
	int get_exec_grade() const;
	int get_sign_grade() const;
	void beSigned(const Bureaucrat& brc);

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

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif