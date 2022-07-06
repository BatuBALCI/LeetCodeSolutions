class Solution {
public:
    int fib(int n) {
        int last = 0, first = 1;
        if (n == 0 || n == 1)
            return n;
        while (n - 1 > 0) {
            int temp = first + last;
            last = first;
            first = temp;
            n--;
        }
        return first;
    }
};