#include<bits/stdc++.h>
#include "User.h"
using namespace std;
class Passenger: public User{
    public:
        string Name,Address;
        int Age;
        long long MobileNo;
        void SetData(string username,string password,string name,string address,int age,long long Mobile);
        void ShowPassengerInfo();
};
