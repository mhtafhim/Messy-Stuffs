#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int D[10000][10000];
int pi[10000][10000];


void printMatrix(int v)  // this function is to print the matrix
{
     for(int i = 1 ; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            if(D[i][j]==INF)
            {
                cout << "i/N    ";
            }
            else
                cout << D[i][j] << "/" << pi[i][j] << "    ";
        }
        cout << endl;
    }
}


void printPath(int s,int d)
{
    vector<int>path;

    int i = d;
    while(i!=-1)
    {
        path.push_back(i);
        i = pi[s][i];
    }
    reverse(path.begin(),path.end());

    cout << "From " << s << " to " << d <<" : ";
    if(path[0]==s)
    {
        for(auto it : path)
        {
            if(it == s)
            {
                cout << it;
            }
            else
            {
                cout << " -> " << it ;
            }

        }
        cout << " and shorted distance : "<< D[s][d]<< endl;


    }
    else
    {
        cout << "There is no path from "<< s <<" to " << d <<"." << endl;

    }

    path.clear();
}


void warshall(vector<pair<int,int>> adj[], int v)
{
    for(int i = 1 ; i<=v; i++)
    {
        for(auto u : adj[i])
        {

            D[i][u.first] = u.second;
            pi[i][u.first] = i;
        }
    }

  //  cout << "D(0) :" << endl;
   // printMatrix(v);   // printing D(0) matrix



    for(int k = 1 ; k<=v; k++)
    {
        for(int i = 1 ; i<=v; i++)
        {
            for(int j = 1 ; j<=v; j++)
            {
                if(D[i][j]>D[i][k]+D[k][j] && (D[i][k]!=INF || D[k][j]!=INF))
                {
                    pi[i][j] = pi[k][j];
                    D[i][j] = D[i][k]+D[k][j];

                }
            }
        }
    //    cout << endl  <<"D(" <<k<<") : " << endl << endl ;
     //   printMatrix(v);  // printing each matrix in every iteration
    }

}

int main()
{
    int v,e;
 //   cout << "Enter the number of vertices : ";
    cin >> v;
 //   cout << "Enter the number of edges : ";
    cin >>e;
    int s,d,w;
  //  cout << "Now enter all the edges and weights (with separated space) : \n";
//   int adj[v+1][v+1];

    vector<pair<int,int>> adj[v+1];

    for(int i=1; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {

            if(i==j)
            {
                D[i][j] = 0;
            }
            else
            {
                D[i][j] = INF;
            }
            pi[i][j] = -1;


        }
    }


    for(int i =0; i<e; i++)
    {
        cin >> s>>d>>w;
        adj[s].push_back(make_pair(d,w));
        adj[d].push_back(make_pair(s,w));
    }


    warshall(adj,v);

     int q;

    cin >> q;


    while(q--)
    {
        int t1,t2;
        cin >> t1 >> t2;

        cout << D[t1][t2] << endl;

    }


    return 0;
}
