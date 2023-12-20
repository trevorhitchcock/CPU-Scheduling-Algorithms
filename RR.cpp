/* Author: thitchcock@muhlenberg.edu
 * Date: 11/13/2023
 * Description: Round Robin implemented in C++
 */
 
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

void roundRobin(vector<Process>& processes, int quantum) {
	
	// queue to store process indexes
	queue<int> readyQueue;
	int currentTime = 0;
	
	// initialize remaining time for each process
	for (int i = 0; i < processes.size(); ++i) {
		processes[i].remaining_time = processes[i].burst_time;
	}
	
	while (true) {
		bool done = true;
		
		for (int i = 0; i < processes.size(); i++) {
			if (processes[i].arrival_time <= currentTime) { // process has arrived
				// if process has time remaining, execute for time quantum
				if (processes[i].remaining_time > 0) {
				done = false;

				// executes process for time quantum or remaining time, whichever is smaller
				if (processes[i].remaining_time <= quantum) {
					currentTime += processes[i].remaining_time;
					processes[i].remaining_time = 0;
				}else {
					currentTime += quantum;
					processes[i].remaining_time -= quantum;
				}

				// Print execution of process for time quantum
				cout << "Process " << processes[i].process_id << " executed for time quantum at time " << currentTime << endl;
				}
			}
		}
	
	// If all processes are executed, break the loop
		if (done) {
			break;
		}
	}
}

int main() {
    vector<Process> processes = {
        {1, 0, 10, 0},
        {2, 5, 15, 0},
        {3, 4, 38, 0},
        {4, 32, 9, 0}
    };
	cout << "\nProcesses before RR:" << endl;
	for (int i =0; i<processes.size();i++) {
		cout << "Process ID: " << processes[i].process_id
		<< ", Arrival time: " << processes[i].arrival_time
		<< ", Burst time: " << processes[i].burst_time
		<< endl;
	}
	
    int quantum;
	
	cout << "\nEnter the quantum: " <<  endl;
	cin >> quantum;

    roundRobin(processes, quantum);

    return 0;
}
