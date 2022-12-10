
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
        return true;
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





int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    string s,d,str;
    int t;
    t=1;
    cin >> t;
    while(t--)
    {
        vector<pair<string,int>> dictionary;
        map<string,int> mp;
        int index=1;
        while(1)
        {
            string temp;
            cin>> temp;
            if(temp == "*")
                break;
            dictionary.push_back(make_pair(temp,index));
            mp[temp] = index;
            index++;


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

        cin.ignore();


        while (getline(cin, str), str != "")
        {


            stringstream ss(str);
            ss >> s >> d;



            int x = mp[s];

            bfsOfGraph(index,graph,x);

            cout <<s<<" "<<d<< " " << cost[mp[d]]<<endl;


        }

        if (t)
            cout << "\n";


    }


    return 0;
}
