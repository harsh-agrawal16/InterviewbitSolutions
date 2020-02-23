/*
Given N x M character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)



Input Format:

    The First and only argument is a N x M character matrix.
Output Format:

    Return a single integer denoting number of black shapes.
Constraints:

    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'
Example:

Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X
Note: we are looking for connected shapes here.

XXX
XXX
XXX
is just one single connected black shape.
*/
int X[] = { 1 , 0 , -1 , 0};
int Y[] = { 0 , 1 , 0 , -1};

void dfs(vector<vector<int>> &visited, vector<string> &A, int i, int j, int n, int m){
    stack<pair<int,int>> s;
    s.push({i,j});
    while(!s.empty()){
        int x = s.top().first;
        int y = s.top().second;
        visited[x][y] = 1;
        s.pop();
        
        for(int i=0;i<4;i++){
            int new_x = x + X[i];
            int new_y = y + Y[i];
            
            if(new_x >=0 && new_x < n && new_y >= 0 && new_y < m && A[new_x][new_y] == 'X' && !visited[new_x][new_y]){
                //visited[new_x][new_y] = 1;
                s.push({new_x,new_y});
            }
        }
        
    }
    return;
}

int Solution::black(vector<string> &A) {
    
    int n = A.size();
    int m = A[0].length();
    
    vector<vector<int>> visited(n,vector<int>(m,0));
    
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == 'X' && !visited[i][j]){
                count++;
                dfs(visited, A, i, j, n, m);
            }
        }
    }
    
    return count;
}
