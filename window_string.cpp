string Solution::minWindow(string A, string B) {
    int len1=A.length();
    int len2=B.length();
    
    if(len2>len1) return "";
    
    //hash maps to store the occurences of characters in the pattern and the string respectively.
    vector<int> hash_pat(256,0);
    vector<int> hash_str(256,0);
    
    for(int i=0;i<len2;i++){
        hash_pat[B[i]]++;
    }
    
    int count=0,start=0,start_index=-1;
    int ans=INT_MAX;
    
    for(int i=0;i<len1;i++){
        hash_str[A[i]]++;
        
        if(hash_pat[A[i]] != 0 && hash_str[A[i]]<=hash_pat[A[i]]) count++;
        
        if(count==len2){
            //now try and decrease the window size
            while(hash_pat[A[start]]==0 || hash_str[A[start]]>hash_pat[A[start]]){
                if(hash_str[A[start]]>hash_pat[A[start]]) hash_str[A[start]]--;
                start++;
            }
            
            int curr_len=i-start+1;
            if(ans > curr_len){
                ans = curr_len;
                start_index = start;
            }
        }
    }
    
    if(start_index==-1) return "";
    else return A.substr(start_index,ans);
    
}
