#include<iostream>
#include<string.h>
using namespace std;

string postOrder="";
struct treeNode{
    treeNode* left=NULL;
    treeNode* right=NULL;
    char node;
};
//初始指针设置为NULL，防止指针乱指，出现判断NULL结果不一致的情况
treeNode* createTree(string preOrder,string inOrder);
void postorderSearch(treeNode* node);

int main(){
    string preOrder,inOrder;
    while(cin>>inOrder>>preOrder){
        treeNode* tree=createTree(preOrder,inOrder);
        // cout<<tree->node<<" "<<tree->left->node<<" "<<tree->right->node<<endl;
        postorderSearch(tree);
        cout<<postOrder<<endl;
        postOrder="";
    }
    return 0;

}

treeNode* createTree(string preOrder,string inOrder){
    if(preOrder.length()==0)
        return NULL;
    else if(inOrder.length()==0)
        return NULL;

    string rootNode=preOrder.substr(0,1);
    int index=inOrder.find(rootNode);
    string inOrder1,inOrder2;
    inOrder1=inOrder.substr(0,index);
    inOrder2=inOrder.substr(index+1,inOrder.length()-index-1);

    string preOrder1,preOrder2;
    preOrder1=preOrder.substr(1,inOrder1.length());
    preOrder2=preOrder.substr(inOrder1.length()+1,preOrder.length()-inOrder1.length()-1);

    // cout<<preOrder1<<" "<<preOrder2<<endl;
    // cout<<inOrder1<<" "<<inOrder2<<endl;
    // cout<<rootNode[0]<<endl;
    
    treeNode* node=new treeNode;
    node->node=rootNode[0];
    if(inOrder1.length()!=0)
        node->left=createTree(preOrder1,inOrder1);
    if(inOrder2.length()!=0)
        node->right=createTree(preOrder2,inOrder2);   
    return node;

}

void postorderSearch(treeNode* node){
    if(node==NULL){
        return;
    }

    // cout<<node->node<<endl;
    treeNode* leftNode=node->left;
    treeNode* rightNode=node->right;
    postorderSearch(leftNode);
    postorderSearch(rightNode);

    string str(1,node->node);
    postOrder.append(str);
}



/**
 * inOrder = ABEDFCHG
 * preOrder= CBADEFGH
 * 
 * 
 * 样例输出:
 * postOrder=AEFDBHGC
 * 
 *  前序遍历方式为：根节点->左子树->右子树

    中序遍历方式为：左子树->根节点->右子树

    后序遍历方式为：左子树->右子树->根节点

    ABEDFCHG
    CBADEFGH
 */