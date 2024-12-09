#ifndef PROVIDER_REPORT_H
#define PROVIDER_REPORT_H

#include <iostream>
#include <vector>
#include "person.h"
#include "transaction.h"
#include <fstream>

using namespace std;

class ProviderReport{
  private:
    Provider provider;
    vector<Transaction> services;
    int num_consultations;
    double total_fee;

   public:
    ProviderReport();
    ProviderReport(Provider&);
    ~ProviderReport();
    void Generate();
    void add_transaction(Transaction&);
    void Clear();
};

#endif
