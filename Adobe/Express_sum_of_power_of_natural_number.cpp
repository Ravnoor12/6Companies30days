#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long int numOfWays(int n, int x)
    {
        vector<long long int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        int maxLimit = pow(n, 1.0/x);
        for(int i = 2; i <= maxLimit; i++){
            int curr = pow(i, x);
            for(int j = n; j >= curr; j--){
                dp[j] += dp[j-curr];
            }
        }
        
        return dp[n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}