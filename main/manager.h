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
#include "person.h"
#include "service.h"
#include "providerReport.h"
#include "transaction.h"

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


class Manager {
private:
    vector<Transaction> transactions;
    string memberFilePath;         // File path for member data
    string providerFilePath;       // File path for provider data
    string serviceFilePath;        // File path for service data
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
    vector<Member> members;        // List of all members
    vector<Provider> providers;    // List of all providers
    vector<Service> services;      // List of all services
    vector<Transaction> transactions;

    // Constructor to initialize file paths
    Manager(const string& memberFile, const string& providerFile, const string& serviceFile){
        memberFilePath = memberFile;
        providerFilePath = providerFile;
        serviceFilePath = serviceFile;
    }

    // Load data from text files
    void loadMembers(bool verbose = false);
    void loadProviders(bool verbose = false);
    void loadServices(bool verbose = false);

    
    
    const Member* getMember(int id) const;
    const Provider* getProvider(int id) const;
    const Service* getService(int id)const ;

    // Get reports
    void serviceDirectory(ofstream & dest);

    // Check member status
    int checkMemberStatus(int memberID) const;


};

#endif // MANAGER_H
