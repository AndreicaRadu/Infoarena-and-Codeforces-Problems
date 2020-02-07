#include <iostream>
#include <string>
#include <map>
using namespace std;
 
int main() {
    map<char, int> mp;
    int n, M = 0;
    string s;
    cin >> s >> n;
    int a[200];
    for (char i : s)
        mp[i]++;
 
    for (int k = 1; k <=1000; k++)
    {
        string ans;
        map<char, int> aux(mp);
        for (char i : s)
        {
            if (aux[i] > 0)
            {
                ans += i;
                aux[i] -= k;
            }
        }
        if(ans.length() > n)
            continue;
        bool good = true;
        for (char i : s)
        {
            if(aux[i] > 0)
                good = false;
        }
        if(good)
        {
            while(ans.length() < n)
                ans += s[0];
            cout << k << "\n" << ans;
            return 0;
        }
    }
    cout << -1;
}
