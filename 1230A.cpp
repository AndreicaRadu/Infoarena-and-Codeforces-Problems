#include <iostream>
using namespace std;
int main()
{
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    int sum = (a + b + c + d);
    if(sum%2 == 1)
    {
        cout << "NO";
        return 0;
    }
    sum = sum/2;
    if(a == sum || b == sum || c == sum || d == sum || a+b == sum || a+c == sum || a+d == sum || b+c == sum || b+d == sum || c+d == sum)
        cout << "YES";
    else cout << "NO";
    return 0;
}
