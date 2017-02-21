class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() <= 1) return true;
        bool isFirstCapital = false, isSecondCapital = false;
        if (word[0] >= 'A' && word[0] <= 'Z') isFirstCapital = true;
        if (word[1] >= 'A' && word[1] <= 'Z') isSecondCapital = true;
        if (! isFirstCapital && isSecondCapital) return false;
        for (size_t i = 2; i < word.size(); i++) {
            if (! isFirstCapital) {
                if (word[i] >= 'A' && word[i] <= 'Z') return false;
            } else {
                if (isSecondCapital) {
                    if (word[i] < 'A' || word[i] > 'Z') return false;
                } else {
                    if (word[i] >= 'A' && word[i] <= 'Z') return false;
                }
            }
        }
        return true;
        
    }
};