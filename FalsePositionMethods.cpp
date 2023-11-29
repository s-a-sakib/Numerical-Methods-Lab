#include <bits/stdc++.h>
using namespace std;

#define ep_s 0.0001

class FalsePosition {
    private:
        double tolerance = 0.0001;
        double function(double x){
            return ( x * x * x - 2 * x * x + 3);
        }

        double falsi(double a, double b){
            return (b*function(a) - a*function(b)) / (function(a) - function(b));
        }
    public:
        double root;
        void solve(){
            double a , b;
            srand(time(0));
            while(true){
                a = -9 + rand() % 10;
                b = rand() % 10;
                if(function(a) * function(b) < 0.0) break;
            }
            if(a > b) swap(a, b);
            cout << "a = " << a << " b = " << b << endl;
            double root;
            int iterations = 1;
            while(true){
                root = falsi(a , b);
                if(function(root) == 0) break;
                
                if(function(root) < 0.0) a = root;
                else b = root;

                double ep_a = abs((falsi(a, b) - root) / root);  // finding absolute relative error
                if(ep_a < tolerance) break;
                cout << "Iteration:  " << iterations++ << "  a = " << a << " b = " << b << endl;
            }
            cout <<" The root is : " << root << endl;
        }
};

int main(){
    FalsePosition position = FalsePosition();
    position.solve();
    return 0;
}