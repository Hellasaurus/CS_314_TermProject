#ifndef ADDRESS_H
#define ADDRESS_H

using namespace std;

#include <string>

class Address{
	public:
    Address();
    Address(string, string, string, string, string);
    ~Address();
    bool Update(string, string, string, string, string);
    void Display();

	private:
    string addr_line_1;
    string addr_line_2;
    string city;
    string state;
    string zip;
};

#endif
