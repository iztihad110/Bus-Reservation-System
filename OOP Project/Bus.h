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
    void showBusInfo(string s);
    void reserveSeat(int n,string s);
    void show_total_seats(string s);
    string get_bus_id();
    int is_id(string s);
    int get_available_seats();
    string getStartingPoint();
    string getDestination();

};


#endif // BUS_H

