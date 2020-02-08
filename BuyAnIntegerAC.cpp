#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long a , b , x;
    cin >> a >> b >> x;
    long long p[12] , ind = 1;
    p[1] = 1; p[0] = 0;
    while(ind < 12)
    {
        ind++;
        p[ind] = p[ind - 1] * 10;
    }
    long long low , lown=0;
    for(int i=1 ; i<11 ; i++)
    {
        low = a*p[i] + b*i;
        if(low <= x) lown = i;
        else break;
    }
    if(lown == 0) {cout << 0; return 0;}
    if(lown == 10) {cout << 1000000000; return 0;}
    long long ans = pow(10 , lown-1);
    long long left=ans , right = ans*10-1 , mid;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(a*mid + b*lown <= x)
        {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    if(ans > 1000000000)
    {
        cout << 999999999;
        return 0;
    }
    cout << ans;
}
