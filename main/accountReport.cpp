#include <iostream>
#include <fstream>
#include <iomanip>
#include "accountReport.h"

using namespace std;

//Constructor
AccountReport::AccountReport(const vector<ProviderReport>& providerReports): reports(providerReports)
{}

//Generate the EFT report
void AccountReport::generateEFT(const string& filename) const
{
    ofstream outFile(filename);

    if (!outFile)
    {
        cerr << "Error: Unable to open " << filename << "!" << endl;
        return;
    }

    outFile << "Electronic Funds Transfer (EFT) Report\n";
    outFile << "***********************************\n\n";
    outFile << left << setw(25) << "Provider Name" << setw(15) << "Provider ID" 
            << "Amount Transferred" << endl;
    outFile << string(60, '-') << endl;

    for (const auto& report : providerReports)
    {
        outFile << left << setw(25) << report.provider.getName()
                << setw(15) << report.provider.getID()
                << fixed << setprecision(2) << report.total_fee << endl;
    }

    outFile.close();
    cout << "EFT Report generated: " << filename << endl;
}

//Generate the Accounts Payable (AP) report
void AccountReport::generateAP(const string& filename) const
{
    ofstream outFile(filename);

    if (!outFile)
    {
        cerr << "Error: Unable to open " << filename << "." << endl;
        return;
    }

    outFile << "Accounts Payable (AP) Report\n";
    outFile << "***********************************\n\n";
    outFile << left << setw(25) << "Provider Name" << setw(15) << "Provider ID" 
            << setw(15) << "Consultations" << "Total Fee" << endl;
    outFile << string(70, '-') << endl;

    int totalConsultations = 0;
    double overallFee = 0.0;

    for (const auto& report : reports)
    {
        outFile << left << setw(25) << report.provider.getName()
                << setw(15) << report.provider.getID()
                << setw(15) << report.num_consultations
                << fixed << setprecision(2) << report.total_fee << endl;

        totalConsultations += report.num_consultations;
        overallFee += report.total_fee;
    }

    outFile << string(70, '-') << endl;
    outFile << left << setw(40) << "Total" 
            << setw(15) << totalConsultations
            << fixed << setprecision(2) << overallFee << endl;

    outFile.close();
    cout << "AP Report generated: " << filename << endl;
}

