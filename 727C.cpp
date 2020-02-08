#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int x, y, z , s;
    printf("? 1 2\n");
    fflush(stdout); cin >> x;
    printf("? 1 3\n");
    fflush(stdout); cin >> y;
    printf("? 2 3\n");
    fflush(stdout); cin >> z;
    s = (x + y + z)/2;
    a.push_back(s-z);
    a.push_back(s-y);
    a.push_back(s-x);
 
    for(int i=3; i< n; i++)
    {
        cout << "? 1 " << i+1 << "\n";
        fflush(stdout);
        int aux;
        cin >> aux;
        a.push_back(aux - a[0]);
    }
    cout << "! ";
    for(int i=0 ; i<n; i++)
        cout << a[i] << " ";
}
