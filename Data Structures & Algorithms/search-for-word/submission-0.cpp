class Solution {
public:
    bool res=false;
    int n,m;
    bool dfs(vector<vector<char>>& b,int i,int j,string &word, int idx){
        if(idx==word.length()){
            return true;
        }
        if(0>i || i>=n || 0>j || j>=m || b[i][j] != word[idx]){
            return false;
        }
        vector<pair<int,int>> d={{1,0},{-1,0},{0,1},{0,-1}};
        bool val=false;
        char temp=b[i][j];
        b[i][j]='#';
        for(int k=0;k<4;k++){
            int ni=d[k].first+i;
            int nj=d[k].second+j;
            val=val||dfs(b,ni,nj,word,idx+1);
        }
        b[i][j]=temp;
        return val;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
