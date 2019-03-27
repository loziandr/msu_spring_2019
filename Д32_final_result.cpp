#include<iostream>
#include<sstream>
#include<exception>


class Calculator
{
public:
    int64_t calculation(const char* str)
    {

        std:: istringstream term(str);
        return addition(term, multiplication(term, number(term)));
    }
private:

    int64_t addition(std:: istringstream& term, int64_t left)
    {
        char add;
        term >> add;
        if(add != '+' && add != '-')
        {
            term.putback(add);
            return left;
        }
        int64_t right = multiplication(term, number(term));
        if(add == '+') return addition(term, left + right);
        return addition(term, left - right);
    }
    int64_t multiplication(std:: istringstream& term, int64_t left)
    {
        char mult;
        term >> mult;
        if(mult != '*' && mult != '/')
        {

            term.putback(mult);
            return left;
        }
        int64_t right = number(term);
        if(mult == '*') return multiplication(term, left * right);
        else if(right == 0) throw std:: invalid_argument("");
        else return multiplication(term, left / right);

    }
    int64_t number(std:: istringstream& term)
    {
        char num;
        int64_t sign = 1;
        term >> num;
        if(num == '-')
        {
            sign = -1;
            term >> num;
        }
        if(num < '0' || num > '9')
            throw std:: invalid_argument("");
        int64_t ans = num - '0';
        return ans * sign;
    }
};


int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		Calculator calc;
		try
		{
			std:: cout << calc.calculation(argv[1]) << std:: endl;
		}
		catch (std:: exception& err)
		{
			std:: cout << "error" << std:: endl;
			return 1;
		}
	}
	else
	{
		std:: cout << "error" << std:: endl;
		return 1;
	}
	return 0;
}

