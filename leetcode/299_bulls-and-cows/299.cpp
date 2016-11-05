#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    // 
    // Secret number:  "1807"
    // Friend's guess: "7810"
    // Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
    // Write a function to return a hint according to the secret number and friend's guess, 
    // use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".
    // 
    // Secret number:  "1123"
    // Friend's guess: "0111"
    // 
    // In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
    // 
    // You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
    // 
    // 
    
    string getHint(string secret, string guess) {
        const int DIGIT_LEN = 10;
        int secret_digits_cnt[DIGIT_LEN] = {0};
        int guess_digits_cnt[DIGIT_LEN]  = {0};
        int bull_cnt[DIGIT_LEN] = {0};

        for (int i=0; i<secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bull_cnt[secret[i] - '0']++;
            }
            secret_digits_cnt[secret[i] - '0']++;
            guess_digits_cnt[guess[i] - '0']++;
        }

        int bull = 0;
        int cow  = 0;
        for (int i=0; i<DIGIT_LEN; i++) {
            if (bull_cnt[i] > 0) {
                bull += bull_cnt[i];
                secret_digits_cnt[i] -= bull_cnt[i];
                guess_digits_cnt[i]  -= bull_cnt[i];
            }
        }

        for (int i=0; i<DIGIT_LEN; i++) {
            if (guess_digits_cnt[i] > 0 && secret_digits_cnt[i] > 0) {
                cow += (guess_digits_cnt[i] > secret_digits_cnt[i] ? secret_digits_cnt[i] : guess_digits_cnt[i]);
            }
        }

        ostringstream ostr;
        ostr << bull << "A" << cow << "B";

        return ostr.str();
    }

    
};



int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.getHint("1807", "7810") << endl;
    cout << s.getHint("1123", "0111") << endl;
    return 0;
}