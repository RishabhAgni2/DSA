class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> st;  // stores current path length at each depth
        int maxLen = 0;
        int i = 0;
        
        while (i < input.size()) {
            int depth = 0;
            
            // Count depth (\t)
            while (i < input.size() && input[i] == '\t') {
                depth++;
                i++;
            }
            
            int start = i;
            bool isFile = false;
            
            // Find full name (until newline)
            while (i < input.size() && input[i] != '\n') {
                if (input[i] == '.')
                    isFile = true;
                i++;
            }
            
            int len = i - start;  // length of current name
            
            // Move to next line
            i++;
            
            // Adjust stack to current depth
            while (st.size() > depth)
                st.pop();
            
            if (isFile) {
                int currLen = len;
                if (!st.empty())
                    currLen += st.top();
                
                maxLen = max(maxLen, currLen);
            } else {
                int currLen = len + 1;  // +1 for '/'
                if (!st.empty())
                    currLen += st.top();
                
                st.push(currLen);
            }
        }
        
        return maxLen;
    }
};