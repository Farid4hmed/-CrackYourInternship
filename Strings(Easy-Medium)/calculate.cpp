int calculate(string s) {
        s += "++";
        char sign = '+';
        int ans = 0, num = 0, tmp = 0;
        for (char& c: s) {
            if (c == ' ') continue;
            if (isdigit(c)) num = 10*num + (c-'0');
            else {
                if (sign == '+') ans += tmp, tmp = num;
                else if (sign == '-') ans += tmp, tmp = -num;
                else if (sign == '*') tmp *= num;
                else tmp /= num;
                sign = c;
                num = 0;
            }
        }
        return ans;
    }
