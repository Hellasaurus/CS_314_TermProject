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

const string memPath = "./users/users_10.csv";
const string proPath = "./users/provider_list.csv";
const string svcPath = "./users/service_list.csv";

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

int main(int argc, char** argv) {
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
    Manager myMan = Manager(memPath, proPath, svcPath);

    myMan.loadMembers();
    myMan.loadProviders();
    myMan.loadServices();

    ofstream ofs("./output/ServiceDirectory.txt", ios_base::out);

    myMan.serviceDirectory(ofs);

    ofs.close();

    // Address newAddress("test", "test2", "portland", "oregon", "97214");
    // newAddress.display();
    // newAddress.update("test", "test2", "salem", "oregon", "97303");
    // newAddress.display();

    return 0;
}

int parseopt(int argc, char** argv, int& verbose) {
    char arg[MAX_ARG_LEN];

    int mode = MODE_INVALID;

    {
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
    }
    return mode;
}
