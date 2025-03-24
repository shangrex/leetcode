/*
class node {
    public:
    node *post;
    node *prev;
    int key, value;
    node(int key, int value){
        this->key = key;
        this->value = value;
        this->post = NULL;
        this->prev = NULL;
    }
};


class LRUCache {
public:
    // store all key and the node address
    unordered_map<int, node*>mp;
    node *head = new node(0, 0);
    node *tail = new node(0, 0);
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->post = tail;
        tail->prev = head;
    }
    
    
    void remove(node* r_node){
        node *prev = r_node->prev;
        node *next = r_node->post;
        prev->post = next;
        next->prev = prev;
    }
    
    
    // add the node in the head of the list
    void insert(node *i_node){
        node *next = head->post;
        next->prev = i_node;
        head->post = i_node;
        i_node->post = next;
        i_node->prev = head;
    }    
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
          
        if(mp.find(key) != mp.end()){
            // key already exist
            cout << "touch " << key << endl;
            remove(mp[key]);
            insert(mp[key]);
            mp[key]->value = value;
        }
        else {
            // cout << this->capacity << endl;
            // cout << mp.size();
            if(this->capacity == mp.size()){
                cout <<"remove value : " << tail->prev->value << endl;
                node *element_tail = tail->prev;
                remove(element_tail);
                mp.erase(element_tail->key);
                
                node *new_node = new node(key, value);
                insert(new_node);
                mp[key] = new_node;
                
            }
            else {
                cout << "input" << key << " " << value << endl;
                node *new_node = new node(key,value);
                insert(new_node);
                mp[key] = new_node;
                //cout << "size" << mp.size() << endl;
            }
        }
    }
};
*/
class node {
    public:
    node *post;
    node *prev;
    int key, value;
    node(int key, int value){
        this->key = key;
        this->value = value;
        this->post = NULL;
        this->prev = NULL;
    }
};


class LRUCache {
public:
    // store all key and the node address
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    list<pair<int, int>> lru;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = dict.find(key);

        if(it == dict.end()){
            return -1;
        }

        int val = it->second->second;

        lru.erase(it->second);
        lru.push_front({key, val});

        dict.erase(it);
        dict[key] = lru.begin();
        return val;
    }
    
    void put(int key, int value) {
        auto it = dict.find(key);

        if(it != dict.end()){
            // exist
            lru.erase(it->second);
            dict.erase(it);
            lru.push_front({key, value});
            dict[key] = lru.begin();
        }
        else {
            // not exist
            if(capacity == lru.size()){
                // full
                auto del = dict.find(lru.rbegin()->first);
                dict.erase(del);
                lru.pop_back();
            }

            lru.push_front({key, value});
            dict[key] = lru.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */