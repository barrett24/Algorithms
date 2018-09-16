//
//  HW.cpp
//  baek
//
//  Created by Sean on 2017. 9. 20..
//  Copyright © 2017년 Sean. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Queue{
private:
    Queue *first;
    Queue *last;
    int num;
public:
    Queue *next;
    Queue *prev;
    Queue(){
        num=0;
        this->first = NULL;
        this->last = NULL;
    }
    ~Queue(){};
    bool empty(){
        if(this->first == NULL){
            return true;// 비어있으면 1 반환
        }
        else{
            return false;//비어있지 않으면 0 반환
        }
    }
    void push(int num){
        Queue *NewData = new Queue();
        NewData->next = NULL;
        NewData->prev = NULL;
        NewData->num = num;
        if(this->first == NULL){
            this->first = NewData;
            this->last = NewData;
        }
        else{
            last->next = NewData;
            NewData->prev = last;
            last = last->next;
        }
    }
    void pop(){
        Queue *temp;
        temp = first;
        first = first->next;
        delete temp;
    }
    int size(){//문자열의 길이 반환
        int cnt=0;
        Queue *p=first;
        while(p != NULL){
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    void front(){//맨 앞 자료 출력
        if(!empty()){
            cout << first->num << endl;
        }
    }
    void back(){//맨 뒤 자료 출력
        if(!empty()){
            cout << last->num << endl;
        }
    }
    void print(){//자료가 있으면 자료 출력
        Queue *p=first;
        if(!empty()){
            for(;p!=NULL;p=p->next){
                cout<<p->num<< " ";
            }
            cout << endl;
        }else cout << "Nothing!!!" << endl;
    }
};
int main(){
    int n;//명령 실행 횟수
    cout << "명령을 실행할 횟수를 입력하세요 : ";
    cin >> n;
    Queue q;
    
    while(n--){
        string cmd;
        cin >> cmd;//명령어 입력
        if(cmd == "push"){//stl의 queue와 최대한 비슷하게 구현했습니다.
            int num;
            cin >> num;
            q.push(num);
        }else if (cmd == "pop"){
            if(q.empty()){
                cout << -1 << endl;
            }else{
                q.front(); cout << "out!" << endl;
                q.pop();
            }
        }else if(cmd == "size"){
            cout << q.size() << endl;
        }else if(cmd == "empty"){
            cout << q.empty() << endl;
        }else if(cmd == "front"){
            if(q.empty()){
                cout << -1 << endl;
            }else{
                q.front();
            }
        }else if (cmd == "back"){
            if(q.empty()){
                cout << -1 << endl;
            }else{
                q.back();
            }
        }else if (cmd == "print"){
            q.print();
        }
    }
    return 0;
}
