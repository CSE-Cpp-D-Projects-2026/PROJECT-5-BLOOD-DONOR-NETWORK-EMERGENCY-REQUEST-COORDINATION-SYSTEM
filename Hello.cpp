#include<iostream>
using namespace std;
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
    void daysBetween(Date d){


    }
    bool isBefore(Date d1){

    }
    Date operator==(){

    }
};
class Person{

};
class Donor{

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
    cout<<"==================================================="<<endl;

    cout<<"\n\nBLOOD DONATION MANAGEMENT SYSTEM\n\n"<<endl;

    cout<<"==================================================="<<endl;

    cout<<"\n1. Donor Management"<<endl;
    cout<<"\n2. Blood Request Management"<<endl;
    cout<<"\n3. Donor Compatibility & Matching"<<endl;
    cout<<"\n4. Donation Management"<<endl;
    cout<<"\n5. Inventory Management"<<endl;
    cout<<"\n6. Reports"<<endl;
    cout<<"\n7. Save Data"<<endl;
    cout<<"\n8. Exit"<<endl;

    Cout<<"Enter choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"Donor Management"<<endl;
            break;
        case 2:
            cout<<"Blood Request Management"<<endl;
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
            cout<<"Reports"<<endl;
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
}