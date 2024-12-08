#include "transaction.h"

// Constructor
Transaction::Transaction(const string& serviceDate, const string& receiveDate, const string& currDate,
                         const string& comment, int memberID, int providerID, const Service& service)
    : serviceDate(serviceDate), receiveDate(receiveDate), currDate(currDate), 
      comment(comment), memberID(memberID), providerID(providerID), service(service) {}

// Getter for Service ID
int Transaction::getServiceId() const {
    return service.getId();
}

// Getter for Service Name
string Transaction::getServiceName() const {
    return service.getServiceName();
}

// Getter for Service Description
string Transaction::getServiceDescription() const {
    return service.getDescription();
}

// Getter for Service Fee
double Transaction::getServiceFee() const {
    return service.getFee();
}

// Getters for individual fields
string Transaction::getServiceDate() const {
    return serviceDate;
}

string Transaction::getReceiveDate() const {
    return receiveDate;
}

string Transaction::getCurrDate() const {
    return currDate;
}

string Transaction::getComment() const {
    return comment;
}

int Transaction::getMemberID() const {
    return memberID;
}

int Transaction::getProviderID() const {
    return providerID;
}

const Service& Transaction::getService() const {
    return service;
}
