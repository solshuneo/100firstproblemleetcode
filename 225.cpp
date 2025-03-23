class MyStack {
    public:
        vector<int> value;
        MyStack() {
            
        }
        
        void push(int x) {
            value.emplace_back(x);
        }
        
        int pop() {
            int v = *value.rbegin();
            value.pop_back();
            return v;
        }
        
        int top() {
            return *value.rbegin();
        }
        
        bool empty() {
            return value.size() == 0;
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */