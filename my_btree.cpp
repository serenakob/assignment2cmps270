#include <iostream>
#include "vector"

using namespace std;
template <class T>
struct treeNode {
    T * data;
    struct treeNode * left;
    struct treeNode * right;
};
template <class T>


struct btree {
private:
    vector< treeNode<T>*> nodes ;
    //requires: nothing
    // effects: returns size of a tree 
    int treeSize(treeNode<T>* root){
        if (root == NULL){
            return 0;
        }
        int roott =1;
        return roott + treeSize(root->left) + treeSize(root->right);
    }
    //requires: nothing
    // effects: find parents index
    int parentind(int node){
        return (node-1)/2;
    }
    //requires: nothing 
    //effects: prints the post order traversal of the tree
    void postOrderPrint(treeNode<T>* root){
        if (root != NULL){
        postOrderPrint(root->left);
        postOrderPrint(root->right);
        cout<<*(root->data);
        }
    }
    //requires: nothing 
    //effects:prints the pre order traversal of the tree
    void preOrderPrint(treeNode<T>* root){
        if (root != NULL){
        cout<<*(root->data);
        preOrderPrint(root->left);
        preOrderPrint(root->right);
        }
    }
    //requires: nothing 
    //effects: prints the in order traversal of the tree
    void inOrderPrint(treeNode<T>* root){
       if (root != NULL){
        inOrderPrint(root->left);
        cout<<*(root->data);
        inOrderPrint(root->right);
       }
    }

public:
    //requires: nothing 
    //effects:add node to the tree at highet possible level
    void addNode(T data){
        int *n = new int;
        *n= data;
        treeNode<T> *temp = new treeNode<T>;
        *temp = &n;
        int index=0;
        for (int i = 0; i < nodes.size(); i++) {
            if(nodes[i] == NULL){
                index = i;
                break;
            }
            else {
                index = i++;
            }
        }
        if (index < nodes.size()){
          nodes[index] = temp;  
        } 
        else {
            nodes.push_back(temp);
        }
        if (index != 0){
            int parent = parentind(index);
            if(nodes[parent]->left != NULL) {
                nodes[parent]->right = temp;
            }
            else {
                nodes[parent]->left = temp;
            }
        }

    }
 
    //requires: nothing 
    //effects:function that deletes a node from the tree
    void deleteNode(T data){
        int index = -1;
        for(int i = 0; i<nodes.size(); i++){
            if (nodes[i] != NULL && *(nodes[i]->data) == data){
                index = i;
            }
        }
        if (index != -1 && nodes[index]->left == NULL && nodes[index]->right == NULL){
            treeNode<T> *temp = nodes[index];
            nodes[index] = NULL;
            if (index != 0){
                int parent = parentind(index);
                if (index%2 == 0) nodes[parent]->right = NULL;
                else nodes[parent]->left = NULL;
            }
            free(temp);
        }
        else cout<<"CANNOT DELETE NODE"<<endl;
    }
    //requires: nothing
    //effects: find tree size
    int treeSize(){
        if (nodes.size() == 0) return 0;
        return treeSize(nodes[0]);
    }
    //requires: nothing
    //effects: find subtree size
    int subtreeSize(T data){
        int index = -1;
        for(int i = 0; i<nodes.size(); i++){
            if (nodes[i] != NULL && *(nodes[i]->data) == data){
                index = i;
            }
        }
        if (index != -1) return treeSize(nodes[index]);
        return 0;
    }
    void postOrderPrint(){
        postOrderPrint(nodes[0]);
    }
    void preOrderPrint(){
        preOrderPrint(nodes[0]);
    }
    void inOrderPrint(){
        inOrderPrint(nodes[0]);
    }

};

//main class to test our tree
int main() {
    btree<int> tree;
    tree.addNode(1);
    tree.addNode(4);
    tree.addNode(7);
    cout<<tree.treeSize()<<endl;
    tree.postOrderPrint();
    tree.addNode(2);
    tree.addNode(3);
    tree.addNode(9);
    tree.inOrderPrint();
    tree.addNode(5);
    cout<<tree.treeSize()<<endl;
    cout<<endl;
    tree.postOrderPrint();
    cout<<endl;
    tree.preOrderPrint();
}
