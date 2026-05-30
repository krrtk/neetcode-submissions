class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> p1(n+2,1);
        vector<int> p2(n+2,1);
        int prod=1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            p1[i+1]=prod;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            p2[i+1]=prod;
        }
        vector<int> res;
        for(int i=1;i<n+1;i++){
            res.push_back(p2[i+1]*p1[i-1]);
        }
        return res;
    }
};
