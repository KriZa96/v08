#include "app.h"
#include <algorithm>
#include <array>

namespace vsite::oop::v8
{
	std::string not_number::what() const  {
		return "Operand is not a number.";
	}


	std::string not_operator::what() const {
		return "Element is not an operator.";
	}


	std::string divide_zero::what() const {
		return "Unable to divide with zero.";
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
		std::string operation;
		std::array<char, 4> supported_operators{ '+', '-', '*', '/' };

		if (
			!(input >> operation) ||
			!operation.size() ||
			operation.find_first_not_of(operation[0]) != std::string::npos ||  // If any char in input is different than others we know its not valid per test line 58
			std::find(supported_operators.begin(), supported_operators.end(), operation[0]) == supported_operators.end()  // if char is not in supported operators
		) {
			throw not_operator();
		}

		return operation[0];

	}


	double calc(int a, char op, int b) {

		double double_a = a;

		switch (op) {
		case '+':
			return double_a + b;
		case '-':
			return double_a - b;
		case '*':
			return double_a * b;
		case '/':
			if (!b) {
				throw divide_zero();
			}
			return double_a / b;
		}
	}
}