#pragma once
#include <iostream>

namespace vsite::oop::v8 
{

	class calculation_error{
	public:
		virtual ~calculation_error() = default;
		virtual std::string what() const = 0;
	};


	class not_number : public calculation_error {
	public:
		std::string what() const override;
	};


	class not_operator : public calculation_error {
	public:
		std::string what() const override;
	};


	class divide_zero : public calculation_error {
	public:
		std::string what() const override;
	};


	int input_num(std::istream& input);

	char input_op(std::istream& input);

	double calc(int a, char op, int b);
}