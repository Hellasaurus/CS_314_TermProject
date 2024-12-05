#include "person.h"
using namespace std;

//***********************************Person class******************************************
//Default constructor
Person::Person(): id(0), name(""), a_address()
{}

//Parameterized constructor
Person::Person(int n_id, const string & n_name, const Address & n_address): id(n_id), name(n_name), a_address(n_address)
{}

//Getter function for 'id'
int Person::get_id() const
{
    return id;
}

//Setter function for 'id'
void Person::set_id(int n_id)
{
    id = n_id;
}

//Setter function for 'name'
string Person::get_name() const
{
    return name;
}

//Getter function for 'name'
void Person::set_name(const string & n_name)
{
    name = n_name;
}

//Check if there is a match
bool Person::is_match(const string & match) const
{
    return name == match || to_string(id) == match;
}

//Display person's information
void Person::display() const
{
    cout << "\nPerson's name: " << name << endl;
    cout << "ID #: " << id << endl;
    cout << "Address is: " << a_address << endl;
}


//********************************Provider class*******************************************
//Default constructor
Provider::Provider()
{}

//Parameterized constructor
Provider::Provider(int n_id, string & n_name, Address & n_address): id(n_id), name(n_name), a_address(n_address)
{}

//Check if there is a match
bool Provider::is_match(const string & match)
{
    return Person::is_match(match);
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
Member::Member(int n_id, string & n_name, Address & n_address, bool n_status): id(n_id), name(n_name), a_address(n_address), status(n_status)
{}

//Check if there is a match
bool Member::is_match(const string & match)
{
    return Person::is_match(match);
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
bool Member::check_status() const
{
    return status;
}

//Update the status of membership
void Member::update_status(bool n_status)
{
    status = n_status;
}

