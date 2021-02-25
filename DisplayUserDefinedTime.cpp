#include <iostream>
#include <iomanip>

using namespace std;

class SetTime{
    protected:
        int h, m, s, in_seconds;
    public:
        int correctTime(){
            if(s > 60){
                m++;
                s -= 60;
            }
            if(m > 60){
                h++;
                m -= 60;
            }
            if(h > 23) h -= 24;

            return h, m, s;
        }                   // corrects time to 24 hour format
        
};

class Time: public SetTime{
    public:
        //Time input from user
        void inputTime(){
            cout<<"Enter time: \n";
            cout<<"Hours? ";
            cin>>h;
            cout<<"Minutes? ";
            cin>>m;
            cout<<"Seconds? ";
            cin>>s;
            in_seconds = h*3600+m*60+s;
        }               

        void showTime(){

            cout<<"The time is = "<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s<<endl;

        }

        // Shows total seconds, before corrected time
        
        void showInSeconds(){
            cout<<"Time in total seconds: "<<in_seconds;
        }
};

int main(){
    int h, m, s;
    Time t;
    t.inputTime();
    t.correctTime();
    t.showTime();
    t.showInSeconds(); 

    return 0;
}
