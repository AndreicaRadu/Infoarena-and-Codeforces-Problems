#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int c = 1000000007;
    int H , W;
    cin >> H >> W;
    vector<string> M(H);
    for(int i=0 ; i<H ; i++)
        cin >> M[i];
    long long d[H][W];
    for(int i=0 ; i<H ; i++)
        for(int j=0 ; j<W ; j++)
            d[i][j] = 0;
    d[0][0] = 1;
    for(int i=0 ; i<H ; i++)
        for(int j=0 ; j<W ; j++)
        {
            if(i>0 && M[i-1][j] == '.')
                d[i][j] += d[i-1][j]%c;
            if(j>0 && M[i][j-1] == '.')
                d[i][j] += d[i][j-1]%c;
        }
    cout << d[H-1][W-1]%c;
}
