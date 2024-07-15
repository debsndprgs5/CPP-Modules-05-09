#include <cstdlib>
#include <iostream>
#include "RPN.hpp"

# define PREFFIX "RPN: Error: "
# define ARGC_ERR "invalid number of arguments"
# define INVALID_EXPR_ERR "invalid expression"

static int errors(const std::string& error_msg)
{
    std::cerr << PREFFIX << error_msg << '\n';
    return EXIT_FAILURE;
}

int main(int argc, char **argv)
{
	if (argc != 2)
        return errors(ARGC_ERR);

	if (!RPN::is_valid_chars(argv[1]))
        return errors(INVALID_EXPR_ERR);

    try {
        std::cout << RPN::calc(argv[1]) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
    }
	return EXIT_SUCCESS;
}