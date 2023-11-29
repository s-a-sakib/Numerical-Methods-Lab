#include <bits/stdc++.h>

using namespace std;

class Falsi {

    private:

    double tolerence = 0.0001;
    
    // double function(double x) {
    //     return (x*x*x + x*x - 1);
    // }
    double function(double x) {

        return ( x * x * x - 2 * x * x + 3);
    }

    double falsi(double a, double b) {
        return (b*function(a) - a*function(b)) / (function(a) - function(b));
    }

    public:

    double root;

    void solve() {
        
        double a, b;
        srand(int(time(0)));

        while(true) {

            a = -9 + rand()%10;
            b = rand()%10;

            if(function(a) * function(b) < 0.0) break;
        }


        int iteration = 1;

        while(true) {

            root = falsi(a, b);

            cout << "root at iteration " << iteration++ << " : " << root << endl; 

            if(function(root) == 0.0) break;

            if(function(root) * function(a) < 0.0) b = root;
            else a = root;

            double ep_a = abs((falsi(a, b) - root) / root);  // finding absolute relative error

            if(ep_a < tolerence) break;

        }

        cout << "The apprx. root is: " << root << endl;
    }
};

int main() {

    Falsi false_position = Falsi();

    false_position.solve();
    
    return 0;
}