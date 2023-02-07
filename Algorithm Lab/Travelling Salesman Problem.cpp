#include<bits/stdc++.h>

using namespace std;
typedef pair<double,double> pr;

const int inf = INT_MAX;



vector<bool> vis(1000,false);
typedef vector<vector<int>> matrix;
typedef pair<int,int> int_pr;
typedef pair<int,matrix> costMatrixPair;

priority_queue<pair<costMatrixPair,int_pr>> pq;


void reduce(vector<vector<int>> adj,int n,int x,int y,int base)
{

    cout << adj[x][y] << endl;

    int cost = adj[x][y];

    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {

            if(i==x || j == y)
                adj[i][j] = inf;
        }
    }



    adj[y][x] = inf;



    int totalsum = 0,rowsum =0,colsum=0;

    for(int i =0; i<n; i++)
    {
        int mn = INT_MAX;

        for(int j =0; j<n; j++)
        {
            if(adj[i][j]!=inf && adj[i][j] < mn)
            {
                mn = adj[i][j];
            }
        }
        //    cout << mn << "  ";
        if(mn!=inf)
            rowsum+=mn;

        for(int j =0; j<n; j++)
        {
            if(adj[i][j]!=inf)
            {
                adj[i][j] =  adj[i][j] - mn;
            }
        }
    }




    for(int i =0; i<n; i++)
    {
        int mn = INT_MAX;
        for(int j =0; j<n; j++)
        {
            if(adj[j][i]!=inf && adj[j][i] < mn)
            {
                mn = adj[j][i];
            }
        }
        //   cout << mn << "  ";
        if(mn!=inf)
            colsum+=mn;

        for(int j =0; j<n; j++)
        {
            if(adj[j][i]!=inf)
            {
                adj[j][i] =  adj[j][i] - mn;
            }
        }
    }



    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(adj[i][j]!=inf)
                cout << setw(5) <<  adj[i][j] << "  " ;
            else
                cout << "   inf" ;
        }
        cout << endl;
    }


    totalsum = rowsum + colsum;

    cout << cost << " " << base << " " << totalsum << " " << endl;
    cost+= base + totalsum;
    cout << "Sum :  "<< cost << endl;

    pq.push({{(-1)*cost,adj},{x,y}});



}




int main()
{

    int n=5;

    //  int adj[n][n];
    vector<vector<int>> adj(n);


    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            int temp;
            cin >> temp;
            if(i!=j)
                adj[i].push_back(temp);
            else
                adj[i].push_back(inf);
        }
    }





    int totalsum = 0,rowsum =0,colsum=0;

    for(int i =0; i<n; i++)
    {
        int mn = INT_MAX;

        for(int j =0; j<n; j++)
        {
            if(i!=j && adj[i][j] < mn)
            {
                mn = adj[i][j];
            }
        }
        //    cout << mn << "  ";
        rowsum+=mn;

        for(int j =0; j<n; j++)
        {
            if(i!=j)
            {
                adj[i][j] =  adj[i][j] - mn;
            }
        }
    }




    for(int i =0; i<n; i++)
    {
        int mn = INT_MAX;
        for(int j =0; j<n; j++)
        {
            if(i!=j && adj[j][i] < mn)
            {
                mn = adj[j][i];
            }
        }
        //   cout << mn << "  ";
        colsum+=mn;

        for(int j =0; j<n; j++)
        {
            if(i!=j)
            {
                adj[j][i] =  adj[j][i] - mn;
            }
        }
    }


    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(i!=j)
                cout << setw(5) <<  adj[i][j] << "  " ;
            else
                cout << "   inf" ;
        }
        cout << endl;
    }



    totalsum = rowsum + colsum;
    cout << "Base sum :  "<< totalsum << endl;

    int source = 1;
    vis[source-1] = true;
    for(int k =source+1; k<=n; k++)
    {
        // cout << k << " ";

        reduce(adj,n,1-1,k-1,totalsum);
    }

    pair<costMatrixPair,int_pr> temp;
     //typedef pair<int,matrix> costMatrixPair;


     /*
    while(!pq.empty())
    {
        temp = pq.top();
        for(int k =source+1; k<=n; k++)
        {
            if(!vis[temp.second.first] && temp.second.second!=k)
                reduce(adj,n,temp.second.second-1,k);
                //reduce(vector<vector<int>> adj,int n,int x,int y,int base)
        }



    }
    */


    return 0;
}

