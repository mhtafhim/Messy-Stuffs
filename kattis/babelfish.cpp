#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
#define inf 1e18

void solve(int cs)
{

    std::map<std::string, std::string> transformations;

  //  std::cout << "Enter words and their Pig Latin equivalents (separated by a space):" << std::endl;

    std::string input;
    while (std::getline(std::cin, input) && !input.empty())
    {
        // Use a stringstream to extract the original word and its Pig Latin equivalent
        std::istringstream iss(input);
        std::string originalWord, pigLatinWord;
        iss >> originalWord >> pigLatinWord;

        // Store the mapping in the map
        transformations[pigLatinWord] = originalWord;
    }

    string s;

     while (getline(std::cin, s))
    {
        if (s.empty())
            break;

        if(transformations.count(s))
            cout << transformations[s] << endl;
        else
            cout << "eh" << endl;
    }

    
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
