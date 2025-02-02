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

			std::cout << std::format("{} {} {} = {}", operand_a, operation, operand_b, result) << std::endl;
		}
		catch (calculation_error& ex) {
			std::cout << std::format("Calculation error occurred -> {}", ex.what()) << std::endl;
			break;
		}
	}
}
