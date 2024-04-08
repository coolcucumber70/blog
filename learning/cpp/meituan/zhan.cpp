class Solution
{
public:
    string simplifyPath(string path)
    {
        string res;
        for (auto  s : path)
        {
            if (isalpha(s))
            {
                res += s;
            }
            else if (s == '/')
            {
                if (res.back() == '/')
                {
                    continue;
                }
                else if (res.back() == '.')
                {
                    res.pop_back();
                }
                else
                {
                    res += s;
                }
            }
            else if (s == '.')
            {
                if (res.back() == '.')
                {
                    res.pop_back();
                    if (res.size() > 1)
                    {
                        res.pop_back();
                    }
                }
            }
        }
        if(res.size()>1){
            res.pop_back();
        }
        return res;
    }
};