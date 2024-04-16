

struct LargerNumberComparator {
    bool operator()(const std::string& a, const std::string& b) {
        // 比较两个数字字符串的组合哪个更大
        return a + b > b + a;
    }
};

string largestNumber(const std::vector<int>& nums) {
    // 将整数转换为字符串
    vector<string> asStrs;
    for (int i = 0; i < nums.size();i++) {
        asStrs.push_back(toString(nums[i]));
    }

    // 使用自定义的比较器来排序
    sort(asStrs.begin(), asStrs.end(), LargerNumberComparator());

    // 如果最大的数字是“0”，则整个数字是0
    if (!asStrs.empty() && asStrs[0] == "0") {
        return "0";
    }

    // 构建最终的字符串
    string largestNumberStr;
    for (const std::string& numStr : asStrs) {
        largestNumberStr += numStr;
    }

    return largestNumberStr;
}