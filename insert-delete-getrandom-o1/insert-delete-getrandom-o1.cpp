class RandomizedSet {
public:
    unordered_map<int,int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool ok = true;
        if(m.find(val) == m.end()) ok = true;
        else ok = false;
        m[val] = 1;
        return ok;
    }
    
    bool remove(int val) {
        bool ok = true;
        if(m.find(val) != m.end()) ok = true;
        else ok = false;
        m[val] = 0;
        if(m[val] == 0) m.erase(val);
        return ok;
    }
    
    int getRandom() {
        auto it = m.begin();
        advance(it, rand() % m.size());
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */