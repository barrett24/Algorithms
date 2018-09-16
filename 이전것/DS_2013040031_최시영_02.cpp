#include <iostream>
using namespace std;
typedef int Data;

class Node{
    friend class List;
protected:
    Data data;
    Node *next;
    Node *prev;
};

class List{
private:
    Node *head;
    Node *tail;
    Node *cur;
    int index = 0;
public:
    List(){
        head = NULL;
        tail = NULL;
        index = 0;
    }
    int Count(){
        return index;
    }
    void Insert(Data data){
        Node *newNode = new Node;
        newNode->data = data;
        
        if (head == NULL){
            head = newNode;
            tail = newNode;
            head->prev = NULL;
            tail->next = NULL;
            index++;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            newNode->next = NULL;
            index++;
        }
    }
    int Insert_Select(int num){//선택한 노드에 입력
        cur = head;
        Node *Now = new Node;
        int val;
        if (cur == NULL){
            cout << "노드가 존재하지 않습니다." << endl;
            return 0;
        }
        while(--num){
            cur = cur->next;
        }
        cout << "입력할 값을 입력하세요 : ";
        cin >> val;
        Now->data = val;
        Now->next = cur;
        Now->prev = cur->prev;
        cur->prev->next = Now;
        cur->prev = Now;
        index++;
        return 1;
    }
    int Print_Select(int num){//노드 선택 -> 앞,뒤 정보도 출력
        cur = head;
        if(cur == NULL){
            cout << "노드가 존재하지 않습니다." << endl;
            return 0;
        }
        cout << "선택한 노드(" << num << "번째) : ";
        while(--num){
            cur = cur->next;
        }
        cout << cur->data << " 앞노드 : " << cur->prev->data << " 다음노드 : " << cur->next->data << endl;
        return 1;
    }
    int Print_Front()
    {
        cur = head;
        
        if (cur == NULL){
            cout << "노드가 존재하지 않습니다." << endl;
            return 0;
        }
        cout << "리스트 출력 : ";
        while (cur != tail->next ){
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
        return 1;
    }
    
    int Print_Back(){
        cur = tail;
        
        if (cur == NULL){
            cout << "노드가 존재하지 않습니다." << endl;
            return 0;
        }
        cout << "리스트 역순출력 : ";
        while (cur != head->prev ){
            cout << cur->data << " ";
            cur = cur->prev;
        }
        cout << endl;
        return 1;
    }
    int Del_Select(int num){//노드 선택 삭제
        cur = head;
        if (cur == NULL){
            cout << "노드가 존재하지 않습니다." << endl;
            return 0;
        }
        while(--num){
            cur = cur->next;
        }
        Node* Left = cur->prev;
        Node* Right = cur->next;
        Left->next = Right;
        if(Right)
            Right->prev = Left;
        delete cur;
        index--;
        return 1;
    }
    int Del_Front(){
        cur = head;
        if (cur == NULL){
            cout << "노드가 존재하지 않습니다." << endl;
            return 0;
        }
        if(cur->next != NULL){
            cur->next->prev = NULL;
            head = cur->next;
            delete cur;
        }
        else{
            head = NULL;
            tail = NULL;
            delete cur;
        }
        
        index--;
        return 1;
    }
    
    int Del_Back(){
        cur = tail;
        if (cur == NULL){
            cout << "노드가 존재하지 않습니다." << endl;
            return 0;
        }
        if (cur->prev != NULL){
            cur->prev->next = NULL;
            tail = cur->prev;
            delete cur;
        }
        else{
            head = NULL;
            tail = NULL;
            delete cur;
        }
        
        index--;
        return 1;
    }
    void Search(int num){
        int i=0, cnt=0;
        cur = head;
        if (cur == NULL){
            cout << "노드가 존재하지 않습니다." << endl;
        }
        else{
            while(cur != tail->next){
                i++;
                if(num == cur->data){
                    cnt++;
                    cout << i << "번째 노드에서 탐색되었습니다." << endl;
                }
                cur = cur->next;
            }
        }
        if(cnt == 0)
            cout << "탐색되지 않았습니다." << endl;
    }
};

int main()
{
    List list;
    int value;
    int num;
    
    while (1){
        cout << "현재 노드 개수 :: " << list.Count() << endl;
        cout << "1:입력 2:선택 입력 3:앞에서 출력 4:뒤에서 출력 5:선택 출력 6:앞의 값 삭제 7:뒤의 값 삭제 8:지정 삭제 9:탐색\n10:종료" << endl;
        cout << "메뉴 선택 :: ";
        cin >> num;
        
        switch(num){
            case 1:
                cout << "값을 입력 하시오 : ";
                cin >> value;
                list.Insert(value);
                break;
            case 2:
                cout << "끼워넣을 노드를 입력하시오 : ";
                cin >> num;
                list.Insert_Select(num);
                break;
            case 3:
                list.Print_Front();
                break;
            case 4:
                list.Print_Back();
                break;
            case 5:
                cout << "보여질 노드를 선택하시오 : ";
                cin >> num;
                list.Print_Select(num);
                break;
            case 6:
                list.Del_Front();
                break;
            case 7:
                list.Del_Back();
                break;
            case 8:
                cout << "지정 삭제할 노드를 입력하시오 : ";
                cin >> num;
                list.Del_Select(num);
                break;
            case 9:
                cout << "탐색할 숫자를 입력하시오 : ";
                cin >> num;
                list.Search(num);
                break;
            case 10:
                return 0;
        }
    }
}
