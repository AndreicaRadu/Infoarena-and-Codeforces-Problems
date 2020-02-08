#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n , k; cin >> n >> k;
    long long h[n];
    for(int i=0 ; i<n ; i++)
        cin >> h[i];
    long long cost[n] = {0};
    cost[1] = abs(h[0] - h[1]);
    for(int i=2 ; i<n ; i++)
    {
        long long c = 1000000000000;
        int j;
        if(i<k) j=0; else j=i-k;
        for(j ; j<i ; j++)
            c = min(c , cost[j] + abs(h[j] - h[i]));
        cost[i] = c;
    }
    cout << cost[n-1];
}
