#include "Convert.hpp"

Convert::Convert()
	: data(0)
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
	return ("Convert: there are too many dots in that number");
}

void Convert::detectType() {
	int length = data.length();
	int is_dot = 0;
	for (int i = 0; i < length; i++) {
		if (!isdigit(data[i]) && data[i] != '.' && i != length && data[i] != 'f') {
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
			else {
				throw TooManyDotsException();
				return ;
			}
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
}

void Convert::print() {
	std::cout << "type: " << type << std::endl;
	std::cout << "Char: " << char_lit << std::endl;
	std::cout << "Int: " << int_lit << std::endl;
	std::cout << "Float: " << float_lit << std::endl;
	std::cout << "Double: " << double_lit << std::endl;
}