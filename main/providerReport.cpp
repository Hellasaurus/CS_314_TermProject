#include "providerReport.h"

ProviderReport::ProviderReport() : provider(), num_consultations(0), total_fee(0.0)
{
  services.clear();
}
ProviderReport::ProviderReport(Provider &providerToAdd) : provider(providerToAdd), num_consultations(0), total_fee(0.0)
{
  services.clear();
}

ProviderReport::~ProviderReport()
{
  clear();
}
void ProviderReport::generate()
{
  std::time_t now = std::time(nullptr);
  std::tm *localTime = std::localtime(&now);

  std::ostringstream filename;
  filename << "../output/provider_report_" << provider.name << "_"
           << std::put_time(localTime, "%Y%m%d_%H%M%S") << ".txt";

  std::ofstream outFile(filename.str());
  if (!outFile)
  {
    std::cerr << "Error: Could not open file for writing!" << std::endl;
    return;
  }

  provider.display(outFile);

  outFile << "SERVICES: " << std::endl;
  for (auto &service : services)
  {
    outFile << "Service Date: " << service.getServiceDate() << std::endl;
    outFile << "Receive Date: " << service.getReceiveDate() << std::endl;
    outFile << "Member ID: " << service.getMemberId() << std::endl;
    outFile << "Service Code: " << service.getServiceId() << std::endl;
    outFile << "Fee: " << service.getServiceFee() << std::endl;
  }

  outFile << "Total Consultations: " << num_consultations << std::endl;
  outFile << "Total Fee: " << total_fee << std::endl;

  outFile.close();
}
void ProviderReport::add_transaction(Transaction &service)
{
  services.push_back(service);
  num_consultations++;
  total_fee += service.getServiceFee();
}
void ProviderReport::clear()
{
  services.clear();
  num_consultations = 0;
  total_fee = 0.0;
}
