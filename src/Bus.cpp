#include "Bus.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<Bus> vec_Bus;

string Bus::get_bus_id()
{
    return busNumber;
}
void Bus :: install()
{
    system("cls");
    cout << "\t\t\tWELCOME TO INSTALLING THE BUSES." << endl;
    cout << "Enter bus number: ";
    cin >> busNumber;
    cout << "Enter total seat no: ";
    cin >> number_of_seats;
    cout << "Enter departure time (HH:MM)[24 HOUR]: ";
    cin >> departure_time;
    cout << "Enter arrival time (HH:MM)[24 HOUR]: ";
    cin >> arrival_time;
    cout << "Enter starting point:";
    cin >> startingPoint;
    cout << "Enter destination:";
    cin >> destination;

    for(int i=0; i<number_of_seats; i++)
    {
        seatStatus.push_back("Vacant");
    }
    reserved_seats = 0;
    available_seats = number_of_seats;
    cout << endl;
    cout << "Installation completed!!\n" ;
}

 void Bus::show_total_seats()
 {
    cout << "TOTAL SEATS IN THIS BUS IS: " << number_of_seats << "\n";

    for(int i=0; i< number_of_seats ; i++)
    {
        if(i%5==0)
                cout << endl;

        cout << "[" << i << "]" << "[" << seatStatus[i] << "]"  << " ";

    }
    cout << endl;
}


void Bus::showBusInfo()
{
    cout<<"\n\n**********************************************************************************************************************\n\n";
    cout << "Bus no.: " << busNumber << endl;
    cout << "Total seat no: " << number_of_seats << endl;
    cout << "Arrival time: " << arrival_time;
    cout << "\t\t\t Departure time: "  << departure_time << endl;
    cout << "Starting point:" <<  startingPoint;
    cout << "\t\t\t Destination:" << destination << endl;
    cout << "Reserved Seats: " << reserved_seats;
    cout << "\t\t\t Available Seats: " << available_seats << endl;
    show_total_seats();
    cout<<"\n\n**********************************************************************************************************************\n\n";

}
void Bus::reserveSeat(int n)    ///Reserve n seats in bus
{
    if (reserved_seats+n <= number_of_seats )    ///Checks if bus is already not filled completely
        {
            reserved_seats += n;   ///Update the value of reserved seats accordingly
            available_seats -= n;  ///Update the value of available seats accordingly

            for(int i=0; i<n; i++)
            {
                int seatno;
                cout << "Enter seat number: ";
                cin >> seatno;

                if(seatno >= number_of_seats)
                {
                    cout << "Seat does not Exist.\n";
                    i--;
                    continue;
                }

                if( seatStatus[seatno] == "Vacant" )
                {
                    string userName;
                    cout << "Enter user name: ";
                    cin >> userName;
                    seatStatus[seatno] = userName;
                }
                else
                {
                    cout << "Seat is reserved.Try Another." << endl;
                }
            }

        }

    else
    {
        cout << "All the seats are reserved." << endl;
    }

}


int  Bus::is_id(string s)
{
    ///Returns whether bus of given id exits or not
    for(int i=0; i<vec_Bus.size(); i++){
            if(vec_Bus[i].get_bus_id() == s){
                return i;       ///Returns index of bus if it exists
                break;
            }
    }
    return -1;  ///Returns -1 if bus does not exists
}
