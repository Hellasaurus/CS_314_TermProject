#include "transaction.h"

// Constructor
Transaction::Transaction(const string &serviceDate, const string &receiveDate,
                         const string &comment, int memberID, int providerID, int serviceID, int transactionID, const Manager *a_manager)
    : serviceDate(serviceDate), sysDate(receiveDate), comment(comment), memberID(memberID), providerID(providerID), serviceID(serviceID), transactionID(transactionID), manager(a_manager) {}

bool Transaction::operator==(int other) const {
    return this->transactionID == other;
}

ostream &operator<<(ostream &dest, Transaction &src) {
    dest << "Transaction id: " << src.transactionID
         << " Provider id: " << src.providerID
         << " Member id: " << src.memberID
         << " Service id: " << src.serviceID << endl
         << " Service date: " << src.serviceDate << endl
         << " Record created: " << src.sysDate;

    return dest;
}

// Getter for Service ID
int Transaction::getServiceId() const { return serviceID; }

// Getter for Service Name
string Transaction::getServiceName() const { return manager->getService(serviceID)->serviceName; }

// Getter for Service Description
string Transaction::getServiceDescription() const { return manager->getService(serviceID)->serviceName; }

// Getter for Service Fee
double Transaction::getServiceFee() const { return manager->getService(serviceID)->fee; }

int Transaction::getMemberId() const { return memberID; }

string Transaction::getServiceDate() const { return serviceDate; }

string Transaction::getReceiveDate() const { return sysDate; }

int Transaction::getProviderId() const { return providerID; }