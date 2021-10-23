#include<bits/stdc++.h>
#include "Passenger.h"
using namespace std;
void Passenger::SetData(string username,string password,string name,string address,int age,long long Mobile){
    UserName=username;
    Name=name;
    Password=password;
    Address=address;
    Age=age;
    MobileNo=Mobile;
}
void Passenger::ShowPassengerInfo(){
    cout<<"\n\n**********************************************************************************************************************\n\n";
    cout<<"\n\n###################################---PASSENGER INFORMATION---#########################################################\n\n";
    cout<<"\t\t\t  Username: ";
    cout<<UserName<<endl;
    //cout<<Password<<endl;
    cout<<"\t\t\t  Name: ";
    cout<<Name<<endl;
    cout<<"\t\t\t  Address  : ";
    cout<<Address<<endl;
    cout<<"\t\t\t  Age: ";
    cout<<Age<<endl;
    cout<<"\t\t\t  Mobile Number: ";
    cout<<MobileNo<<endl;
    cout<<"\n\n**********************************************************************************************************************\n\n";
}
