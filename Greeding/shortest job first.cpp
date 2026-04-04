#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate average waiting time
float calculateAverageWaitTime(vector<int>& jobs) {
    
    // Sort jobs in ascending order (Shortest Job First)
    sort(jobs.begin(), jobs.end());

    float waitTime = 0;   // total waiting time
    int totalTime = 0;    // execution time passed
    int n = jobs.size();  // number of jobs

    // Calculate waiting time for each job
    for(int i = 0; i < n; i++) {
        waitTime += totalTime;  // add time already spent
        totalTime += jobs[i];   // execute current job
    }

    // return average waiting time
    return waitTime / n;
}

int main() {

    vector<int> jobs = {4, 3, 7, 1, 2};

    cout << "Array Representing Job Durations: ";
    for(int job : jobs) {
        cout << job << " ";
    }
    cout << endl;

    float ans = calculateAverageWaitTime(jobs);

    cout << "Average waiting time: " << ans << endl;

    return 0;
}