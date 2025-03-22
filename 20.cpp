class Solution {
    public:
        bool opposite(int x, int y) {
            if (x == '(' && y == ')') return true;
            if (x == '[' && y == ']') return true;
            if (x == '{' && y == '}') return true;
            return false;
        }
        bool isValid(string s) {
            stack<char> st;
            for (auto x : s) {
                if (st.empty()) {
                    if (x == '(' || x == '[' || x == '{') {
                        st.push(x);
                    } else return false;
                } else {
                    if (x == '(' || x == '[' || x == '{') {
                        st.push(x);
                    } else if (opposite(st.top(), x)) {
                        st.pop();
                    } else return false;
                }
            }
            return st.empty();
        }
    };