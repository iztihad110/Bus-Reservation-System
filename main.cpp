#include<iostream>
#include<vector>
#include "Bus.h"

using namespace std;

extern vector<Bus> vec_Bus;

int main()
{

    int ch;
    while(1)
    {
        cout << "\t\t\t Bus Reserve System \n";
        cout << "\t\t\t 1.Install \n";
        cout << "\t\t\t 2.Reservation \n";
        cout << "\t\t\t 3.Show Bus Info \n";
        cout << "\t\t\t 4.Exit \n";
        cout << "\t\t\tEnter your choice --> ";
        cin >> ch;

        if(ch==1)
        {
            Bus b1;
            b1.install();
            vec_Bus.push_back(b1);
        }
        else if(ch==2)
        {
            cout << "\n\t\t\t Reservation Process" << endl;
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
                    vec_Bus[id].reserveSeat(n);
                    break;
                }
                cout<<"\n\n**********************************************************************************************************************\n\n";

            }
        }
        else if(ch==3)
        {
              if( vec_Bus.size() <= 0)
              {
                  cout << "No Bus Available." << endl;
              }
              else
              {
                  for(int i =0; i<vec_Bus.size(); i++)
                    {
                            vec_Bus[i].showBusInfo();
                    }


              }
        }
        else if (ch==4)
        {
            break;
        }
    }

    return 0;
}


