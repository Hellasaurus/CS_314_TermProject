#include "person.h"
using namespace std;

//***********************************Person class******************************************
//Default constructor
Person::Person(): id(0), name(""), a_address()
{}

//Parameterized constructor
Person::Person(int n_id, const string& n_name, const Address& n_address): id(n_id), name(n_name), a_address(n_address)
{}

//Getter function for 'id'
int Person::getId() const
{
    return id;
}

//Setter function for 'id'
void Person::setId(int n_id)
{
    id = n_id;
}

//Getter function for 'name'
string Person::getName() const
{
    return name;
}

//Setter function for 'name'
void Person::setName(const string& n_name)
{
    name = n_name;
}

//Getter function for address
Address Person::getAddress() const
{
    return a_address;
}

//Setter function for address
void Person::setAddress(const Address& n_address)
{
    a_address = n_address;
}
//Check if there is a match
bool Person::isMatch(const string& match) const
{
    return name == match || to_string(id) == match;
}

//Display person's information
void Person::display() const
{
    cout << "\nPerson's name: " << name << endl;
    cout << "ID #: " << id << endl;
    cout << "Address is: " << endl;
    a_address.display();
}


//********************************Provider class*******************************************
//Default constructor
Provider::Provider()
{}

//Parameterized constructor
Provider::Provider(int n_id, string& n_name, Address& n_address): id(n_id), name(n_name), a_address(n_address)
{}

//Check if there is a match
bool Provider::isMatch(const string& match)
{
    return Person::isMatch(match);
}

//Display a provider's information
int Provider::display() const
{   
    cout << "*** Displaying Providers ***" << endl;
    int temp = Person::display();
    return temp;
}


//**********************************Member class*******************************************
//Default constructor
Member::Member(): status(true)
{}

//Parameterized constructor
Member::Member(int n_id, string& n_name, Address& n_address, bool n_status): id(n_id), name(n_name), a_address(n_address), status(n_status)
{}

//Check if there is a match
bool Member::isMatch(const string& match)
{
    return Person::isMatch(match);
}

//Display member's information
int Member::display() const
{   
    cout << "*** Displaying Members ***" << endl;
    int temp = Person::display();
    if (check_status() == true)
    {
        cout << "The status of this member is ACTIVE!" << endl;
    }
    else
    {
        cout << "The member status is SUSPENDED."
             << "\nBecause the member has not paid membership fees for at least a month."
             << endl;
    }
    return temp;
}

//Check the status of membership
bool Member::checkStatus() const
{
    return status;
}

//Update the status of membership
void Member::updateStatus(bool n_status)
{
    status = n_status;
}

