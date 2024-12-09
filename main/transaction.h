#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "service.h"  // Include the Service class header

using namespace std;

class Transaction {
private:
    string serviceDate;  // Date of the service
    string receiveDate;  // Date the transaction was received
    string currDate;     // Current date of transaction processing
    string comment;      // Additional comments about the transaction
    int memberID;        // Member ID associated with the transaction
    int providerID;      // Provider ID associated with the transaction
    int serviceID;     // Service object associated with the transaction

public:
    // Constructor
    Transaction(const string& a_serviceDate, const string& a_receiveDate, const string& a_currDate,
                const string& a_comment, int a_memberID, int a_providerID, const int a_serviceID);



    // Getters for individual fields
    string getServiceDate() const;
    string getReceiveDate() const;
    int getMemberId() const;
  
};

#endif // TRANSACTION_H
