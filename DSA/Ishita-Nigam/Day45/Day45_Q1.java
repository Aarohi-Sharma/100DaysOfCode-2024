//Long Pressed Name
public class Day45_Q1 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Test cases
        System.out.println(solution.isLongPressedName("alex", "aaleex")); 
        System.out.println(solution.isLongPressedName("saeed", "ssaaedd")); 
        System.out.println(solution.isLongPressedName("leelee", "lleeelee")); 
        System.out.println(solution.isLongPressedName("laiden", "laiden")); 
    }
}

class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int i = 0, j = 0;

        while (j < typed.length()) {
            if (i < name.length() && name.charAt(i) == typed.charAt(j)) {
                i++;
                j++;
            } else if (j > 0 && typed.charAt(j) == typed.charAt(j - 1)) {
                j++;
            } else {
                return false;
            }
        }

        return i == name.length();
    }
}
