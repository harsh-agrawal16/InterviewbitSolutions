/*
There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:

The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
Output Format:

Return an integer representing the minimal cost required.
Constraints:

1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3
Examples:

Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6
  */

/*This solution is using Prim's Algorithm but memory limit exceeds in this case*/
/*Kruskal's would be more better, look below for a more better solution*/

int Solution::solve(int A, vector<vector<int> > &B) {
    
    int k;
    //created an adjacency matrix for the graph first.
    vector<vector<int>> adList(A+1, vector<int> (A+1, INT_MAX));
    for(int i=0;i<B.size();i++){
        adList[B[i][0]][B[i][1]] = B[i][2];
        adList[B[i][1]][B[i][0]] = B[i][2];
    }
    
    int ans=0;
    vector<vector<int>> edges(2,vector<int>(A-1));
    
    vector<int> near(A+1,INT_MAX);
    
    int min_cost = INT_MAX;
    
    //checking only the upper triangular portion of the matrix as the graph is undirected.
    for(int gap=0;gap<A;gap++){
        for(int i=0,j=gap;j<=A;i++,j++){
            if(adList[i][j]<min_cost){
                edges[0][0] = i;
                edges[1][0] = j;
                min_cost = adList[i][j];
            }
        }
    }
    near[edges[0][0]] = 0;
    near[edges[1][0]] = 0;
    //e++;
    int u = 
    ans+=min_cost;
    
    //first update of near
    for(int i=1;i<=A;i++){
        if(near[i]!=0){
            near[i] = (adList[edges[0][0]][i] > adList[edges[1][0]][i])? edges[1][0] : edges[0][0];
        }
    }
    
    //now repetitive step starts.
    for(int i=1;i<A-1;i++){
        min_cost = INT_MAX;
        for(int j=1;j<=A;j++){
            if(near[j]!=0 && adList[j][near[j]]<min_cost){
                min_cost = adList[j][near[j]];
                edges[0][i] = j;
                edges[1][i] = near[j];
                k = j;
            }
        }
        ans+=min_cost;
        near[k] = 0;
        
        for(int i=1;i<=A;i++){
            if(near[i]!=0){
                near[i] = (adList[i][near[i]] > adList[k][i])? k : near[i];
            }
        }
        
    }
    
    return ans;
}




/*Using Kruskal's algorithm*/

bool comp(vector<int> a , vector<int> b){
    return a[2] < b[2];
}

int find(int parent[], int u){
    if(parent[u] < 0){
        return u;
    }
    return find(parent, parent[u]);
}

void Union(int parent[] , int a, int b){
    
    int x = find(parent,a);
    int y = find(parent,b);
    
    if(parent[x] < parent[y]){
        parent[x] = parent[x] + parent[y];
        parent[y] = x;
    }else{
        parent[y] = parent[x] + parent[y];
        parent[x] = y;
    }
    
}

int Solution::solve(int A, vector<vector<int> > &B) {   
    
    sort(B.begin(),B.end(),comp);
    
    int parent[A+1];
    fill_n(parent, A+1, -1);
    
    
    int ans = 0;
    
    for(int i=0;i<B.size();i++){
        //check to see if they have same or different parents
        int a = find(parent,B[i][0]);
        int b = find(parent,B[i][1]);
        
        //if different we will do union now
        if(a!=b){
            Union(parent,a,b);
            ans+=B[i][2];
        }
    }
    
    
    return ans;
}