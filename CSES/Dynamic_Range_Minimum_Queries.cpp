#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define inf 1e18


#define mx 1000000
ll arr[mx];
ll tree[mx * 3];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left] , tree[Right]);
}

ll query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 1e9; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return min(p1,p2); //বাম এবং ডান পাশের যোগফল
}

void update(int node, int b, int e, int i, ll newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] =  min(tree[Left] , tree[Right]);
}


void solve(int cs){

    int n,q;
    cin >> n >> q;

    for(int i= 1 ; i <= n ; i ++)
    {
        cin >> arr[i];
    }
    init(1,1,n);

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            ll a , b;
            cin >> a >> b;
            update(1,1,n,a,b);
        }
        else
        {
            ll a , b;
            cin >> a >> b;
            ll ans = query(1,1,n,a,b);
            cout << ans << endl;;

        }
    }
    
}

int main(){
    fast;
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++)
    {
       // cout << "Case " << i  << ":\n";
        solve(i);
    } 
    return 0;
}
