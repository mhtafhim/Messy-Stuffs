#include<bits/stdc++.h>


using namespace std;


const int INF = 1e7;
int D[1000][1000];
int pi[1000][1000];
//int adj[1000][1000];

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

    cout << "D(0) :" << endl;
    for(int i = 1 ; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            if(D[i][j]>INF-1000)
            {
                cout << "i/N    ";
            }
            else
                cout << D[i][j] << "/" << pi[i][j] << "    ";
        }
        cout << endl;
    }



    for(int i = 1 ; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            for(int k = 1 ; k<=v; k++)
            {
                if(D[j][k]>D[j][i]+D[i][k])
                {
                    pi[j][k] = pi[i][k];
                    D[j][k] = D[j][i]+D[i][k];

                }
            }
        }
        cout << endl  <<"D(" <<i<<") : " << endl << endl ;
        for(int i = 1 ; i<=v; i++)
        {
            for(int j = 1 ; j<=v; j++)
            {
                if(D[i][j]>INF-1000)
                {
                    cout << "i/N    ";
                }
                else
                    cout << D[i][j] << "/" << pi[i][j] << "    ";
            }
            cout << endl;
        }
    }

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
    }


    warshall(adj,v);


    cout <<endl<< "Final Output Matrix : " << endl;

    for(int i = 1 ; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            if(D[i][j]>INF-1000)
            {
                cout << "i/N    ";
            }
            else
                cout << D[i][j] << "/" << pi[i][j] << "    ";
        }
        cout << endl;
    }




    cout << endl;

    /* for(int i =1; i<=v; i++)
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



1 2 3
1 3 8
1 5 -4
2 4 1
2 5 7
3 2 4
4 1 2
4 3 -5
5 4 6
*/
