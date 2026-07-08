class MedianFinder {
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }    
    double findMedian() {
       vector<int> temp;
       while(!pq.empty()){
        temp.push_back(pq.top());
        pq.pop();
       }
       int n=temp.size();
       int sum=0;
       for(int i=0;i<n;i++){
        sum+=temp[i];
        pq.push(temp[i]);
       }
       if(n%2!=0){
        return temp[n/2];
       }
       return (temp[n/2]+temp[(n/2)-1])/2.0;
    }
};
