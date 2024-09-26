class Solution {
public:
    int find_p(vector<int>& ps, int i) {
        return ps[i] == i ? i : ps[i] = find_p(ps, ps[i]); 
    }
    void union_p(vector<int>& ps, vector<int>& cs, int i, int j) {
        int pi = find_p(ps, i), pj = find_p(ps, j);
        if (pi != pj) {
            ps[pi] = pj;
            cs[pj] += cs[pi];
        }
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<int> ps(n), cs(n, 1);
        iota(ps.begin(), ps.end(), 0);
        for (int i=0; i<n; ++i){
            for (int j=0; j<i; ++j){
                if (graph[i][j]){
                    union_p(ps, cs, i, j);
                }
            }
        }
        vector<int> ct(n);
        for (int i : initial){
            ++ct[find_p(ps, i)];
        }
        int msf_i = *min_element(initial.begin(), initial.end()), msf = 0;
        for (int i : initial) {
            if (ct[find_p(ps, i)] != 1) continue;
            int s = cs[find_p(ps, i)];
            if (s > msf) msf = s, msf_i = i;
            if (s == msf) msf_i = min(msf_i, i);
        }
        return msf_i;   
    }
};
