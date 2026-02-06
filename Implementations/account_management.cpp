#include<iostream>
using namespace std;
class Account{
    friend void deposit(Account &,float amount);
    friend void withdraw(Account &,float amount);
    private:
    string accountHolderName;
    long long int accountNumber;
    float balance;
    public:
    void Initialize(){
        cout<<"Enter accountHolderName :";
        getline(cin,accountHolderName);
        cout<<"Enter accountNumber :";
        cin>>accountNumber;
        cout<<"Enter initial balance :";
        cin>>balance;

    }
    void display(){
        cout<<"accountHolderName :"<<accountHolderName<<endl;
        cout<<"accountNumber :"<<accountNumber<<endl;
        cout<<"current balance :"<<balance<<endl;
    }
};

    void deposit(Account &a, float amount){
    a.balance+=amount;
    cout<<"Total amount in account :"<<a.balance<<endl<<"\n\n";
    }
    void withdraw(Account &a, float amount){
      if(a.balance<amount)
        cout<<"Transaction Unauthoraized \n\n";
     else
       cout<<"Total Remainning amount in account :"<<a.balance-amount<<endl<<"\n\n";

   }

 int main(){
    float amount;
    int choise ;
    Account a1;
    
    a1.Initialize();
    a1.display();
     cout<<"Enter your amount :";
    cin>>amount;
    cout<<"Enter 1 for deposit\nEnter 2 for withdraw\n";
    cin>>choise;
    cout<<"----After deposit or withdraw your account detail ----\n";
      switch(choise){
            case 1:{
                deposit(a1,amount);  
                break;
            }
            case 2:{
                 withdraw(a1, amount);
                break;
            }  
        }
    
    return 0;
 }