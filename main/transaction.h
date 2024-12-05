#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
private:
    string serviceDate;  // Date of the service
    string receiveDate;  // Date the transaction was received
    string currDate;     // Current date of transaction processing
    string comment;      // Additional comments about the transaction
    int memberID;        // Member ID associated with the transaction
    int providerID;      // Provider ID associated with the transaction
    int serviceID;       // Service ID associated with the transaction

public:
    // Constructor
    Transaction(const string& serviceDate, const string& receiveDate, const string& currDate,
                const string& comment, int memberID, int providerID, int serviceID);

    // Method to check memberID and return all fields if it matches
    string checkByMemberID(int id) const;

    // Method to check providerID and return all fields if it matches
    string checkByProviderID(int id) const;

    // Getters for individual fields (optional for external access)
    string getServiceDate() const;
    string getReceiveDate() const;
    string getCurrDate() const;
    string getComment() const;
    int getMemberID() const;
    int getProviderID() const;
    int getServiceID() const;
};

#endif // TRANSACTION_H