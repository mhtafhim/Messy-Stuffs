
#include <bits/stdc++.h>
using namespace std;

int FIFOPageReplacement(const vector<int> &referenceString, int numFrames)
{
    queue<int> fifoQueue;
    unordered_set<int> pageSet;
    int pageFaults = 0;

    for (int page : referenceString)
    {
        if (pageSet.find(page) == pageSet.end())
        {
            if (fifoQueue.size() == numFrames)
            {
                int removedPage = fifoQueue.front();
                fifoQueue.pop();
                pageSet.erase(removedPage);
            }

            fifoQueue.push(page);
            pageSet.insert(page);
            pageFaults++;
        }
    }

    return pageFaults;
}

int LIFOPageReplacement(const vector<int> &referenceString, int numFrames)
{
    stack<int> fifoQueue;
    unordered_set<int> pageSet;
    int pageFaults = 0;

    for (int page : referenceString)
    {
        if (pageSet.find(page) == pageSet.end())
        {
            if (fifoQueue.size() == numFrames)
            {
                int removedPage = fifoQueue.top();
                fifoQueue.pop();
                pageSet.erase(removedPage);
            }

            fifoQueue.push(page);
            pageSet.insert(page);
            pageFaults++;
        }
    }

    return pageFaults;
}

int OptimalPageReplacement(const vector<int> &referenceString, int numFrames)
{
    unordered_set<int> pageSet;
    //  vector<int> nextUse(referenceString.size(), -1);

    map<int, int> nextUsee;
    int pageFaults = 0;

    for (int i = 0; i < referenceString.size(); i++)
    {

        nextUsee[referenceString[i]] = distance(referenceString.begin(),
                                                find(referenceString.begin() + i + 1,
                                                     referenceString.end(),
                                                     referenceString[i]));

        if (pageSet.find(referenceString[i]) == pageSet.end())
        {
            if (pageSet.size() == numFrames)
            {
                int pageToReplace = -1, farthestUse = -1;
                for (int page : pageSet)
                {
                    if (farthestUse == -1 || nextUsee[page] > farthestUse)
                    {

                        farthestUse = nextUsee[page];
                        pageToReplace = page;
                    }
                }
                pageSet.erase(pageToReplace);
            }

            pageSet.insert(referenceString[i]);
            pageFaults++;
        }

    }

    return pageFaults;
}

int main()
{
    int numFrames, numPages;

    cout << "Enter the number of frames: ";
    cin >> numFrames;

    cout << "Enter the number of pages in the reference string: ";
    cin >> numPages;

    vector<int> referenceString(numPages);

    cout << "Enter the reference string: ";
    for (int i = 0; i < numPages; ++i)
    {
        cin >> referenceString[i];
    }

    int fifoFaults = FIFOPageReplacement(referenceString, numFrames);
    int optimalFaults = OptimalPageReplacement(referenceString, numFrames);
    int lifoFault = LIFOPageReplacement(referenceString, numFrames);

    cout << "FIFO Page Faults: " << fifoFaults << endl;
    cout << "Optimal Page Faults: " << optimalFaults << endl;
    cout << lifoFault << endl;

    return 0;
}
