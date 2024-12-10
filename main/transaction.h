#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "service.h" // Include the Service class header
#include "manager.h"

using namespace std;

class Transaction
{
private:
    string serviceDate; // Date of the service
    string receiveDate; // Date the transaction was received
    string comment;     // Additional comments about the transaction
    int memberID;       // Member ID associated with the transaction
    int providerID;     // Provider ID associated with the transaction
    int serviceID;      // Service object associated with the transaction
    const Manager *manager;

public:
    // Constructor
    Transaction(const string &serviceDate, const string &receiveDate,
                const string &comment, int memberID, int providerID, int service, const Manager &a_manager);

    // Getters for Service data fields
    int getServiceId() const;
    string getServiceName() const;
    string getServiceDescription() const;
    double getServiceFee() const;
    int getServiceCode() const;
    int getProviderId() const;

    // Getters for individual fields
    string getServiceDate() const;
    string getReceiveDate() const;
    int getMemberId() const;
};

#endif // TRANSACTION_H
