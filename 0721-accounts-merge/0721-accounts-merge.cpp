class Solution {
public:
    /*
    Hint: DFS 

    email to accounts
    email1: [node1, node2]
    email2: [node1]
    email3: [node3]

    <node1, <email1, email2>>
    dfs()
    Hint: Union Find
    */

    void dfs(set<string> &email,int i, vector<int>&visited, map<string, vector<int>>&emailToAccounts, vector<vector<string>>&accounts){
        if(visited[i] == 1) return;
        
        visited[i] = 1;

        for(int a = 1; a < accounts[i].size(); a++){
            email.insert(accounts[i][a]);
            for(int b = 0; b < emailToAccounts[accounts[i][a]].size(); b++){
                dfs(email,emailToAccounts[accounts[i][a]][b] , visited, emailToAccounts, accounts);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        map<string, vector<int>> emailToAccounts;

        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                emailToAccounts[accounts[i][j]].push_back(i);
            }
        }

        vector<int>visited(n, 0);
        vector<vector<string>>rst;
        for(int i = 0; i < accounts.size(); i++){
            if(visited[i] == 0){
                set<string>email;
                dfs(email,i,visited,emailToAccounts,accounts);
                vector<string>tmp;
                tmp.push_back(accounts[i][0]);
                for(auto e : email){
                    tmp.push_back(e);
                }
                rst.push_back(tmp);
            }
        }

        return rst;
    }
};