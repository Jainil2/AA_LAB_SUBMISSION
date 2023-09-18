#include <iostream>
#include <string>

void naiveStringMatch(const std::string &text, const std::string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i)
    {
        int j;
        for (j = 0; j < m; ++j)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            std::cout << "Pattern found at position " << i << std::endl;
    }
}

int main()
{
    std::string text = "ABABABAB";
    std::string pattern = "ABA";

    std::cout << "Text: " << text << std::endl;
    std::cout << "Pattern: " << pattern << std::endl;

    std::cout << "Occurrences:" << std::endl;
    naiveStringMatch(text, pattern);

    return 0;
}
