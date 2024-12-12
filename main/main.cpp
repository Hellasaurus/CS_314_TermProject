// main.cpp
// CS 314 Group 7
// Fall 2024

#include <stdio.h>

#include "address.h"
#include "manager.h"
#include "memberReport.h"
#include "person.h"
#include "providerReport.h"
#include "service.h"

using namespace std;

const string memPath = "./users/users_10000.csv";
const string proPath = "./users/provider_list.csv";
const string svcPath = "./users/service_list.csv";
const string txPath = "./users/transactions_list.csv";
const string PRO_DIRECTORY_PATH = "./output/ServiceDirectory.txt";

const size_t MAX_ARG_LEN = 100;

const int MODE_INVALID = -1;
const int MODE_HELP = 0;
const int MODE_PRO = 1;
const int MODE_ACC = 2;
const int MODE_MGMT = 3;

const string helpstring =
    "ChocAnon Data Processing Software Module Demo!\n\
CS 314 Group #7\n\n\
This program can be run in the following demo modes:\n\
\t-h : help\n\
\t-p : provider mode\n\
\t-a : accounting mode\n\
\t-m : manager mode\n\
\t-v : verbose\n\n";

int parseopt(int argc, char** argv, int& verbose);
int managerTerminal(Manager& man, int& verbose);
int providerTerminal(Manager& man, int& verbose);
int accountingTerminal(Manager& man, int& verbose);

int main(int argc, char** argv) {
    cout.imbue(locale("en_US.UTF-8"));
    // bail if no argument
    if (argc <= 1) {
        cout << helpstring;
        return 0;
    }

    int verbose = 0;
    int mode = parseopt(argc, argv, verbose);

    if (mode < 1) {
        cout << helpstring;
        return 0;
    }

    // initialize manager
    Manager myMan = Manager(memPath, proPath, svcPath, txPath);

    myMan.loadMembers(verbose);
    myMan.loadProviders(verbose);
    myMan.loadServices(verbose);
    myMan.loadTX(verbose);

    switch (mode) {
        case MODE_PRO:
            mode = providerTerminal(myMan, verbose);
            break;

        default:
            break;
    }

    // Address newAddress("test", "test2", "portland", "oregon", "97214");
    // newAddress.display();
    // newAddress.update("test", "test2", "salem", "oregon", "97303");
    // newAddress.display();

    return 0;
}

// parses the command line, returning an int indicating the chosen mode.
int parseopt(int argc, char** argv, int& verbose) {
    char arg[MAX_ARG_LEN];

    int mode = MODE_INVALID;

    for (int i = 0; i < argc; i++) {
        strncpy(arg, argv[i], MAX_ARG_LEN);
        if (arg[0] == '-') {
            switch (arg[1]) {
                case 'h':  // help mode
                case 'H':
                    return MODE_HELP;
                    break;

                case 'v':  // verbosity
                case 'V':
                    cout << "Verbosity has been increased!\n";
                    verbose++;
                    break;

                case 'm':  // manager mode
                case 'M':
                    if (mode == MODE_INVALID) {
                        mode = MODE_MGMT;
                        cout << "Starting program in manager mode...\n";
                    }
                    break;
                case 'p':  // provider mode
                case 'P':
                    if (mode == MODE_INVALID) {
                        mode = MODE_PRO;
                        cout << "Starting Program in provider mode...\n";
                    }
                    break;

                case 'a':  // accounting mode
                case 'A':
                    if (mode == MODE_INVALID) {
                        mode = MODE_ACC;
                        cout << "Starting Program in Accounting mode...\n";
                    }
                    break;

                default:
                    mode = MODE_HELP;
                    break;
            }
        }
    }
    return mode;
}

int providerTerminal(Manager& man, int& verbose) {
    // get the provider's ID
    int currID = -1;
    Provider currProvider;
    // loop control
    bool done = false;
    char c;

    ofstream ofs;

    for (int i = 0; i < 10; i++) {
        cout << "Please enter your provider ID Number:\n";
        cin >> currID;
        cin.ignore(100, '\n');
        if (man.getProvider(currID)) {
            currProvider = *man.getProvider(currID);
            i += 100;
        } else {
            cout << "Invalid item Number! Try again.\n";
        }
    }
    if (currID < 0) {
        cout << "Access denied";
        exit(EXIT_FAILURE);
    }
    cout << "Access Granted!\n"
         << "Provider Info:\n";
    currProvider.display();

    for (int i = 0; i < 100; i++) {
        cout << "\n\
Choose an option:\n\
\tv : Validate member's status\n\
\tr : Request Provider Directory\n\
\tt : Create a transaction\n\
\tq : Exit\n\n";

        cin >> c;
        cin.ignore(1000, '\n');

        switch (c) {
            case 'v':
                // verify member number
                for (int i = 0; i < 10; i++) {
                    cout << "Please enter the Member number:\n";
                    cin >> currID;
                    cin.ignore(1000, '\n');
                    cin.clear();
                    const Member* mem = man.getMember(currID);
                    if (mem) {
                        cout << "This member's status is: ";
                        cout << (mem->checkStatus() ? "Active" : "Inactive");
                        cout << endl;
                        i += 100;

                    } else if (mem == nullptr) {
                        cout << "Unable to find member. Please double check the number" << endl;
                        i += 100;

                    } else {
                        cout << "Invalid item Number! Try again.\n";
                    }
                }
                break;

            case 'r':
                ofs.open(PRO_DIRECTORY_PATH, ios_base::out);
                cout << (verbose ? "Creating Service Directory...\n" : "");
                if (ofs.is_open()) {
                    man.serviceDirectory(ofs);
                    ofs.close();
                    cout << "Created the service directory at: " << PRO_DIRECTORY_PATH;
                } else {
                    cout << "Something went wrong! Unable to create the directory.\n";
                }
                break;

            case 't':
                cout << "Create a Transaction: \n";

                break;
            case 'q':
                cout << "Exiting program...\n";
                exit(EXIT_SUCCESS);
                break;

            default:
                cout << "invalid selection: " << c << endl;

                break;
        }
    }

    return 0;
}
