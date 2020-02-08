#include <bits/stdc++.h>
using namespace std;
 
int n;
bool init , col[300];
bool consec(int x)
{
    cout << "? ";
    for(int i=x ; i<n+x ; i++)
        cout << i << " ";
    cout << "\n";
    cout.flush();
    string rb;
    cin >> rb;
    if(rb == "Red")
        return true;
    return false;
}
bool f1(int b , int start)
{
    cout << "? " << b << " ";
    for(int i=start ; i<n-1+start ; i++)
        cout << i << " ";
    cout << "\n";
    cout.flush();
    string rb;
    cin >> rb;
    if(rb == "Red")
        return true;
    return false;
}
bool f2(int b , int k)
{
    cout << "? " << b << " ";
    for(int i=1 ; i<k ; i++)
        cout << i << " ";
    for(int i=k+1+n ; i<=2*n ; i++)
        cout << i << " ";
    cout << "\n";
    cout.flush();
    string rb;
    cin >> rb;
    if(rb == "Red")
        return true;
    return false;
}
int main()
{
    cin >> n;
    cout << "? ";
    for(int i=1 ; i<=n ; i++)
        cout << i << " ";
    cout << "\n";
    cout.flush();
    string rb;
    cin >> rb;
    if(rb == "Red")
        init = true;
    else init = false;
    int left=1 , right=n , ans=200;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(consec(mid) == init)
        {
            ans = mid+1;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    col[ans-1] = init; col[ans+n-1] = !init;
    for(int i=1 ; i<ans-1 ; i++)
        col[i] = f1(i , ans);
    for(int i=ans+n ; i<=2*n ; i++)
        col[i] = f1(i , ans);
    for(int i=ans ; i<ans+n-1 ; i++)
        col[i] = f2(i , ans-1);
    cout << "! ";
    for(int i=1 ; i<=2*n ; i++)
    {
        if(col[i])
            cout << "R";
        else cout << "B";
    }
    cout << "\n";
    cout.flush();
}
