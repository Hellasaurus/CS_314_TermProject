#include "manager.h"


using namespace std;

void Manager::loadMembers(bool verbose)
{
    ifstream ifs (memberFilePath.c_str());
    stringstream linestream;
    string line;

    // contains a string indicating each data member. 
    string memData[MEMBER_DATA_COLS];
    // data member index
    int i;

    char c;

    while (getline(ifs, line))
    {
        linestream = stringstream(line);
        //reset count
        i = 0;
        //clear strings
        for ( int j = 0; j < MEMBER_DATA_COLS; j++) memData[j] = "";

        //create a string for each column
        while (linestream.get(c)){

            if (c == ',') i++;
            else memData[i] += c;
        }

        //initialize a member with collected data and add it to the vector
        members.push_back(
            Member(
                getMemberID(),
                memData[0],
                Address(memData[MEMBER_NAME_INDEX],
                    " ",
                    memData[MEMBER_ADDRESS_1_INDEX],
                    memData[MEMBER_CITY_INDEX],
                    memData[4]),
                MEMBER_DEFAULT_STATUS)
            );
        if (verbose){
            cout << "Adding member: ";
            members.back().display();
        }

    }
    

}

int Manager::getMemberID() {return currMemberID++;}
int Manager::getProviderID() {return currProviderID++;}
int Manager::getServiceID() {return currServiceID++;}
int Manager::getTXID() {return currTXID++;}
