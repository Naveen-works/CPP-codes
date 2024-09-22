class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t position = haystack.find(needle);
        if (position != string::npos) {
            return position;
        } else {
            return -1;
        }
    }
};

/*
1->use find() function to search for entire string
2->if position !=npos return position else return -1

Time complexity:
O(N+M)				//N-haystack size and M-needle size


solution-2
class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystackLength = haystack.size();
        int needleLength = needle.size();
        
        // If needle is empty, return 0
        if (needleLength == 0) {
            return 0;
        }
        
        // If haystack is smaller than needle, return -1
        if (haystackLength < needleLength) {
            return -1;
        }
        
        for (int i = 0; i <= haystackLength - needleLength; ++i) {
            int j;
            for (j = 0; j < needleLength; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needleLength) {
                return i;
            }
        }
        
        return -1;
    }
};
*/

