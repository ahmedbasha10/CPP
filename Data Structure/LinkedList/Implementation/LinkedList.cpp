#include <iostream>

using namespace std;


template <typename T> struct Node{
    T value;
    Node<T>* prev;
    Node<T>* next;
    
    Node(T value, Node<T>* prev, Node<T>* next) : value(value), prev(prev), next(next){}
    Node(T value) : value(value), prev(nullptr), next(nullptr){}
};

template <typename T> class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size = 0;
public:
    LinkedList() : head(nullptr), tail(nullptr){}

    bool IsEmpty(){
        return size == 0;
    }
    void InsertFirst(T value){
        Node<T>* newNode = new Node<T>(value);
        if(size == 0){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }
    void AppendNode(T value){
        Node<T>* newNode = new Node<T>(value);
        if(size == 0){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev= tail;
            tail = newNode;
        }
        ++size;
    }
    void InsertAt(int position, int value){
        if(position < 0 || position > size){
            cout << "Insert Out Of Range\n";
            return; 
        }
        if(position == 0){
            InsertFirst(value);
        }
        else if(position == size){
            AppendNode(value);
        }
        else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* iterator = head;
            for(int i = 1; i < position; ++i){
                iterator = iterator->next;
            }
            newNode->next = iterator->next;
            newNode->prev = iterator;
            iterator->next->prev = newNode;
            iterator->next = newNode;
            ++size;
        }
    }
    void PopHead(){
        if(IsEmpty()){
            cout << "Linked List is Empty\n";
            return;
        }
        else if(size == 1){
            delete head;
            head = tail = nullptr;
        }
        else{
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        --size;
    }
    void PopTail(){
        if(IsEmpty()){
            cout << "Linked List is Empty\n";
            return;
        }
        else if(size == 1){
            delete tail;
            head = tail = nullptr;
        }
        else{
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        --size;
    }
    void RemoveAt(int position){
        if(position < 0 || position >= size){
            cout << "Delete Out Of Range\n";
            return;
        }
        if(position == 0){
            PopHead();
        }
        else if(position == size-1){
            PopTail();
        }
        else{
            Node<T>* iterator = head;
            for(int i = 1; i <= position; ++i){
                iterator = iterator->next;
            }
            iterator->prev->next = iterator->next;
            iterator->next->prev = iterator->prev;
            delete iterator;
            --size;
        }
    }
    void Print(){
        Node<T>* temp = head;
        for(int i = 0; i < size; ++i){
            if(i == 0){
                cout << temp->value << " " << temp->next->value << endl;
            }
            else if(i == size-1){
                cout << temp->value << " " << temp->prev->value << endl;
            }
            else{
                cout << temp->value << " " << temp->next->value << " " << temp->prev->value << endl;    
            }
            temp = temp->next;
        }
    }
};


int main(){

    LinkedList<int> list;
    
    list.AppendNode(1);
    list.AppendNode(2);
    list.AppendNode(3);
    list.InsertFirst(4);
    list.InsertAt(2, 10);
    list.InsertAt(2, 15);
    cout << list.IsEmpty() << "\n";
    list.Print();
    cout << "************************\n";
    list.PopHead();
    list.PopTail();
    list.RemoveAt(2);
    list.RemoveAt(30);
    list.Print();
    return 0;
}