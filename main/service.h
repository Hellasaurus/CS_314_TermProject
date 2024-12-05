#include <string>
#include <iostream>

using namespace std;

class Service {
private:
    int id;
    string serviceName;
    string description;
    double fee;

public:
    // Constructor
    Service(int id, const string& serviceName, const string& description, double fee)
        : id(id), serviceName(serviceName), description(description), fee(fee) {}

    // Method to get service details as a string
    string getServiceDetails() const {
        return "ID: " + to_string(id) + "\n" +
               "Name: " + serviceName + "\n" +
               "Description: " + description + "\n" +
               "Fee: $" + to_string(fee);
    }

    // Method to display the name if ID matches
    void displayNameIfIdMatches(int inputId) const {
        if (id == inputId) {
            cout << "Service Name: " << serviceName << endl;
        }
    }

    // Getter for ID
    int getId() const {
        return id;
    }

    // Getter for Service Name
    string getServiceName() const {
        return serviceName;
    }

    // Getter for Description
    string getDescription() const {
        return description;
    }

    // Method to get the fee
    double getFee() const {
        return fee;
    }
};
