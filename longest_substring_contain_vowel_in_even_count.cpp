class Solution {
public:
    int findTheLongestSubstring(string s) {
         unordered_map<int, int> maskMap;
    maskMap[0] = -1; // To handle the case when the entire substring from the beginning is valid
    
    int mask = 0; // Bitmask representing the current state of vowels
    int maxLength = 0;
    
    // Traverse the string
    for (int i = 0; i < s.size(); ++i) {
        // Update the mask based on the current character
        if (s[i] == 'a') {
            mask ^= (1 << 0); // Toggle the bit for 'a'
        } else if (s[i] == 'e') {
            mask ^= (1 << 1); // Toggle the bit for 'e'
        } else if (s[i] == 'i') {
            mask ^= (1 << 2); // Toggle the bit for 'i'
        } else if (s[i] == 'o') {
            mask ^= (1 << 3); // Toggle the bit for 'o'
        } else if (s[i] == 'u') {
            mask ^= (1 << 4); // Toggle the bit for 'u'
        }
        
        // Check if the current mask has been seen before
        if (maskMap.find(mask) != maskMap.end()) {
            // Calculate the length of the substring
            maxLength = max(maxLength, i - maskMap[mask]);
        } else {
            // Store the first occurrence of this mask
            maskMap[mask] = i;
        }
    }
    
    return maxLength;

    }
};
