#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include "RPN.hpp"

static int ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

RPN::RPN(void) {};

RPN::RPN(const RPN &to_copy) {
    *this = to_copy;
}

RPN& RPN::operator=(const RPN &to_copy) {
	(void)to_copy;
    return *this;
}

RPN::~RPN(void) {};


bool RPN::is_valid_chars(const std::string& str)
{
    if (str.find_first_not_of("0123456789+-/* ") == std::string::npos)
	    return true;
	return false;
}

long long RPN::calc(const std::string& input)
{
    int left;
    int right;
    int result;
    std::stringstream postfix(input);
    std::stack<int> temp;
    std::string s;

    while (postfix >> s)
    {
        if (s == "+" || s == "-" || s == "/" || s == "*")
        {
            if (temp.size() < 2)
                throw No_Result_Exception();                
            right = temp.top();
            temp.pop();
            left = temp.top();
            temp.pop();
            switch (s.at(0))
            {
                case '+': result =  left + right ; break;
                case '-': result =  left - right ; break;
                case '/':
                    if (right != 0)
                        result =  left / right; 
                    else
                        throw Division_By_Zero_Exception();
                break;
                case '*': result =  left * right ; break;
            }
            temp.push(result);
        }
        else
            temp.push(ft_stoi(s));
    }
	return temp.top();
}


const char*	RPN::No_Result_Exception::what() const throw() {
	return "RPN error: Wrong format or unrecognised expressions";
}

const char*	RPN::Division_By_Zero_Exception::what() const throw() {
	return "RPN error: Division by zero may cause the timeline to collapse, try avoiding that";
}