#include<iostream>
using namespace std;
struct node{
    int key;
    struct node*l;
    struct node*r;
    int sum;
};
struct node *newNode(int item)
{
    struct node *temp =  new node;
    temp->key = item;
    temp->l = temp->r = NULL;
    temp->sum=0;
    return temp;
}
int Sum(struct node*n){
    if(n==NULL){
        return 0;
    }
    n->sum=n->key+Sum(n->l)+Sum(n->r);
    return n->sum; 
}
int prefixSum(struct node*n){
    return((n->sum)-(n->r->sum)-n->key);
}
int main(){
    struct node *root = newNode(11);
    root->l = newNode(2);
    root->r = newNode(29);
    root->l->l = newNode(1);
    root->l->r = newNode(7);
    root->r->l = newNode(15);
    root->r->r = newNode(40);
    root->r->r->l = newNode(35);
    Sum(root);
    cout<<prefixSum(root)<<endl;
    return 0;
}