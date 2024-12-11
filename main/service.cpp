#include "service.h"

using namespace std;

Service::Service(int a_id, const string &a_serviceName, const string &a_description, double a_fee) {
    id = a_id;
    serviceName = a_serviceName;
    description = a_description;
    fee = a_fee;
}

void Service::display() const {
    streamsize temp = cout.width();
    cout << "id: " << setw(6) << setfill('0') << id
         << setw(temp) << setfill(' ')
         << " Service Name: " << serviceName
         << " Service Description: " << description
         << " Service fee: $" << put_money(fee, true)
         << '\n';
}

bool Service::operator==(int other) const { return this->id == other; }
