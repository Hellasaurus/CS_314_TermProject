#include "transaction.h"

// Constructor
Transaction::Transaction(const string& a_serviceDate, const string& a_receiveDate, const string& a_currDate,
                         const string& a_comment, int a_memberID, int a_providerID, int a_serviceID)
    : serviceDate(a_serviceDate), receiveDate(ra_eceiveDate), currDate(a_currDate), 
      comment(a_comment), memberID(a_memberID), providerID(a_providerID), serviceID(a_serviceID) {}



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

