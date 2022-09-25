// link :- https://binarysearch.com/problems/0-1-Knapsack
int solve(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>>dp(n+1,vector<int >(capacity+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=capacity;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if( weights[i-1]<=j){
                dp[i][j]=max(dp[i-1][j-weights[i-1]]+values[i-1],dp[i-1][j]);
            }else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];
}
