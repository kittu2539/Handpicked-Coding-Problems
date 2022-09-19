// link :- https://binarysearch.com/problems/Airplane-Seat-Shuffling
double solve(int n) {
    double dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }
    double pref = 0;
    for(int i=1;i<=n;i++){
        if(i==1)dp[i]=1;
        else dp[i]=(1.00/(double)i)*(1.00+pref);
        if(i!=1)pref+=dp[i];
    }
    return dp[n];
}
