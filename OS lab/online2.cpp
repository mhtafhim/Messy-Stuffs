#include <bits/stdc++.h>
using namespace std;

struct proc
{
    int procNo, arrival, cputime;
    int waitingTime, TurnaroundTime, completionTime;
    bool processed = false;

    proc() : procNo(0), arrival(0), cputime(0) {}
};

bool compareByArrival(const proc &a, const proc &b)
{
    if (a.arrival == b.arrival)
        return a.cputime > b.cputime;
    return a.arrival < b.arrival;
}

int main()
{
    int n;
    cin >> n;

    vector<proc> process(n);

    for (int i = 0; i < n; i++)
    {
        process[i].procNo = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> process[i].cputime;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> process[i].arrival;
    }

    sort(process.begin(), process.end(), compareByArrival);

    process[0].waitingTime = 0;
    process[0].TurnaroundTime = process[0].cputime;

    process[0].completionTime = process[0].cputime;
    process[0].processed = true;

    int sumWaitingTime = process[0].waitingTime, sumTurnAround = process[0].TurnaroundTime;

    int curr = 1;
    int currentTime = process[0].completionTime;

    cout << process[0].arrival;
    cout << "----(P"<<process[0].procNo<<")----" << currentTime;

    for (int i = 1; i < n; i++)
    {
        curr = -1;
        for (int j = 0; j < n; j++)
        {
            if (!process[j].processed && (curr == -1 || (currentTime - process[curr].arrival) < (currentTime - process[j].arrival) && currentTime >= process[j].arrival))
            {
                curr = j;
                process[curr].waitingTime = currentTime - process[curr].arrival;
            }
        }

        process[curr].waitingTime = max(0, currentTime - process[curr].arrival);
        if (process[curr].waitingTime == 0)
        {
            process[curr].completionTime = process[curr].arrival + process[curr].cputime;
        }
        else
        {
            process[curr].completionTime = currentTime + process[curr].cputime;
        }

        process[i].TurnaroundTime = process[curr].waitingTime + process[curr].cputime;
        process[curr].processed = true;

        sumWaitingTime += process[curr].waitingTime;
        sumTurnAround += process[curr].TurnaroundTime;
        currentTime = process[curr].completionTime;
        cout << "----(P"<<process[curr].procNo<<")----" << currentTime;
    }
    cout << "\n \n";


    cout << "Total waiting time : " << sumWaitingTime << endl;
    cout << "Average Waiting Time : " << (float)sumWaitingTime / n << endl;
    cout << "Total Turnaround Time :" << sumTurnAround << endl;
    cout << "Average Turn Around Time : " << (float)sumTurnAround / n << endl;

    return 0;
}