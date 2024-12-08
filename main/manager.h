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
    void addMember(int ID, const string& name, bool memberStatus,
                   const string& addr_line_1, const string& addr_line_2,
                   const string& city, const string& state, const string& zip);

    // Add new provider
    void addProvider(int ID, const string& name,
                     const string& addr_line_1, const string& addr_line_2,
                     const string& city, const string& state, const string& zip);

    // Check member status
    bool checkMemberStatus(int memberID) const;

    // Write data back to text files
    void writeData() const;
};

#endif // MANAGER_H
