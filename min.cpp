#include<iostream>
using namespace std;
int getj(int *st,int n,int k,int t){
    while (k>0){
        if(k%2==0){
            k=(k-1)/2;
        }
        else{
            break;
        }
    }
    while(k<n-1){
        if(st[k]<st[t]){
            if(st[k*2+1]<st[t]){
                return k=2*k+1;
            }
            else if(st[k*2+1]<st[t]){
                return k=k*2+2;
            }
        }
        else{
            return getj(st,n,k,t);
        }
    }
    return 0;
}
void build(int*st,int l,int r,int i,int a[]){
    if(l==r){
        st[i]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(st,l,mid,2*i+1,a);
    build(st,mid+1,r,2*i+2,a);
    st[i]=min(st[2*i+1],st[2*i+1]);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int d[4*n-1];
    int *st=d;
    build(st,0,n-1,0,a);
    int k;
    cin>>k;
    int result=getj(st,sizeof(st),n-1+k,n-1+k);
    cout<<result<<endl;
}