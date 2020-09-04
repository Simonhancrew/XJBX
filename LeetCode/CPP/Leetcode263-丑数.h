class Solution
{
public:
    bool isUgly(int num)
    {
        if (num == 0)
        {
            return false;
        }
        if (num == 1)
        {
            return true;
        }
        if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
        {
            return false;
        }
        while (num % 2 == 0)
        {
            num = num / 2;
        }
        while (num % 3 == 0)
        {
            num = num / 3;
        }
        while (num % 5 == 0)
        {
            num = num / 5;
        }

        return num == 1;
    }
};

//更优雅，回溯

class Solution2
{
public:
    bool isUgly(int num)
    {
        if (num < 1)
        {
            return false;
        }
        auto result = search(num);
        return result;
    }

private:
    bool search(int num)
    {
        if (num == 1)
        {
            return true;
        }
        if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
        {
            return false;
        }
        else
        {
            return num % 2 == 0 ? search(num / 2) : false || num % 3 == 0 ? search(num / 3) : false || num % 5 == 0 ? search(num / 5) : false;
        }
    }
};