//**Note this code is using the simulation method simulation 1000000

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to simulate a single game
bool simulateGame() {
    vector<char> allenBox = {'G', 'W', 'W'};  // G for Golden, W for White
    vector<char> benjaminBox = {'G', 'G', 'G', 'G', 'G', 'G', 'W', 'W', 'W', 'W'};
    
    random_shuffle(allenBox.begin(), allenBox.end());
    random_shuffle(benjaminBox.begin(), benjaminBox.end());
    
    int allenIndex = 0;
    int benjaminIndex = 0;
    
    while (true) {
        // Allen's turn
        if (allenBox[allenIndex] == 'G') {
            return true;  // Allen wins
        }
        allenIndex++;
        
        // Benjamin's turn
        if (benjaminBox[benjaminIndex] == 'G') {
            return false;  // Benjamin wins
        }
        benjaminIndex++;
    }
}

int main() {
    srand(time(0));  // Initialize random seed
    
    int numSimulations = 1000000;  // Number of simulations to run
    int allenWins = 0;
    
    for (int i = 0; i < numSimulations; ++i) {
        if (simulateGame()) {
            allenWins++;
        }
    }
    
    double probability = static_cast<double>(allenWins) / numSimulations;
    
    cout << "Probability that Allen wins: " << probability << endl;
    
    return 0;
}
