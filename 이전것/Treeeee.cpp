//
//  Tree.cpp
//  baek
//
//  Created by Sean on 2017. 11. 2..
//  Copyright © 2017년 Sean. All rights reserved.
//
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Tree;
template <typename T>
class Node {
    friend class Tree<T>;
private:
    T data;
    Node* left;
    Node* right;
public:
    Node(T data = 0, Node* left = NULL, Node* right = NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class Tree {
private:
    Node<T>* root;
public:
    Tree(T data = 0) {
        root = new Node<T>(data);
    }
    void buildTree() {
        root->left = new Node<T>('B', new Node<T>('D', new Node<T>('H')), new Node<T>('E', new Node<T>('I'), new Node<T>('J')));
        root->right = new Node<T>('C', new Node<T>('F'), new Node<T>('G', NULL, new Node<T>('K')));
    }
    
    Node<T>* SetRoot() {
        return root;
    }
    
    void Print(Node<T>* cur) {
        cout << cur->data << " ";
    }
    
    // 전위 순회
    void preorder(Node<T>* cur) {
        if (cur != NULL) {
            Print(cur);
            preorder(cur->left);
            preorder(cur->right);
        }
    }
    
    // 중위 순회
    void inorder(Node<T>* cur) {
        if (cur != NULL) {
            inorder(cur->left);
            Print(cur);
            inorder(cur->right);
        }
    }
    
    // 후위 순회
    void postorder(Node<T>* cur) {
        if (cur != NULL) {
            postorder(cur->left);
            postorder(cur->right);
            Print(cur);
        }
    }
    //레벨 순회
    void levelorder(Node<T>* cur){
        cout << "Levelorder >> ";
        queue<Node<T>*> q;
        q.push(cur);
        while(!q.empty()){
            Node<T>* now=q.front();
            q.pop();
            if(now != NULL){
                Print(now);
                q.push(now->left);
                q.push(now->right);
            }
        }
    }
};

int main() {
    Tree<char> tree('A');
    tree.buildTree();
    cout << "Preorder >> ";// 출력문 함수안에 넣기
    tree.preorder(tree.SetRoot());
    cout << endl;
    
    cout << "Inorder >> ";
    tree.inorder(tree.SetRoot());
    cout << endl;
    
    cout << "Postorder >> ";
    tree.postorder(tree.SetRoot());
    cout << endl;
    
    tree.levelorder(tree.SetRoot());
}
