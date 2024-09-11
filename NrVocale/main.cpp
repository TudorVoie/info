#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    int v[5] = {0};
    cin.get(s, 255);
    for(int i = 0; i < strlen(s); i++){
        if(tolower(s[i]) == 'a') {
           v[0]++;
           continue;
        }
        if(tolower(s[i]) == 'e') {
           v[1]++;
           continue;
        }
        if(tolower(s[i]) == 'i') {
           v[2]++;
           continue;
        }
        if(tolower(s[i]) == 'o') {
           v[3]++;
           continue;
        }
        if(tolower(s[i]) == 'u') {
           v[4]++;
           continue;
        }
    }
    int mx = 0, j;
    for(int i = 0; i < 5; i++)
    {
        if(v[i] > mx) mx = v[i], j = i;
    }
    if(j == 0){
        cout << 'A';
    }
    if(j == 1){
        cout << 'E';
    }
    if(j == 2){
        cout << 'I';
    }
    if(j == 3){
        cout << 'O';
    }
    if(j == 4){
        cout << 'U';
    }
    return 0;
}
