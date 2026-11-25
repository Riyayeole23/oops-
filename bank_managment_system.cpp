#include<iostream>
#include<vector>
using namespace std;
class bankAccount{
    private:
    int accNumber;
    int balance;
    string name;
    public:
    bankAccount(int accNo, string n, int b){
        accNumber=accNo;
        balance=b;
        name=n;
    }
    vector<string>Transactions;
    int getaccNumber(){
        return accNumber;
    }
    string getName(){
        return name;
    }
    
    void setBalance(int b){
        balance= b;
    }
    void deposit(){
        int amount;
        while(true){
            cout<<"enter amount to deposit"<<endl;
            cin>>amount;
            if(amount<=0){
                cout<<"enter valid amount number"<<endl;
                continue;
            }
            else{
                balance=balance+amount;
                Transactions.push_back("Deposited"+ to_string(amount));
                cout<<"tour current balance is"<<balance<<endl;
                break;
            }


        }

    }
    void withdraw(){
        int amount;
        while(true){
            cout<<"enter amount to withdraw"<<endl;
            cin>>amount;
            if(amount<=0){
                cout<<"enter valid amount to withdraw"<<endl;
                continue;
            }
            else if(amount>balance){
                cout<<"insufficient balance"<<endl;
                break;

            }
            else{
                balance=balance-amount;
                Transactions.push_back("Withdrawn:"+ to_string(amount));
                cout<<"your current balance is"<<balance<<endl;
                break;
            }
            
        }
        
    }
    void checkBalance(){
        cout<<"your balance is"<<balance<<endl;
        
    }
    void displayDetails(){
        cout<<"Account holder's name: "<<name<<endl;
        cout<<"Account numner: "<<accNumber<<endl;
        cout<<"Bank balance: "<<balance<<endl;
    }
    void changeName(){
        cout<<"your current name is: "<<name<<endl;
        string newName;
        cout<<"enter new name"<<endl;
        cin>>newName;
        name=newName;
        cout<<"your name changed to: "<<name<<endl;
    }
    void showTransactions(){
        if(Transactions.empty()){
            cout<<"No transaction history available"<<endl;
        }
        else{
        for(int i=0; i<Transactions.size(); i++){
            cout<<"transaction history is: "<<endl;
            cout<<Transactions[i]<<endl;
            }
        }
    }
    
    

    void logout(){
    
        cout<<"thankyou!! visit again"<<endl;
    }
    void bankMenu(){
        int choice;
        choice=0;
        while(choice!=7){
            cout<<"Bank menu are"<<endl;
            cout<<"1.diposit"<<endl;
            cout<<"2.withdraw"<<endl;
            cout<<"3.checkbalance"<<endl;
            cout<<"4.displayDetails"<<endl;
            cout<<"5.changeName"<<endl;
            cout<<"6.showTransactions"<<endl;
            cout<<"7.logout"<<endl;
            cout<<"enter your choice"<<endl;
            cin>>choice;
            switch(choice){
                case 1:
                    deposit();
                    break;
                case 2:
                    withdraw();
                    break;
                case 3:
                    checkBalance();
                    break;
                case 4:
                    displayDetails();
                    break;
                case 5:
                    changeName();
                    break;
                case 6:
                    showTransactions();
                case 7:
                    cout<<"tankyou!! visit again"<<endl;
                    break;
            
                default:
                    cout<<"invalid choice"<<endl;
                    break;
            }
        }
    }
};
class bank{
    public:
    vector<bankAccount>Accounts;
    bank(){
    Accounts.push_back(bankAccount(101, "Riya", 5000));
    Accounts.push_back(bankAccount(102, "kalpita", 8000));
    Accounts.push_back(bankAccount(103, "Om", 10000));
    }
    void createAccount(){
        int accNo;
        while(true){
            
            cout<<"enter 3 digit account number"<<endl;
            cin>>accNo;
            int temp = accNo;
            int count = 0;
        while(temp > 0){
            temp = temp / 10;
            count++;
        }

        if(count != 3){
            cout<<"invalid account number"<<endl;
            continue;
        }
        else{

        int found = 0;

        for(int i=0; i<Accounts.size(); i++){
            if(accNo == Accounts[i].getaccNumber()){
                found = 1;
                break;
            }
        }

        if(found == 1){
            cout<<"account number already taken"<<endl;
            cout<<"please enter a different account number"<<endl;
            continue;
        }

        cout<<"account number saved"<<endl;
        break;
        }
    }
        string n;
        cout<<"enter the name of account holder"<<endl;
        cin>>n;
        int b=0;
        bankAccount newAccount(accNo, n, b);
        Accounts.push_back(newAccount);
        cout<<"account created successfully"<<endl;
        cout<<"your initial bank balance is 0"<<endl;
    }
    void openAccount(){
            int accNo;
            cout<<"enter account number"<<endl;
            cin>>accNo;
            for(int i=0; i<Accounts.size(); i++){
                if(Accounts[i].getaccNumber()==accNo){
                    cout<<"welcome "<<Accounts[i].getName()<<endl;
                    Accounts[i].bankMenu();
                    return;
                }
            }
            cout<<"account not found"<<endl;
        }
    void bankMenu(){
        int choice;
        choice=0;
        while(choice!=3){
            cout<<"1.create new account"<<endl;
            cout<<"2.open existing account"<<endl;
            cout<<"exit from bank menu"<<endl;
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
                cout<<"thankyou!! visit again"<<endl;
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

        
    





            
