#include <bits/stdc++.h>
#include <fstream>
using namespace std;
 
int c[26];
int main()
{
    int n , odd=0;
    string s;
    cin >> s;
    n = s.length();
    for(int i=0 ; i<n ; i++)
        c[(int)s[i] - 97]++;
    string ans;
    for(int i=0 ; i<n ; i++)
        ans += 'a';
    for(int i=0 ; i<26 ; i++)
        if(c[i]%2 == 1)
            odd++;
    int l=0 , r=25;
    while(odd > 1)
    {
        while(c[l]%2 == 0)
            l++;
        while(c[r]%2 == 0)
            r--;
        c[l]++; c[r]--; odd -= 2;
    }
    l=0; r=n-1;
    for(int i=0 ; i<26 ; i++)
        while(c[i]>1)
        {
            ans[l] = (char)(i + 97);
            ans[r] = (char)(i + 97);
            l++; r--; c[i] -= 2;
        }
    if(n%2 == 1)
        for(int i=0 ; i<26 ; i++)
            if(c[i] == 1)
                ans[l] = (char)(i + 97);
    cout << ans;
}
