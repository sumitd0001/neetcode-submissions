class MyHashSet {
public:
    vector<int> result;

    MyHashSet() {
        
    }

    void add(int key) {
        if (!contains(key)) {
            result.push_back(key);
        } 
    }
    
    void remove(int key) {
        for (int i = 0; i<result.size(); ++i) {
            if (result[i] == key) {result[i] = -1; break;}
        } 
    }
    
    bool contains(int key) {
        for (auto x : result) {
            if (x == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */