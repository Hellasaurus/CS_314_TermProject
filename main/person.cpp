#include "person.h"
using namespace std;

//***********************************Person class******************************************
//Default constructor
Person::Person(): id(0), name(""), address()
{}

//Parameterized constructor and initialization list
Person::Person(int n_id, const string& n_name, const Address& n_address): id(n_id), name(n_name), address(n_address)
{
    setId(n_id);
}

bool Person::operator==(const Person &other) const
{
    if (this == &other) return true;
    if (this->id == other.id) return true;

    return false;
}

bool Person::operator==(const int other) const
{
    if (this->id == other) return true;
    return false;
}

//Getter function for 'id'
int Person::getId() const
{
    return id;
}

//Setter function for 'id'
void Person::setId(int n_id)
{
    if(n_id <= 999999999)
    {
        id = n_id;
    }
    else
    {
        throw invalid_argument("ID must be a 9-digit number.");
    }
}


//Setter function for address
void Person::setAddress(const Address& n_address)
{
    address = n_address;
}

//Display person's information
void Person::display(ostream& outFile) const
{
    outFile << "\nPerson's name: " << name << endl;
    outFile << "ID #: " << id << endl;
    outFile << "Address is: ";
    address.display(outFile);
}
void Person::display() const{
    cout << "\nPerson's name: " << name << endl;
    cout << "ID #: " << id << endl;
    cout << "Address is: ";
    address.display();
}


//********************************Provider class*******************************************
//Default constructor
Provider::Provider()
{}

//Parameterized constructor with initialization list
Provider::Provider(int n_id, const string& n_name, const Address& n_address): Person(n_id, n_name, n_address)
{}

//Display a provider's information
void Provider::display(ostream& outFile) const
{   
    outFile << "*** Displaying Provider ***" << endl;
    Person::display(outFile);
}
void Provider::display() const
{   
    cout << "*** Displaying Provider ***" << endl;
    Person::display();
}


//**********************************Member class*******************************************
//Default constructor
Member::Member(): status(true)
{}

//Parameterized constructor
Member::Member(int n_id, const string& n_name, const Address& n_address, bool n_status): Person(n_id, n_name, n_address), status(n_status)
{}

//Display member's information
void Member::display(ostream& outFile) const
{   
    outFile << "*** Displaying Member ***" << endl;
    Person::display(outFile);
    if (checkStatus() == true)
    {
        outFile << "The status of this member is ACTIVE!" << endl;
    }
    else
    {
        outFile << "The member status is SUSPENDED."
             << "\nBecause the member has not paid membership fees for at least a month."
             << endl;
    }
}

void Member::display() const
{   
    cout << "*** Displaying Member ***" << endl;
    Person::display();
    if (checkStatus() == true)
    {
        cout << "The status of this member is ACTIVE!" << endl;
    }
    else
    {
        cout << "The member status is SUSPENDED."
             << "\nBecause the member has not paid membership fees for at least a month."
             << endl;
    }
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

