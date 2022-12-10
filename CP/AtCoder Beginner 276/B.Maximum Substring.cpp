#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        //    vector <int> v;
        long long counter1=0,counter2=0;
        long long final1 = 0, character = 0;
        char save ;
        unsigned long long int ans1 = 0,ans2 = 0;
        bool x = true,y = true;
        char temp;
        cin >> temp;
        //  v.push_back(temp);
        save = temp;

        for(long long i =1 ; i < n ; i++)
        {

            if(temp == '1' )
            {
                counter1++;

            }
            else
            {
                counter2++;

            }

            if(save == temp)
                character++;

            else
            {
                if(character> final1)
                    final1= character;

                character=1;
                save=temp;
            }

            cin >> temp;

        }



        if(temp == '1' )
        {
            counter1++;

        }
        else
        {
            counter2++;

        }

        if(save == temp)
            character++;

        else
        {
            if(character> final1)
                final1 = character;

            character=0;
            save=temp;
        }

        if(character> final1)
            final1 = character;

     //   cout << counter1 << " " << counter2 << " " << final1  << endl;


        ans1 = counter1* counter2;
        ans2 = final1 * final1;



        if(ans2>ans1)
        {
            cout << ans2<< endl;
        }
        else
        {
            cout << ans1 << endl;
        }



    }



    return 0;

}
