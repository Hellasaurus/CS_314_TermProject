#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include "address.h"

using namespace std;


//Person class
class Person
{
    public:
        Person();
        Person(int n_id, const string& n_name, const Address& n_address);
        
        int getId() const;
        string getName() const;
        Address getAddress() const;
        void setName(const string& n_name);
        void setId(int n_id);
        void setAddress(const Address& n_address);
        bool isMatch() const;
        void display() const;

        int id;
        string name;
        Address address;
};

//Provider class, derived from Person
class Provider: public Person
{
    public:
        Provider();
        Provider(int n_id, const string& n_name, const Address& n_address);
        bool isMatch(const string& match) const;
        void display() const;
};

//Member class, derived from Person
class Member: public Person
{
    public:
        Member();
        Member(int n_id, const string& n_name, const Address& n_address, bool n_status);
        bool isMatch(const string& match) const;
        void display() const;
        bool checkStatus() const;
        void updateStatus(bool n_status);

        bool status;
};

#endif
