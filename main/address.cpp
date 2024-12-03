#include  "address.h"
#include <iostream>
Address::Address(){}
Address::Address(string newLine1, string newLine2, string newCity, string newState, string newZip){
  addr_line_1 = newLine1;
  addr_line_2 = newLine2;
  city = newCity;
  state = newState;
  zip = newZip;
}
Address::~Address(){}
bool Address::Update(string newLine1, string newLine2, string newCity, string newState, string newZip){
  addr_line_1 = newLine1;
  addr_line_2 = newLine2;
  city = newCity;
  state = newState;
  zip = newZip;

  return true;
}
void Address::Display(){
 cout << "Address Line 1: " << addr_line_1 << endl;
 cout << "Address Line 2: " << addr_line_2 << endl;
 cout << "City: " << city << endl;
 cout << "State: " << state << endl;
 cout << "Zip: " << zip << endl;
}
