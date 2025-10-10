import java.util.HashSet;

public class LongestSubstringWithoutRepeatingCharacters {
    
    // Function to find length of the longest substring without repeating characters
    public static int lengthOfLongestSubstring(String s) {
        // 'left' and 'right' define the sliding window boundaries
        int left = 0, maxLen = 0;
        
        // HashSet to store unique characters in the current window
        HashSet<Character> set = new HashSet<>();

        // Move the 'right' pointer one step at a time
        for (int right = 0; right < s.length(); right++) {
            // If the current character already exists in the set,
            // remove characters from the left until it becomes unique
            while (set.contains(s.charAt(right))) {
                set.remove(s.charAt(left)); // remove leftmost character
                left++; // move window forward
            }

            // Add the current character to the set
            set.add(s.charAt(right));

            // Update the maximum length found so far
            maxLen = Math.max(maxLen, right - left + 1);
        }

        // Return the length of the longest substring
        return maxLen;
    }
}

//     // Main method for testing
//     public static void main(String[] args) {
//         System.out.println(lengthOfLongestSubstring("abcabcbb")); // Output: 3 ("abc")
//         System.out.println(lengthOfLongestSubstring("bbbbb"));    // Output: 1 ("b")
//         System.out.println(lengthOfLongestSubstring("pwwkew"));   // Output: 3 ("wke")
//     }

