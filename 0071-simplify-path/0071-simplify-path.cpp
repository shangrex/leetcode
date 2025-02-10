class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        path += "/";
        while(true){
            int pos = path.find("/");
            if(pos < 0) {
                break;
            }
            string elem = path.substr(0, pos);
            cout << elem << endl;
            if(elem == ".." && !st.empty()){
                st.pop_back();
            }
            else if(elem != "" && elem != ".." && elem != ".") {
                // else
                st.push_back(elem);
            }
            path = path.substr(pos+1);
            // cout << path << endl;
            // cout << "ne" << endl;
        }

        string ret = "/";
        bool flag = false;
        for(int i = 0; i < st.size(); i++){
            ret += st[i] + "/";
            flag = true;
        }
        if(flag)ret.pop_back();
        return ret;
    }
};