#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("jocul.in"); ofstream fout("jocul.out");
 
int main()
{
    int n , sum = 0 , dp[100100];
    fin >> n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
        fin >> v[i];
    for(int i=0 ; i<n ; i++)
        sum += v[i];
    dp[0] = 1;
    for(int i=0 ; i<n ; i++)
        for(int j=sum ; j>=0 ; j--)
            if(dp[j])
                dp[j+v[i]] = 1;
    for(int i=sum/2 ; i>=0 ; i--)
        if(dp[i] == 1)
        {
            fout << i << " " << sum - i;
            return 0;
        }
}
