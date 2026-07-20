class Solution {
public:
    void helper(int i,int j,int col,vector<vector<int>>&grid){
        while(i<j){
            int r1=i/col,c1=i%col;
            int r2=j/col,c2=j%col;

            swap(grid[r1][c1],grid[r2][c2]);
            i++;j--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        int total=m*n;
        k%=total;
        if(k==0) return grid;
        helper(0,total-1,n,grid);
        helper(0,k-1,n,grid);
        helper(k,total-1,n,grid);

        return grid;
        
        
    }
};