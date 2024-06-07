#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

typedef std::string string;

class BitcoinExchange
{
private:
  std::map<string, string> _data;

  string prevDate(const string &date);
  string nextDate(const string &date);
  string trim(const string &str);

  void validateNumber(const string &str);
  bool fileExists(const char *filename);
  bool fileEmpty(const char *filename);
  bool validDate(const string &str);
  bool isLeapYear(int year);
  bool onlydigits(const string &str, int (*isDigit)(int));

  int ft_stoi(const string &str);
  double ft_stod(const string &str);
  string ft_to_string(int value);

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &copy);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void MainFrame(const char *filename);
};
