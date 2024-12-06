// main.cpp
// CS 314 Group 7 
// Fall 2024

#include <iostream>
#include <fstream>
#include <vector>

#include "records.h"
#include "address.h"

int main(int argc, char ** argv) {

  ifstream servStream = ifstream();
  servStream.open("./users/services.csv");
  vector<Service> servDB = vector<Service>();

  readServices(servStream, servDB);

  for (int i = 0; i < servDB.size(); i++){
    servDB[i].display(); 
    cout << "\n";
  }

  return 0;
}
