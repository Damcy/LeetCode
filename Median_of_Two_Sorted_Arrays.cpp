class Solution {
public:
    double findValue(int A[], int m, int B[], int n, int pos) {
        if(m > n) {
            return findValue(B, n, A, m, pos);
        }
        if(m == 0) {
            return B[pos - 1];
        }
        if(pos == 1) {
            return min(A[0], B[0]);
        }
        int pos_a = min((pos+1)/2, m);
        int pos_b = pos - pos_a;
        if(A[pos_a - 1] < B[pos_b - 1]) {
            return findValue(A + pos_a, m - pos_a, B, n, pos - pos_a);
        }
        else if(A[pos_a - 1] > B[pos_b - 1]) {
            return findValue(A, m, B + pos_b, n - pos_b, pos - pos_b);
        }
        else {
            return A[pos_a - 1];
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2) {
            return findValue(A, m, B, n, (m+n)/2 + 1);
        }
        else {
            return (findValue(A, m, B, n, (m+n)/2) + findValue(A, m, B, n, (m+n)/2 + 1)) / 2;
        }
    }
};
