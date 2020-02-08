#include<bits/stdc++.h>
using namespace std;
//ifstream fin("permutari.in"); ofstream fout("permutari.out");
//
//void generate_comb(int nr , int n , vector<int>uz , vector<int> &cmb)
//{
//    if (nr == n)
//    {
//        for (int i=0 ; i<n; i++)
//            fout << cmb[i]+1 << " ";
//        fout << "\n";
//        return;
//    }
//    for (int i=0 ; i<n ; i++)
//        if(!uz[i])
//        {
//            cmb[nr] = i; uz[i] = 1;
//            generate_comb(nr + 1 , n , uz , cmb);
//            cmb[nr] = 0; uz[i] = 0;
//        }
//}
 
int main()
{
    int n0 , n;
    cin >> n0;
    n = n0;
    stack <int> s;
    vector <int> cifre;
    while(n0>0)
    {
        s.push(n0%10);
        n0=n0/10;
    }
    while(!s.empty())
    {
        cifre.push_back(s.top());
        s.pop();
    }
    long long m = 1 << cifre.size() , maxcf = 0;
    queue <int> q;
    for(long long i=1 ; i<=m ; i++)
    {
        for(int j=0 ; j<cifre.size() ; j++)
            if(i & (1 << j))
                q.push(cifre[j]);
        long long f=0 , nr=0;
        while(!q.empty() && q.front() == 0)
            q.pop();
        while(!q.empty())
        {
            nr = nr*10 + q.front();
            q.pop();
            f++;
        }
        if((long long)sqrt(nr)*(long long)sqrt(nr) == nr)
            if(maxcf<f)
                maxcf=f;
    }
    if(maxcf)
        cout << cifre.size() - maxcf;
    else cout<<-1;
    return 0;
}
