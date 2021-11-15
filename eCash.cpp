#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class eCash{

private:
    int Money;
    string ID;
    FILE *file;

public:
    void login(string account){
        ID = account;
        file = fopen(ID.c_str(), "r");
        if(file==NULL){
            cout << "eCash: 帳號不存在, 第一次使用!" << endl;
            Money = 0;
        }
        else{
            cout << "eCash: 帳號開啟完成!" << endl << endl;
            fscanf(file, "%d", &Money);
        }
    }

    void logout(){
        file = fopen(ID.c_str(), "w");
        fprintf(file, "%d", Money);
        fclose(file);
        cout << "eCash: 帳號登出, 已存檔!" << endl;
        cout << "謝謝，ByeBye!" <<endl;
    }

    void store(int m){
        if(m<=0){
            cout << "eCash: 請輸入大餘0的金額" << endl;
        }
        else{
            Money += m;
            cout << "eCash: 您存了" << m << "元" << endl;
        }
    }

    void pay(int m){
        if(m<=0){
            cout << "eCash: 請輸入大餘0的金額" << endl;
        }
        else if(m>Money){
            cout << "eCash: 您的錢不夠" << endl;
        }
        else{
            Money -= m;
            cout << "eCash: 您花了" << m << "元" << endl;
        }
    }

    void display(){
        cout << "eCash: 您尚有" << Money << "元" << endl;
    }
};

int main(){
    class eCash EC;
    string account;
    char key;
    int deposit,spend;

    cout << "=== 歡迎使用eCash ===" << endl;
    cout << "eCash: 請輸入您的帳號: ";
    cin >> account;
    EC.login(account);

    //operate
    while(1){
        cout << account << "您好，請選擇項目:" << endl;
        cout << "s: 儲值" << endl;
        cout << "p: 消費" << endl;
        cout << "d: 查詢餘額" << endl;
        cout << "q: 離開" << endl;
        cout << "> ";

        cin >> key;
        switch(key){
            case 'd':
                EC.display();
                break;

            case 's':
                cout << "請輸入儲存金額:" << endl;
                cin >> deposit;
                EC.store(deposit);
                break;

            case 'p':
                cout << "請輸入消費金額:" << endl;
                cin >> spend;
                EC.pay(spend);
                break;

            case 'q':
                EC.logout();
                system("pause");
                return 0;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
