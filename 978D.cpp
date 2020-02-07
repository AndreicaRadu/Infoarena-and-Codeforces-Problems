#include <iostream>
#include <vector>
using namespace std;
 
int n;
 
int traverse(int x , int y , vector <long long> a)
{
    a[0] += x; a[1] += y;
    bool ok = true;
    int ans = 0;
    long long pas = a[1] - a[0];
    for(int i=2 ; i<n ; i++)
    {
        if(a[i] == a[i-1] + pas)
            continue;
        else if(a[i] == a[i-1] + pas + 1)
        {
            ans++;
            a[i]--;
        }
        else if(a[i] == a[i-1] + pas - 1)
        {
            ans++;
            a[i]++;
        }
        else
        {
            ok = false;
            break;
        }
    }
    if(x!=0) ans++;
    if(y!=0) ans++;
    if(ok)
        return ans;
    return -1;
}
 
int main()
{
    cin >> n;
    vector <long long> a(n);
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    int a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9;
    a1 = traverse(0 , 0 , a);
    a2 = traverse(-1 , 0 , a);
    a3 = traverse(1 , 0 , a);
    a4 = traverse(0 , 1 , a);
    a5 = traverse(-1 , 1 , a);
    a6 = traverse(1 , 1 , a);
    a7 = traverse(0 , -1 , a);
    a8 = traverse(-1 , -1 , a);
    a9 = traverse(1 , -1 , a);
    if(a1 == -1 && a2 == -1 && a3 == -1 && a4 == -1 && a5 == -1 && a6 == -1 && a7 == -1 && a8 == -1 && a9 == -1)
    {
        cout << -1;
        return 0;
    }
    int m = 100010;
    if(a1 < m && a1!=-1) m = a1;
    if(a2 < m && a2!=-1) m = a2;
    if(a3 < m && a3!=-1) m = a3;
    if(a4 < m && a4!=-1) m = a4;
    if(a5 < m && a5!=-1) m = a5;
    if(a6 < m && a6!=-1) m = a6;
    if(a7 < m && a7!=-1) m = a7;
    if(a8 < m && a8!=-1) m = a8;
    if(a9 < m && a9!=-1) m = a9;
    cout << m;
}
