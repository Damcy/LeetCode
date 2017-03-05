// author: Ian
// create on: 2017-03-05
// email: stmayue@gmail.com
// description: LRU Cache

struct CacheNode
{
    int key;
    int value;
    CacheNode(int k, int v): key(k), value(v) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        } else {
            bi_list.splice(bi_list.begin(), bi_list, cache_map[key]);
            cache_map[key] = bi_list.begin();
            return cache_map[key]->value;
        }
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) == cache_map.end()) {
            if (bi_list.size() == size) {
                cache_map.erase(bi_list.back().key);
                bi_list.pop_back();
            }
            bi_list.push_front(CacheNode(key, value));
            cache_map[key] = bi_list.begin();
        } else {
            cache_map[key]->value = value;
            bi_list.splice(bi_list.begin(), bi_list, cache_map[key]);
            cache_map[key] = bi_list.begin();
        }
    }
private:
    list<CacheNode> bi_list;
    unordered_map<int, list<CacheNode>::iterator> cache_map;
    int size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */