#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for std::sort
using namespace std;

struct proc
{
    int procNo, arrival, cputime;
    int waitingTime,TurnaroundTime,completionTime;

    // Default constructor
    proc() : procNo(0), arrival(0), cputime(0) {}
};

// Comparison function for sorting based on arrival time
bool compareByArrival(const proc &a, const proc &b)
{
    return a.arrival < b.arrival;
}
bool compareByNo(const proc &a, const proc &b)
{
    return a.procNo < b.procNo;
}

bool compareByCpuTime(const proc &a, const proc &b)
{
    return a.cputime < b.cputime;
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

    int sumWaitingTime =  process[0].waitingTime , sumTurnAround = process[0].TurnaroundTime;

    for(int i = 1; i < n ; i ++)
    {
        sort(process.begin() + i, process.end(), compareByCpuTime);
        
        process[i].waitingTime = max(0,process[i-1].completionTime - process[i].arrival);
        if(process[i].waitingTime == 0 )
        {
             process[i].completionTime = process[i].arrival + process[i].cputime;
        }
        else
        {
            process[i].completionTime = process[i-1].completionTime  + process[i].cputime;
        }
       
        process[i].TurnaroundTime = process[i].waitingTime + process[i].cputime;

        sumWaitingTime += process[i].waitingTime;
        sumTurnAround +=  process[i].TurnaroundTime;
    }


  //  sort(process.begin(), process.end(), compareByNo);
cout << "Proc     WT    TAT     CT  "<< endl;

    for (int i = 0; i < n; i++)
    {
        cout << process[i].procNo << "        " << process[i].waitingTime << "       " << process[i].TurnaroundTime <<"      "<< process[i].completionTime << endl;
    }


    cout << "Average Waiting Time : "  << (float)sumWaitingTime/n << endl;
    cout << "Average Turn Around Time : " << (float)sumTurnAround/n << endl;



    return 0;
}