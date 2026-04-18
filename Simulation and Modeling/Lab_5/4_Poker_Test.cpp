#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

struct PokerResult {
    int sample_size;
    int five_kind;
    int four_kind;
    int full_house;
    int three_kind;
    int two_pair;
    int one_pair;
    int all_different;
};

PokerResult poker_test(vector<double>& numbers, int digits = 5) {
    PokerResult result = {(int)numbers.size(), 0, 0, 0, 0, 0, 0, 0};

    for (double num : numbers) {
        // Convert to digit string
        string digit_str = to_string(num).substr(2, digits);
        while (digit_str.length() < digits) {
            digit_str += '0';
        }

        // Count digit frequencies
        map<char, int> digit_counts;
        for (char d : digit_str) {
            digit_counts[d]++;
        }

        // Extract counts
        vector<int> counts;
        for (auto& p : digit_counts) {
            counts.push_back(p.second);
        }
        sort(counts.rbegin(), counts.rend());

        // Classify pattern
        if (counts.size() == 1) {
            result.five_kind++;
        } else if (counts.size() == 2) {
            if (counts[0] == 4) {
                result.four_kind++;
            } else if (counts[0] == 3) {
                result.full_house++;
            }
        } else if (counts.size() == 3) {
            if (counts[0] == 3) {
                result.three_kind++;
            } else if (counts[0] == 2 && counts[1] == 2) {
                result.two_pair++;
            }
        } else if (counts.size() == 4) {
            result.one_pair++;
        } else {
            result.all_different++;
        }
    }

    return result;
}

void display_poker_results(PokerResult& result) {
    cout << "Sample size: " << result.sample_size << "\n";
    
    int total = result.five_kind + result.four_kind + result.full_house 
                + result.three_kind + result.two_pair + result.one_pair 
                + result.all_different;

    cout << "All Same: " << result.five_kind << " (" 
         << fixed << setprecision(2) 
         << (double)result.five_kind / total * 100 << "%)\n";
    cout << "Four of a Kind: " << result.four_kind << " (" 
         << (double)result.four_kind / total * 100 << "%)\n";
    cout << "Full House: " << result.full_house << " (" 
         << (double)result.full_house / total * 100 << "%)\n";
    cout << "Three of a Kind: " << result.three_kind << " (" 
         << (double)result.three_kind / total * 100 << "%)\n";
    cout << "Two Pair: " << result.two_pair << " (" 
         << (double)result.two_pair / total * 100 << "%)\n";
    cout << "One Pair: " << result.one_pair << " (" 
         << (double)result.one_pair / total * 100 << "%)\n";
    cout << "All Different: " << result.all_different << " (" 
         << (double)result.all_different / total * 100 << "%)\n";
}

int main() {
    srand(time(0));

    // TEST 1: Random numbers
    cout << "TEST 1: Random numbers\n";
    vector<double> random_nums1;
    for (int i = 0; i < 500; i++) {
        random_nums1.push_back((double)rand() / RAND_MAX);
    }
    PokerResult result1 = poker_test(random_nums1, 5);
    display_poker_results(result1);

    // TEST 2: Another random sample
    cout << "\nTEST 2: Another random sample\n";
    vector<double> random_nums2;
    for (int i = 0; i < 500; i++) {
        random_nums2.push_back((double)rand() / RAND_MAX);
    }
    PokerResult result2 = poker_test(random_nums2, 5);
    display_poker_results(result2);

    // TEST 3: Biased data
    cout << "\nTEST 3: Biased data (clustered values)\n";
    vector<double> biased_nums;
    for (int i = 0; i < 500; i++) {
        double x;
        if ((double)rand() / RAND_MAX < 0.7) {
            x = 0.4 + ((double)rand() / RAND_MAX) * 0.2;
        } else {
            x = (double)rand() / RAND_MAX;
        }
        biased_nums.push_back(x);
    }
    PokerResult result3 = poker_test(biased_nums, 5);
    display_poker_results(result3);

    return 0;
}
