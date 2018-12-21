class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int inDegree[numCourses];
        vector<int> res;
        list<int>* adjList = new list<int>[numCourses];
        queue<int> vec;
        memset(inDegree, 0, sizeof(inDegree));
        for (auto i : prerequisites) {
            adjList[i.first].push_back(i.second);
            inDegree[i.second]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                vec.push(i);
                res.push_back(i);
            }
        }
        
        while (!vec.empty()) {
            int v = vec.front();
            vec.pop();
            for (auto it = adjList[v].begin(); it != adjList[v].end(); it++) {
                inDegree[*it]--;
                if (inDegree[*it] == 0) {
                    vec.push(*it);
                    res.push_back(*it);
                }
            }
        }
        reverse(res.begin(),res.end());
        if (res.size() < numCourses) {
            res.clear();
        }
        return res;
    }
};
