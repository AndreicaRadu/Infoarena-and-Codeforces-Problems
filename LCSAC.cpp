#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string X , Y;
    cin >> X >> Y;
    int d[X.length()+1][Y.length()+1];
    //int ans = 0;
    for (int i=0 ; i<=X.length() ; i++)
        d[i][0] = 0;
    for (int j=0 ; j<=Y.length() ; j++)
        d[0][j] = 0;
    for (int i=1 ; i<=X.length() ; i++)
        for (int j=1 ; j<=Y.length() ; j++)
        {
            d[i][j] = max(d[i][j-1] , d[i-1][j]);
            if (X[i-1] == Y[j-1])
            {
                d[i][j] = max(d[i-1][j-1] + 1 , d[i][j]);
                //ans = max(ans , d[i][j]);
            }
        }
    //cout << ans;
    string ans;
    for(int i=X.size()-1, j=Y.size()-1 ; i>=0 && j>=0 ; )
    {
        if( X[i] == Y[j] )
        {
            ans += X[i];
            j--;
            i--;
        }
        else if(d[i+1][j+1] == d[i][j+1])
            i--;
        else
            j--;
    }
    reverse(ans.begin() , ans.end());
    cout << ans;
}
