template <class T>
class MyList{
public:
    List(){
        head = nullptr;
        length = 0;
        q = nullptr;
        p = nullptr;
    }
    void add(T t){
        if (head == nullptr){
            q = new Node();
            q->data = t;
            q->next = NULL;
            length++;
            head = q;
            p = head;
        }else{
            q = new Node();
            q->data = t;
            q->next = NULL;
            length++;
            p->next = q;
            p = q;
        }
    }
    void remove(int t){
        if(length >= length){
            return;
        }
        length--;
        //delete head
        if(n==0){
            q = head;
            head = head->next;
            delete (q);
        }else{
            q = head;
            for(int i = 0;i < n-1;i++){
                q = q->next;
            }
            Node *t = q->next;
            q->next = q->next->next;
            delete (t);
        }
        p = head;
        if(p!=nullptr){
            while(p->next ==nullptr){
                p = p->next;
            }
        }
    } 
    int getSize(){
        return length;
    }
    
    int getLength(){
        return getSize();
    }

    T  get(int n){
        q = head;
        for(int i = 0;i<n;i++){
            q = q->next;
        }
        return q->data;
    }
private:
    struct Node{
        T data;
        Node *next;
    };
    Node *head;
    //size 
    int length;
    //process 
    Node *p;
    //temp 
    Node *q;
};