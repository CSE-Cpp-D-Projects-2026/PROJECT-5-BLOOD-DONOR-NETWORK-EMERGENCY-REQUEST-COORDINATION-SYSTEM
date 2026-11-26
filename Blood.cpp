#include<iostream>
#include<vector>
using namespace std;
class Donor {
public:
    int id = 0, age = 0;
    string name, contact, location, group;
    bool available = true;

    void display() const {
        cout << id << " | " << name << " | " << age << " | " << contact << " | "
             << location << " | " << group << " | "
             << (available ? "Available" : "Unavailable") << "\n";
    }
    string toText() const {
        return to_string(id) + "|" + name + "|" + to_string(age) + "|" + contact + "|" +
               location + "|" + group + "|" + (available ? "1" : "0");
    }
    static Donor fromText(const string& line) {
        Donor d; string f; stringstream ss(line);
        getline(ss, f, '|'); d.id = stoi(f);
        getline(ss, d.name, '|');
        getline(ss, f, '|'); d.age = stoi(f);
        getline(ss, d.contact, '|');
        getline(ss, d.location, '|');
        getline(ss, d.group, '|');
        getline(ss, f, '|'); d.available = (f == "1");
        return d;
    }
};
void registerDonor(vector<Donor>& list) {                                      // TC01
    Donor d;
    cout << "ID: ";            cin >> d.id;
    cin.ignore(1000, '\n');
    cout << "Name: ";          getline(cin, d.name);
    cout << "Age: ";           cin >> d.age;
    cout << "Contact (10 digits): "; cin >> d.contact;
    cin.ignore(1000, '\n');
    cout << "Location: ";      getline(cin, d.location);
    cout << "Blood group (O-,O+,A-,A+,B-,B+,AB-,AB+): "; cin >> d.group;
    d.available = true;

    validateDonor(d, list);          // throws if anything is wrong
    list.push_back(d);
    saveText(list);                  // persist immediately
    cout << "Donor registered and saved.\n";
}