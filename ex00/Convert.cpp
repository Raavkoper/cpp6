#include "Convert.hpp"

Convert::Convert()
	: data("unset")
{}
 
Convert::Convert( const Convert& other) {
	data = other.data;
}
 
Convert::Convert(std::string newData) 
	: data(newData)
{}

Convert::~Convert() {}

Convert& Convert::operator=( const Convert& other ) {
	data = other.data;

	return *this;
}

void Convert::setData(char *argv) {
	data = argv;
}

std::string Convert::getData() {
	return (data);
}

std::string Convert::getType() {
	return (type);
}

const char *Convert::TypeIsStringException::what() const throw() {
	return ("Convert: data type cant be a string dude");
}

const char *Convert::TooManyDotsException::what() const throw() {
	return ("Convert: get your dot game up this doesnt work");
}

const char *Convert::WrongFException::what() const throw() {
	return ("Convert: cant put f's there buddy");
}

int Convert::checkEdges() {
	if (data == "-inff" || data == "+inff" || data == "nanf") {
		type = "float";
		return (1);
	}
	if (data == "-inf" || data == "+inf" || data == "nan") {
		type = "double";
		return (1);
	}
	return (0);
}

int Convert::fChecks() {
	int length = data.length();
	int f_count = 0;
	if (length == 1 && data[0] == 'f') {
		type = "char";
		return (1);
	}
	if (data == ".-" || data == "-." || data == "-.f")
		throw TooManyDotsException();
	if (length == 2 && data[0] == '.' && data[1] == 'f')
		throw TooManyDotsException();
	if (length == 1 && data[0] == '.') {
		type = "char";
		return (1);
	}
	for (int i = 0; i < length; i++) {
		if (data[i] == 'f') {
			f_count++;
			if (i != length - 1)
				throw WrongFException();
		}
	}
	return (0);
}

int Convert::isDumb() {
	return (data == "-inf" || data == "+inf" || data == "nan" ||
		data == "-inff" || data == "+inff" || data == "nanf");
}

void Convert::detectType() {
	int length = data.length();
	int is_dot = 0;
	if (checkEdges())
		return ;
	if (fChecks())
		return ;
	for (int i = 0; i < length; i++) {
		if (!isdigit(data[i]) && data[i] != '.' && data[i] != '-' && i != length && data[i] != 'f') {
			if (length == 1) {
				type = "char";
			}
			else
				throw TypeIsStringException();
			return ;
		}
		if (data[i] == '.') {
			if (!is_dot)
				is_dot++;
			else
				throw TooManyDotsException();
		}
	}
	if (!is_dot)
		type = "int";
	else if (data[length - 1] == 'f')
		type = "float";
	else
		type = "double";
}

void Convert::fillTypes() {
	if (type == "char") {
		char_lit = data[0];
		int_lit = data[0];
		float_lit = static_cast<float>(data[0]);
		double_lit = static_cast<double>(data[0]);
	}
	if (type == "int") {
		try {
			if (std::stoll(data) > 2147483647 || std::stoll(data) < -2147483648)
				int_lit = 0;
			else
				int_lit = std::stoi(data);
		} catch (std::exception &e) {}
		char_lit = int_lit;
		float_lit = static_cast<float>(int_lit);
		double_lit = static_cast<double>(int_lit);
	}
	if (type == "float") {
		float_lit = std::stof(data);
		char_lit = static_cast<char>(float_lit);
		int_lit = static_cast<int>(float_lit);
		double_lit = static_cast<double>(float_lit);
	}
	if (type == "double") {
		double_lit = std::stod(data);
		char_lit = static_cast<char>(double_lit);
		int_lit = static_cast<int>(double_lit);
		float_lit = static_cast<double>(double_lit);
	}
}

void Convert::print() {
	int i = 0;
	std::cout << "Type: " << type << std::endl;
	std::cout << "Char: ";
	if (int_lit <= 127 && int_lit >= 0) {
		if (isprint(char_lit))
			std::cout << char_lit << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "Impossible" << std::endl;
	std::cout << "Int: ";
	try {
		if (type == "char") {
			std::cout << int_lit << std::endl;
			i++;
		}
		else if (std::stoll(data) > 2147483647 || std::stoll(data) < -2147483648) {
			std::cout << "Impossible" << std::endl;
			i++;
		}
	} catch(std::exception &e) {
		std::cout << "Impossible" << std::endl;
		i++;
	}
	if (isDumb() && !i) {
		std::cout << "Impossible" << std::endl;
		i++;
	}
	else if (!i)
		std::cout << int_lit << std::endl;
	std::cout << "Float: " << float_lit;
	if (type == "int" || type == "char" || (!modf(float_lit, &float_lit) && !isDumb()))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "Double: " << double_lit;
	if (type == "int" || type == "char" || (!modf(double_lit, &double_lit) && !isDumb()))
		std::cout << ".0";
	std::cout << std::endl;
}
