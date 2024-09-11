#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int cnt = 0;
    char s[256];
    cin.getline(s, 255);
    for(int i = 1; i < strlen(s) - 1; i++){
        if(s[i] == ' ') { }
        else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
           if(s[i - 1] != 'a' && s[i- 1] != 'e' && s[i- 1] != 'i' &&
              s[i- 1] != 'o' && s[i- 1] != 'u' && s[i - 1] != ' ')
            {
                    if(s[i + 1] != 'a' && s[i+ 1] != 'e' && s[i+ 1] != 'i' &&
                    s[i+ 1] != 'o' && s[i+ 1] != 'u' && s[i + 1] != ' ')
                {
                    cnt++;
                    //cout << i << " ";
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
