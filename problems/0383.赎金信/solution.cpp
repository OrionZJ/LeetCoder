class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for (char a : magazine) {
            umap[a]++;
        }
        for (char b : ransomNote) {
            if (umap.find(b) != umap.end()) {
                if (--umap[b] < 0) return false;
            } else return false;
        }
        return true;
    }
};