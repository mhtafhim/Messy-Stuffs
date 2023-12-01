#include <bits/stdc++.h>
using namespace std;

struct proc
{
    int procNo, arrival, cputime;
    int waitingTime, TurnaroundTime, completionTime;
    bool processed = false;

    proc() : procNo(), arrival(0), cputime(0) {}
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


    sort(process.begin(),process.end(),compareByArrival);



    
}