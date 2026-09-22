struct node{
    int product;
    int count[5];
    node(){
        memset(count,0,sizeof(count));
        product=1;
    }
    node(int num,int k){ //some methods make life easier
        memset(count,0,sizeof(count));
        count[product=num%k]=1;
    }
    void join(node& right, int k){
        for(int x=0;x<k;x++) count[(product*x)%k]+=right.count[x];
        product=(product*right.product)%k;
    }
};
node seg[4*100001];
void buildTree(vector<int>& nums, int id, int l, int r, int k){
    if (l == r) {
        seg[id]=node(nums[l],k);
        return;
    }
    int mid = (l + r) / 2;
    buildTree(nums,id*2,l,mid,k);
    buildTree(nums,id*2+1,mid+1,r,k);
    //you finally read this line, I was too lazy so,
    //well, I went to the internet, searched basic segment tree implement, copied the build func, paste, 
    //forget it for a while, to mess with node, 
    //dup this into update/querry, add the two bellow lines, add vairable k, 
    //nothing to special about this function LOL
    seg[id]=seg[id*2];
    seg[id].join(seg[id*2+1],k);
}
void update(int id, int l, int r,int i, int u, int k){
    if(i<l||i>r) return; 
    if (l==r) {
        seg[id]=node(u,k);
        return;
    }
    int mid = (l + r) / 2;
    if(mid>=i) update(id*2,l,mid,i,u,k); else update(id*2+1,mid+1,r,i,u,k);
    seg[id]=seg[id*2];
    seg[id].join(seg[id*2+1],k);
}
node querry(int id, int l, int r, int ql, int qr,int k){
    if(r<ql||l>qr) return node(); 
    if(ql<=l&&r<=qr) return seg[id];
    int mid = (l + r) / 2;
    node left=querry(id*2,l,mid,ql,qr,k), right=querry(id*2+1,mid+1,r,ql,qr,k);
    left.join(right,k);
    return left;
}

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        buildTree(nums,1,0,n-1,k);
        vector<int> res; res.reserve(queries.size());
        for(auto&q:queries){
            int index=q[0],val=q[1],start=q[2],x=q[3];
            update(1,0,n-1,index,val,k);
            res.push_back(querry(1,0,n-1,start,n-1,k).count[x]);
        }
        return res;
    }
};