#ifndef PERSON_H
#define PERSON_H

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "address.h"

using namespace std;

// Person class
class Person {
   public:
    Person();
    Person(int n_id, const string &n_name, const Address &n_address);

    bool operator==(const Person &other) const;
    bool operator==(const int other) const;

    int getId() const;
    void setId(int n_id);
    void setAddress(const Address &n_address);
    void display(ostream &) const;
    void display() const;

    int id;
    string name;
    Address address;
};

// Provider class, derived from Person
class Provider : public Person {
   public:
    Provider();
    Provider(int n_id, const string &n_name, const Address &n_address);
    bool isMatch(const string &match) const;
    void display(ostream &) const;
    void display() const;
};

// Member class, derived from Person
class Member : public Person {
   public:
    Member();
    Member(int n_id, const string &n_name, const Address &n_address, bool n_status);
    void display(ostream &) const;
    bool checkStatus() const;
    void updateStatus(bool n_status);
    void display() const;

    bool status;
};

#endif
