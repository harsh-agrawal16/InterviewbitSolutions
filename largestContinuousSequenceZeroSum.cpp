vector<int> Solution::lszero(vector<int> &A) {
    
    unordered_map<int,int> HashMap;
    vector<int> sol;
    //HashMap[0] = -1;
    int sum=0;
    int ans=0;
    int begin,end;
    
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(A[i]==0) {
            //ans = max(ans,1);
            if(ans<1){
                begin=i;
                end=i;
                ans = 1;
            }
        }
        
        if(sum==0) {
            //ans = max(ans,i+1);
            if(ans < i+1){
                begin = 0;
                end = i;
                ans = i+1;
            }
        }
            
        if(HashMap.find(sum)!=HashMap.end()){
            if(ans < i - HashMap[sum]){
                ans = i- HashMap[sum];
                begin = HashMap[sum]+1;
                end = i;
            }
        }
        else{
            HashMap[sum] = i;
        }
    }
    
    for(int i=begin;i<=end;i++){
        sol.push_back(A[i]);
    }
    
    return sol;
}

