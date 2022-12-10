#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int k = 1; k<=t; k++)
    {
        int n;
        cin>>n;
        int inBus=0;
        int maxi = 0,maxStop=0;
        bool f = true;
        for(int i =0; i<n; i++)
        {
            int in,out;
            cin>>in >> out;
            inBus = inBus-out;
            if(inBus==0)
            {
                if(maxi<maxStop)
                    maxi = maxStop;
                maxStop=0;
                f= false;
            }

            inBus = inBus+in;
            maxStop++;

        }
        if(f == true)
            cout<< "Case " << k <<": "<< maxStop << endl;
        else
        {
            cout<< "Case " << k <<": "<< maxi << endl;
        }

    }
    return 0;
}
