#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include "address.h"

using namespace std;

//Vivi Chen

class Person
{
    public:
        Person();
        Person(int n_id, const string & n_name, const Address & n_address);
        
        int get_id() const;
        void set_id(int n_id);
        string get_name() const;
        void set_name(const string & n_name);

        bool is_match() const;
        void display() const;

        int id;
        string name;
        Address a_address;
};

class Provider: public Person
{
    public:
        Provider();
        Provider(int n_id, string & n_name, Address & n_address);
        bool is_match(const string & match);
        int display() const;
};

class Member: public Person
{
    public:
        Member();
        Member(int n_id, string & n_name, Address & n_address, bool n_status);
        bool is_match(const string & match);
        int display() const;
        bool check_status() const;
        void update_status(bool n_status);

        bool status;
};

#endif
