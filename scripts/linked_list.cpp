
struct node{
  node *prv, *nxt;
  int val;
  node(int x){
    val = x;
    prv = nxt = NULL;
  }
};
struct LL{
  node *head, *tail;
  map<int, node*> pos;
  LL(){
    head = tail = NULL;
  }
  
  void push_back(int x){
    node *cur = new node(x);
    if(head == NULL){
      head = tail = cur;
      pos[x] = head;
    }
    else {
      tail->nxt = cur;
      cur->prv = tail;
      tail = cur;
      pos[x] = tail;
    }
  }
  void push_front(int x){
    node *cur = new node(x);
    if(head == NULL){
      head = tail = cur;
      pos[x] = head;
    }
    else {
      head->prv = cur;
      cur->nxt = head;
      head = cur;
      pos[x] = head;
    }
  }

  void print(){
    node *now = head;
    while(now != NULL){
      cout << (now->val) << ' ';
      now = now->nxt;
    }
    cout << '\n';
  }
};
