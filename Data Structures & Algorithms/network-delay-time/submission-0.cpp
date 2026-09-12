class Solution {

    struct cmp {
        bool operator() (auto& x, auto& y) {
            return x[0] > y[0];
        }
    };

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<vector<int>>> adj;
        for(auto& t: times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        int minTime = 0;
        vector<int> visited(n + 1, 0);
        priority_queue<
        vector<int>,
        vector<vector<int>>,
        cmp
        > pq;

        pq.push({0, k});
        while(!pq.empty()) {
            int time = pq.top()[0], node = pq.top()[1];
            pq.pop();

            if(visited[node]) continue;

            minTime = time;
            visited[node] = 1;
            for(auto& n: adj[node]) {
                if(!visited[n[0]]) {
                    pq.push({n[1] + time, n[0]});
                }
            }
        }

        for(int i = 1; i <= n; i++)
            if(!visited[i]) return -1;

        return minTime;
    }
};