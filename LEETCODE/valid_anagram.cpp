class Solution{
    public:
        bool isAnagram(string s, string t){
            if(s.length() != t.length()){
                return false;
            }
            unordered_map<int, int> countS;
            unordered_map<int, int> countT;
            for(int i = 0; i < s.length(); i++){
                countS[s[i]]++;
                countT[t[i]]++;
            }
            return counts == countT;
        }
};