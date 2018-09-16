//
//  02.cpp
//  baek
//
//  Created by Sean on 2017. 10. 13..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
using namespace std;
class Node{
    friend class List;
private:
    Node* next;
    Node* prev;
    int val;
    Node(Node* n, Node* p, int v){
        this->next = n;
        this->prev = p;
        this->val = v;
    }
    Node(int v){
        this->next = NULL;
        this->prev = NULL;
        this->val = v;
    }
};
class List{
private:
    Node* first;
    Node* last;
    int size;
public:
    List(int val){
        last = first = new Node(val);
        size = 1;
    }
    void Push_right(int val){
        Node* newNode = new Node(val);
        if (first == NULL)
            last = first;
        else{
            newNode->next = first;
            first->prev = newNode;
        }
        first = newNode;
        size++;
    }
    void Push_left(int val){
        Node* newNode = new Node(val);
        if (last == NULL)
            first = last;
        else{
            newNode->prev = last;
            last->next = newNode;
        }
        last = newNode;
        size++;
    }
    void Push(int index, int val){
        if (index <0 || index >= size){
            cout << "인덱스 범위 초과" << endl;
            return;
        }
        else if (index == 0){
            Push_right(val);
        }
        else if (index == size-1){
            Push_left(val);
        }
        else{
            Node* newNode = new Node(val);
            Node* cur = first;
            newNode->next = cur;
            newNode->prev = cur->prev;
            cur->prev->next = newNode;
            cur->prev = newNode;
        }
        size++;
    }
    void Del(){
        if(first != NULL){
            Node* remove = first;
            first = first->next;
            first->prev = NULL;
            delete remove;
            size--;
        }
    }
    void print(){
        Node* cur = first;
        while(cur != NULL){
            if (cur->next == NULL)
                cout << cur->val << endl;
            else
                cout << cur->val << " ";
            cur = cur->next;
        }
    }
    ~List(){
        Node* cur = first;
        while (cur != NULL)
            Del();
    }
};
int main(){
    
    return 0;
}
