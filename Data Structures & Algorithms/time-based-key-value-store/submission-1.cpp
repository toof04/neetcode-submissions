class TimeMap {
private : 
public:
    TimeMap() {
        // unordered_map<string, vector<pair<int,string>>>keyStore;
    }
    unordered_map<string, vector<pair<int,string>>>keyStore;
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto &values = keyStore[key];
        auto it = lower_bound(values.begin(), values.end(), timestamp, []( pair<int, string>element, int timestamp){return element.first < timestamp;});
        if(it!=values.end() and it->first == timestamp)return it->second;

        if(it==values.begin()){return "";}
        --it;
        return it->second;

    }

};
