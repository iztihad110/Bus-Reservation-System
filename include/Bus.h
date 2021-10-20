#ifndef BUS_H
#define BUS_H

#include<string>
#include<vector>
using namespace std;

class Bus
{
private:
    string busNumber;
    int  number_of_seats;
    string arrival_time;
    string departure_time;
    vector<string> seatStatus; /// 2D string
    string startingPoint;
    string destination;
    int reserved_seats;
    int available_seats;
public:

    void install();
    void showBusInfo();
    void reserveSeat(int n);
    void show_total_seats();
    string get_bus_id();
    int is_id(string s);

};


#endif // BUS_H
