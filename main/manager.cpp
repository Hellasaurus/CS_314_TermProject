#include "manager.h"

using namespace std;

Manager::Manager(const string &memberFile, const string &providerFile, const string &serviceFile, const string &txFile) {
    memberFilePath = memberFile;
    providerFilePath = providerFile;
    serviceFilePath = serviceFile;
    txFilePath = txFile;
}

void Manager::loadMembers(bool verbose) {
    ifstream ifs(memberFilePath.c_str());
    stringstream linestream;
    string line;

    // contains a string indicating each data member.
    string memData[MEMBER_DATA_COLS];
    // data member index
    int i;

    char c;

    while (getline(ifs, line)) {
        linestream = stringstream(line);
        // reset count
        i = 0;
        // clear strings
        for (int j = 0; j < MEMBER_DATA_COLS; j++)
            memData[j] = "";

        // create a string for each column
        while (linestream.get(c)) {
            if (c == ',')
                i++;
            else
                memData[i] += c;
        }

        // initialize a member with collected data and add it to the vector
        members.push_back(
            Member(
                getMemberID(),
                memData[MEMBER_NAME_INDEX],
                Address(memData[MEMBER_ADDRESS_1_INDEX],
                        " ",
                        memData[MEMBER_CITY_INDEX],
                        memData[MEMBER_STATE_INDEX],
                        memData[MEMBER_ZIP_INDEX]),
                MEMBER_DEFAULT_STATUS));
        if (verbose) {
            cout << "Adding member: ";
            members.back().display();
        }
    }
    ifs.close();
}

void Manager::loadProviders(bool verbose) {
    ifstream ifs(providerFilePath.c_str());
    stringstream linestream;
    string line;

    // contains a string indicating each data member.
    string proData[PROVIDER_DATA_COLS];
    // data PROVIDER index
    int i;

    char c;

    while (getline(ifs, line)) {
        linestream = stringstream(line);
        // reset count
        i = 0;
        // clear strings
        for (int j = 0; j < PROVIDER_DATA_COLS; j++)
            proData[j] = "";

        // create a string for each column
        while (linestream.get(c)) {
            if (c == ',')
                i++;
            else if (c == '"') {
                ;
            }  // ugly way to ignore quotations.
            else
                proData[i] += c;
        }

        // initialize a PROVIDER with collected data and add it to the vector
        providers.push_back(
            Provider(
                getProviderID(),
                proData[PROVIDER_NAME_INDEX],
                Address(proData[PROVIDER_ADDRESS_1_INDEX],
                        " ",
                        proData[PROVIDER_CITY_INDEX],
                        proData[PROVIDER_STATE_INDEX],
                        proData[PROVIDER_ZIP_INDEX])));
        if (verbose) {
            cout << "Adding provider: ";
            providers.back().display();
        }
    }
    ifs.close();
}

