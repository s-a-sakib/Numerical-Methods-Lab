#include <bits/stdc++.h>
#define tolerance 0.0001
#define N 100
using namespace std;

class NewtonRapsonMethods{
    private:
        double function(double x){
            return x*x*x -2*x - 21;
        }
        double difference(double x){
            return 3*x*x - 2;
        }
    public:
        void solve(){
            double root , previous_root;
            int step = 1;

            srand(int(time(0)));
            while(true){
                previous_root = rand() % 10;
                if(difference(previous_root)!= 0) break;
            }
            
            while(true){
                double dfx = difference(previous_root);

                if(dfx == 0.0){
                    previous_root++;
                }
                double fx = function(previous_root);
                dfx = difference(previous_root);

                root = previous_root - (fx / dfx);
                if (function(root) == 0.0 || abs(root - previous_root) < tolerance){
                    break;
                }
                cout << "iterations: " << step << "  estimated root: " << previous_root << endl;
                previous_root = root;

                if (step >= N) {
                cout << "Maximum number of iterations reached. The method may not have converged." << endl;
                return;
                }
                step++;
            }
            cout << "--------------------------------" << endl;
            cout <<" The root is " << previous_root << endl;
        }
};

int main(){
    NewtonRapsonMethods method = NewtonRapsonMethods();
    method.solve();
    return 0;
}