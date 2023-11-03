#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

void solve(){
	int n; cin>>n;
//	multiset<pi>st;
	multiset<int>L,R;
	for(int i=1; i<=n; i++){
		char ch; cin>>ch;
		int l,r; cin>>l>>r;
		if(ch == '+'){
		//	st.insert(pi(l,r));
			L.insert(l);
			R.insert(r);
		}
		else{
			//st.erase(st.find(pi(l,r)));
			L.erase(L.find(l));
			R.erase(R.find(r));
		}
		if(L.size() < 2) cout<<"NO"<<'\n';
		else{
        //    cout << *R.begin() << " " << *L.rbegin() << endl;
			if(*R.begin() < *L.rbegin()) cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	//cin >> t;
	while(t--) solve();
}