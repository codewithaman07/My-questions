#include <list>
#include <map>
using namespace std;

class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mp;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void recent(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        int val = mp[key].second;
        recent(key);
        return val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key].second = value;
            recent(key);
        } else {
            if (dll.size() == capacity) {
                int lru = dll.back();
                dll.pop_back();
                mp.erase(lru);
            }
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
