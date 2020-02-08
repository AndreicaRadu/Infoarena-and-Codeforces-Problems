#include <bits/stdc++.h>
using namespace std;
vector<int> a;
bool ok(int x , int n , int m)
{
    int convinced=0 , use=0;
    for(int i=0 ; i<n ; i++)
    {
        if(a[i] <= convinced)
            convinced++;
        else if(use < x)
        {
            use++;
            convinced++;
        }
        if(convinced==m)
            return true;
    }
    return false;
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i=0 ; i<n ; i++)
    {
        int aux;
        cin >> aux;
        a.push_back(aux);
    }
    int left=0 , right=n , ans=m;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(ok(mid , n , m))
        {
            right = mid-1;
            ans=mid;
        }
        else left = mid+1;
    }
    cout << ans;
    return 0;
}
