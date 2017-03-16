// author: Ian
// create on: 2017-03-16
// email: stmayue@gmail.com
// description: Fraction to Recurring Decimal

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        } else if (denominator == 0) {
            return "";
        }
        string ans = "";
        if ((numerator > 0) ^ (denominator >0)) {
            ans = "-";
        }

        long num = numerator;
        long den = denominator;
        num = abs(num);
        den = abs(den);
        // before point
        string tmp;
        stringstream stream;
        long res = num / den;
        long left = (num % den) * 10;
        stream << res;
        stream >> tmp;
        ans += tmp;
        if (left == 0) {
            return ans;
        }
        map<long, int> m;
        ans += ".";
        // after point
        while (left != 0) {
            if (m.find(left) != m.end()) {
                int pos = m[left];
                string part_1 = ans.substr(0, pos);
                string part_2 = ans.substr(pos, ans.size() - pos);
                ans = part_1 + "(" + part_2 + ")";
                return ans;
            }
            m[left] = ans.size();
            res = left / den;
            stringstream ss;
            ss << res;
            ss >> tmp;
            ans += tmp;
            left = (left % den) * 10;
        }
        return ans;
    }
};