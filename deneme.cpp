#include <bits/stdc++.h>
using namespace std;   

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int diffCount = 0,i;
    for(i=0; i<100000000;i++){
        for (int i = 0; i < s1.length(); i++) {
        if (s1[1] != s2[1]) {
            diffCount++;
        }
    }
    }
}