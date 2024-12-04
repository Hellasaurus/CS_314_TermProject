// records.h
// CS 314 Group 7 
// Fall 2024
// Definitions for the data types that constitute user, provider, similar records


#include <string.h>
#include <iostream>
#include <vector>

#include "address.h"

using namespace std;

// Address string lengths
const int ADDR_HOUSE_LEN = 25;
const int ADDR_CITY_LEN = 14;
const int ADDR_STATE_LEN = 2;
const int ADDR_ZIP_LEN = 5;

// generic user constants
const int USR_ID_MAX = 999999999; // restrain ID values to 9 digits
const int USR_NAME_LEN = 25;

class User
{
public:
    User(string a_name, Address a_addr);

    int id;
    string name;
    Address address;

    void display();

};

class Member : public User
{
public:
    Member(string a_name, Address a_addr, bool status)
    : User(a_name, a_addr) {}

    bool status;
};

class Provider : public User
{
public:
    Provider( string a_name, Address a_addr)
    : User(a_name, a_addr) {}
};

class Service
{
public:
    Service(int a_id, string a_name);

    int id;
    string name;
};

User::User(string a_name, Address a_addr)
{
    name = a_name;
    address = a_addr;
}

int readMembers(FILE fd, vector<Member>);
int readProviders(FILE fd, vector<Provider>);
int readServices(FILE fd, vector<Service>);