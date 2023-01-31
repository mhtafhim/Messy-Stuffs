#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int INF = 999999999;

int m[5][5] = {0};
int s[5][5] = {0};

void printPath(int i,int j)
{
    if(i==j)
    {
        cout << "A" << i;
        return;
    }

    else
        cout << "(";
    printPath(i,s[i][j]);
    printPath(s[i][j],j);

    cout << ")";
}



int main()
{

    fast

    int n = 5;
    int p[] = {5,4,6,2,7};

    int j,minimum,q;
//   cout << INF << endl;
    for(int d = 1; d<n-1; d++)
    {
      //  cout << "d = " << d << " ";
        for(int i = 1 ; i < n-d ; i++)
        {
            j = i+d;
            minimum = INF;
        //    cout << "i = " << i << " ";

            for(int k=1; k<=j-1; k++)
            {
             //   cout << "k = " << k << " j = "<< j<<endl;

                cout << i-1 << "  "<<k<< " "<<j<<endl;
              //  cout << p[i-1]<< "  "<<p[k]<< " "<<p[j]<<endl;
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
           //     cout << q << "  and  "<< minimum << endl;
                if(q<minimum)
                {
                    minimum = q;
                    s[i][j] = k;

                }
            }
            m[i][j] = minimum;
        }



    }


     for(int a=1; a<n; a++)
        {
            for(int b=1; b<n; b++)
            {
                cout <<setw(10)<< m[a][b] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;




 //   printPath(1,4);





    cout << m[1][n-1] << endl;


    return 0;
}

