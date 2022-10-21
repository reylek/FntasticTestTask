#include <iostream>
#include <string>

std::string convertText(std::string &iText) {
    const int lengthText = iText.length();
    std::string oText(lengthText, '(');
    const int delta = 'a' - 'A';
    for (int i = 0; i <= lengthText; i++) {
        if (oText[i] == '(') {
            bool isMoreOne = false;
            for (int j = i + 1; j <= lengthText; j++) {
                if ((iText[i] == iText[j]) || ((iText[i] >= 'A' && iText[i] <= 'Z') && (iText[i] + delta == iText[j])) || ((iText[i] >= 'a' && iText[i] <= 'z') && (iText[i] - delta == iText[j]))) {
                    oText[j] = ')';
                    isMoreOne = true;
                }
            }
            if (isMoreOne) {
                oText[i] = ')';
            }
        }
    }
    return oText;
}

int main()
{
    std::string inputText = "";
    std::getline(std::cin, inputText);
    std::cout << convertText(inputText);
}
