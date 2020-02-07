#include <iostream>
using namespace std;
 
bool different_nums(int a)
{
    int k[10] = {0};
    while(a>0)
    {
        k[a%10]++;
        if(k[a%10] > 1)
            return false;
        a /= 10;
    }
    return true;
}
int main()
{
    int l , r;
    cin >> l >> r;
    for(int i=l ; i<=r ; i++)
    {
        if(different_nums(i))
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
