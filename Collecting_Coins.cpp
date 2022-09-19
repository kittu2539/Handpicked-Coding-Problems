// link :- https://binarysearch.com/problems/Collecting-Coins
int solve(vector<vector<int>>& matrix) {
    int n=matrix.size(),m=matrix[0].size();
    int dp[n][m];
    dp[0][0]=matrix[0][0];
    for(int i=1;i<n;i++)dp[i][0]=dp[i-1][0]+matrix[i][0];
    for(int j=1;j<m;j++)dp[0][j]=dp[0][j-1]+matrix[0][j];
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=matrix[i][j]+max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
