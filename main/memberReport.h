#ifndef MEMBER_REPORT_H
#define MEMBER_REPORT_H

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "person.h"
#include "transaction.h"

using namespace std;

class memberReport {
   public:
    memberReport();
    memberReport(Member &member);
    ~memberReport();
    void Generate();
    void addService(Transaction &service);
    void Clear();

   private:
    Member member;
    vector<Transaction> services;
};

#endif
