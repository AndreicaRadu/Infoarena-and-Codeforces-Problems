#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    long long h[n][3];
    for(int i=0 ; i<n ; i++)
        cin >> h[i][0] >> h[i][1] >> h[i][2];
    long long cost[n][3] = {0};
    cost[0][0] = h[0][0];
    cost[0][1] = h[0][1];
    cost[0][2] = h[0][2];
    for(int i=1 ; i<n ; i++)
    {
        cost[i][0] = h[i][0] + max(cost[i-1][1] , cost[i-1][2]);
        cost[i][1] = h[i][1] + max(cost[i-1][0] , cost[i-1][2]);
        cost[i][2] = h[i][2] + max(cost[i-1][1] , cost[i-1][0]);
    }
    cost[n-1][0] = max(cost[n-1][0] , cost[n-1][1]);
    cout << max(cost[n-1][0] , cost[n-1][2]);
}
