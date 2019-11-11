class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int circles = n;
        // -1 means the node itself is final root
        vector<int> root(n,-1);
        
        // union different set by using root
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++){
                if(M[i][j])
                {
                    int X = findRoot(i, root);
                    int Y = findRoot(j, root);
                    if (X != Y)
                    {
                        --circles;
                        root[X] = Y;
                    }
                }
            }
        return circles;
    }
    // find root node
    int findRoot(int x, vector<int>& root){
        // if node find root its itself, then return it.
        // otherwise, recurrsion find parents root.
        return root[x] == -1 ? x : findRoot(root[x], root);
    }
};