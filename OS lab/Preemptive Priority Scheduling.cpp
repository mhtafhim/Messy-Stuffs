#include <iostream>
#include <queue>

using namespace std;

struct Process {
  int id;
  int burstTime;
  int arrivalTime;
  int remainingTime;
  int priority;
};

bool compareBurstTime(Process a, Process b) {
  return a.remainingTime < b.remainingTime;
}

bool comparePriority(Process a, Process b) {
  if (a.remainingTime == b.remainingTime) {
    return a.priority > b.priority;
  }
  return a.remainingTime < b.remainingTime;
}

void preemptivePriority(Process processes[], int n) {
  priority_queue<Process, vector<Process>, comparePriority> readyQueue;
  int currentTime = 0;
  int completedProcesses = 0;

  // Sort processes by arrival time
  sort(processes, processes + n, [](const Process& a, const Process& b) {
    return a.arrivalTime < b.arrivalTime;
  });

  while (completedProcesses < n) {
    // Add processes that have arrived to the ready queue
    for (int i = 0; i < n; i++) {
      if (processes[i].arrivalTime <= currentTime && !processes[i].remainingTime) {
        processes[i].remainingTime = processes[i].burstTime;
        readyQueue.push(processes[i]);
      }
    }

    // If ready queue is not empty, preempt process with shortest remaining time
    if (!readyQueue.empty()) {
      Process process = readyQueue.top();
      readyQueue.pop();

      // Execute process for the minimum of remaining time and its burst time
      int executedTime = min(process.remainingTime, process.burstTime);
      process.remainingTime -= executedTime;
      currentTime += executedTime;

      // Check for process completion
      if (process.remainingTime == 0) {
        process.turnaroundTime = currentTime - process.arrivalTime;
        process.waitingTime = process.turnaroundTime - process.burstTime;
        completedProcesses++;
      } else {
        readyQueue.push(process);
      }
    } else {
      currentTime++;
    }
  }

  // Calculate average waiting and turnaround time
  float avgWaitingTime = 0.0;
  float avgTurnaroundTime = 0.0;
  for (int i = 0; i < n; i++) {
    avgWaitingTime += processes[i].waitingTime;
    avgTurnaroundTime += processes[i].turnaroundTime;
  }
  avgWaitingTime /= n;
  avgTurnaroundTime /= n;

  // Print results
  cout << "Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << endl;
  for (int i = 0; i < n; i++) {
    cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << endl;
  }
  cout << "Average Waiting Time: " << avgWaitingTime << endl;
  cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}

int main() {
  int n;

  cout << "Enter the number of processes: ";
  cin >> n;

  Process processes[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter process " << i + 1 << " details:" << endl;
    cout << "  Burst Time: ";
    cin >> processes[i].burstTime;
    cout << "  Arrival Time: ";
    cin >> processes[i].arrivalTime;
    cout << "  Priority: ";
    cin >> processes[i].priority;
    processes[i].id = i + 1;
  }

  preemptivePriority(processes, n);

  return 0;
}
