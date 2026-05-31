class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> rm(n,0);
        int maxx=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxx=max(maxx,prices[i]);
            rm[i]=maxx;
        }
        maxx=0;
        for(int i=0;i<n;i++){
            if(rm[i]<prices[i]){
                continue;
            }
            else{
                maxx=max(maxx,rm[i]-prices[i]);
            }
        }
        return maxx;
    }
};
