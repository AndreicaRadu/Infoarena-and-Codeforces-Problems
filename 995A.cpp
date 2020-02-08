#include <bits/stdc++.h>
using namespace std;
 
int c , n , park[2][200] , p=0;
vector<pair<int , pair<int , int>>> v;
 
void rotate()
{
    if((p == 0 && c == 2*n)|| p == c) return;
    int z=0;
    for(int i=1 ; i<=2*n ; i++)
        if(park[1][i] == 0) {z = i; break;}
    int pos=z;
    while(park[1][pos] == 0) {pos++; if(pos == 2*n+1) pos=1;}
    for(int i=pos ; p<c ; i++)
    {
        if(i==2*n+1 || i==1)
        {
            if(park[1][1])
            {
                swap(park[1][1] , park[1][2*n]);
                v.push_back({park[1][2*n] , {1 , 2*n}});
                if(park[0][2*n] && park[0][2*n] == park[1][2*n])
                {
                    v.push_back({park[0][2*n] , {0 , 2*n}});
                    p++;
                    park[0][2*n] = 0; park[1][2*n] = 0;
                }
            }
            i=1;
            continue;
        }
        if(park[1][i])
        {
            swap(park[1][i], park[1][i - 1]);
            v.push_back({park[1][i - 1], {1, i - 1}});
            if (park[0][i-1] == park[1][i - 1])
            {
                v.push_back({park[0][i - 1], {0, i - 1}});
                p++;
                park[0][i - 1] = 0;
                park[1][i - 1] = 0;
            }
        }
    }
}
int main()
{
    cin >> n >> c;
    for(int i=1 ; i<=n ; i++) cin >> park[0][i];
    for(int i=1 ; i<=n ; i++) cin >> park[1][i];
    for(int i=2*n ; i>=n+1 ; i--) cin >> park[1][i];
    for(int i=2*n ; i>=n+1 ; i--) cin >> park[0][i];
    for(int i=1 ; i<=2*n ; i++)
        if(park[0][i] && park[0][i] == park[1][i])
        {
            v.push_back({park[0][i] , {0 , i}});
            p++;
            park[0][i] = 0; park[1][i] = 0;
        }
    if(p == 0 && c == 2*n)
    {
        cout << -1;
        return 0;
    }
    if(p == 0 && n == 1)
    {
        cout << 2 << "\n";
        if(park[1][1] == 1) {cout << "1 3 1\n";cout << "1 4 1\n";}
        else {cout << "1 2 1\n";cout << "1 1 1\n";}
        return 0;
    }
    rotate();
    cout << v.size() << "\n";
    for(int i=0 ; i<v.size() ; i++)
    {
        cout << v[i].first << " ";
        if(v[i].second.first == 0 || v[i].second.first == 3)
        {
            if(v[i].second.second <= n)
                cout << 1 << " " << v[i].second.second << "\n";
            else cout << 4 << " " << 2*n - v[i].second.second + 1 << "\n";
            continue;
        }
        if(v[i].second.second == 1)
        {
            cout << "2 " << "1\n";
            continue;
        }
        else if(v[i].second.second == n+1)
            cout << "3 " << n << "\n";
        else if(v[i].second.second > n)
            cout << "3 " << 2*n - v[i].second.second + 1 << "\n";
        else cout << "2 " << v[i].second.second << "\n";
    }
}
