#include<bits/stdc++.h>
using namespace std;
 
bool a[10020][10020] = {false};
bool check(int i , int j)
{
    bool x = false;
    x = (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    i -= 1;
    x = x || (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    i -= 1;
    x = x || (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    i += 2;
    j -= 1;
    x = x || (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    i -= 1;
    x = x || (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    i -= 1;
    x = x || (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    i += 2;
    j -= 1;
    x = x || (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    i -= 1;
    x = x || (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    i -= 1;
    x = x || (a[i][j] && a[i+1][j] && a[i+2][j] && a[i][j+1] && a[i+1][j+1] && a[i+2][j+1] && a[i][j+2] && a[i+1][j+2] && a[i+2][j+2]);
    return x;
}
 
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i=1 ; i<=m ; i++)
    {
        int x , y;
        cin >> x >> y;
        a[x+2][y+2] = true;
        if(check(x+2 , y+2))
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
