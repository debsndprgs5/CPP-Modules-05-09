#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <exception>

class RPN {
    public:
        RPN(void);
        RPN(const RPN &to_copy);
        RPN &operator=(const RPN &to_copy);
        ~RPN(void);

        static bool is_valid_chars(const std::string& expr);
        static long long calc(const std::string& expr);

        class No_Result_Exception : public std::exception {
            public:
                virtual const char* what() const throw();  
        };

        class Division_By_Zero_Exception : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};

#endif