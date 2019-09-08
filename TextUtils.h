/**
 * @ATIVIDADE_PRATICA_P01_HIPERMÍDIA
 *
 * @MINISTRADO_POR Prof. Evandro Zatti, M. Eng.
 *
 * @AUTOR Leonardo Pliskieviski
 */
#ifndef P01_TEXT_UTILS_H
#define P01_TEXT_UTILS_H
#include <string>

using namespace std;

class TextUtils {
    public:
        explicit TextUtils(const string &inputText);

        string convertToUppercase();
        string convertToLowercase();
        string capitalizeFirstLetter();
        string reverseAll();

        int getTotalTextLength();

        static bool checkIfCharIsInUppercase(const char &targetChar);
        static bool checkIfCharIsInLowercase(const char &targetChar);
        static bool checkIfCharIsASpace(const char &targetChar);
        static bool checkIfCharIsTheEndOfString(const char &targetChar);
        static char transformTargetCharToLowercase(const char &targetChar);
        static char transformTargetCharToUppercase(const char &targetChar);

        string getText();

    private:
        string text;
};

#endif
