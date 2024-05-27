#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat bureaucrat("Mr. Gurt", 1);

		cout << bureaucrat << std::endl;

		bureaucrat.promote_crat();

		cout << bureaucrat << std::endl;

		bureaucrat.demote_crat();

		cout << bureaucrat << std::endl;

	} 
	catch (Bureaucrat::GradeTooHighException &e)
	{
		cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat("Ms. Gurta", 150);

		cout << bureaucrat << std::endl;

		bureaucrat.demote_crat();

		cout << bureaucrat << std::endl;

		bureaucrat.promote_crat();

		cout << bureaucrat << std::endl;

	} 
	catch (Bureaucrat::GradeTooLowException &e) 
	{
		cout << e.what() << std::endl;
	}

	return 0;
}