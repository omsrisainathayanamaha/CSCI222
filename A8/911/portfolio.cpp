#include <iostream>
using namespace std;
class BankAccount
{
        public:
        double balance;
        BankAccount()
        {balance=0;}
        BankAccount(double b)
        {
                balance = b;
        }
        void deposit(double a){
                balance += a;
        }
        void withdraw(double a)
        {

                if(a > balance){balance-=10;
                }
                balance -= a;
        }
};

class Portfolio
{
        private:
                bool isS(string a){return (a.compare("S"));}
                bool isC(string a){return (a.compare("C"));}
        public:
                BankAccount s;
                BankAccount c;
                Portfolio(){
                        s = BankAccount();
                        c = BankAccount();

                }
                Portfolio(double sa, double ch){
                        s = BankAccount(sa);
                        c = BankAccount(ch);
                }
                void deposit(string b, double a){
                        if(isS(b)){s.deposit(a);}
                        else if(isC(b)){c.deposit(a);}
                }
                void withdraw(string b, double a){
                        if(isS(b)){s.withdraw(a);}
                        else if(isC(b)){c.withdraw(a);}
                }
                void transfer(string b, double a){
                        if(isS(b)){s.withdraw(a); c.deposit(a);}
                        else if(isC(b)){s.deposit(a); c.withdraw(a);}

}
                void printAccounts()
                {
                        cout << "Savings: " << s.balance << " Checking: " << c.balance << endl;
                }

};

int main()
{
        Portfolio p = Portfolio(1000,259.25);
        p.printAccounts();
        p.deposit("S", 250);
        p.printAccounts();
        p.withdraw("C", 200);
        p.printAccounts();
        p.transfer("S", 259);
        p.printAccounts();
}

