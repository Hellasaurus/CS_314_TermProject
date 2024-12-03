// main.cpp
// CS 314 Group 7 
// Fall 2024

#include <stdio.h>
#include "address.h"

int main(int argc, char ** argv) {
  
  Address newAddress("test", "test2", "portland", "oregon", "97214");
  newAddress.Display();
  newAddress.Update("test", "test2", "salem", "oregon", "97303");
  newAddress.Display();

  return 0;
}
