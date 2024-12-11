#ifndef ACCOUNT_REPORTS_H
#define ACCOUNT_REPORTS_H

#include <vector>
#include <string>
#include "providerReport.h"

using namespace std;

//AccountReport class to generate EFT report and AP report
class AccountReport
{
    public:
        AccountingReports(const vector<ProviderReport>& providerReports);
        void generateEFT(const string& filename) const;
        void generateAP(const string& filename) const;

    private:
        vector<ProviderReport> reports;
};

#endif

