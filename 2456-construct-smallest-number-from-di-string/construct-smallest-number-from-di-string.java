class Solution {
    public String smallestNumber(String pattern) {
        StringBuilder num = new StringBuilder();
        int cnt = 1, n = pattern.length();
        Stack<Character> st = new Stack<>();
        for(int i = 0; i<=n; i++){
            st.push((char)(cnt+'0'));
            cnt++;
            if(i<n && pattern.charAt(i) == 'I'){
                while(!st.isEmpty()){
                    num.append(st.pop());
                }
            }
        }
        while(!st.isEmpty()){
            num.append(st.pop());
        }
        return num.toString();
    }
}