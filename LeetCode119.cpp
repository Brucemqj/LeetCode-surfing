class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rst;
        if(rowIndex < 0) rst;
        rst.push_back(1);
        if(rowIndex == 0) return rst;
        rst.push_back(1);
        if(rowIndex == 1) return rst;
        for(int i=2; i <= rowIndex; ++i)
        {
            vector<int> row(i+1, 1);
            rst.push_back(1);
            for(int j=1; j < i; ++j)
            {
                row[j] = rst[j-1] + rst[j];
            }
            for(int j=0; j < i+1; ++j)
                rst[j] = row[j];
        }
        return rst;
    }
};