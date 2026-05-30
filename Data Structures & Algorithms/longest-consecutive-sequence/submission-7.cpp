class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int,vector<int>, greater<int>> pq;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        vector<int> res;
        while(!pq.empty()){
            if(!st.contains(pq.top())){
                res.push_back(pq.top());
                st.insert(pq.top());
            }    
            pq.pop();
        }
        int len=0;
        int maxx=0;
        if(res.size()==0){
            return 0;
        }
        for(int i=0;i<res.size()-1;i++){
            if(abs(res[i]-res[i+1])==1){
                len++;
                maxx=max(maxx,len);
            }
            else{
                len=0;
            }
        }
        // if(res.size()==1){
        //     return 1;
        // }
        // int i=0;
        // int j=0;
        // int maxx=INT_MIN;
        // while(i<=j && j<res.size()){
        //     if(i==j){
        //         maxx=max(maxx,j-i);
        //         j++;
        //         continue;
        //     }
        //     if(res[j]-res[i]==j-i){
        //         maxx=max(maxx,j-i);
        //         j++;
        //         continue;
        //     }
        //     else{
        //         maxx=max(maxx,j-i);
        //         i++;
        //     }
        // }

        return maxx+1;
    }
};
