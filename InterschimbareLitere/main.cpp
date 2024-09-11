#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[11], v, c, a, b;
    cin >> s;
    int cntvocale = 0, cntcons = 0;
    for(int i = 0; i < strlen(s); i++){
        if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u' || tolower(s[i]) == 'i')
        {
            if(cntvocale == 0) v = s[i], a = i;
            cntvocale++;
        }
        else {
            c = s[i], b = i;
            cntcons++;
        }
    }

    if(cntvocale == strlen(s) - 1 || cntcons == strlen(s - 1)) cout << "IMPOSIBIL";
    else {
        s[a] = c;
        s[b] = v;
        cout << s;
    }

    return 0;
}
