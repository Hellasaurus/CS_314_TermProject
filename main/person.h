#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include "address.h"

using namespace std;


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
        Address a_address;
};

class Provider: public Person
{
    public:
        Provider();
        Provider(int n_id, string& n_name, Address& n_address);
        bool isMatch(const string& match);
        int display() const;
};

class Member: public Person
{
    public:
        Member();
        Member(int n_id, string& n_name, Address& n_address, bool n_status);
        bool isMatch(const string& match);
        int display() const;
        bool checkStatus() const;
        void updateStatus(bool n_status);

        bool status;
};

#endif
