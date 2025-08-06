// class LRUCache {
// public:
//     list<int> dll; //it contains the key
//     map<int, pair<list<int>::iterator, int>> cache; //key->(list_node, value)
//     int capacity;
    
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }
    
//     void makeMostRecentlyUsed(int key) {
//         dll.erase(cache[key].first);
//         dll.push_front(key);
//         cache[key].first = dll.begin();
//     }
    
//     int get(int key) {
//         if(!cache.count(key))
//             return -1;
        
//         makeMostRecentlyUsed(key);
//         return cache[key].second;
//     }
    
//     void put(int key, int value) {
//         if(cache.count(key)) {
//             cache[key].second = value;
//             makeMostRecentlyUsed(key);
//         } else {
//             dll.push_front(key);
//             cache[key] = {dll.begin(), value};
//             capacity--;
//         }
        
//         if(capacity < 0) {
//             cache.erase(dll.back());
//             dll.pop_back();
//             capacity++;
//         }
//     }
// };

class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newnode){
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if(m.size() == cap){
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};