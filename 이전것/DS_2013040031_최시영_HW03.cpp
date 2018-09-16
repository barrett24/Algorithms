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
    int cnt=1;
public:
    Tree(T data = 0) {
        root = new Node<T>(data);
    }
    //트리 만들기
    void Make(Node<T>* cur) {
        T cmd;
        queue<Node<T>*> t;
        t.push(cur);
        cout << "나머지 성분 입력 >> ";
        
        while(!t.empty()){
            Node<T>* now = t.front();
            t.pop();
            if(now != NULL){
                cin >> cmd;
                if(cmd != '@'){// 널문자 '\0'
                    now -> left = new Node<T>(cmd);
                    t.push(now->left);
                }
                cin >> cmd;
                if(cmd != '@'){
                    now -> right = new Node<T>(cmd);
                    t.push(now->right);
                }
            }
        }
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
    char start;
    
    cout << "루트 성분 입력 >> ";
    cin >> start;
    Tree<char> tree(start);
    
    tree.Make(tree.SetRoot());
    
    cout << "Preorder >> ";
    tree.preorder(tree.SetRoot());
    cout << endl;
    
    cout << "Inorder >> ";
    tree.inorder(tree.SetRoot());
    cout << endl;
    
    cout << "Postorder >> ";
    tree.postorder(tree.SetRoot());
    cout << endl;
    
    cout << "Levelorder >> ";
    tree.levelorder(tree.SetRoot());
    cout << endl;
}
