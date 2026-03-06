#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
struct Node 
{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val) {};
};
class Cache
 {
protected:
    map<int, Node*> mp;
    int cp;
    Node* tail;
    Node* head;
    virtual void set(int, int) = 0;
    virtual int get(int) = 0;
};
class LRUCache : public Cache
 {
public:
    LRUCache(int capacity) 
    {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }
    void set(int k, int v) override
     {
        if (mp.find(k) != mp.end()) 
        {
            Node* node = mp[k];
            node->value = v;
            moveToHead(node);
            return;
        }
        Node* newNode = new Node(k, v);
         if (mp.empty()) 
         {
            head = tail = newNode;
        } 
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        mp[k] = newNode;
        if (mp.size() > cp) {
            Node* temp = tail;
            mp.erase(tail->key);
            tail = tail->prev;
            if (tail) tail->next = NULL;
            delete temp;
        }
    }
    int get(int k) override 
    {
        if (mp.find(k) == mp.end())
         {
            return -1;
        }
        Node* node = mp[k];
        moveToHead(node);
        return node->value;
    }
private:
    void moveToHead(Node* node)
     {
        if (node == head) return;
        if (node == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->next = head;
        node->prev = NULL;
        head->prev = node;
        head = node;
    }
};
int main() 
{
   int n, capacity, i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) 
   {
      string command;
      cin >> command;
      if(command == "get") 
      {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set")
       {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
