#include "app.h"
#include <algorithm>
#include <array>

namespace vsite::oop::v8
{
	std::string not_number::what() const  {
		return "Not a number.";
	}


	std::string not_operator::what() const {
		return "Invalid operation.";
	}


	std::string divide_zero::what() const {
		return "Divide by zero.";
	}


	int input_num(std::istream& input) {
		int number;

		// istream has defined operator bool to check if error occurred
		if (input >> number) {
			return number;
		}

		throw not_number();
	}


	char input_op(std::istream& input) {
		char operator_;
		input >> operator_;
		
		if (
			operator_ != '+' &&
			operator_ != '-' &&
			operator_ != '*' &&
			operator_ != '/') {
			throw not_operator();
		}

		return operator_;
	}


	double calc(int a, char op, int b) {

		switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (!b) {
				throw divide_zero();
			}
			return static_cast<double>(a) / b;
		}
	}
}