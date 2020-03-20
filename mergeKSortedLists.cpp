/*
Merge k sorted linked lists and return it as one sorted list.
Example :
1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in
1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
https://www.interviewbit.com/problems/merge-k-sorted-lists/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
void heapify(vector<ListNode*> &A, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;
    
    if(l<n && !A[l] && A[l]->val < A[smallest]->val){
        smallest = l;
    }
    
    
    if(r<n && !A[r] && A[r]->val < A[smallest]->val){
        smallest = r;
    }
    
    if(smallest != i){
        swap(A[i],A[smallest]);
        heapify(A,n,smallest);
    }
}
 
 
/*ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
 
    int n = A.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(A,n,i);
    }

    ListNode* head = A[0];
    ListNode* temp = head;
    A[0]=A[0]->next;
    
    int j=0;
    while(j<n){
        while(A[j] == NULL) j++;
        if(j>=n) break;
        temp->next = A[j];
        A[j] = A[j]->next;
        if(A[j]) heapify(A,n,j);
        temp = temp->next;
    }
    
    temp->next = NULL;
    
    return head;
    
}*/
struct compare{
    bool operator()(ListNode* const&a, ListNode* const& b)
    {
        return a->val > b->val;
    }
};


ListNode* Solution::mergeKLists(vector<ListNode*> &A){
    
    int n = A.size();
    if(n==0) return NULL;
    
    ListNode* head = NULL;
    ListNode* last = NULL;
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    
    for(auto i = 0;i<n;i++){
        if(A[i]) pq.emplace(A[i]);
    }
    
    while(!pq.empty()){
        
        ListNode* temp = pq.top();
        pq.pop();
        
        if(head== NULL){
            head = temp;
            last = head;
        }
        
        else{
            last->next = temp;
            last = last->next;
        }
        
        
        if(temp->next) pq.emplace(temp->next);
        
    }
    
    last->next = NULL;
    
    return head;
    
    
    
}










