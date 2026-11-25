#include<iostream>
#include<vector>
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
        cout<<"your total bank balance is"<<balance<<endl;
    }
    void withdraw(){
        int amount;
        cout<<"enter amount";
        cin>>amount;
        if(balance>=amount){
            balance=balance-amount;
        }
        else{
            cout<<"balance is unsufficient"<<endl;
        }
    }
    void checkbalance(){
            cout<<"your availabe bank balance is"<<balance<<endl;
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
                case 1:
                    deposit();
                    break;
                case 2:
                    withdraw();
                    break;
                case 3:
                    checkbalance();
                    break;
                case 4:
                    cout<<"thank you"<<endl;
                    break;
                default:
                    cout<<"invalid choice"<<endl;
            }
        }
    


    }
};
class bank{
    public:
    vector<bankAccount> accounts;
    
    bank(){
        accounts.push_back(bankAccount(101, "Riya", 5000));
        accounts.push_back(bankAccount(102, "om", 8000));
        accounts.push_back(bankAccount(103, "kalpita", 10000));
          
    }
    void createAccount(){
        int accNo;
        cout<<"enter account number"<<endl;
        cin>>accNo;
        string n;
        cout<<"enter name"<<endl;
        cin>>n;
        bankAccount newAccount(accNo, n, 0);
        accounts.push_back(newAccount);
        cout<<"account created successfully"<<endl;
        cout<<"your initial bank balance is 0"<<endl;

    }
    void openAccount(){
        int accNo;
        cout<<"enter account number"<<endl;
        cin>>accNo;
        for(int i=0; i<accounts.size();i++){
            if(accounts[i].accountNo==accNo){
                cout<<"welcome"<<accounts[i].name<<endl;
                accounts[i].bankMenu();
                return;
            }
        }
        cout<<"account not found"<<endl;
    }
    void bankMenu(){
        int choice=0;
        while(choice!=3){
            cout<<"bank menu are"<<endl;
            cout<<"1.create acount"<<endl;
            cout<<"2.open existing account"<<endl;
            cout<<"exit"<<endl;
            cout<<"enter choice"<<endl;
            cin>>choice;
            switch(choice){
                case 1:
                    createAccount();
                    break;
                case 2:
                    openAccount();
                    break;
                case 3:
                    cout<<"thank you"<<endl;
                    break;
                default:
                    cout<<"invalid choice"<<endl;
            }
        }
    }
};
int main(){
    bank b;
    b.bankMenu();
    return 0;
}