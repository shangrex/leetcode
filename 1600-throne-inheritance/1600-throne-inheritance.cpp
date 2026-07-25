class ThroneInheritance {
private:
    set<string> dead; // store who is alive
    unordered_map<string, vector<string>> family;
    string king;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void dfs(vector<string> &ret, string cur){
        if(dead.count(cur) == 0)  ret.push_back(cur);
        for(auto &i : family[cur]){
            dfs(ret, i);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> ret;
        dfs(ret, king);
        return ret;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */