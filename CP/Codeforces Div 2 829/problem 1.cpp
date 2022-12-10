#include<bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >>n;
        char temp ;
        stack< char> st;
  //      char arr[n];
     //   int countQ=0;
      //  int countA =0;
        for(int i =0; i<n ; i++)
        {

            cin >> temp ;

            if(temp == 'Q')
                st.push(temp);
            else if(temp == 'A' && !st.empty())
                st.pop();


        }

        //  cout << countQ << " " << countA << endl;
      //  cout << st.empty() << " " << st.size() << endl;
        if(st.empty())
            cout<< "Yes"<<endl;
        else
            cout << "No"<<endl;


    }

    return 0;
}
