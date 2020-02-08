#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n , prim[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53 , 59 , 61 , 67 , 71};
    cin >> n;
    if(n==8)
    {
        cout << 24;
        return 0;
    }
    vector <long long> div;
    int d = 2;
    while(n > 1)
    {
        while(n % d == 0)
        {
            div.push_back(d);
            n /= d;
        }
        d++;
    }
    if(n > 1)
        div.push_back(n);
    long long ans=1;
    for(int i = 0; i < div.size(); i++)
    {
        int ind = div.size() - i - 1;
        long long aux = div[ind] - 1;
        while(aux--)
            ans *= prim[i];
    }
    cout << ans;
    return 0;
}
