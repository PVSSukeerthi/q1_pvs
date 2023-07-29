
#include <iostream>
using namespace std;
 
int highestPowerof2(int n)
{
    int res = 0;
    for (int i = n; i >= 1; i--) {
        if ((i & (i - 1)) == 0) {
            res = i;
            break;
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    cout << n-highestPowerof2(n)+1<<endl;
    return 0;
}