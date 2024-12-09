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
void memberReport::Generate() {
  std::ofstream outFile("member_report.txt");

  if (!outFile) {
    std::cerr << "Error: Could not open file for writing!" << std::endl;
    return;
  }

  member.display(outFile); 

  for (auto &service : services) {
    outFile << "Date of Service: " << service.getServiceDate() << std::endl;
    outFile << "Provider ID: " << service.getProviderId() << std::endl;
    outFile << "Service name: " << service.getServiceName() << std::endl;
  }

  outFile.close();
}
void memberReport::addService(Transaction& service){
  services.push_back(service);
}
void memberReport::Clear(){
  services.clear();
}
