#include<bits/stdc++.h>


using namespace std;


const int INF = 1e7;
int D[1000][1000];
int pi[1000][1000];
int adj[1000][1000];

void warshall(int v)
{
    for(int i = 1 ; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            if(adj[i][j]!=0)
            {
                D[i][j] = adj[i][j] - adj[i][i];
                pi[i][j] = i;
            }
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
            else cout << D[i][j] << "/" << pi[i][j] << "    ";
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
            else cout << D[i][j] << "/" << pi[i][j] << "    ";
        }
        cout << endl;
    }
    }

}

/*

void printPath(int s,int d)
{
    vector<int>path;
    /* if(parents[d]==(-1))
     {
         cout << "From " << s << " to " << d <<" : ";
         cout << "Cant reach there." << endl;
         return;
     }

    int i = d;
    while(i!=-1)
    {
        path.push_back(i);
        i = parents[i];
    }
    //  path.push_back(s);


    reverse(path.begin(),path.end());


    cout << "From " << s << " to " << d <<" : ";
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

    cout << " and shorted distance : "<< cost[d]<< endl;

    path.clear();
}
 */

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

    for(int i=1; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            adj[i][j] = 0;
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
        adj[s][d] = w;
    }


    warshall(v);


    cout <<endl<< "Final Output Matrix : " << endl;

    for(int i = 1 ; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            if(D[i][j]>INF-1000)
            {
                cout << "i/N    ";
            }
            else cout << D[i][j] << "/" << pi[i][j] << "    ";
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
