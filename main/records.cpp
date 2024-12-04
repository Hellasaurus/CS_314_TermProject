// records.cpp
// CS 314 Group 7 
// Fall 2024

#include "records.h"
#include <iostream>
#include <sstream>

#include <string>

using namespace std;

int readServices(istream& source, vector<Service> dest)
{
    string line = string();
    string token = string();
    istringstream linestream;

    while (!(source.eofbit))
    {
        getline(source, line);
        linestream.str(line);
        
        getline(linestream, token, ',');
        
        getline(linestream, token, ',');
        
    }
    
    return 0;
}
