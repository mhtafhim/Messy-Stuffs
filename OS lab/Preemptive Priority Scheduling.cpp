#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int id;
    int burstTime;
    int arrivalTime;
    int priority;
    int remainingTime;
    int turnaroundTime = 0;
    int waitingTime = 0;
    bool vis = false;
};

struct ComparePriority
{
    bool operator()(const Process &a, const Process &b) const
    {
        if (a.priority == b.priority)
        {
            return a.arrivalTime > b.arrivalTime;
        }
        return a.priority > b.priority;
    }
};

void preemptivePriority(Process processes[], int n)
{
    std::priority_queue<Process, std::vector<Process>, ComparePriority> readyQueue;
    //  priority_queue<Process, vector<Process>, comparePriority> readyQueue;
    int currentTime = 0;
    int completedProcesses = 0;

    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrivalTime <= currentTime && !processes[i].vis)
        {
            processes[i].remainingTime = processes[i].burstTime;
            processes[i].vis = true;
            readyQueue.push(processes[i]);
        }
    }

    while (completedProcesses < n)
    {
        // If ready queue is not empty, preempt process with highest priority
        if (!readyQueue.empty())
        {
            Process process = readyQueue.top();
            readyQueue.pop();

            // Execute process for the minimum of remaining time and its burst time
            int executedTime = 1;
            process.remainingTime -= executedTime;
            currentTime += executedTime;
            bool ok = false;
            //    cout << currentTime << endl;
            for (int i = 0; i < n; i++)
            {
                if (processes[i].arrivalTime <= currentTime && !processes[i].vis)
                {
                    ok = true;
                    processes[i].remainingTime = processes[i].burstTime;
                    processes[i].vis = true;
                    readyQueue.push(processes[i]);
                }
            }

            // Check for process completion
            if (process.remainingTime == 0)
            {
                //  cout << currentTime << endl;
                processes[process.id - 1].turnaroundTime = currentTime - processes[process.id - 1].arrivalTime;
                processes[process.id - 1].waitingTime = processes[process.id - 1].turnaroundTime - processes[process.id - 1].burstTime;

                completedProcesses++;

                //  cout << process.id << " " << process.turnaroundTime << " " << process.waitingTime << endl;
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

    // Print results
    cout << "\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].priority << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << endl;
    }
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}

int main()
{
    int n;

    //   cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    for (int i = 0; i < n; i++)
    {

        cin >> processes[i].burstTime;
        processes[i].id = i + 1;
    }

    for (int i = 0; i < n; i++)
    {

        cin >> processes[i].arrivalTime;
    }

    for (int i = 0; i < n; i++)
    {

        cin >> processes[i].priority;
    }

    cout << endl;

    preemptivePriority(processes, n);

    return 0;
}
