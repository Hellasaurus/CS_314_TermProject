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
  std::time_t now = std::time(nullptr);
  std::tm *localTime = std::localtime(&now);

  std::ostringstream filename;
  filename << "../output/member_report_" << member.name << "_"
    << std::put_time(localTime, "%Y%m%d_%H%M%S") << ".txt";

  std::ofstream outFile(filename.str());
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
