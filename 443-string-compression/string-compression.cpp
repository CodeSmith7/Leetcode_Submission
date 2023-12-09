class Solution {
public:
    int compress(vector<char>& chars) {
    int i = 0;
    int index = 0;
    while (i < chars.size()) {
        char current = chars[i];
        int count = 0;
        while (i < chars.size() && chars[i] == current) {
            i++;
            count++;
        }
        chars[index++] = current;
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[index++] = c;
            }
        }
    }
    return index;
}

};