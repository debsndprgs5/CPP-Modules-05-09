#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
using std::cout;


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