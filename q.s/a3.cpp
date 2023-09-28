#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<long long, int> dp;
    long long sum = 0,count = 0,n;
    cin >> n;
    
    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    for (int i=0; i<n; i++) {
        sum += t[i];
        
        if (sum == 0) 
            count++;

        if (dp.find(sum) != dp.end()) 
            count += dp[sum];
        
        dp[sum]++;
    }

    cout << count << endl;
    
    return 0;
}
