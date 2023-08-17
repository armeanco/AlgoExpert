#include <string>
int levenshteinDistance(std::string str1, std::string str2) {
    int size1 = str1.size();
    int size2 = str2.size();
    int verif[size1 + 1][size2 + 1];

    for (int i = 0; i <= size1; i++)
        verif[i][0] = i;
    for (int j = 0; j <= size2; j++)
        verif[0][j] = j;
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            int cost = (str2[j - 1] == str1[i - 1]) ? 0 : 1;

            verif[i][j] = min(
                min(verif[i - 1][j] + 1, verif[i][j - 1] + 1),
                verif[i - 1][j - 1] + cost
            );
        }
    }
    return verif[size1][size2];
}
