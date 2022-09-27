// link :- https://binarysearch.com/problems/Decode-Message
int solve(string a) {
    if(a[0]=='0')return 0;
    int n=a.size();
    int dp[n+1]={};
    memset(dp,-1,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(a[i-1]=='0'){
            if(a[i-2]!='1' && a[i-2]!='2')return 0;
            else dp[i]=dp[i-2];
        }else {
            dp[i]=dp[i-1];
            if(i>1){
                if(a[i-2]=='1' || (a[i-1]<='6' && a[i-2]=='2')){
                    dp[i]+=dp[i-2];
                }
            }
        }
    }
    return dp[n];
}
