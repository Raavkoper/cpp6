#include "Convert.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Wrong input.. ./convert *string to convert*" << std::endl;
		return (1);
	}
	Convert convert(argv[1]);

	convert.detectType();
	convert.fillTypes();

	std::cout << "type: " << convert.getType() << std::endl;
	// std::cout << "Char: " << convert.toChar() << std::endl;
	// std::cout << "Int: " << convert.toInt() << std::endl;
	// std::cout << "Float: " << convert.toFloat() << std::endl;
	// std::cout << "Double: " << convert.toDouble() << std::endl;
}