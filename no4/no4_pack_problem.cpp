#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cmath>

const int SIMULATIONS = 100000;

int simulate() {
    std::set<int> collected;
    int packs = 0;

    while (collected.size() < 6) {
        int number = rand() % 6 + 1; // Random number between 1 and 6
        collected.insert(number);
        packs++;
    }

    return packs;
}

int main() {
    std::srand(std::time(0));

    std::vector<int> results;
    results.reserve(SIMULATIONS);

    for (int i = 0; i < SIMULATIONS; ++i) {
        results.push_back(simulate());
    }

    double sum = std::accumulate(results.begin(), results.end(), 0.0);
    double mean = sum / SIMULATIONS;

    double sq_sum = std::inner_product(results.begin(), results.end(), results.begin(), 0.0);
    double variance = sq_sum / SIMULATIONS - mean * mean;

    std::cout << "E[X] (Mean): " << mean << std::endl;
    std::cout << "Var(X) (Variance): " << variance << std::endl;
    std::cout << "E[X^2]: " << (mean * mean + variance) << std::endl;

    return 0;
}
