#ifndef MANAGER_H
#define MANAGER_H

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>

#include "fwd.h"
#include "transaction.h"
#include "person.h"
#include "service.h"
#include "providerReport.h"

using namespace std;

const int MEMBER_DATA_COLS = 5;
const int MEMBER_NAME_INDEX = 0;
const int MEMBER_ADDRESS_1_INDEX = 1;
const int MEMBER_CITY_INDEX = 2;
const int MEMBER_STATE_INDEX = 3;
const int MEMBER_ZIP_INDEX = 4;

const int MEMBER_STATUS_GOOD = 1;
const int MEMBER_STATUS_INACTIVE = 0;
const int MEMBER_STATUS_DNE = -1;

const bool MEMBER_DEFAULT_STATUS = true;

const int PROVIDER_DATA_COLS = 5;
const int PROVIDER_NAME_INDEX = 0;
const int PROVIDER_ADDRESS_1_INDEX = 1;
const int PROVIDER_CITY_INDEX = 2;
const int PROVIDER_STATE_INDEX = 3;
const int PROVIDER_ZIP_INDEX = 4;

const int SERVICE_DATA_COLS = 4;
const int SERVICE_ID_INDEX = 0;
const int SERVICE_NAME_INDEX = 1;
const int SERVICE_DESC_INDEX = 2;
const int SERVICE_COST_INDEX = 3;

const int TX_DATA_COLS = 6;
const int TX_ID_INDEX = 0;
const int TX_SVCID_INDEX = 1;   // index of the service ID in transaction CSV
const int TX_PROID_INDEX = 2;   // provider id index
const int TX_MEMID_INDEX = 3;   // member id index
const int TX_SVCTIME_INDEX = 4; // service time index
const int TX_COMMENT_INDEX = 5; // transaction comment index

class Manager
{
private:
    string memberFilePath;   // File path for member data
    string providerFilePath; // File path for provider data
    string serviceFilePath;  // File path for service data
    int currMemberID = 1;
    int currProviderID = 1;
    int currServiceID = 1;
    int currTXID = 1;

    /// @brief gets the next ID in sequence
    int getMemberID();
    /// @brief gets the next ID in sequence
    int getProviderID();
    /// @brief gets the next ID in sequence
    int getServiceID();
    /// @brief gets the next ID in sequence
    int getTXID();

public:
    vector<Member> members;           // List of all members
    vector<Provider> providers;       // List of all providers
    vector<Service> services;         // List of all services
    vector<Transaction> transactions; // List of all transactions

    // Constructor to initialize file paths
    Manager(const string &memberFile, const string &providerFile, const string &serviceFile);

    // Load data from text files
    void loadMembers(bool verbose = false);
    void loadProviders(bool verbose = false);
    void loadServices(bool verbose = false);

    const Member *getMember(int id) const;
    const Provider *getProvider(int id) const;
    const Service *getService(int id) const;

    const Transaction *getTX(int id) const;                                 // gets a transaction by id
    vector<Transaction> &getTX(Member &query, vector<Transaction> &dest);   // given a member, add associated transactions to dest
    vector<Transaction> &getTX(Provider &query, vector<Transaction> &dest); // given a provider, add associated transactions to dest

    // Get reports
    void serviceDirectory(ofstream &dest);

    // Check member status
    int checkMemberStatus(int memberID) const;
};

#endif // MANAGER_H
