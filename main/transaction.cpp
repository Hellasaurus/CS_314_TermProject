#include "transaction.h"

// Constructor
Transaction::Transaction(const string& serviceDate, const string& receiveDate, const string& currDate,
                         const string& comment, int memberID, int providerID, const Service& service)
    : serviceDate(serviceDate), receiveDate(receiveDate), currDate(currDate), 
      comment(comment), memberID(memberID), providerID(providerID), service(service) {}


// Getter for Service ID
int Transaction::getServiceId() const {
    return service.id;
}

// Getter for Service Name
string Transaction::getServiceName() const {
    return service.serviceName;
}

// Getter for Service Description
string  Transaction::getServiceDescription() const {
    return service.description;
}

// Getter for Service Fee
double Transaction::getServiceFee() const {
    return service.fee;
}

