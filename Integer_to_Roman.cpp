class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        while(num) {
            if(num >= 900) {
                if(num >= 1000) {
                    result += "M";
                    num -= 1000;
                }
                else {
                    result += "CM";
                    num -= 900;
                }
            }
            else if(num >= 400) {
                if(num >= 500) {
                    result += "D";
                    num -= 500;
                }
                else {
                    result += "CD";
                    num -= 400;
                }
            }
            else if(num >= 90) {
                if(num >= 100) {
                    result += "C";
                    num -= 100;
                }
                else {
                    result += "XC";
                    num -= 90;
                }
            }
            else if(num >= 40) {
                if(num >= 50) {
                    result += "L";
                    num -= 50;
                }
                else {
                    result += "XL";
                    num -= 40;
                }
            }
            else if(num >= 9) {
                if(num >= 10) {
                    result += "X";
                    num -= 10;
                }
                else {
                    result += "IX";
                    num -= 9;
                }
            }
            else {
                if (num >= 5) {
                    result += "V";
                    num -= 5;
                }
                else if(num >= 4){
                    result += "IV";
                    num -= 4;
                }
                else {
                    result += "I";
                    --num;
                }
            }
        }
        return result;
    }
};
