#include "app.h"
#include <format>
using namespace vsite::oop::v8;

int main()
{

	while (true) {
		try {
			int operand_a = input_num(std::cin);
			char operation = input_op(std::cin);
			int operand_b = input_num(std::cin);

			double result = calc(operand_a, operation, operand_b);

			std::format("{} {} {} = {}", operand_a, operation, operand_b, result);
		}
		catch (calculation_error& ex) {
			std::format("Calculation error ocurred -> {}", ex.what());
			break;
		}
	}
}
