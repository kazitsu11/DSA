struct segmentTree{
vector<long long>tree;
vector<int>arr;
int n;

 long long combine(long long a,long long b){
    return a+b;
 }

 void build(int node,int left,int right){
    if(left==right){
        tree[node]=arr[left];
        return;
    }
    int mid=left+(right-left)/2;

    build(2*node+1,left,mid);

    build(2*node+2,mid+1,right);

    tree[node]=combine(tree[2*node+1],tree[2*node+2]);
 }
  long long query(int node,int left,int right,int ql,int qr){
    if(ql>right || qr<left){
        return 0;
    }
    else if(ql<=left && qr>=right){
        return tree[node];
    }
    int mid=left+ (right-left)/2;

    long long leftans=query(2*node+1,left,mid,ql,qr);
    long long rightans=query(2*node+2,mid+1,right,ql,qr);

    return combine(leftans,rightans);
    }
  
 void update(int node,int left,int right,int index,int value){
   if(left==right){
    arr[index]=value;
    tree[node]=value;
    return;
   }

   int mid=left+(right-left)/2;

   if(index<=mid){
    update(2*node+1,left,mid,index,value);
   }
   else{
    update(2*node+2,mid+1,right,index,value);
   }

    tree[node]=combine(tree[2*node+1],tree[2*node+2]);
 }
 segmentTree(vector<int>&nums){
    arr=nums;
    n=arr.size();
    tree.resize(4*n);

    build(0,0,n-1);
  }

  long long query(int ql,int qr){
    return query(0,0,n-1,ql,qr);
  }

  void update(int index,int value){
     update(0,0,n-1,index,value);
  }
};
class NumArray {
public:
segmentTree st;
    NumArray(vector<int>& nums):st(nums) {
    }
    
    void update(int index, int val) {
         st.update(index,val);
    }
    
    int sumRange(int left, int right) {
        return st.query(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */