/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1, right = n;

        while(left <= right)
        {
            long long mid = (left + right) / 2;

            int value = guess(mid);
            if(value == 0)
                return mid;
            else if(value == -1)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return 0;
    }
};