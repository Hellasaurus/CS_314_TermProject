#include "person.h"
using namespace std;

//***********************************Person class******************************************
//default constructor
Person::Person(): id(0); name(""), a_address()
{}

Person::Person(int n_id, const string & n_name, const Address & n_address): id(n_id), name(n_name), a_address(n_address)
{}

//destructor
Person::~Person()
{}

//insert a new person
int Person::insert_person(int n_id, const string & n_name, const Address & n_address)
{
    id = n_id;
    name = n_name;
    a_address = n_address;
    return 1;
}

//check if there is a match
bool Person::is_match(const string & match) const
{
    return name == match || to_string(id) == match;
}

//display person's information
int Person::display() const
{
    cout << "\nPerson's name: " << name << endl;
    cout << "ID #: " << id << endl;
    cout << "Address is: " << a_address << endl;

    return 0;
}


//********************************Provider class*******************************************
//default constructor
Provider::Provider()
{}

//insert a new provider
int Provider::insert_provider(int n_id, string & n_name, Address & n_address)
{
    int temp = Person::insert_person(n_id, n_name, n_address);
    return temp;
}

//check if there is a match
bool Provider::is_match(const string & match)
{
    return Person::is_match(match);
}

//display a provider's information
int Provider::display() const
{   
    cout << "*** Displaying Providers ***" << endl;
    int temp = Person::display();
    return temp;
}


//**********************************Member class*******************************************
//default constructor
Member::Member(): status(true)
{}

//insert a new member
int Member::insert_member(int n_id, string & n_name, Address & n_address, bool n_status)
{
    int temp = Person::insert_person(n_id, n_name, n_address);
    status = n_status;
    return temp;
}

//check if there is a match
bool Member::is_match(const string & match)
{
    return Person::is_match(match);
}

//display member's information
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

//check the status of membership
bool Member::check_status()
{
    return status;
}


