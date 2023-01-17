#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

bool visited[1000] = {false};
vector<int> parents(1000,-1);
vector<long long>cost(1000,INF);
//int it= 0;

void prims(vector<pair<int,int>> adj[],int v,int n)
{
    // visited[v] = true;

    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,v));

    while(!q.empty())
    {


        int n = q.top().second;
        q.pop();
        if(!visited[n])
        {
            //    cout << "visiting " <<n << " with distance " << q.top().first << endl;
            visited[n] = true;

            for(auto u : adj[n])
            {
                //     it++;
                if(!visited[u.first])
                    if(cost[u.first] > u.second)
                    {
                        q.push(make_pair((-1)*(u.second),u.first));
                        //         cout  << "               pushing " << u.first << " with distance " <<  cost[n]+u.second << endl;
                        cost[u.first] = u.second;
                        parents[u.first] = n ;
                    }
            }
        }

    }

    cout << endl;

    for (int i = 1; i <= n; ++i)
    {
        if(i==v) continue;

        printf("%d - %d and Weight = %d\n", parents[i], i,cost[i]);
    }

}



void add_edge(vector<pair<int,int>> adj[],int s,int d,int w)
{
    adj[s].push_back(make_pair(d,w));
    adj[d].push_back(make_pair(s,w));
}

int main()
{
    int v,e;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "Enter the number of edges : ";
    cin >>e;
    int s,d,w;
    cout << "Now enter all the edges and weights (with separated space) : \n";
    vector<pair<int,int>> adj[v+1];
    for(int i =0; i<e; i++)
    {
        cin >> s>>d>>w;
        add_edge(adj,s,d,w);
    }


    int source;
    cout << "Enter the source : ";
    cin>> source;
    cost[source] =0;

    prims(adj,source,v);

    cout << endl;



    /*
    for(int i =1; i<=v; i++)
    {
        cout << cost[i] << "/" << parents[i] << " " ;
    }



        for(int i =1; i<=v; i++)
        {
            printPath(source,i);
        }

        // cout << endl << it << endl;

    */

    return 0;
}


/*
1 2 2
1 4 4
4 2 1
2 8 5
4 8 3
3 2 3
3 5 2
4 3 3
5 2 4
2 7 3
8 7 4
8 6 1
*/
