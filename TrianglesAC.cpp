#include <bits/stdc++.h>
using namespace std;
int L[2019] , n;
int find3rd(int x , int y)
{
    int left = y+1 , right = n - 1 , mid;
    int ans = -1;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(L[mid] < L[x] + L[y])
        {
            left = mid + 1;
            ans = mid;
        }
        else right = mid - 1;
    }
    if(ans == -1)
        return 0;
    return ans - y;
}
 
int main()
{
    cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> L[i];
    sort(L , L+n);
    int ans = 0;
    for(int i=0 ; i<n ; i++)
        for(int j=i+1 ; j<n ; j++)
            ans += find3rd(i , j);
    cout << ans;
}
