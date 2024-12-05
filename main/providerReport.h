#ifndef PROVIDER_REPORT_H
#define PROVIDER_REPORT_H

#include <iostream>
#include <vector>
using namespace std;

class ProviderReport{
  private:
    Provider provider;
    vector<Transaction> services;
    int num_consultations;
    double total_fee;

   public:
    ProviderReport();
    ~ProviderReport();
    void Generate();
};

#endif
