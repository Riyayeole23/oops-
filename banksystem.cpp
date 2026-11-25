#include<iostream>
using namespace std;
class bankAccount{
    public:
    int accountNo;
    int balance;
    string name;
    bankAccount(int accNo, string n, int b){
        accountNo=accNo;
        name=n;
        balance=b;
    }
    void deposit(){
        int amount;
        cout<<"enter amount";
        cin>>amount;
        balance=balance+amount;
        cout<<"total balance is"<<balance<<endl;
    }
    void withdraw(){
        int amount;
        cout<<"enter amount";
        cin>>amount;
        if(balance>=amount){
            balance=balance-amount;
        }
        else{
            cout<<"insufficient balance"<<endl;
        }
    }
    void checkbalance(){
            cout<<"your balance is<<balance"<<endl;
    }
    void bankMenu(){
        int choice=0;
        while(choice!=4){
            cout<<"bank menu are"<<endl;
            cout<<"1.deposit"<<endl;
            cout<<"2.withdraw"<<endl;
            cout<<"3.checkBalance"<<endl;
            cout<<"4.exit"<<endl;
            cout<<"enter choice"<<endl;
            cin>>choice;
            switch(choice){
                case1:
                deposit();
                break;
                case2:
                withdraw();
                break;
                case3:
                checkbalance();
                break;
                case4:
                cout<<"thank you"<<endl;
                break;
                default:
                cout<<"invalid choice"<<endl;
            }
        }
    


    }
};
int main(){
    bankAccount Riya(101, "riya", 0);
    bankAccount om(102, "om", 0);
    bankAccount kalpita(103, "kalpita", 0);
    int accountNo;
    cout<<"enter accountnumber"<<endl;
    cin>>accountNo;
    if(accountNo=101){
        cout<<"welcome riya"<<Riya.name<<endl;
        Riya.bankMenu();

    }
    else if(accountNo=102){
        cout<<"welcome om"<<om.name<<endl;
        om.bankMenu();
    }
    else if(accountNo=103){
        cout<<"welcome kalpita"<<kalpita.name<<endl;
        kalpita.bankMenu();
    }
    else{
        cout<<"account not found"<<endl;
    }
    return 0;
}
