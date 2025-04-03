struct Log {
    int id;
    string status;
    int timeStamp;
};


class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n, 0);
        stack<Log> st;
        for(auto &log : logs){
            stringstream ss(log);
            string s_st, s_time, s_id;
            getline(ss, s_id, ':');
            getline(ss, s_st, ':');
            getline(ss, s_time, ':');
            Log item = {stoi(s_id), s_st, stoi(s_time)};
            // cout << s_id << " " << s_st << " " << s_time << endl;

            
            if(item.status == "start"){
                st.push(item);
            }
            else {
                Log tp = st.top();
                int diff = item.timeStamp - tp.timeStamp + 1;
                ret[item.id] += diff;
                st.pop();

                if(!st.empty()){
                    ret[st.top().id] -= diff;
                }
            }

        }
        return ret;
    }
};