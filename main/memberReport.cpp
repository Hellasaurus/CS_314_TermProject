#include "memberReport.h"

memberReport::memberReport(): member(){
  services.clear();
}

memberReport::memberReport(Member &memberAdd): member(memberAdd){
  services.clear();
}
memberReport::~memberReport(){
  Clear();
}
void memberReport::Generate(){
  member.display();
  for (auto & service : services){
    cout << "Date of Service: " << service.getServiceDate() << endl;
    cout << "Provider ID: " << service.getProviderId() << endl;
    cout << "Service name: " << service.getServiceName() << endl;
  }
}
void memberReport::addService(Transaction& service){
  services.push_back(service);
}
void memberReport::Clear(){
  services.clear();
}
