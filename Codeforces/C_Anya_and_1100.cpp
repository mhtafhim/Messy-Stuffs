#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool has1100(const string &s, int pos) {
    return pos >= 0 && pos + 3 < s.size() && s.substr(pos, 4) == "1100";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;

        int count1100 = 0;

        for (int i = 0; i + 3 < s.size(); ++i) {
            if (has1100(s, i)) {
                ++count1100;
            }
        }

    
        while (q--) {
            int i;
            char v;
            cin >> i >> v;
            --i;  
           
            for (int j = i - 3; j <= i; ++j) {
                if (has1100(s, j)) {
                    --count1100;
                }
            }

          
            s[i] = v;

       
            for (int j = i - 3; j <= i; ++j) {
                if (has1100(s, j)) {
                    ++count1100;
                }
            }

          
            cout << (count1100 > 0 ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
