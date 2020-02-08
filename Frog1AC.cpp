#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int n; cin >> n;
  int h[n];
  for(int i=0 ; i<n ; i++)
    cin >> h[i];
  int cost[n] = {0};
  cost[1] = abs(h[0] - h[1]);
  cost[2] = min(abs(h[0] - h[2]) , cost[1] + abs(h[1] - h[2]));
  for(int i=3 ; i<n ; i++)
    cost[i] = min(cost[i-1] + abs(h[i-1] - h[i]) , cost[i-2] + abs(h[i-2] - h[i]));
  cout << cost[n-1];
}
