#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int r , c , k;
        cin >> r >> c >> k;
        vector<string> mp(r) , ans(r);
        for (int i=0 ; i<r ; i++)
            cin >> mp[i];
        char ch[62];
        ch[0] = 'a';
        for(int i=1 ; i<26 ; i++) ch[i] = ch[i-1] + 1;
        ch[26] = 'A';
        for (int i=27 ; i<52 ; i++) ch[i] = ch[i-1] + 1;
        ch[52] = '0';
        for (int i=53 ; i<62 ; i++) ch[i] = ch[i-1] + 1;
        int rice=0;
        for (int i=0 ; i<r ; i++)
            for (int j=0 ; j<c ; j++)
                if(mp[i][j] == 'R')
                    rice++;
        int a = rice / k , b[k];
        for(int i=0 ; i<k ; i++) b[i] = a;
        rice -= k*a;
        for(int i=0 ; i<rice ; i++) b[i]++;
        int currk = 0;
        for(int i=0 ; i<r ; i++)
        {
            if(i%2 == 0)
                for (int j=0 ; j<c ; j++)
                {
                    ans[i] += ch[currk];
                    if (mp[i][j] == 'R') b[currk]--;
                    if (b[currk] == 0 && currk < k - 1) currk++;
                }
            else
                for(int j=c-1 ; j>=0 ; j--)
                {
                    ans[i] += ch[currk];
                    if (mp[i][j] == 'R') b[currk]--;
                    if (b[currk] == 0 && currk < k - 1) currk++;
                }
        }
        for(int i=0 ; i<r ; i++)
        {
            if(i%2 == 0)
                cout << ans[i] << "\n";
            else
            {
                reverse(ans[i].begin() , ans[i].end());
                cout << ans[i] << "\n";
            }
        }
    }
}
