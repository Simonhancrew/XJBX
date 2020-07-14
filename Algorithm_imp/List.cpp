template<class T> 
class List { 
private: 
  struct Node { 
    T data; 
    Node *next; 
  }; 
  //head 
  Node *head; 
  //size 
  int length; 
  //process 
  Node *p; 
  //temp 
  Node *q; 
public: 
  List() 
  { 
    head = NULL; 
    length = 0; 
    p = NULL; 
  } 
  void add(T t) 
  { 
    if(head == NULL) 
    { 
      q = new Node(); 
      q->data = t; 
      q->next = NULL; 
      length ++ ; 
      head = q ; 
      p = head; 
    } 
    else
    { 
      q = new Node(); 
      q->data = t; 
      q->next = NULL; 
      length ++; 
      p -> next = q; 
      p = q; 
    } 
  }  
  void remove(int n) 
  { 
    if(n >= length ) 
    { 
      return; 
    } 
    length -- ; 
    //删除头节点 
    if(n == 0) 
    { 
      q = head ; 
      head = head -> next; 
      delete(q); 
    } 
    else
    { 
      q = head; 
      for(int i = 0 ; i < n-1 ; i++) 
      { 
        q = q -> next; 
      } 
      Node *t = q ->next; 
      q->next = q->next ->next; 
      delete(t);   
    } 
    // 
    p = head; 
    if (p != NULL) 
    { 
      while(p->next != NULL) 
      { 
        p = p->next; 
      } 
    }   
  }   
  int getSize() 
  { 
    return length; 
  }  
  int getLength() 
  { 
    return getSize(); 
  }  
  T get(int n) 
  { 
    q = head; 
    for (int i = 0 ;i < n ; i++) 
    { 
      q = q->next; 
    } 
    return q->data; 
  } 
}; 
