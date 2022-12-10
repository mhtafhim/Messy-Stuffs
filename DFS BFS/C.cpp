#include <bits/stdc++.h>

using namespace std;

int cost[9][9];
bool vis[9][9];

//int xy[][] = {(-2,-1),(-1,-2),(1,-2),(1,-1),(2,1),(1,2),(-1,1),(-1,2)};
int xx[] = {1,2,2,1,-2,-1,-1,-2};
int yy[] = {2,1,-1,-2,-1,-2,2,1};

void bfsOfGraph(int a,int b,int ad,int bd)
{
    for(int i=0; i<=8; i++)
    {
        for(int j=0; j<=8; j++)
        {
            cost[i][j]=0;
            vis[i][j] = false;
        }


    }

    pair<int,int> pr;


    // To check if already visited
    if (!vis[a][b])
    {
        queue<pair<int,int>> q;
        vis[a][b] = true;
        q.push(make_pair(a,b));


        while (!q.empty() && !cost[ad][bd])
        {
            pr = q.front();
            //    cout << g_node<< " ";
            q.pop();
            for (int i =0; i<8; i++)
            {

                if(!vis[pr.first+xx[i]][pr.second+yy[i]] && pr.first+xx[i] > 0 && pr.first+xx[i] < 9 && pr.second+yy[i] > 0 && pr.second+yy[i] < 9)
                {
                    //     cout << pr.first+xx[i] << " " << pr.second+yy[i] << endl;
                    vis[pr.first+xx[i]][pr.second+yy[i]] = true;
                    cost[pr.first+xx[i]][pr.second+yy[i]] = cost[pr.first][pr.second] +1;
                    q.push(make_pair(pr.first+xx[i],pr.second+yy[i]));

                }
            }
        }
    }


}





int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);




    int grid[9][9];
    string s,d;

    int t;
    t=1;
//   cin >> t;
    while(cin >>s>>d)
    {


        int a = s[0] - 96 ;
        int b = s[1] - 48 ;
        int ad = d[0] - 96 ;
        int bd = d[1] - 48 ;

        //  cout << a << " " << b << " " << ad << " " << bd << endl;
        bfsOfGraph(a,b,ad,bd);

        cout  << "To get from " << s <<" to " << d << " takes " <<cost[ad][bd]<<" knight moves."<<endl;



    }






    return 0;
}
