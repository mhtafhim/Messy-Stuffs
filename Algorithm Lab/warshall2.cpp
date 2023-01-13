#include<bits/stdc++.h>


using namespace std;


const int INF = 1e9;
int D[1000][1000];
int pi[1000][1000];
//int adj[1000][1000];


void printMatrix(int v)
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
    /* if(parents[d]==(-1))
     {
         cout << "From " << s << " to " << d <<" : ";
         cout << "Cant reach there." << endl;
         return;
     }
     */
    int i = d;
    while(i!=-1)
    {
        path.push_back(i);
        i = pi[s][i];
    }
    //  path.push_back(s);


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

    cout << "D(0) :" << endl;
    printMatrix(v);



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
        cout << endl  <<"D(" <<k<<") : " << endl << endl ;
        printMatrix(v);
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

    printMatrix(v);



    cout << endl;


    for(int i = 1 ; i<=v; i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            printPath(i,j);

        }
        cout << endl;
    }

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


Output Screen :

Enter the number of vertices : 5
Enter the number of edges : 9
Now enter all the edges and weights (with separated space) :
1 2 3
1 3 8
1 5 -4
2 4 1
2 5 7
3 2 4
4 1 2
4 3 -5
5 4 6
D(0) :
0/-1    3/1    8/1    i/N    -4/1
i/N    0/-1    i/N    1/2    7/2
i/N    4/3    0/-1    i/N    i/N
2/4    i/N    -5/4    0/-1    i/N
i/N    i/N    i/N    6/5    0/-1

D(1) :

0/-1    3/1    8/1    i/N    -4/1
i/N    0/-1    i/N    1/2    7/2
i/N    4/3    0/-1    i/N    999999996/1
2/4    5/1    -5/4    0/-1    -2/1
i/N    i/N    i/N    6/5    0/-1

D(2) :

0/-1    3/1    8/1    4/2    -4/1
i/N    0/-1    i/N    1/2    7/2
i/N    4/3    0/-1    5/2    11/2
2/4    5/1    -5/4    0/-1    -2/1
i/N    i/N    i/N    6/5    0/-1

D(3) :

0/-1    3/1    8/1    4/2    -4/1
i/N    0/-1    i/N    1/2    7/2
i/N    4/3    0/-1    5/2    11/2
2/4    -1/3    -5/4    0/-1    -2/1
i/N    i/N    i/N    6/5    0/-1

D(4) :

0/-1    3/1    -1/4    4/2    -4/1
3/4    0/-1    -4/4    1/2    -1/1
7/4    4/3    0/-1    5/2    3/1
2/4    -1/3    -5/4    0/-1    -2/1
8/4    5/3    1/4    6/5    0/-1

D(5) :

0/-1    1/3    -3/4    2/5    -4/1
3/4    0/-1    -4/4    1/2    -1/1
7/4    4/3    0/-1    5/2    3/1
2/4    -1/3    -5/4    0/-1    -2/1
8/4    5/3    1/4    6/5    0/-1

Final Output Matrix :
0/-1    1/3    -3/4    2/5    -4/1
3/4    0/-1    -4/4    1/2    -1/1
7/4    4/3    0/-1    5/2    3/1
2/4    -1/3    -5/4    0/-1    -2/1
8/4    5/3    1/4    6/5    0/-1

From 1 to 1 : 1 and shorted distance : 0
From 1 to 2 : 1 -> 5 -> 4 -> 3 -> 2 and shorted distance : 1
From 1 to 3 : 1 -> 5 -> 4 -> 3 and shorted distance : -3
From 1 to 4 : 1 -> 5 -> 4 and shorted distance : 2
From 1 to 5 : 1 -> 5 and shorted distance : -4

From 2 to 1 : 2 -> 4 -> 1 and shorted distance : 3
From 2 to 2 : 2 and shorted distance : 0
From 2 to 3 : 2 -> 4 -> 3 and shorted distance : -4
From 2 to 4 : 2 -> 4 and shorted distance : 1
From 2 to 5 : 2 -> 4 -> 1 -> 5 and shorted distance : -1

From 3 to 1 : 3 -> 2 -> 4 -> 1 and shorted distance : 7
From 3 to 2 : 3 -> 2 and shorted distance : 4
From 3 to 3 : 3 and shorted distance : 0
From 3 to 4 : 3 -> 2 -> 4 and shorted distance : 5
From 3 to 5 : 3 -> 2 -> 4 -> 1 -> 5 and shorted distance : 3

From 4 to 1 : 4 -> 1 and shorted distance : 2
From 4 to 2 : 4 -> 3 -> 2 and shorted distance : -1
From 4 to 3 : 4 -> 3 and shorted distance : -5
From 4 to 4 : 4 and shorted distance : 0
From 4 to 5 : 4 -> 1 -> 5 and shorted distance : -2

From 5 to 1 : 5 -> 4 -> 1 and shorted distance : 8
From 5 to 2 : 5 -> 4 -> 3 -> 2 and shorted distance : 5
From 5 to 3 : 5 -> 4 -> 3 and shorted distance : 1
From 5 to 4 : 5 -> 4 and shorted distance : 6
From 5 to 5 : 5 and shorted distance : 0


Process returned 0 (0x0)   execution time : 14.513 s
Press any key to continue.



  */
