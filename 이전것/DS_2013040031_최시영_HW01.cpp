#include <iostream>
#include <string>
using namespace std;
class Queue{
private:
    Queue *first;
    Queue *last;
    string smt;//입력받는 문자열(숫자, 알파벳, 한글 모두가능)
public:
    Queue *next;
    Queue *prev;
    Queue(){
        smt={0};
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
    void push(string smt){
        Queue *NewData = new Queue();
        NewData->next = NULL;
        NewData->prev = NULL;
        NewData->smt = smt;
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
            cout << first->smt << endl;
        }
    }
    void back(){//맨 뒤 자료 출력
        if(!empty()){
            cout << last->smt << endl;
        }
    }
    void print(){//자료가 있으면 자료 출력
        Queue *p=first;
        if(!empty()){
            for(;p!=NULL;p=p->next){
                cout<<p->smt<< " ";
            }
            cout << endl;
        }else cout << "Nothing!!!" << endl;
    }
};
int main(){
    //setlocale(LC_ALL, "");
    int n;//명령 실행 횟수
    cout << "명령을 실행할 횟수를 입력하세요 : ";
    cin >> n;
    Queue q;
    
    while(n--){
        string cmd;
        cin >> cmd;//명령어 입력
        if(cmd == "push"){//stl의 queue와 최대한 비슷하게 구현했습니다.
            string smt;
            cin >> smt;
            q.push(smt);
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
        }else if (cmd == "quit"){//종료 커맨드
            cout << "bye~~" << endl;
            break;
        }
    }
    return 0;
}
