#include <iostream>
#include <string>
#include <vector>

void preprocessShiftTable(const std::string &pattern, std::vector<int> &shiftTable)
{
    int m = pattern.length();
    for (int i = 0; i < 256; ++i)
    {
        shiftTable[i] = m;
    }
    for (int i = 0; i < m - 1; ++i)
    {
        shiftTable[pattern[i]] = m - 1 - i;
    }
}

void horspoolStringMatch(const std::string &text, const std::string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    std::vector<int> shiftTable(256);

    preprocessShiftTable(pattern, shiftTable);

    int i = m - 1;
    while (i < n)
    {
        int j = 0;
        while (j < m && text[i - j] == pattern[m - 1 - j])
        {
            j++;
        }
        if (j == m)
        {
            std::cout << "Pattern found at position " << i - m + 1 << std::endl;
        }
        i += shiftTable[text[i]];
    }
}

int main()
{
    std::string text = "ABCABCDAB";
    std::string pattern = "CAB";

    std::cout << "Text: " << text << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;

    std::cout << "Occurrences:" << std::endl;
    horspoolStringMatch(text, pattern);

    return 0;
}
