#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>
using namespace std;
using namespace std::chrono;

void cin_hour(int &x){
    cout << "通知する時を入力してください：";
    cin >> x;
    while(x<0||x>23)
    {
        cout << "エラー：時は0~23で入力してください\n";
        cout << "通知する時を入力してください：";
        cin >> x;
    }
}

void cin_min(int &x){
    cout<<"通知する分を入力してください：";
    cin >> x;
    while(x<0||x>59){
        cout << "エラー：分は0~59で入力してください\n";
        cout<<"通知する分を入力してください：";
        cin >> x;
    }
}

int main(){
    int hour;
    int min;
    cin_hour(hour);
    cin_min(min);

    time_point p = system_clock::now();
    time_t t=system_clock::to_time_t(p);
    tm *lt = localtime(&t);
    if(hour==lt->tm_hour && min==lt->tm_min){
        cout << "一致する";
    }
    // cout <<"現在時刻："<<setfill('0')
    //      << setw(2) <<(*lt).tm_hour<< ":"
    //      << setw(2)<<(*lt).tm_min << ":"
    //      << setw(2) <<(*lt).tm_sec << "\n";
    return 0;
}