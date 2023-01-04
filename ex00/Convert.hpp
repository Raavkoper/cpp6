#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <string>
#include <sstream>
 
class Convert {
private: 
	std::string data;
	std::string type;

	std::string char_lit;
	std::string int_lit;
	std::string float_lit;
	std::string double_lit;
 
public: 
	Convert(); 
	Convert( const Convert &other); 
	Convert(std::string newData);
	~Convert(); 
	Convert& operator=( const Convert &other); 

	void setData(char *argv);
	void detectType();
	void fillTypes();
	std::string getData();
	std::string getType();
}; 
 
#endif
