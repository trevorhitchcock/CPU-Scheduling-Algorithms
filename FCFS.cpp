/* Author: thitchcock@muhlenberg.edu
 * Date: 11/13/2023
 * Description: FCFS implemented in C++
 */

#include <iostream>
#include <vector>
#include <algorithm> // for sort function

using namespace std;

// function for sorting based on arrival time
// if a.second.first is less than b.second.first, the function returns true,
// indicating that a should be placed before b in the sorted vector
bool compareByArrival(const pair<string, pair<int, int>>& a, const pair<string, pair<int, int>>& b) {
    return a.second.first < b.second.first;
}

int main() {
    // constant context switch time
    const int CS_TIME = 5;
    int total = 0;

    // create vector of pairs with string keys and pair of integers as values
    vector<pair<string, pair<int, int>>> processInfo;

    // add elements to the vector
    processInfo.push_back(make_pair("P1", make_pair(15, 4)));
    processInfo.push_back(make_pair("P2", make_pair(0, 65)));
    processInfo.push_back(make_pair("P3", make_pair(11, 76)));
    processInfo.push_back(make_pair("P4", make_pair(10, 90)));

    // display unsorted elements
    cout << "Processes before FCFS:" << endl;
    for (const auto& entry : processInfo) {
        cout << "Process ID: " << entry.first
             << ", Arrival time: " << entry.second.first
             << ", Total service time: " << entry.second.second
             << endl;
    }

    // sorts vector based on the first element of the pair using the custom comparison function
    sort(processInfo.begin(), processInfo.end(), compareByArrival);

    // display sorted elements
    cout << "\nProcesses after FCFS:" << endl;
    for (const auto& entry : processInfo) {
        cout << "Process ID: " << entry.first
             << ", Arrival time: " << entry.second.first
             << ", Total service time: " << entry.second.second
             << endl;
        total += entry.second.second;
    }

    // finds total time with context switch
    // very easy for FCFS
    total += processInfo.size() * CS_TIME;
    cout << "\nThe total time FCFS takes is " << total << " with a context switch time of " << CS_TIME << endl;

    return 0;
}

