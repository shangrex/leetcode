struct event{
    int id;
    string status;
    int timestamp;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stringstream ss;        
        int pos = 0;
        vector<event> e;
        for(int i = 0; i < logs.size(); i++){
            string log = logs[i];
            pos = log.find(":");
            int id = stoi(log.substr(0, pos));
            log = log.substr(pos+1);
            pos = log.find(":");
            string status = log.substr(0, pos);
            int timestamp = stoi(log.substr(pos+1));
            e.push_back({id, status, timestamp});
        }

        vector<int> ret(n, 0);
        stack<event> st;
        for(int i = 0; i < e.size(); i++){
            if(e[i].status == "start"){
                if(!st.empty()){
                    auto tope = st.top();
                    st.pop();
                    cout << tope.timestamp << " " << e[i].timestamp << endl;
                    ret[tope.id] += e[i].timestamp - tope.timestamp;
                    tope.timestamp = e[i].timestamp-1;
                    st.push(tope);
                }
                st.push(e[i]);
            }
            else {
                if(st.empty()) return {};
                auto tope = st.top();
                st.pop();
                cout << tope.timestamp << " " << e[i].timestamp << endl;
                ret[tope.id] += e[i].timestamp - tope.timestamp+1;

                if(!st.empty()){
                    auto tope = st.top();
                    tope.timestamp = e[i].timestamp+1;
                    st.pop();
                    st.push(tope);
                }
            }

        }

        return ret;
    }
};