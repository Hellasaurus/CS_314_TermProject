// main.cpp
// CS 314 Group 7 
// Fall 2024

#include <stdio.h>
#include "address.h"
#include "providerReport.h"

int main(int argc, char ** argv) {
  
  Address newAddress("test", "test2", "portland", "oregon", "97214");
  newAddress.display();
  newAddress.update("test", "test2", "salem", "oregon", "97303");
  newAddress.display();

  return 0;
}
