
#include <bits/stdc++.h>

using namespace std;

int cost[10000];
bool vis[10000];

int arr[] = {1,10,100,1000,-1,-10,-100,-1000};

/*
void printPath(map<int,int> &prev, int v)
{
    int u = prev[v];
    cout << v << endl;

    if (u != v)
        printPath(prev, u);

}

*/

bool checkNeighour(string s1, string s2)
{
    int len = s1.length();
    if(len!=s2.length())
        return false;

    int dif=0;

    for(int i =0; i<len; i++)
    {
        if(s1[i]!=s2[i])
            dif++;
    }
    if(dif==1)
        return true;
    else
        return false;

}


bool isPrime(int n) {
    if (n == 1) {
        return false;
    }

    int i = 2;
    while (i*i <= n) {

        if (n % i == 0) {
            return false;
        }
        i += 1;
    }

    return true;
}



void bfsOfGraph(int a,int b)
{
    for(int i=1000; i<10000; i++)
    {

        cost[i]=0;
        vis[i] = false;
    }

    int pr;
    // To check if already visited
    if (!vis[a])
    {
    //    map<int ,int> prev;
        queue<int> q;
        vis[a] = true;
        q.push(a);
    //    prev[a] = a;


        while (!q.empty() && !vis[b])
        {
            pr = q.front();
            //    cout << g_node<< " ";
            q.pop();
            for (int i =0; i<8; i++)
            {

                for(int j =1; j<10; j++)
                {

                    int temp = pr - (arr[i]*j) ;
                    string temp1 =  to_string(pr);
                    string temp2 = to_string(temp);


                    if(!vis[temp] && isPrime(temp) && temp <10000 && temp > 999 && temp !=pr && checkNeighour(temp1,temp2))
                    {
                        //     cout << pr.first+xx[i] << " " << pr.second+yy[i] << endl;
                     //   cout << temp <<endl;
                   //     prev[temp] = pr;
                        vis[temp] = true;
                        cost[temp] = cost[pr] +1;
                        q.push(temp);


                    }

                }

            }
        }
   //      printPath(prev, b);
    //        cout << endl;
    }


}





int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>a>>b;


        bfsOfGraph(a,b);

        cout << cost[b] << endl;

    }





    return 0;
}
