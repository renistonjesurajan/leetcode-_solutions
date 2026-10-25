char* longestCommonPrefix(char** strs, int strsSize) {
    // If the input array is empty, return an empty string
    if (strsSize == 0) {
        return "";
    }
    
    // Take the first string as a reference
    char* first_str = strs[0];
    
    // Loop through each character of the first string
    for (int i = 0; first_str[i] != '\0'; i++) {
        char ch = first_str[i];
        
        // Compare this character with the same position in all other strings
        for (int j = 1; j < strsSize; j++) {
            // If the current string ends early or character doesn't match
            if (strs[j][i] == '\0' || strs[j][i] != ch) {
                // Terminate the first string at this index to cut it short
                first_str[i] = '\0';
                return first_str;
            }
        }
    }
    
    return first_str;
}
