#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Process
{
    int id;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    bool vis = false;
};


void roundRobin(Process processes[], int n, int quantum)
{
    queue<Process> readyQueue;
    int currentTime = 0;
    int completedProcesses = 0;


    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrivalTime <= currentTime && !processes[i].vis)
        {
            readyQueue.push(processes[i]);
            processes[i].vis = true;
        }
    }

    cout << "\nGantt chart : \n0-";

    while (completedProcesses < n)
    {

        // If ready queue is not empty, execute the process
        if (!readyQueue.empty())
        {
            Process process = readyQueue.front();
            readyQueue.pop();

            // Execute process for the minimum of burst time and quantum
            int remainingTime = min(process.burstTime, quantum);
            process.burstTime -= remainingTime;
            currentTime += remainingTime;
            /*Gantt Chart*/
             cout << "---(" << process.id << ")---";
             cout << currentTime;

            for (int i = 0; i < n; i++)
            {
                if (processes[i].arrivalTime <= currentTime && !processes[i].vis)
                {
                    readyQueue.push(processes[i]);
                    processes[i].vis = true;
                }
            }

            // Calculate waiting and turnaround time for completed processes
            if (process.burstTime == 0)
            {
                processes[process.id - 1].turnaroundTime = currentTime - processes[process.id - 1].arrivalTime;
                processes[process.id - 1].waitingTime = processes[process.id - 1].turnaroundTime - processes[process.id - 1].burstTime;
                completedProcesses++;
            }
            else
            {
                readyQueue.push(process);
            }
        }
        else
        {
            currentTime++;
        }
    }

    // Calculate average waiting and turnaround time
    float avgWaitingTime = 0.0;
    float avgTurnaroundTime = 0.0;

    for (int i = 0; i < n; i++)
    {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    
    cout << "\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << endl;
    }
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}

int main()
{
    int n, quantum;

  //  cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];
  //  cout << "\nEnter the cpu time consecutively : ";
    for (int i = 0; i < n; i++)
    {

        cin >> processes[i].burstTime;
        processes[i].id = i + 1;
        processes[i].turnaroundTime = 0;
        processes[i].waitingTime = 0;
    }

  //  cout << "\nEnter the arrival time consecutively : ";
    for (int i = 0; i < n; i++)
    {

        cin >> processes[i].arrivalTime;
    }

  //  cout << "\nEnter the time quantum: ";
    cin >> quantum;

    roundRobin(processes, n, quantum);

    return 0;
}
