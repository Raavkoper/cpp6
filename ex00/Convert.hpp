#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <string>
#include <sstream>
 
class Convert {
private: 
	std::string data;
	std::string type;

	char char_lit;
	int int_lit;
	float float_lit;
	double double_lit;
 
public: 
	Convert(); 
	Convert( const Convert &other); 
	Convert(std::string newData);
	~Convert(); 
	Convert& operator=( const Convert &other); 

	void setData(char *argv);
	void detectType();
	std::string getData();
	std::string getType();
}; 
 
#endif
