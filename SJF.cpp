/* Author: thitchcock@muhlenberg.edu
 * Date: 11/13/2023
 * Description: SJF implemented in C++
 */

#include <iostream>
#include <vector>
#include <algorithm> // for sort function

using namespace std;

// function for sorting based on burst time
// if a.second.second is less than b.second.second, the function returns true,
// indicating that a should be placed before b in the sorted vector
bool compareByBurst(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
    return a.second.second < b.second.second;
}

int main() {
    // constant context switch time
    const int CS_TIME = 5;
    int total = 0;

    // create vector of pairs with string keys and pair of integers as values
	// Process, arrival time, burst time
    vector<pair<string, pair<int, int>>> processInfo;

    // add elements to the vector
	// assuming all Ps arrive at same time for SJF
    processInfo.push_back(make_pair("P1", make_pair(0, 900)));
    processInfo.push_back(make_pair("P2", make_pair(0, 45)));
    processInfo.push_back(make_pair("P3", make_pair(0, 88)));
    processInfo.push_back(make_pair("P4", make_pair(0, 9)));

    // display unsorted elements
    cout << "Processes before SJF:" << endl;
    for (const auto& entry : processInfo) {
        cout << "Process ID: " << entry.first
             << ", Arrival time: " << entry.second.first
             << ", Total service time: " << entry.second.second
             << endl;
    }

    // sorts vector based on the second element of the pair using the custom comparison function
    sort(processInfo.begin(), processInfo.end(), compareByBurst);

    // display sorted elements
    cout << "\nProcesses after SJF:" << endl;
    for (const auto& entry : processInfo) {
        cout << "Process ID: " << entry.first
             << ", Arrival time: " << entry.second.first
             << ", Total service time: " << entry.second.second
             << endl;
        total += entry.second.second;
    }

    // finds total time with context switch
    total += processInfo.size() * CS_TIME;
    cout << "\nThe total time FCFS takes is " << total << " with a context switch of " << CS_TIME << endl;

    return 0;
}

