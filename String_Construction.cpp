// link :- https://binarysearch.com/problems/String-Construction
int dp[51][51][51];
int recur(vector<string >&v,int a,int b,int n,int ind){
    if(ind==n+1)return 0;
    if(dp[ind][a][b]!=-1)return dp[ind][a][b];
    int cnta=0,cntb=0;
    for(char ch=0;ch<(int)v[ind-1].length();ch++){
        if(v[ind-1][ch]=='A')cnta++;
        else cntb++;
    }
    if(a>=cnta && b>=cntb){
        dp[ind][a][b]=max(recur(v,a,b,n,ind+1),1+recur(v,a-cnta,b-cntb,n,ind+1));
    }else dp[ind][a][b]=recur(v,a,b,n,ind+1);
    return dp[ind][a][b];
}
int solve(vector<string>& strings, int a, int b) {
    for(int i=0;i<=(int)strings.size();i++){
        for(int aa=0;aa<=a;aa++){
            for(int bb=0;bb<=b;bb++){
                dp[i][aa][bb]=-1;
            }
        }
    }
    dp[0][0][0]=0;
    return recur(strings,a,b,(int)strings.size(),1);
}
