class Solution {
public:
    class DSU {
    private:
        vector<int> parent;
    public:
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int node) {
            if (parent[node] == node) return node;
            return parent[node] = find(parent[node]);
        }

        bool unite(int u, int v) {
            int rootu = find(u);
            int rootv = find(v);
            if (rootu == rootv) return false;
            parent[rootu] = rootv;
            return true;
        }
    };

    int kruskals(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int weight = 0;
        int edgesused = 0;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dsu.unite(u, v)) {
                weight += wt;
                edgesused++;
                if (edgesused == n - 1) break;
            }
        }
        return edgesused == n - 1 ? weight : INT_MAX;
    }

    int kruskalskip(int n, vector<vector<int>>& edges, int from, int to) {
        DSU dsu(n);
        int weight = 0;
        int edgesused = 0;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (u == from && v == to) continue;

            if (dsu.unite(u, v)) {
                weight += wt;
                edgesused++;
                if (edgesused == n - 1) break;
            }
        }
        return edgesused == n - 1 ? weight : INT_MAX;
    }

    int kruskalforced(int n, vector<vector<int>>& edges, int from, int to, int forcedwt) {
        DSU dsu(n);
        int weight = 0;
        int edgesused = 0;

        dsu.unite(from, to);
        weight += forcedwt;
        edgesused++;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dsu.unite(u, v)) {
                weight += wt;
                edgesused++;
                if (edgesused == n - 1) break;
            }
        }
        return edgesused == n - 1 ? weight : INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // store original index at edges[i][3] before sorting
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int basemstweight = kruskals(n, edges);
        vector<vector<int>> result(2);

        for (int i = 0; i < edges.size(); i++) {
            // critical: removing it increases MST weight (or disconnects the graph)
            if (kruskalskip(n, edges, edges[i][0], edges[i][1]) > basemstweight) {
                result[0].push_back(edges[i][3]);
            }
            // pseudo-critical: forcing it in still gives an MST of the same weight
            else if (kruskalforced(n, edges, edges[i][0], edges[i][1], edges[i][2]) == basemstweight) {
                result[1].push_back(edges[i][3]);
            }
        }

        return result;
    }
};