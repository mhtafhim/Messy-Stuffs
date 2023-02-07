#include <bits/stdc++.h>

using namespace std;

int V[1000][1000];
vector<int>ans;





int main()
{
    int n;
    n=4;
    int b[]={3,4,5,6},weight[] = {2,3,4,5};

    int maximum = 5;

    for(int i=0;i<=maximum;i++)
    {
        V[0][i] = 0;
    }
    for(int i=0 ; i<= n ; i++)
    {
        V[i][0] = 0;
    }

    for(int i =1 ; i<=n;i++)
    {
        for(int w=1;w<=maximum ; w++)
        {
            if(weight[i-1]<= w)
            {
                if(b[i-1]+V[i-1][w-weight[i-1]] > V[i-1][w])
                {
                    V[i][w] = b[i-1] + V[i-1][w-weight[i-1]] ;
                }
                else
                {
                     V[i][w] = V[i-1][w];
                }
            }
            else
            {
                V[i][w] = V[i-1][w];
            }
        }
    }


/*
     for(int i =0;i<=4;i++)
    {
        for(int j = 0;j<=5;j++)
        {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
*/

    cout << "Maximum benefit : " << V[4][5] << endl;

   int i=n , k = maximum,cnt;

   while(i>0)
   {
       if(V[i][k]!=V[i-1][k])
       {
           ans.push_back(i-1);
           i--;
           k -= weight[i-1];

       }
       else
       {
           i--;
       }
   }


   for(auto it : ans)
   {
       cout << weight[it] << " ";
   }



 //  cout << "running " ;


   return 0;
}
