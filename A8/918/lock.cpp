#include <iostream>

using namespace std;

class ComboLock
{
        private:
                int secret1, secret2, secret3, sinceReset;
                bool s1C, s2C, s3C;
        public:
                int currentPoint;
                ComboLock(int s1, int s2, int s3){
                        secret1=s1;
                        secret2=s2;
                        secret3=s3;
                        sinceReset=0;
                        s1C = false;
                        s2C = false;
                        s3C = false;
                        currentPoint=0;
                }

                void reset(){currentPoint=sinceReset=s1C=s2C=s3C=0;}
                void left(int t)
                {
                        currentPoint-=t;
                        while(currentPoint<0){currentPoint+=40;}
                        s2C = (sinceReset==1 && currentPoint==secret2);
                        ++sinceReset;

                }
                void right(int t){
                        currentPoint+=t;
                        while(currentPoint>39){currentPoint-=40;}
                        s1C = s1C || (sinceReset==0 && currentPoint == secret1);
                        s3C = (sinceReset==2 && currentPoint == secret3);


                        sinceReset++;
                }
                const bool open(){
                        return s1C && s2C && s3C;
                }



};

int main(){
        ComboLock c = ComboLock(22, 23, 24);
        c.right(22);
        c.left(39);
        c.right(1);
        cout <<"Opened: " <<  c.open()<<endl;

        string q = "C";
        int ticks;
        bool right;
        bool openAfter;
        bool reset;
        while(q.compare("Q")){
                cout << "Direction: (right is 1, left is 0)  ";
                cin >> right;
                cout << "Ticks: ";
                cin >> ticks;
                cout << "Open after this turn? 1 for yes, 0 for no  ";
                cin >> openAfter;
                cout << "Quit after this turn? Q to do it  ";
                cin >> q;
                cout << "Reset after this turn? (1 for yes, 0 for no): ";
                cin >> reset;
                if(right){c.right(ticks);}
                else{c.left(ticks);}
                if(openAfter){reset=1; cout << "Opened: " << c.open() << endl;}
                if(reset){c.reset(); cout << "Resetted" << endl;}

        }
}
