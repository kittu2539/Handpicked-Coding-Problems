// link :- https://binarysearch.com/problems/Double-String-Concatenation
int minEditDis(string s,string s1){
    int n=s.length(),m=s1.length();
    if(s=="")return s1.length();
    if(s1=="")return s.length();
    int dp[n+1][m+1];
    dp[0][0]=0;
    for(int i=0;i<=n;i++)dp[i][0]=i;
    for(int j=0;j<=m;j++)dp[0][j]=j;
    
    // cout<<"dp = \n";
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<"\n";
    // }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=i+j;
            if(s[i-1]==s1[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            dp[i][j]=min(dp[i][j],1+min(dp[i-1][j],dp[i][j-1]));
        }
    }

    return dp[n][m];
}
int solve(string s) {
    int ans=s.length(),n=s.length();
    for(int i=0;i<n;i++){
        string s1=s.substr(0,i), s2=s.substr(i,n-i);
        ans=min(ans,minEditDis(s1,s2));
    }
    return ans;

}
