#include "Convert.hpp"

Convert::Convert()
	: data(0)
{

}
 
Convert::Convert( const Convert& other) {
	data = other.data;

	*this = other;
}
 
Convert::Convert(std::string newData) 
	: data(newData)
{

}

Convert::~Convert() {

}

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

void Convert::detectType() {
	int length = data.length();
	int is_dot = 0;
	for (int i = 0; i < length; i++) {
		if (!isdigit(data[i]) && data[i] != '.' && i != length && data[i] != 'f') {
			if (length == 1) {
				type = "char";
			}
			else
				type = "string";
			return ;
		}
		if (data[i] == '.') {
			if (!is_dot)
				is_dot++;
			else {
				type = "invalid";
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