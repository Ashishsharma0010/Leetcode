class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //brute force method because it is going every element and checking wheater it is 0 or not 
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
         
         for(int i=0; i<n; i++){
            for(int j=0;  j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=-1;
                    col[j]=-1;
                
                }

            }
         }
         //elements ko jo maine -1 kiya h jaha pr 0 tha unki m zero m convert kr raha hu ek or four loop use krke
          
          for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i]==-1 || col[j]==-1){
                  matrix[i][j]=0;
                }
            }
          }

         
   
        
    }
};