class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
    }
    
    int get(int key) {
        if (_size == 0) {
            return -1;
        }
        auto it = _list.begin();
        for (int i = 0; i < _size; ++i) {
            if (it->key == key) {
                auto node = *it;
                _list.erase(it);
                _list.push_front(node);
                return node.value;
            }
            ++it;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        auto it = _list.begin();
        for (int i = 0; i < _size; ++i) {
            if (it->key == key) {
                it->value = value;
                auto node = *it;
                _list.erase(it);
                _list.push_front(node);
                return;
            }
            ++it;
        }

        if (_size == _capacity) {
            _list.pop_back();
            --_size;
        }
        _list.push_front({key, value});
        ++_size;
    }

private:
    struct Node {
        int key;
        int value;
        Node(int _key, int _value): key(_key), value(_value) {}
    };
    list<Node> _list;
    int _capacity;
    int _size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
