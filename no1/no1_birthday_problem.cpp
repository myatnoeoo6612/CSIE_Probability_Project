#include <iostream>
#include <iomanip>

int main() {
    const int numPeople = 23;
    const int numDays = 365;
    
    // Calculate the probability
    double probability = 1.0;
    for (int i = 0; i < numPeople; ++i) {
        probability *= (numDays - i) / static_cast<double>(numDays);
    }
    
    // Print the probability
    std::cout << std::fixed << std::setprecision(7);
    std::cout << "Probability that none of the " << numPeople 
              << " people have the same birthday: " << probability << std::endl;
    
    // Verify the result
    if (probability >= 0.4927027 && probability <= 0.4927029) {
        std::cout << "The calculated probability matches the expected value of approximately 0.4927028" << std::endl;
    } else {
        std::cout << "The calculated probability does not match the expected value" << std::endl;
    }
    
    return 0;
}
