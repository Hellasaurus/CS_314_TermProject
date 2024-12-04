#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

//Vivi Chen

class Person
{
    public:
        Person();
        virtual ~Person();
        int insert_person(int n_id, const string & n_name, const Address & n_address);
        virtual bool is_match(const string & match);
        virtual int display() const;

    protected:
        int id;
        string name;
        Address a_address;
};

class Provider: public Person
{
    public:
        Provider();
        int insert_provider(int n_id, string & n_name, Address & n_address);
        bool is_match(const string & match);
        int display() const;

    protected:
};

class Member: public Person
{
    public:
        Member();
        int insert_member(int n_id, string & n_name, Address & n_address, bool n_status);
        bool is_match(const string & match);
        int display() const;
        bool check_states();

    protected:
        bool status;
        
};

#endif
