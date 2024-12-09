#ifndef ADDRESS_H
#define ADDRESS_H


#include <string>
#include <fstream>

using namespace std;
class Address{
public:
    Address();
    /// @brief initialize address
    /// @param  address line 1
    /// @param  line 2
    /// @param  city
    /// @param  state
    /// @param  zip
    Address(string, string, string, string, string);
    bool update(string, string, string, string, string);
    void display(ostream& outFile) const;
    void display() const;
    
    string addr_line_1;
    string addr_line_2;
    string city;
    string state;
    string zip;
};

#endif
