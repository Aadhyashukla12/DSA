class Solution {
public:
    int longestValidParentheses(string s) {
        
        // Stack will store indices of characters.
        // We push -1 to act as a base boundary BEFORE the string starts.
        stack<int> st;
        st.push(-1);

        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                // Store index of '(' so that a future ')' can match it
                st.push(i);
            } 
            else { // current char is ')'

                // Pop once: this attempts to match this ')' with a previous '('
                st.pop();

                if (st.empty()) {
                    // Stack became empty → no '(' was available to match this ')'
                    // This ')' is UNMATCHED → it BREAKS the valid substring chain.
                    //
                    // So we push its index as a NEW BOUNDARY.
                    // Any valid substring must start after this position.
                    st.push(i);
                } 
                else {
                    // Stack NOT empty → st.top() is the index BEFORE
                    // the current valid substring.
                    //
                    // Length of valid substring ending at i = i - st.top()
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};