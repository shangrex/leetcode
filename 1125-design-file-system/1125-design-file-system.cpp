class FileSystem {
public:

    unordered_map<string, int>mp;
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        if(mp.find(path) != mp.end()){
            return false;
        }

        // /leet/code
        // /leet
        auto f = path.rfind("/");
        // cout << f <<endl;
        string parent = path.substr(0, f);
        // cout << parent << endl;
        if(parent != "" && mp.find(parent) == mp.end()){
            // not exist
             return false;
        }

        mp[path] = value;
        return true;
    }
    
    int get(string path) {
        if(mp.find(path) == mp.end()) return -1;
        return mp[path];   
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */