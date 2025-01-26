#include<bits/stdc++.h>
#define ll                    long long
#define lli                   long long int
#define ld                    long double
#define lld                   long long double
#define ui                    unsigned int
#define ull                   unsigned long long
#define vi                    vector<int>
#define vs                    vector<string>
#define vl                    vector<long>
#define vll                   vector<long long>
#define pb                    push_back
#define pp                    pop_back
#define pll                   pair<int, int>
#define pii                   pair<int,int>
#define pll                   pair<ll,ll>
#define psi                   pair<string,int>
#define psl                   pair<string,ll>
#define pci                   pair<char,int>
#define pcl                   pair<char,ll>
#define mii                   map<int,int>
#define si                    set<int>
#define sl                    set<ll>
#define msi                   multiset<int>
#define msl                   multiset<ll>
#define spb                   insert
#define qi                    queue<int>
#define pqi                   priority_queue<int>
#define all(a)                sort(a.begin(),a.end())
#define all(ar)               sort(ar.begin(),ar.end())
#define all(v)                sort(v.begin(), v.end())
#define all(x)                x.begin(),x.end()
#define rall(a)               reverse(a.begin(),a.end())
#define YES                   printf("YES\n")
#define NO                    printf("NO\n")
#define nl                    printf("\n")
#define endl                  '\n'
#define yes                   cout << "Yes" << endl;
#define no                    cout<<"No"<<endl;
#define e4                    int main()
#define INF                   LLONG_MAX
 
#define erase_duplicates(x)   x.erase(unique(all(x)),x.end());
#define Faster                ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fast                  ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
//ll gcd(ll a, ll b) {while(b){a%=b; swapx<ll>(a,b); } return a;}
//ll lcm(ll a, ll b) {return (a * 1ll * b) / gcd(a,b);}#include<iostream>
 
using namespace std;
const ll inf = (ll)1e18;
const ll mod = (ll)1e9+7;
 
 
 
#define Mod 1000000007
// Function to calculate GCD
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// Function to calculate LCM
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
//ceil value
int ceil(int a,int b)
{
    return (a+b-1)/b;
}
///*** BITS ***///
void binaryNum(int num) ///*** Print Binary Number ***///
{
    for(int i=31; i>=0; i--)
    {
        cout << ((num>>i) & 1);
    }
    cout << endl;
}
 
ll binary_str_to_dec(string s)
{
    ll dec_num = 0,p=0;
 
    for(ll i = s.size()-1; i >= 0; i--)
    {
        if(s[i] == '1')
        {
            dec_num+= pow(2,p);
        }
        p++;
    }
 
    return dec_num;
}
//---BIT--
bool Bit_set_unset_check(int num,int bit_number_check)
{
    if((num & (1 << bit_number_check)) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Set-Bit
void Bit_set(int num,int set_bit)
{
    binaryNum(num | (1<<set_bit));
}
//Unset-Bit
void Bit_unset(int num,int unset_bit)
{
    binaryNum(num & (~(1 << unset_bit)));
}
//Toggle-Bit
void Bit_toggle(int num,int toggle_bit)
{
    binaryNum(num ^ (1 << toggle_bit));
}
//Set-Bit-Count
//Builtin Function = __builtin_popcount(num);
//Builtin Function = __builtin_popcountll(num);
 
int set_Bit_cnt(int num)
{
    int cnt = 0;
    for(int i=31; i>=0; i--)
    {
        if((num & (1 << i)) != 0)
        {
            cnt++;
        }
    }
    return cnt;
}
//Unset-Bit-Count
int unset_Bit_cnt(int num)
{
    int cnt = 0;
    for(int i=31; i>=0; i--)
    {
        if((num & (1 << i)) == 0)
        {
            cnt++;
        }
    }
    return cnt;
}
///*** BINARY EXPONENTITAION ***///
//recursive method of binary exponentiation or power calculate
int binExp(int a, int b)
{
    if(b==0) return 1;
    int res = binExp(a, b/2);
    if(b&1) return (a*(res*res)); //odd
    else return (res*res); //even
}
 
ll power(ll base,ll n,ll mod)
{
    ll result = 1;
    while(n)
    {
        if(n%2 != 0)
        {
            result=(result*base)%mod; /// mod = 1e9
            n--;
        }
        else
        {
            base=(base*base)%mod;  /// if need last digit use 10 base
            n/=2;
        }
    }
 
    return result;
}
int binEp(int a, int b, int m)
{
    int result = 1;
    while(b>0)
    {
        if(b&1)
        {
            result = (result*1LL*a)%m;
        }
        a = (a*1LL*a)%m;
        b>>=1;
    }
    return result;
}
///Modular m.Inverse calculate
ll powerMod(ll a, ll b)
{
    if(b==0)return 1;
 
    if(b%2==0)
    {
        ll x = powerMod(a, b/2);
        return (x*x)%Mod;
    }
    else
    {
        ll x = powerMod(a, b/2);
        return ((x*x)%Mod * a)%Mod;
    }
 
    return 0;
}
 
ll inverseMod(ll a)
{
    return powerMod(a, Mod-2);
}
 
 
//Big-Mod
bool big_mod(string num, ll a)
{
 
    // Initialize result
    ll res = 0;
 
    // One by one process all digits of 'num'
    for (ll i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
 
    if(res == 0) return true;
    else return false;
 
}
//Divisor-Number
 
// PRIME NUMBER TEST//
bool prime(int n)
{
    if(n<2)return false;
    if(n<=3)return true;
    if(n%2==0)return false;
    for(int i=3; i*i<=n; i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}
 
//Graph Grid
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
 
/*
 
bool ispair(ll m){
 
    ll x = m;
 
    while(x--){
        ll res = x%10;
        if(res != 0 && m%res != 0)return false;
        x = x/10;
    }
 
    return true;
}
*/