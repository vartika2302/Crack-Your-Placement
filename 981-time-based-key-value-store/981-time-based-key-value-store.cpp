class TimeMap {
private:
    map<string,map<int,string>>mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!mpp.count(key)) return "";
        for(int currtime = timestamp;currtime>=1;currtime--) {
            if(mpp[key].count(currtime)) return mpp[key][currtime];
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */