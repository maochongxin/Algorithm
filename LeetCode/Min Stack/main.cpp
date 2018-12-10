class MinStack {
public:
    /** initialize your data structure here. */
    
    vector<int> vec;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if (vec.empty()) {
            vec.push_back(x);
            vec.push_back(x);
        } else {
            int t = *(vec.end() - 1);
            vec.push_back(x);
            if (t < x) {
                vec.push_back(t);
            } else {
                vec.push_back(x);
            }
        }
    }
    
    void pop() {
        vec.pop_back();
        vec.pop_back();
    }
    
    int top() {
        return *(vec.end() - 2);
    }
    
    int getMin() {
        return *(vec.end() - 1);
    }
};
