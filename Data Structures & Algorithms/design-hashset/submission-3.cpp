class MyHashSet {

    private : 
        vector<bool> res;

    public : 

        MyHashSet () : res(1000001, 0) {}

        void add (const int& key) {
            res[key] = true;
        }
        bool contains (const int& key) {
            return res[key];
        }
        void remove (const int& key) {
            res[key] = false;
        }
};









































/*
class MyHashSet {
public:
    vector<bool> result;

    MyHashSet() : result(1000001, false) {}

    void add(int key) {
        result[key] = true; 
    }
    
    void remove(int key) {
        result[key] = false; 
    }
    
    bool contains(int key) {
        return result[key];
    }
};
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */