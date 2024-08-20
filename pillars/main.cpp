#include <iostream>
#include <cmath>
using namespace std;

long long a[100001],b[100001],p[100001];

int main()
{
    int n,d,mx=-1,val=0;
    cin >> n >> d;
    
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        p[i]=i;
        b[i]=1;
    }
    
    for(int i = n-1; i >= 0; i--)
    {
        int f = i + 400;
        for(int j = i+1; j < min(n, f); j++)
        {
            if(abs(a[i]-a[j]) >= d)
            {
                if(b[j] +1 > b[i])
                {
                    b[i] = b[j] + 1;
                    p[i] = j;
                }
            }
        }
        
        if(b[i] > mx)
        {
            mx = b[i];
            val = i;
        }
    }
    
    cout << mx << '\n' << val+1 <<  ' ';
    
    while(val != p[val])
    {
        cout << p[val]+1 <<  ' ';
        val = p[val];
    }
}
