struct fileNode{
    unordered_map<string, fileNode*> next;
    bool isFile;
    string content;
    fileNode(){
        content = "";
        isFile = false;
    }
};

class FileSystem {
public:

    fileNode *root;
    FileSystem() {
        root = new fileNode();
    }
    
    fileNode* goPath(string path){
        fileNode *cur = root;
        stringstream ss(path);
        string line = "";
        while(getline(ss, line, '/')){
            if(cur->next[line] == NULL){
                cur->next[line] = new fileNode();
            }
            cur = cur->next[line];
        }
        return cur;
    }

    vector<string> ls(string path) {
        fileNode *cur = goPath(path);

        if(cur->isFile){
            string tmp = path.substr(path.rfind('/')+1);
            cout << tmp;
            return {tmp};
        }

        vector<string> rst;
        for(auto &p : cur->next){
            rst.push_back(p.first);
        }
        sort(rst.begin(), rst.end());
        return rst;
    }
    
    void mkdir(string path) {
        fileNode *cur = goPath(path);
    }
    
    void addContentToFile(string filePath, string content) {
        fileNode* cur = goPath(filePath);
        cur->content += content;
        cur->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        fileNode *cur = goPath(filePath);
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */