#include<bits/stdc++.h>
#include "Passenger.h"
#include "Bus.h"
using namespace std;
vector<Passenger>users;
extern vector<Bus> vec_Bus;
Passenger temp;
string System_Code="Crack_of_dawn";
void Show_Available_Buses(){
    cout<<"\t\t\t  Available Buses"<<endl;
    for(int i=0;i<vec_Bus.size();i++){
        if(vec_Bus[i].get_available_seats()>0){
            cout<<"\t\t\t  Bus No.: "<<vec_Bus[i].get_bus_id()<<endl;
            cout<<"\t\t\t  Starting Point: "<<vec_Bus[i].getStartingPoint()<<endl;
            cout<<"\t\t\t  Destination: "<<vec_Bus[i].getDestination()<<endl;
        }
    }
    cout<<endl;
}
void Show_All_Buses(){
    cout<<"\t\t\t  All Buses"<<endl;
    for(int i=0;i<vec_Bus.size();i++){
        cout<<"\t\t\t  Bus No.: "<<vec_Bus[i].get_bus_id()<<endl;
        cout<<"\t\t\t  Starting Point: "<<vec_Bus[i].getStartingPoint()<<endl;
        cout<<"\t\t\t  Destination: "<<vec_Bus[i].getDestination()<<endl;
    }
    cout<<endl;
}
bool Login(){
    string Username,Password;
    cout<<"Enter Username:"<<" ";
    cin>>Username;
    cout<<"Enter Password:"<<" ";
    cin>>Password;
    for(int i=0;i<users.size();i++){
        Passenger p=users[i];
        if(p.UserName==Username && p.Password==Password){
            temp=p;
            return 1;
        }
    }
    return 0;
}
void Register(){
    string Username,Password,Name,Address;
    int Age,MobileNo;
    cout<<"Enter Username:"<<" ";
    cin>>Username;
    for(int i=0;i<users.size();i++){
        if(users[i].UserName==Username){
            cout<<"This Username has already been taken"<<endl;
            return;
        }
    }
    cout<<"Enter Password:"<<" ";
    cin>>Password;
    cout<<"Enter Name:"<<" ";
    getchar();
    getline(cin,Name);
    getchar();
    cout<<"Enter Address:"<<" ";
    getchar();
    getline(cin,Address);
    getchar();
    cout<<"Enter Age:"<<" ";
    cin>>Age;
    cout<<"Enter Mobile Number:"<<" ";
    cin>>MobileNo;
    cout<<"Your registration has been successful"<<" ";
    Passenger p;
    p.SetData(Username,Password,Name,Address,Age,MobileNo);
    users.push_back(p);
}
int main(){
    while(1){
        int t;
        cout<<"\n\n###################################---BUS RESERVATION SYSTEM---#########################################################\n\n";
        cout<<"\t\t\t  Press 1 to Login"<<endl;
        cout<<"\t\t\t  Press 2 to Register"<<endl;
        cout<<"\t\t\t  Press 3 to Add Bus"<<endl;
        cout<<"\t\t\t  Press 4 to Exit"<<endl;
        cout<<"\t\t\t  Enter Choice:"<<" ";
        cin>>t;
        if(t==1){
            if(Login()){
                cout<<"\t\t\t  Login Successful"<<endl;
                int ch;
                while(1)
                {
                    //cout << "\t\t\t  Bus Reserve System \n";
                    cout << "\t\t\t  Press 1 to reserve seat \n";
                    cout << "\t\t\t  Press 2 to show Bus Information \n";
                    cout << "\t\t\t  Press 3 to show Passenger Information \n";
                    cout << "\t\t\t  Press 4 to Logout \n";
                    cout << "\t\t\t  Enter your choice --> ";
                    cin >> ch;
                     if(ch==1)
                     {
                         Show_Available_Buses();
                         cout << "\n\t\t\t  Reservation Process" << endl;
                         string bno;
                         cout << "Enter bus no.: ";
                         cin >> bno;
                         for(int i =0; i<vec_Bus.size(); i++)
                         {
                             cout<<"\n\n**********************************************************************************************************************\n\n";
                             int id;
                             id = vec_Bus[i].is_id(bno);
                             if(id == -1){
                                 cout << "No match found.\n";
                                 break;
                             }
                            else{
                                cout << "Enter the number of seats you need to book: ";
                                int n;
                                cin >> n;
                                vec_Bus[id].reserveSeat(n,temp.UserName);
                                break;
                            }
                           cout<<"\n\n**********************************************************************************************************************\n\n";

                       }
                   }
                   else if(ch==2)
                   {
                       if( vec_Bus.size() <= 0)
                       {
                           cout << "No Bus Available." << endl;
                       }
                       else
                       {
                           Show_All_Buses();
                           cout<<"Enter Bus Number: ";
                           string BusNo;
                           cin>>BusNo;
                           int idx=-1;
                           for(int i=0;vec_Bus.size();i++){
                               if(vec_Bus[i].get_bus_id()==BusNo){
                                   idx=i;
                                   break;
                               }
                           }
                           if(idx==-1) cout<<"There is no such bus"<<endl;
                           else{
                               vec_Bus[idx].showBusInfo(temp.UserName);
                           }

                       }
                  }
                  else if (ch==3)
                  {
                     temp.ShowPassengerInfo();
                  }
                  else if(ch==4) break;
               }
            }
            else{
                cout<<"\t\t\t  Your Username and Passwords don't match"<<endl;
            }
        }
        if(t==2){
            Register();
        }
        if(t==3){
            string system_code;
            cout<<"Enter System Code: ";
            cin>>system_code;
            if(system_code==System_Code){
                cout<<"\t\t\t  Access Granted"<<endl;
                Bus b1;
                b1.install();
                vec_Bus.push_back(b1);
            }
            else{
                cout<<"\t\t\t  Access Denied. You have entered the wrong code."<<endl;
            }
        }
        if(t==4) break;

    }
}
