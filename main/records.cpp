// records.cpp
// CS 314 Group 7 
// Fall 2024

#include "records.h"
#include <iostream>
#include <sstream>

#include <string>

using namespace std;

const int MAX_LINE = 1000;

int readServices(istream& source, vector<Service>& dest)
{
    string line;
    string token = "";
    istringstream linestream;
    int new_id;
    string new_name;


    for (int i = 0; getline(source, line); i++)
    {
        linestream.str(line);

        dest.push_back(Service());
        
        getline(linestream, token, ',');
        cout << token << "\n";
        dest[i].id = atoi(token.c_str());
        
        getline(linestream, token, ',');
        cout << token <<"\n";
        dest[i].name = token;

    }
    
    return 0;
}

void Service::display(ostream& stream , char delim)
{
    stream << id << delim << name;
}

User::User(string a_name, Address a_addr)
{
    name = a_name;
    address = a_addr;
}
