// link :- https://binarysearch.com/problems/Longest-Common-Subsequence
int solve(string a, string b) {
    if(a=="" || b=="")return 0;
    int n=a.length(),m=b.length();
    int dp[n+1][m+1];
    dp[0][0]=0;
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i][j]));
            }else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
