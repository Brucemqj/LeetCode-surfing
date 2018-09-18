class Solution {
public:
     vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rst;
        if(numRows <= 0) return rst;
        vector<int> levelOne(1,1);
        rst.push_back(levelOne);
        if(1 == numRows) return rst;
        vector<int> levelTwo(2,1);
        rst.push_back(levelTwo);
        for(int i=2; i < numRows; ++i) // i is in [0, numRows)
        {
            vector<int> levelI(i+1,1);
            for(int j=1; j < i; ++j) // j is in [1, numRows-1)
            {
                levelI[j] = rst[i-1][j-1] + rst[i-1][j];
            }
            rst.push_back(levelI);
        }
        return rst;
    }
};