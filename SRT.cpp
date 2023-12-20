/* Author: thitchcock@muhlenberg.edu
 * Date: 11/13/2023
 * Description: SRT implemented in C++
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// used a struct to easily grab variables
// much easier than n.n
// same as SJF except now includes remaining time for each process
struct Process {
	int process_id;
	int arrival_time;
	int burst_time;
	int remaining_time;
};

// finds process with the shortest remaining time
// vector of processes and current time as parameters
int findShortestRemainingTime(vector<Process>& processes, int currentTime) {
	int shortestRemainingTime = INT_MAX;
	int shortestIndex = -1;

	// for each process in proccesses
	for (int i = 0; i < processes.size(); i++) {
		// if process has arrived and has remaining burst time
		if ( (processes[i].arrival_time <= currentTime) && (processes[i].remaining_time < shortestRemainingTime) && (processes[i].remaining_time > 0)) {
			shortestRemainingTime = processes[i].remaining_time;
			shortestIndex = i; // index of process
		}
	}
	return shortestIndex;
}

// Function to calculate average waiting time and turnaround time
void findAvgTime(vector<Process>& processes) {

	int totalWaitingTime = 0;
	int totalTurnaroundTime = 0;
	int currentTime = 0;
	
	// initialize remaining time for each process
	for (int i = 0; i < processes.size(); ++i) {
		processes[i].remaining_time = processes[i].burst_time;
	}
	
	// determines which process to execute based on shortest remaining time
	while (true) {
		int shortest = findShortestRemainingTime(processes, currentTime);
	
		// no processes left, break the loop
		if (shortest == -1) {
			break;
		}
	
	// decrease shortest process by 1
	processes[shortest].remaining_time--;
	currentTime++;
	
	// if process done running
	if (processes[shortest].remaining_time == 0) {
		// calculate waiting time and turnaround time
		int waitingTime = currentTime - processes[shortest].arrival_time - processes[shortest].burst_time;
		int turnaroundTime = waitingTime + processes[shortest].burst_time;
	
		// add to total
		totalWaitingTime += waitingTime;
		totalTurnaroundTime += turnaroundTime;
		}
	}
	
	// calculate averages
	float avgWaitingTime = static_cast<float>(totalWaitingTime) / processes.size();
	float avgTurnaroundTime = static_cast<float>(totalTurnaroundTime) / processes.size();
	cout << "Average Waiting Time: " << avgWaitingTime << endl;
	cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}

int main() {
	vector<Process> processes = {
	{1, 0, 65, 0},
	{2, 21, 5, 0},
	{3, 76, 60, 0},
	{4, 4, 21, 0}
	};
	
	cout << "\nProcesses before SRT:" << endl;
	for (int i =0; i<processes.size();i++) {
		cout << "Process ID: " << processes[i].process_id
		<< ", Arrival time: " << processes[i].arrival_time
		<< ", Burst time: " << processes[i].burst_time
		<< endl;
	}
	cout << "\n" << endl;
	
	// find avg wait time and avg turnaround time
	findAvgTime(processes);
	
	return 0;
}
