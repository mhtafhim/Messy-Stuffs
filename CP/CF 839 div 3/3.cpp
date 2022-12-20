
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

        int n,limit;
        cin >> n >> limit;
        vector<int> v;
        int counter =1;
        int index = 1;
        int temp=1;
        int ts;

        while(temp<=limit  &&  counter <= n)
        {


            //    if(temp<=limit)
            //     v.push_back(temp);
            cout << temp<<" " <<counter<< endl;
            if(counter == n && temp ==limit)
            {
                v.push_back(temp);
                break;
            }

            else if(counter == n)
            {
                break;
            }


            v.push_back(temp);
            temp = temp + index;
            counter++;

            index++;
        }
        /*

                ts = v.size();
                if((n-counter)>0)
                {
                    v[ts] = v[ts] - index-1;
                    temp = v[ts-1]+1;
                    //     cout << "bal " << temp << endl;
                    //   int t = n - counter-1;
                    while(counter != n)
                    {
                        counter++;
                        //      cout << "counter   " << counter << endl;
                        v.push_back(temp++);

                    }


                }

        */

        for(auto it:v)
        {
            cout << it << " " ;
        }

        cout << endl;



    }


    return 0;
}
