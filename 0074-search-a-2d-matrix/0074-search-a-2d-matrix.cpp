class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int  s = 0, e = m*n-1;

        while(s<=e){
            int mid = s + (e-s)/2;
            int i = mid / n;
            int j = mid % n;
            if(matrix[i][j] == target) return true;

            if(matrix[i][j] > target){
                e = mid -1;
            }else{
                s = mid + 1;
            }
        } 
        return false;
    }
};