#include <iostream>
#include <iomanip>
#include <cmath>

// Function to calculate log factorial
double logFactorial(int n) {
    double result = 0.0;
    for (int i = 1; i <= n; ++i) {
        result += std::log(i);
    }
    return result;
}

// Function to calculate log combination log(nCr)
double logCombination(int n, int r) {
    return logFactorial(n) - logFactorial(r) - logFactorial(n - r);
}

int main() {
    // Total ways to choose 5 cards from 52
    double logTotalWays = logCombination(52, 5);

    // (a) Probability of Straight
    double logStraightWays = std::log(10) + 5 * std::log(4);
    double straightProbability = std::exp(logStraightWays - logTotalWays);

    // (b) Probability of Full House
    double logFullHouseWays = std::log(13) + logCombination(4, 3) + std::log(12) + logCombination(4, 2);
    double fullHouseProbability = std::exp(logFullHouseWays - logTotalWays);

    // (c) Probability of Flush
    double logFlushWays = std::log(4) + logCombination(13, 5);
    double flushProbability = std::exp(logFlushWays - logTotalWays);

    // Output the probabilities
    std::cout << std::fixed << std::setprecision(9);
    std::cout << "Probability of Straight: " << straightProbability << std::endl;
    std::cout << "Probability of Full House: " << fullHouseProbability << std::endl;
    std::cout << "Probability of Flush: " << flushProbability << std::endl;

    // Verification
    if (straightProbability >= 0.003940037 && straightProbability <= 0.003940039) {
        std::cout << "The calculated probability for Straight matches the expected value of approximately 0.003940038" << std::endl;
    } else {
        std::cout << "The calculated probability for Straight does not match the expected value" << std::endl;
    }

    if (fullHouseProbability >= 0.001440575 && fullHouseProbability <= 0.001440577) {
        std::cout << "The calculated probability for Full House matches the expected value of approximately 0.001440576" << std::endl;
    } else {
        std::cout << "The calculated probability for Full House does not match the expected value" << std::endl;
    }

    if (flushProbability >= 0.001980791 && flushProbability <= 0.001980793) {
        std::cout << "The calculated probability for Flush matches the expected value of approximately 0.001980792" << std::endl;
    } else {
        std::cout << "The calculated probability for Flush does not match the expected value" << std::endl;
    }

    return 0;
}
