#include "providerReport.h"

ProviderReport::ProviderReport(): provider(), num_consultations(0), total_fee(0.0){
  services.clear();
}
ProviderReport::ProviderReport(Provider& providerToAdd):provider(providerToAdd), num_consultations(0), total_fee(0.0){
  services.clear();
}

ProviderReport::~ProviderReport(){
  Clear();
}

void ProviderReport::Generate(){
  provider.display();
  cout << "SERIVCES: " << endl;
  for(auto & service : services){
    cout << "Service Date: " << service.getServiceDate() << endl;
    cout << "Receive Date: " << service.getReceiveDate() << endl;
    cout << "Member ID: " << service.getMemberId() << endl;
    cout << "Service Code: " << service.getServiceCode() << endl;
    cout << "Fee: " << service.getServiceFee() << endl;
  }
  cout << "Total Consultations: " << num_consultations << endl;
  cout << "Total Fee: " << total_fee << endl;
}
void ProviderReport::add_transaction(Transaction& service){
  services.push_back(service);
  num_consultations++;
  total_fee += service.getServiceFee();
}
void ProviderReport::Clear(){
  services.clear();
  num_consultations = 0;
  total_fee = 0.0;
}
