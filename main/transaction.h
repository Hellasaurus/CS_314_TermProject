#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

#include "fwd.h"
#include "manager.h"
#include "service.h"  // Include the Service class header

using namespace std;

class Transaction {
   public:
    string serviceDate;  // Date of the service
    string sysDate;      // Date the transaction was received
    string comment;      // Additional comments about the transaction
    int memberID;        // Member ID associated with the transaction
    int providerID;      // Provider ID associated with the transaction
    int serviceID;       // Service ID associated with the transaction
    int transactionID;   // Transaction ID for this object
    const Manager *manager;

    // Constructor
    Transaction(const string &serviceDate, const string &receiveDate,
                const string &comment, int memberID, int providerID, int service, int transactionID, const Manager *a_manager);

    bool operator==(int other) const;
    friend ostream &operator<<(ostream &dest, Transaction &src);

    // Getters for Service data fields
    int getServiceId() const;
    string getServiceName() const;
    string getServiceDescription() const;
    double getServiceFee() const;
    int getProviderId() const;

    // Getters for individual fields
    string getServiceDate() const;
    string getReceiveDate() const;
    int getMemberId() const;
};

#endif  // TRANSACTION_H
