#ifndef PROVIDER_REPORT_H
#define PROVIDER_REPORT_H

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "person.h"
#include "transaction.h"

using namespace std;

class ProviderReport {
   private:
    Provider provider;
    vector<Transaction> services;
    int num_consultations;
    double total_fee;

   public:
    ProviderReport();
    ProviderReport(Provider &);
    ~ProviderReport();
    void generate();
    void add_transaction(Transaction &);
    void clear();
};

#endif
