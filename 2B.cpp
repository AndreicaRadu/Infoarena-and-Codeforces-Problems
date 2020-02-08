#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    long long m[n][n];
    int two[n][n] , d2[n][n] , is0=0 , px0 , py0;
    char str2[n][n];
    for(int i=0 ; i<n ; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            if(!is0 && m[i][j] == 0)
            {
                is0 = 1;
                px0 = i; py0 = j;
            }
        }
    for(int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            int x = 0;
            while(m[i][j] % 2 == 0 && m[i][j])
            {
                m[i][j] /= 2;
                x++;
            }
            two[i][j] = x;
        }
    }
    d2[0][0] = two[0][0];
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
        {
            if(i==0 && j!=0)
            {
                str2[i][j] = 'R';
                d2[i][j] = d2[i][j-1] + two[i][j];
            }
            if(j==0 && i!=0)
            {
                str2[i][j] = 'D';
                d2[i][j] = d2[i-1][j] + two[i][j];
            }
            if(i!=0 && j!=0)
            {
                if(d2[i][j-1] <= d2[i-1][j])
                {
                    str2[i][j] = 'R';
                    d2[i][j] = d2[i][j-1] + two[i][j];
                }
                else
                {
                    str2[i][j] = 'D';
                    d2[i][j] = d2[i-1][j] + two[i][j];
                }
            }
        }
    int ans1 = d2[n-1][n-1];
    string sans1;
    int p=n-1 , q=n-1;
    while(p!=0 || q!=0)
    {
        sans1 += str2[p][q];
        if(str2[p][q] == 'R')
            q--;
        else p--;
    }
    for(int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            int x = 0;
            while(m[i][j] % 5 == 0 && m[i][j])
            {
                m[i][j] /= 5;
                x++;
            }
            two[i][j] = x;
        }
    }
    d2[0][0] = two[0][0];
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
        {
            if(i==0 && j!=0)
            {
                str2[i][j] = 'R';
                d2[i][j] = d2[i][j-1] + two[i][j];
            }
            if(j==0 && i!=0)
            {
                str2[i][j] = 'D';
                d2[i][j] = d2[i-1][j] + two[i][j];
            }
            if(i!=0 && j!=0)
            {
                if(d2[i][j-1] <= d2[i-1][j])
                {
                    str2[i][j] = 'R';
                    d2[i][j] = d2[i][j-1] + two[i][j];
                }
                else
                {
                    str2[i][j] = 'D';
                    d2[i][j] = d2[i-1][j] + two[i][j];
                }
            }
        }
    int ans2 = d2[n-1][n-1];
    string sans2;
    p=n-1 , q=n-1;
    while(p!=0 || q!=0)
    {
        sans2 += str2[p][q];
        if(str2[p][q] == 'R')
            q--;
        else p--;
    }
    reverse(sans1.begin() , sans1.end());
    reverse(sans2.begin() , sans2.end());
    if(is0 && ans1 > 1 && ans2 > 1)
    {
        cout << 1 << "\n";
        int aux = py0;
        while(aux--) cout << 'R';
        aux = n-1;
        while(aux--) cout << 'D';
        aux = n-1 - py0;
        while(aux--) cout << 'R';
        return 0;
    }
    if(ans1 <= ans2) cout << ans1 << "\n" << sans1;
    else cout << ans2 << "\n" << sans2;
}
