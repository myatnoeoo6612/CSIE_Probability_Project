#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double simulate(int trials, double p) {
    int total_flips = 0;
    
    for (int i = 0; i < trials; ++i) {
        int heads = 0, tails = 0, flips = 0;
        while (heads < 2 || tails < 1) {
            flips++;
            double rand_val = (double)rand() / RAND_MAX;
            if (rand_val < p) {
                heads++;
            } else {
                tails++;
            }
        }
        total_flips += flips;
    }
    
    return (double)total_flips / trials;
}

int main() {
    srand(time(0));
    int trials = 1000000; // Number of simulation trials
    
    double p1 = 0.55;
    double p2 = 0.60608454;
    double p3 = 0.65;
    
    double E_X_p1 = simulate(trials, p1);
    double E_X_p2 = simulate(trials, p2);
    double E_X_p3 = simulate(trials, p3);
    
    cout << "E[X] for p = 0.55: " << E_X_p1 << endl;
    cout << "E[X] for p = 0.60608454: " << E_X_p2 << endl;
    cout << "E[X] for p = 0.65: " << E_X_p3 << endl;
    
    return 0;
}
