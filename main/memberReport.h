#ifndef MEMBER_REPORT_H
#define MEMBER_REPORT_H

#include "transaction.h"
#include "person.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

class memberReport{
  public:
    memberReport();
    memberReport(Member &member);
    ~memberReport();
    void Generate();
    void addService(Transaction& service);
    void Clear();
  private:
    Member member;
    vector<Transaction> services;
};

#endif
