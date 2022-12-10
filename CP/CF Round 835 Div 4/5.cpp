
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> v(n);
        int countzero =0,countone=0;

        for(int i =0; i<n; i++)
        {
            cin >> v[i];
            if(v[i]==0)
                countzero++;
            else
                countone++;
        }

        if(countone>countzero)
        {
            int temp = n-1;
            while(1)
            {
                if(v[temp]==1)
                {
                    if(temp == 0)
                        break;
                    v[temp]= 0;
                    break;
                }
                temp--;
            }

        }
        else
        {
            if(v[0]==0)
            {
                v[0]=1;

            }
            else
            {
                int temp = n-1;
                while(1)
                {
                    if(v[temp]==1)
                    {
                        if(temp == 0)
                            break;
                        v[temp]= 0;
                        break;
                    }
                    temp--;
                }
            }

        }



        int counter =0;
        for(int i =0; i<n; i++)
        {
            if(v[i]==1)
            {
                for(int j=i+1; j<n; j++)
                {
                    if(v[j]==0)
                        counter++;
                }
            }
        }
        cout << counter << endl;

    }




    return 0;
}