void Manager::loadServices(bool verbose) {
    ifstream ifs(serviceFilePath.c_str());
    if (!ifs.is_open())
        cout << "Service file did not open successfully\n";
    stringstream linestream;
    string line;

    // contains a string indicating each data member.
    string srvData[SERVICE_DATA_COLS];
    // data SERVICE index
    int i;

    char c;

    while (getline(ifs, line)) {
        linestream = stringstream(line);
        // reset count
        i = 0;
        // clear strings
        for (int j = 0; j < SERVICE_DATA_COLS; j++)
            srvData[j] = "";

        // create a string for each column
        while (linestream.get(c)) {
            if (c == ',')
                i++;
            else if (c == '"') {
                ;
            }  // ugly way to ignore quotations.
            else
                srvData[i] += c;
        }

        // initialize a service with collected data and add it to the vector
        services.push_back(
            Service(
                stoi(srvData[SERVICE_ID_INDEX]),
                srvData[SERVICE_NAME_INDEX],
                srvData[SERVICE_DESC_INDEX],
                stod(srvData[SERVICE_COST_INDEX]) * 100.0));
        if (verbose) {
            cout << "Adding service: ";
            services.back().display();
        }
    }
    ifs.close();
}
void Manager::loadTX(bool verbose) {
    ifstream ifs(txFilePath.c_str());
    if (!ifs.is_open())
        cout << "Transaction file did not open successfully\n";
    stringstream linestream;
    string line;

    // contains a string indicating each data member.
    string txData[TX_DATA_COLS];
    // data transaction index
    int i;

    char c;

    while (getline(ifs, line)) {
        linestream = stringstream(line);
        // reset count
        i = 0;
        // clear strings
        for (int j = 0; j < TX_DATA_COLS; j++)
            txData[j] = "";

        // create a string for each column
        while (linestream.get(c)) {
            if (c == ',')
                i++;
            else if (c == '"') {
                ;
            }  // ugly way to ignore quotations.
            else
                txData[i] += c;
        }

        // initialize a service with collected data and add it to the vector

        char timeStr[100];

        chrono::system_clock::time_point now = chrono::system_clock::now();
        time_t now_c = chrono::system_clock::to_time_t(now);
        const tm *currtm = localtime(&now_c);

        strftime(timeStr, 99, "%d-%m-%Y %H:%M:%OS", currtm);

        transactions.push_back(
            Transaction(
                txData[TX_SVCTIME_INDEX],
                string(timeStr),
                txData[TX_COMMENT_INDEX],
                atoi(txData[TX_MEMID_INDEX].c_str()),
                atoi(txData[TX_PROID_INDEX].c_str()),
                atoi(txData[TX_SVCID_INDEX].c_str()),
                getTXID(),
                this));

        if (verbose) {
            cout << "Adding transaction: ";
            cout << transactions.back() << endl;
        }
    }
    ifs.close();
}

/// @brief search for a value by ID
/// @param id - The ID we are searching for
const Member *Manager::getMember(int id) const {
    for (int i = 0; i < members.size(); i++) {
        if (members[i] == id)
            return &members[i];
    }
    return nullptr;
}
/// @brief search for a value by ID
/// @param id - The ID we are searching for
const Provider *Manager::getProvider(int id) const {
    for (int i = 0; i < providers.size(); i++) {
        if (providers[i] == id)
            return &providers[i];
    }
    return nullptr;
}
/// @brief search for a value by ID
/// @param id - The ID we are searching for
const Service *Manager::getService(int id) const {
    for (int i = 0; i < services.size(); i++) {
        if (services[i] == id)
            return &services[i];
    }
    return nullptr;
}

const Transaction *Manager::getTX(int id) const {
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i] == id)
            return &transactions[i];
    }
    return nullptr;
}

vector<Transaction> &Manager::getTX(Member &query, vector<Transaction> &dest) {
    for (Transaction &i : transactions) {
        if (query == i.memberID) {
            dest.push_back(Transaction(i));
        }
    }
    return dest;
}

vector<Transaction> &Manager::getTX(Provider &query, vector<Transaction> &dest) {
    for (Transaction &i : transactions) {
        if (query == i.providerID) {
            dest.push_back(Transaction(i));
        }
    }
    return dest;
}

int Manager::createTransaction() {
    int memid;
    int proid;
    int serid;

    string serviceDate;
    string sysDate;

    string rawcom;
    string comment;

    transactions.push_back(Transaction(serviceDate, sysDate, comment, memid, proid, serid, getTXID(), this));
}

void Manager::serviceDirectory(ofstream &dest) {
    dest << "====== ChocAn Service Directory ======" << " ======\n\n";
    dest << "Service ID | Service Name \n";
    for (const Service &service : services) {
        dest << "    " << setw(6) << setfill('0') << service.id << " : " << setw(40) << setfill('.') << service.serviceName << endl;
    }
}

int Manager::checkMemberStatus(int memberID) const {
    const Member *memptr = getMember(memberID);
    if (memptr == nullptr)
        return MEMBER_STATUS_DNE;
    if (memptr->status)
        return MEMBER_STATUS_GOOD;
    return MEMBER_STATUS_INACTIVE;
}

int Manager::getMemberID() { return currMemberID++; }
int Manager::getProviderID() { return currProviderID++; }
int Manager::getServiceID() { return currServiceID++; }
int Manager::getTXID() { return currTXID++; }
