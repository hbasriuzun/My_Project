//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;


int main() {
    int t,n,coun=0,coun2=0,mn1,mn2;
    cin >> t;
    while(t--){
        coun=0;
        coun2=0;
        cin >> n;
        string a,b;
        
        cin >> a >>b;
        
        for(int i=0; i<n; i++)
            if(a[i] != b[i])
                coun++;

        reverse(b.begin(),b.end());
        
        for(int i=0; i<n; i++)
            if(a[i] != b[i])
                coun2++;

        int p=0;
        if(coun2 == 0){
            coun2 = 1;
            p=1;
        }

        if(coun == 1){
            cout << 1 << endl;
            continue;
        }
        coun =2*coun+1;
        coun2 = 2*coun2; 
        if(n%2 != 0)
            coun++;
        else
            coun2++;

        if(p == 1)
            coun2 -= 1;

        if(coun <= coun2){
            cout << coun << endl;
        }else{
            cout << coun2 << endl;  
        }

    }
    
}
