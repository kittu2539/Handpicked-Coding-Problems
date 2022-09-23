link :- https://binarysearch.com/problems/Maximum-Product-Path-in-Matrix
int solve(vector<vector<int>>& nums) {
    int mod = 1e9+7;
    int n=nums.size(),m=nums[0].size();
    vector<vector<long>>ndp(n,vector<long>(m)),pdp(n,vector<long>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ndp[i][j]=nums[i][j];
            pdp[i][j]=nums[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)continue;
            if(i==0){
                ndp[i][j]*=ndp[i][j-1];
                pdp[i][j]*=pdp[i][j-1];
            }
            else if(j==0){
                ndp[i][j]*=ndp[i-1][j];
                pdp[i][j]*=pdp[i-1][j];
            }else {
                ndp[i][j]=min(ndp[i-1][j]*nums[i][j],ndp[i][j-1]*nums[i][j]);
                ndp[i][j]=min(ndp[i][j],min(pdp[i-1][j]*nums[i][j],pdp[i][j-1]*nums[i][j]));

                pdp[i][j]=max(pdp[i-1][j]*nums[i][j],pdp[i][j-1]*nums[i][j]);
                pdp[i][j]=max(pdp[i][j],max(ndp[i-1][j]*nums[i][j],ndp[i][j-1]*nums[i][j]));
            }
        }
    }
    return (pdp[n-1][m-1]<0?-1:pdp[n-1][m-1]%mod);
}
