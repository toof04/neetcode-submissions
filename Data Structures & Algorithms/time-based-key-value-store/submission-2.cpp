class TimeMap {
private : 
public:
    TimeMap() {
    }
    unordered_map<string, vector<pair<int,string>>>keyStore;
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto &values = keyStore[key];
        auto it = upper_bound(values.begin(), values.end(), timestamp, []( int timestamp, pair<int, string>element){return element.first > timestamp;});

        if(it==values.begin()){return "";}
        --it;
        return it->second;
    }

};
