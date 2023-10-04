class MyHashMap {
public:
    vector<int> keys;
    vector<int> values;
    MyHashMap() {
    }
    void put(int key, int value) {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if(it!=keys.end()){
            values[(it - keys.begin())] = value;
        }else{
            keys.push_back(key);
            values.push_back(value);
        }
        
    }
    int get(int key) {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if(it==keys.end()){
            return -1;
        }else{
            return values[it-keys.begin()];
        }
    }
    void remove(int key) {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if(it!=keys.end()){
            keys.erase(it);
            values.erase(values.begin() + (it - keys.begin()));
        }
    }
};