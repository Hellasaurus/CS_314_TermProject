#ifndef ADDRESS_H
#define ADDRESS_H


#include <string>

using namespace std;
class Address{
public:
    Address();
    Address(string, string, string, string, string);
    bool Update(string, string, string, string, string);
    void Display();
    
    string addr_line_1;
    string addr_line_2;
    string city;
    string state;
    string zip;
};

#endif
