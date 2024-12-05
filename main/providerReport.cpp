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

void ProviderReport::Generate(){}
void ProviderReport::add_transaction(Transaction& service){}
void ProviderReport::Clear(){}
