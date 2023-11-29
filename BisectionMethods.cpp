#include <bits/stdc++.h>
using namespace std;

#define ep_s 0.0001

class Bisection {
    private:
        double low, up;
        double function(double x) {
            return x*x*x -2*x*x + 3;
        }

    public:
    void solve() {
        srand(int(time(0)));

        while(true) {
            low = -9 + rand()%10;
            up = rand()%10;

            if(function(low) * function(up) < 0.0) break; //minus * plus = minus
        }

        if(low > up) swap(low, up);
        cout << "low: " << low << "   up: " << up << endl;

        double root = (low+up) / 2;
        double prev_root = root;
        int iteration = 1;
        while(true) {
            double calc = function(root) * function(low);
            if(calc > 0.0) low = root;
            else if(calc < 0.0) up = root;
            else break;          
            root = (low+up) / 2;
            double ep_a = abs((root - prev_root) / root); // Relative error
            if(ep_a < ep_s) break;
            prev_root = root;
            cout << "root at iteration " << iteration++ << " : " << root << endl;
            cout << "a = " << low << "    b = " << up << endl;
        }
        cout << "the root is: " << root << endl;
        cout << "Total number of iterations : " << iteration << endl;
    }
};

int main() {

    Bisection bisect = Bisection();

    bisect.solve();

    return 0;
}