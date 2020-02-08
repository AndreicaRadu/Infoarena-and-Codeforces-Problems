#include <bits/stdc++.h>
#include <fstream>
using namespace std;
 
ifstream fin("arbsat2.in"); ofstream fout("arbsat2.out");
set<pair<int, int>> ans;
vector<pair<int, int>> v;
void divide(int left, int right)
{
    if(left>=right)
        return;
    int mid = (left + right)/2;
    divide(left, mid);
    divide(mid + 1, right);
    int x = v[mid].first;
    for(int i=left ; i<=right ; i++)
        if(v[i].first != x)
            ans.insert({x, v[i].second});
}
 
int main()
{
    int n, m;
    fin >> n >> m;
    v.resize(n);
    for(auto& i: v)
        fin >> i.first >> i.second;
    sort(v.begin(), v.end());
    divide(0, n - 1);
    fout << ans.size() << "\n";
    for(auto i: ans)
        fout << i.first << " " << i.second << "\n";
    return 0;
}

