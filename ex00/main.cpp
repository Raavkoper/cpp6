#include "Convert.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Wrong input.. ./convert <string to convert>" << std::endl;
		return (1);
	}
	Convert convert(argv[1]);
	int set = 0;

	try {
		convert.detectType();
		set++;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	if (set) {
		convert.fillTypes();
		convert.print();
	}
}