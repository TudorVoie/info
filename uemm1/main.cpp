#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, a[100001], right[100001];
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    stack<int> st;

    right[n] = -1;
    st.push(n);
    for(int i = n - 1; i >= 1; i--){
        while(!st.empty() && a[i] >= a[st.top()])
            st.pop();

        if(st.empty())
            right[i] = -1;
        else
            right[i] = a[st.top()];

        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = 1; i <= n; i++) cout << right[i] << " ";
    return 0;
}
