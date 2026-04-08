class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int num = x;
        int ans = 0;

        while (x > 0) {
            int rem = x % 10;

            if (ans > INT_MAX / 10 ||
               (ans == INT_MAX / 10 && rem > 7))
                return false; 
            ans = ans * 10 + rem;
            x /= 10;
        }

        return ans == num;
    }
};
