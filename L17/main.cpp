#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */


void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
    if (index == digits.length()) {
        combinations.push_back(combination);
    } else {
        char digit = digits[index];
        const string& letters = phoneMap.at(digit);
        for (const char& letter: letters) {
            combination.push_back(letter);
            backtrack(combinations, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> combinations;
    if (digits.empty()) {
        return combinations;
    }
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string combination;

    backtrack(combinations, phoneMap, digits, 0, combination);

    return combinations;
}





int main() {
    std::cout << "Hello, World!" << std::endl;

    auto result = letterCombinations("22436");
    cout<<result.size()<<endl;
    for(auto &s : result)
        cout<<s<<endl;

    return 0;
}
