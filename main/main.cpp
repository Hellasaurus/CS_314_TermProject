// main.cpp
// CS 314 Group 7 
// Fall 2024

#include <stdio.h>

#include "address.h"
#include "manager.h"
#include "person.h"
#include "providerReport.h"
#include "service.h"

const string memPath = "./users/users_10.csv";
const string proPath = " ";
const string svcPath = " ";

int main(int argc, char ** argv) {

  Manager myMan = Manager(memPath, proPath, svcPath);

  myMan.loadMembers(true);
  
  // Address newAddress("test", "test2", "portland", "oregon", "97214");
  // newAddress.display();
  // newAddress.update("test", "test2", "salem", "oregon", "97303");
  // newAddress.display();

  return 0;
}
