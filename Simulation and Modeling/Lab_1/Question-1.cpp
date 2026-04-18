/* Question -1: 'A call center operates 6 days a week, 9 hours a day. It receives 1620 calls per week.
Calculate the mean inter-arrival time and mean arrival rate (calls per minute).' */
#include <iostream>
using namespace std;

int main() {
    int days_per_week = 6;
    int hours_per_day = 9;
    int calls_per_week = 1620;
    
    double total_minutes_per_week = days_per_week * hours_per_day * 60;
    double mean_arrival_rate = calls_per_week / total_minutes_per_week;
    double mean_inter_arrival_time = 1 / mean_arrival_rate;
    
    cout << "Mean arrival rate: " << mean_arrival_rate << " calls per minute" << endl;
    cout << "Mean inter-arrival time: " << mean_inter_arrival_time << " minutes" << endl;
    
    return 0;
}