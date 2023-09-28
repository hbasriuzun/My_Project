//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
map<long long,long long> m;


int main() {
    long long int n,sum=1,i,y,j;
    int ch=0;
    cin >> n;

    if(n == 1){
        cout << 1;
        return 0;
    }else if(n == 2){
        cout << 2;
        return 0;
    }
    for(i=2; i<=n; i*=2){
        sum+=1;
    }
    for(i=3; i<=n; i+=2){
        for(j=i; j<=n; j=j*2){
            sum+=i;
        }
    }

    
    cout << sum;
}
