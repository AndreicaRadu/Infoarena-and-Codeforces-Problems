#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("joben.in"); ofstream fout("joben.out");
 
multiset<int> func(string s)
{
    multiset <int> ans;
    int f[27] = {0};
    for(char i : s)
        f[(int)i - 97]++;
    for(int i=0 ; i<26 ; i++)
        if(f[i])
            ans.insert(f[i]);
    return ans;
}
 
int main()
{
    int n;
    fin >> n;
    while(n--)
    {
        string a , b;
        fin >> a >> b;
        if(func(a) == func(b))
            fout << "DA";
        else fout << "NU";
        fout << "\n";
    }
}
