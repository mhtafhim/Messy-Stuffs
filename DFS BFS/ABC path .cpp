#include <bits/stdc++.h>

using namespace std;


int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1}; //8 direction
int dp[51][51];
char grid[51][51];
int H,W;
//int it = 0;


void dfs(int x,int y,int distance)
{
    dp[x][y]= distance+1;
  //  it++;
  //  cout << grid[x][y]  << " : " << dp[x][y]<< endl;

    for(int i = 0; i<8; i++)
    {
        if( grid[x][y]+1 == grid[x+ dx[i]][y+ dy[i]]  && (x + dx[i]) < (H) && (x+ dx[i]) >=0 &&(y + dy[i]) < (W) && (y + dy[i]) >= 0  && dp[x+ dx[i]][y + dy[i]] < dp[x][y] + 1)
        {
            dfs(x+ dx[i],y+ dy[i],dp[x][y]);
        }

    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
//   cin >> t;
    while(true)
    {
        //    int H,W;
        cin >> H>>W;
   //     cout << "fuck" << endl;

        if(H ==0 && W == 0)
        {
            break;
        }


        for(int i =0 ; i<51; i++)
        {
            for(int j =0; j<51; j++)
            {
                dp[i][j] = 0;
            }
        }




        for(int i =0; i<H ; i++)
        {
            for(int j =0 ; j< W ; j++)
            {
                cin>> grid[i][j];
            }
        }

//cout << "you" << endl;


        for(int i=0; i<H; i++)
        {
            for(int j=0; j<W; j++)
            {
                if(grid[i][j] == 'A' && dp[i][j] == 0)
                    dfs(i, j, 0);
            }
        }




        int maxi = dp[0][0];

        for(int i =0 ; i<H; i++)
        {
            for(int j =0; j<W; j++)
            {
                //     cout << dp[i][j] << " " ;
                if(dp[i][j]>maxi)
                    maxi = dp[i][j];
            }
            //   cout << endl;
        }


        printf("Case %d: %d\n", t, maxi);
        //   cout <<"Case " << t << ": " <<len << endl;
     //   cout <<"Case " << t << ": " <<maxi << endl;
     //   cout << it << endl;
        t++;


    }


    return 0;
}

