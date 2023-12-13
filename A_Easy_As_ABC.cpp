#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // 8 direction
vector<string> s(3);
bool vis[3][3];
int cost[3][3];
char parent[3][3];

set<string> st;
string ss;

void bfs(int x, int y)
{

    cout << "ok 1" << endl;

    vector<char> vs;
    vector<pair<int, int>> prv;
    // vector<pair<char,pair<int,int>>> vv;
    int inx, iny;
  //  char mn = s[x][y];
    char mn = 'C';
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << i << endl;
        if ((x + dx[i]) < 3 && (x + dx[i]) >= 0 && (y + dy[i]) < 3 && (y + dy[i]) >= 0)
        {
            if (mn > s[x + dx[i]][y + dy[i]])
            {
                mn = s[x + dx[i]][y + dy[i]];
            }
        }
    }
    cout << mn << endl;
   

    for (int i = 0; i < 8; i++)
    {
        if ((x + dx[i]) < 3 && (x + dx[i]) >= 0 && (y + dy[i]) < 3 && (y + dy[i]) >= 0)
        {
            if (mn == s[x + dx[i]][y + dy[i]])
            {
                vs.push_back(mn);
                prv.push_back({x + dx[i], y + dy[i]});
                cnt++;
            }
        }
    }

    cout << "ok 2" << endl;
    for (auto u : prv)
        cout << u.first << " " << u.second << endl;
}

void solve(int cs)
{

    for (int i = 0; i < 3; i++)
        cin >> s[i];

    bfs(2, 2);

    // cout << s[0][0];
}

int main()
{
    fast;
    int t = 1;
    //    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i  << ":\n";
        solve(i);
    }
    return 0;
}
