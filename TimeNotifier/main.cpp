#include "main.h"

void cin_hour(int &x){
    string input;

    while(true){
        cout << "通知する時を入力してください：";
        cin >> input;

        if(input.length()>2){
            cout << "2桁以内で入力してください\n";
            continue;
        }else if(input.empty() ||
                 input.find_first_not_of("0123456789") != string::npos){
            cout << "数字を入力してください\n";
            continue;
        }

        x = stoi(input);
        
        if(x<0 || x>23){
            cout << "エラー：分は0~23で入力してください\n";
            continue;
        }

        break;
    }
}

void cin_min(int &x){
    string input;

    while(true){
        cout<<"通知する分を入力してください：";
        cin >> input;

        if(input.length()>2){
            cout << "2桁以内で入力してください\n";
            continue;
        }else if(input.empty() ||
                 input.find_first_not_of("0123456789") != string::npos){
            cout << "数字を入力してください\n";
            continue;
        }

        x = stoi(input);
        
        if(x<0 || x>59){
            cout << "エラー：時は0~59で入力してください\n";
            continue;
        }

        break;
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
            system("powershell -ExecutionPolicy Bypass -File test.ps1");
    }else {
        while (!(hour==lt->tm_hour && min==lt->tm_min)){
            p = system_clock::now();
            t = system_clock::to_time_t(p);
            lt = localtime(&t);

            if(hour==lt->tm_hour && min==lt->tm_min){
                system("powershell -ExecutionPolicy Bypass -File test.ps1");
                break;
            }else{
                this_thread::sleep_for(seconds(1));
            }
        }
    }

    return 0;
}