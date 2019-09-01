#include <iostream>

using namespace std;

void buildTree(int* arr,int* tree,int start,int end,int treeNodeid){
    
    if(start == end){
        tree[treeNodeid] = arr[start];
        return;
    }
    
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNodeid);
    buildTree(arr,tree,mid+1,end,2*treeNodeid+1);
    
    tree[treeNodeid]=tree[2*treeNodeid]+tree[2*treeNodeid+1];
}


void update(int* arr,int* tree,int start,int end,int node,int ind,int val){
    if(start == end){
        arr[ind] += val;
        tree[node] += val;
        return;
    }
    int mid=(start+end ) / 2;
    if(ind <= mid && ind>=start){
        update(arr,tree,start,mid,2*node,ind,val);
    }else{
        update(arr,tree,mid+1,end,2*node + 1,ind,val);
    }
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int* arr,int* tree,int start,int end,int node,int l,int r){
    if( l>end || r<start ) return 0;
    else{
        if(l<=start && end<=r){
            // Node Interval Completly contained
            return tree[node];
        }else{
            int mid=(start+end)/2;
            int left=query(arr,tree,start,mid,2*node,l,r);
            int right=query(arr,tree,mid+1,end,2*node+1,l,r);
            return left+right;
        }
    }
}


int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int* tree=new int[18];
    buildTree(arr,tree,0,8,1);
    update(arr,tree,0,8,1,0,5);
    cout<<query(arr,tree,0,8,1,3,6)<<endl;
    cout<<arr[0]<<endl;
    
    return 0;
}
