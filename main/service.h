#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Service {
public:
    int id;
    string serviceName;
    string description;
    double fee;

    // Constructor
    Service(int a_id, const string& a_serviceName, const string& a_description, double a_fee);

    void display() const;

    // Method to get service details as a string
    string getServiceDetails() const {
        return "ID: " + to_string(id) + "\n" +
               "Name: " + serviceName + "\n" +
               "Description: " + description + "\n" +
               "Fee: $" + to_string(fee);
    }

    bool operator==(int other) const;

};
