#include<iostream>
#include<vector>
using namespace std;
class bank;
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
    int getBalance(){
        return balance;
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
                    break;
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
    
    void transferMoney(){
        
        int senderAccNO;
        int receiverAccNo;
        int amount;
        int senderIndex=-1;
        int receiverIndex=-1;
        while(senderIndex==-1){
            cout<<"enter sender's account number"<<endl;
            cin>>senderAccNO;
            for(int i=0; i<Accounts.size(); i++){
                if(Accounts[i].getaccNumber()==senderAccNO){
                senderIndex=i;
            }
        }
        if(senderIndex==-1){
            cout<<"account not found"<<endl;
        }
    }
    
        while(receiverIndex==-1){
            cout<<"enter receiver's account number"<<endl;
            cin>>receiverAccNo;
            if(senderAccNO==receiverAccNo){
                cout<<"can't transfer money to same account"<<endl;
                continue;
        }
            for(int i=0; i<Accounts.size(); i++){
                if(Accounts[i].getaccNumber()==receiverAccNo){
                    receiverIndex=i;
                    break;
            }
        }
            if(receiverIndex==-1){
                cout<<"account not found"<<endl;
                return;
            }
        }
        
            
            cout<<"enter amount to tranfer"<<endl;
            cin>>amount;
            if(amount>0 && amount<=Accounts[senderIndex].getBalance()){
                Accounts[senderIndex].setBalance(Accounts[senderIndex].getBalance()-amount);
                Accounts[receiverIndex].setBalance(Accounts[receiverIndex].getBalance()+amount);

            }
            else{
                cout<<"invalid amount or insufficient balance"<<endl;
            }
            cout<<"money transferred successfully"<<endl;
            cout<<"balance of account "<<Accounts[senderIndex].getaccNumber() <<"is "<< Accounts[senderIndex].getBalance() << endl;
            cout<<"balance of account "<<Accounts[receiverIndex].getaccNumber() <<"is "<< Accounts[receiverIndex].getBalance() << endl;
        
        }
    void deleteAccount(){
        int delete_acc;
        cout<<"enter account number to delete"<<endl;
        cin>>delete_acc;
        for(int i=0; i<Accounts.size(); i++){
            if(delete_acc==Accounts[i].getaccNumber()){
                Accounts.erase(Accounts.begin()+i);
                cout<<"account deleted successfully"<<endl;
                return;
            }
        }
                cout<<"account not found"<<endl;
    }
            
        
    void bankMenu() {
        int choice;
        choice=0;
        while(choice!=5){
            cout<<"1.create new account"<<endl;
            cout<<"2.open existing account"<<endl;
            cout<<"3.transfer money"<<endl;
            cout<<"4.delete account"<<endl;
            cout<<"5.exit from bank menu"<<endl;
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
                transferMoney();
                case 4:
                deleteAccount();
                case 5:
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

        
    





            
