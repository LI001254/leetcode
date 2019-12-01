class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        if (num < 0)
            return "-" + convertToBase7(-num);
        string str = "";
        while (num > 0)
        {
            int rem = num % 7;
            num /= 7;
            str = to_string(rem) + str;
        }
        return str;
    }
};