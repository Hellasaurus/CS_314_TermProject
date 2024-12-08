#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
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
const bool MEMBER_DEFAULT_STATUS = true;
const int PROVIDER_DATA_COLS = 5;
const int SERVICE_DATA_COLS = 5;


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

    // Constructor to initialize file paths
    Manager(const string& memberFile, const string& providerFile, const string& serviceFile){
        memberFilePath = memberFile;
        providerFilePath = providerFile;
        serviceFilePath = serviceFile;
    }

    // Load data from text files
    void loadMembers(bool verbose = false);
    void loadProviders();
    void loadServices();

    // get next sequential ID;

    // Get reports
    string getProviderReport();
    string getServiceReport();

    // Add new member
    void addMember(Member& to_add);

    // Add new provider
    void addProvider(Provider & to_add);

    // Check member status
    bool checkMemberStatus(int memberID) const;


};

#endif // MANAGER_H
