// main.cpp
// CS 314 Group 7 
// Fall 2024

#include <stdio.h>

#include "address.h"
#include "manager.h"
#include "person.h"
#include "providerReport.h"
#include "service.h"
#include "memberReport.h"

using namespace std;

const string memPath = "./users/users_10.csv";
const string proPath = "./users/provider_list.csv";
const string svcPath = "./users/service_list.csv";

int main(int argc, char ** argv) {

  cout.imbue(locale("en_US.UTF-8")); // formats money type

  Manager myMan = Manager(memPath, proPath, svcPath);

  myMan.loadMembers();
  myMan.loadProviders();
  myMan.loadServices();

  ofstream ofs("./output/ServiceDirectory.txt",ios_base::out);

  myMan.serviceDirectory(ofs);

  ofs.close();

  
  // Address newAddress("test", "test2", "portland", "oregon", "97214");
  // newAddress.display();
  // newAddress.update("test", "test2", "salem", "oregon", "97303");
  // newAddress.display();

  return 0;
}
