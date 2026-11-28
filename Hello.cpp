#include<bits/stdc++.h>
using namespace std;
int id,age;
string contact; 
string name,bloodgroup,location;
int a=0,b=0,ab=0,o=0,an=0,bn=0,abn=0,on=0;
class Donor{
    public:
    int id,age;
    string name,bloodgroup,location,contact;
    Donor(int id,int age,string name,string bloodgroup,string contact,string location){
        this->id=id;
        this->age=age;
        this->name=name;
        this->bloodgroup=bloodgroup;
        this->contact=contact;
        this->location=location;
    }
    void print(){
        cout<<"Donor Id : "<<id;
        cout<<"Donor Age : "<<age;
        cout<<"Name : "<<name;
        cout<<"Bloodgroup : "<<bloodgroup;
        cout<<"Contact : "<<contact;
        cout<<"location : "<<location;
    }
       void saveToFile(const string& filename = "donors.txt") {
        ofstream file(filename, ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        file << id << "|" << age << "|" << name << "|" << bloodgroup << "|"
             << contact << "|" << location << "\n";
        file.close();
        cout<<"Donor saved successfully"<<endl;
    }

vector<Donor> loadDonors(const string& filename = "donors.txt") {
    vector<Donor> donors;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, age, name, bg, contact, location;
        getline(ss, id, '|');
        getline(ss, age, '|');
        getline(ss, name, '|');
        getline(ss, bg, '|');
        getline(ss, contact, '|');
        getline(ss, location, '|');
        donors.push_back(Donor(stoi(id), stoi(age), name, bg, contact, location));
    }
    return donors;
}
};
void validAge(int age){
    if(age>=18 && age<=60){
        cout<<"You are eligible to donote"; 
    }
    else{
        cout<<"You are not eligible ";
    }
    return;
}
void getdetails(){
    
    cout<<"Enter Donor Id : "<<endl;
    cin>>id;
    cout<<"Enter Donor age : "<<endl;
    cin>>age;
    validAge(age);

    cout<<"Enter Contact : "<<endl;
    cin>>contact;
    cin.ignore();
    cout<<"Enter name : "<<endl;
    getline(cin,name);

    cout<<"Enter Blood Group : "<<endl;
    getline(cin,bloodgroup);

    cout<<"Enter Location : "<<endl;
    getline(cin,location);


}
class Date{
    int day;
    int month;
    int year;
    Date(){
        day=1;
        month=1;
        year=2000;

    }
    Date(int day,int mon,int year){
        this->day=day;  
        this->month=mon;
        this->year=year;

    }
    bool isLeapYear(){
        if(year%400==0 || year%4==0 && year%100!=0){
            return true;
        }
        return false;

    }
    bool isValid(){
        if(day<1 || year<1 || month<1 || month>12){
            return false;
        }
        int days[]={31,28,31,30,31,30,31,31,30,31,30,31};

        if(isLeapYear()){
            days[1]=29;
        }
        return day <= days[month-1];
    }
    void displayDate(){
        if(!isValid()){
            cout<<"Invalid date";
            return;
        }
        else{
            if(day<10){
                cout<<"0"<<day<<"-";
            }
            if(month<10){
                cout<<"0"<<month<<"-"<<year<<endl;
            }
        }

    }
  
    
};
class SearchDonor{

    public:

    void searchById(int searchId) {

        ifstream file("donors.txt");

        if (!file) {
            cout << "Unable to open donors.txt";
            return;
        }

        string line;
        bool found = false;

        while (getline(file, line)) {

            stringstream ss(line);

            string id, age, name, bloodGroup;
            string contact, location, availability;

            getline(ss, id, '|');
            getline(ss, age, '|');
            getline(ss, name, '|');
            getline(ss, bloodGroup, '|');
            getline(ss, contact, '|');
            getline(ss, location, '|');
            getline(ss, availability, '|');

            if (stoi(id) == searchId) {

                found = true;

                cout << "\nDonor Found!\n";
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Blood Group: " << bloodGroup << endl;
                cout << "Contact: " << contact << endl;
                cout << "Location: " << location << endl;

                if (availability == "1") {
                    cout << "Availability: True" << endl;
                }
                else {
                    cout << "Availability: False" << endl;
                }

                break;
            }
        }

        if (!found) {
            cout << "Donor not found!" << endl;
        }

        file.close();
    }
};

   



class Requester{

};
class BloodRequest{

};
class DonationRecord{

};
class DonorResponse{

};
class BloodInventory{
    public:

    void displayInventory(){
        cout<<"A+ Group : "<<a<<endl;
        cout<<"B+ Group : "<<b<<endl;
        cout<<"A- Group : "<<an<<endl;
        cout<<"B- Group : "<<bn<<endl;
        cout<<"AB+ Group : "<<ab<<endl;
        cout<<"AB- Group : "<<abn<<endl;
        cout<<"O+ Group : "<<o<<endl;
        cout<<"O- Group : "<<on<<endl;
        return;

    }

};
class CompatibilityService{

};

class MatchingService{

};
class FileManager{

};
class ReportGenerator{

};
class BloodDonorSystem{


};

int main(){
    int choice;
    
    do{
        cout<<"==================================================="<<endl;
    cout<<"\nBLOOD DONATION MANAGEMENT SYSTEM\n"<<endl;
    cout<<"==================================================="<<endl;

    cout<<"\n1. Register Donor"<<endl;
    cout<<"\n2. Search Donor"<<endl;
    cout<<"\n3. Update Availability"<<endl;
    cout<<"\n4. Record Donation"<<endl;
    cout<<"\n5. Allocate Stock"<<endl;
    cout<<"\n6. Show Inventory"<<endl;
    cout<<"\n7. "<<endl;
    cout<<"\n8. Exit"<<endl;

    cout<<"Enter choice : ";
    cin>>choice;


    switch(choice){
        case 1: {
            getdetails();
            Donor d(id,age,name,bloodgroup,contact,location);
            d.saveToFile();
            cout<<"Donor register successfully"<<endl;
            break;
        }
        case 2:
            SearchDonor s;
            int id;
            cout<<"Enter Donor ID : ";
            cin>>id;
            s.searchById(id);
            break;
        case 3:
            cout<<"Donor Compatibility & Matching"<<endl;
            break;
        case 4:
            cout<<"Donation Management"<<endl;
            break;
        case 5:
            cout<<"Inventory Management"<<endl;
            break;
        case 6:
            BloodInventory b;
            b.displayInventory();
            bool y=true;
            int boolean;
            cout<<"If you want to add stock then enter 1 otherwise enter 0 : ";
            cin>>boolean;
            if(boolean){
                y=true;
            }
            else{
                y=false;
            }
            if(y){
                
            }

            break;
        case 7:
            cout<<"Save Data"<<endl;
            break;
        case 8:
            cout<<"Exit"<<endl;
            break;
        default:
            cout<<"Invalid choice"<<endl;
    }
}while(choice!=8);
}
