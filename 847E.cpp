#include <bits/stdc++.h>
using namespace std;
 
string board;
int f[100100] , n , nrp = 0;
int leftmostpack(int x)
{
    for(int i=x ; i<n ; i++)
        if(board[i] == 'P' && !f[i])
        {
            f[i] = 1;
            return i;
        }
    return n+1;
}
bool check(int x)
{
    for(int i=0 ; i<n ; i++)
        f[i] = 0;
    int lastp = 0 , lasta=0;
    for(int i=0 ; i<nrp ; i++)
    {
        int a = leftmostpack(lastp) , b = n+1;
        for(int j=lasta ; j<n ; j++)
            if(board[j] == '*' && !f[j])
            {
                b = j;
                lasta = j;
                break;
            }
        if(b == n+1)
            return true;
        if(abs(a - b) > x)
            continue;
        if(b > a)
        {
            for(int j=a ; j<=min(a+x , (int)board.length()-1) ; j++)
                if(board[j] != 'P')
                    f[j] = 1;
        }
        else
        {
            for(int j=b ; j<a ; j++)
                if(board[j] != 'P')
                    f[j] = 1;
            for(int j=a ; j<=min(max(a + x - 2*(a-b) , a + (x - (a-b))/2) , (int)board.length()-1) ; j++)
                if(board[j] != 'P')
                    f[j] = 1;
        }
        lastp = a;
    }
    for(int i=0 ; i<n ; i++)
        if(board[i] == '*' && !f[i])
            return false;
    return true;
}
 
int main()
{
    cin >> n >> board;
    for(int i=0 ; i<n ; i++)
        if(board[i] == 'P')
            nrp++;
    int left=0 , right = 2*n , mid , ans = 2*n;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(!check(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            ans = min(ans , mid);
        }
    }
    cout << ans;
}
