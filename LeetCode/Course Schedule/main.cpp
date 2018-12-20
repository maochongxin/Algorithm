class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int inDegree[numCourses];
        list<int>* adjList = new list<int>[numCourses];
        queue<int> vec;
        memset(inDegree,0,sizeof(inDegree));
        for (auto i : prerequisites) {
            adjList[i.first].push_back(i.second);
            inDegree[i.second]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                vec.push(i);
            }
        }
        int count = 0;
        while (!vec.empty()) {
            int v = vec.front();
            vec.pop();
            for (auto it = adjList[v].begin(); it != adjList[v].end(); it++) {
                inDegree[*it]--;
                if (inDegree[*it] == 0) {
                    vec.push(*it);
                }
            }
            count++;
        }
        return count == numCourses;
    }
};
