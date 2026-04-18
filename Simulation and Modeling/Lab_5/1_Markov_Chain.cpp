#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class MarkovChain {
private:
    vector<vector<double>> transition_matrix;
    vector<string> states;
    int n_states;

public:
    MarkovChain(vector<vector<double>>& trans, vector<string>& st) 
        : transition_matrix(trans), states(st), n_states(st.size()) {}

    vector<int> simulate(int start_state, int steps) {
        vector<int> path;
        path.push_back(start_state);
        int current = start_state;

        for (int i = 0; i < steps; i++) {
            double rand_val = (double)rand() / RAND_MAX;
            double sum = 0;
            int next_state = 0;

            for (int j = 0; j < n_states; j++) {
                sum += transition_matrix[current][j];
                if (rand_val <= sum) {
                    next_state = j;
                    break;
                }
            }

            path.push_back(next_state);
            current = next_state;
        }

        return path;
    }

    string print_path(vector<int>& path) {
        string result = "";
        for (int i = 0; i < path.size(); i++) {
            if (i > 0) result += " -> ";
            result += states[path[i]];
        }
        return result;
    }
};

int main() {
    srand(time(0));

    // Example 1: Weather Markov Chain
    cout << "=================================================\n";
    cout << "EXAMPLE 1: Weather Prediction\n";
    cout << "=================================================\n";

    vector<string> weather_states = {"Sunny", "Cloudy", "Rainy"};
    vector<vector<double>> weather_trans = {
        {0.7, 0.2, 0.1},
        {0.3, 0.4, 0.3},
        {0.2, 0.3, 0.5}
    };

    MarkovChain mc(weather_trans, weather_states);

    cout << "\nSimulating 20-day weather:\n";
    for (int i = 0; i < 3; i++) {
        vector<int> path = mc.simulate(0, 20);
        cout << "Simulation " << i + 1 << ": " << mc.print_path(path) << "\n";
    }

    // Count frequencies
    cout << "\nState Frequencies (1000 simulations):\n";
    vector<int> counts(3, 0);
    for (int i = 0; i < 1000; i++) {
        vector<int> path = mc.simulate(0, 100);
        for (int state : path) {
            counts[state]++;
        }
    }

    int total = counts[0] + counts[1] + counts[2];
    for (int i = 0; i < 3; i++) {
        cout << weather_states[i] << ": " 
             << fixed << setprecision(2) 
             << (double)counts[i] / total * 100 << "%\n";
    }

    // Example 2: Gambler's Problem
    cout << "\n\nEXAMPLE 2: Gambler's Problem\n";
    cout << "=================================================\n";

    vector<string> gambler_states = {"Broke", "$1", "$2", "$3", "$4", "Won"};
    vector<vector<double>> gambler_trans = {
        {1.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {0.5, 0.0, 0.5, 0.0, 0.0, 0.0},
        {0.0, 0.5, 0.0, 0.5, 0.0, 0.0},
        {0.0, 0.0, 0.5, 0.0, 0.5, 0.0},
        {0.0, 0.0, 0.0, 0.5, 0.0, 0.5},
        {0.0, 0.0, 0.0, 0.0, 0.0, 1.0}
    };

    MarkovChain mc2(gambler_trans, gambler_states);

    cout << "\nGambler starting with $3:\n";
    for (int i = 0; i < 5; i++) {
        vector<int> path = mc2.simulate(3, 50);
        cout << "Game " << i + 1 << ": " << mc2.print_path(path) << "\n";
    }

    return 0;
}
