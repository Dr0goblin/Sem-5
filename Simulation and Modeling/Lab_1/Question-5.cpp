/* Question-5: 'Customers arrive in a bank according to a Poisson&#39;s process with mean inter
arrival time of 10 minutes. Customers spend an average of 5 minutes on the
single available counter, and leave.
a. Probability that a customer will not have to wait at the counter.
b. Expected number of customers in the bank.
c. Time a customer expects to spend in the bank.' */
#include <iostream>
using namespace std;

int main() {
    double mean_inter_arrival = 10;
    double mean_service_time = 5;
    
    double arrival_rate = 1 / mean_inter_arrival;
    double service_rate = 1 / mean_service_time;
    double rho = arrival_rate / service_rate;
    
    double prob_no_wait = 1 - rho;
    double expected_customers = rho / (1 - rho);
    double expected_time_system = 1 / (service_rate - arrival_rate);
    
    cout << "a. Probability no wait: " << prob_no_wait << endl;
    cout << "b. Expected customers: " << expected_customers << endl;
    cout << "c. Expected time in bank: " << expected_time_system << " minutes" << endl;
    
    return 0;
}