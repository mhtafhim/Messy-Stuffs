

#include <bits/stdc++.h>

using namespace std;

bool checkNeighour(string s1, string s2)
{
    int len = s1.length();
    if(len!=s2.length())
        return false;

    int dif=0;

    for(int i =0; i<len; i++)
    {
        if(s1[i]!=s2[i])
            dif++;
    }
    if(dif==1)
    {
        cout << s1 << " " << s2 << endl;
        return true;
    }

    else
        return false;

}



int cost[10000];



void bfsOfGraph(int V, vector<int> adj[],int i)
{
    for(int i=0; i<=V; i++)
    {
        cost[i]=0;

    }

    // vector<int> bfs_traversal;
    vector<bool> vis(V, false);



    // To check if already visited
    if (!vis[i])
    {
        queue<int> q;
        vis[i] = true;
        q.push(i);


        while (!q.empty())
        {
            int g_node = q.front();
            //    cout << g_node<< " ";
            q.pop();
            for (auto it : adj[g_node])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    cost[it] = cost[g_node] +1;
                    //   cout << "cost =" << cost[it] << " " << it <<"maximum "<< maximum << endl;

                    //      cout << it<< " ";
                    //    cout << "cost =" << cost[it] << " " << it <<"maximum "<< maximum << endl;
                    q.push(it);
                }
            }
            // cout << endl;
        }
    }


}

bool isPrime(int number)
{

    if (number < 2)
        return false;

    if (number == 2 || number == 3)
        return true;

    if(number % 2 == 0)
        return false;

    int sqr = (int)sqrt(number);
    int dx = 4;

    for (int i = 5; i <= sqr; i+=dx)
    {
        if (number % i == 0)
            return false;
        dx = - (dx - 6);

    }

    return true;
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int  s,d;
    int t;
    t=2;

    stringstream ss;
    string temp,from,to;
    vector<pair<string,int>> dictionary;
    map<string,int> mp;
    int index=1;
    for(int x = 1001 ; x < 10000 ; x=x+2)
    {

        if(isPrime(x))
        {
            temp =  to_string(x);
            cout << temp << " " << index <<endl;
            dictionary.push_back(make_pair(temp,index));
            mp[temp] = index;
            index++;
        }

    }



    vector<int> graph[index];


    for(int i =0; i<dictionary.size(); i++)
    {
        for(int j =0; j<dictionary.size(); j++)
        {
            if( i!=j && checkNeighour(dictionary[i].first,dictionary[j].first))
                //  cout << dictionary[i].second << " " << dictionary[j].second << " " ;
                graph[dictionary[i].second].push_back(dictionary[j].second);
        }
    }



    while(t--)
    {

        cin >> s;
        from =  to_string(s);

        cin>>d;
        to =  to_string(d);


       // cout << from[0] << " " << to[0] << endl;
        int x = mp[from];

        bfsOfGraph(index,graph,x);

        cout <<from<<" "<<to<< " " << cost[mp[to]]<<endl;


    }




return 0;
}
