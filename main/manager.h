#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include "person.h"
#include "service.h"
#include "providerReport.h"

using namespace std;

class Manager {
private:
    vector<Member> members;        // List of all members
    vector<Provider> providers;    // List of all providers
    vector<Service> services;      // List of all services
    string memberFilePath;         // File path for member data
    string providerFilePath;       // File path for provider data
    string serviceFilePath;        // File path for service data

public:
    // Constructor to initialize file paths
    Manager(const string& memberFile, const string& providerFile, const string& serviceFile){
        memberFilePath = memberFile;
        providerFilePath = providerFile;
        serviceFilePath = serviceFile;
    }

    // Load data from text files
    void loadMembers();
    void loadProviders();
    void loadServices();

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
