/*
Given N bags, each bag contains Ai chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Ai chocolates, then the magician fills the ith bag with floor(Ai/2) chocolates.

Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units of time.

For example,

K = 3
N = 2
A = 6 5

Return: 14

At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates
At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates
At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate
so, total number of chocolates eaten: 6 + 5 + 3 = 14

Note: Return your answer modulo 10^9+7
*/

void heapify(vector<int> &chocos, int n, int i){
     int largest = i;
     int l = 2*i+1;
     int r = 2*i+2;
     
     if(l<n && chocos[l]>chocos[largest]){
         largest = l;
         
     }
     
     if(r<n && chocos[r]>chocos[largest] ){
         largest = r;
     }
     
     if(largest!=i){
         swap(chocos[i],chocos[largest]);
         heapify(chocos,n,largest);
     }
     
}
 
 
int Solution::nchoc(int A, vector<int> &B) {
    int n = B.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(B,n,i);
    }
    
    long long int d = pow(10, 9) + 7;
    long long int ans=0;
    while(A && n>0){
        ans = (ans%d + B[0]%d)%d;
        B[0] = B[0]/2;
        heapify(B,n,0);
        A--;
    }
    
    return ans%d;
    
    
}

