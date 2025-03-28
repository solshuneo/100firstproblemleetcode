class MyQueue {
    public:
        queue<int> qu;
        MyQueue() {
            
        }
        
        void push(int x) {
            qu.push(x);
        }
        
        int pop() {
            int t = qu.front();
            qu.pop();
            return t;
        }
        
        int peek() {
            return qu.front();
        }
        
        bool empty() {
            return qu.empty();
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */