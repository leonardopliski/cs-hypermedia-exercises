/**
 * @ATIVIDADE_PRATICA_P01_HIPERMÍDIA
 *
 * @MINISTRADO_POR Prof. Evandro Zatti, M. Eng.
 *
 * @AUTOR Leonardo Pliskieviski
 */
#include <algorithm>
#include "TextUtils.h"

using namespace std;

#define LOWERCASE_A_IN_ASCII 97
#define LOWERCASE_Z_IN_ASCII 122
#define UPPERCASE_A_IN_ASCII 65
#define UPPERCASE_Z_IN_ASCII 90
#define NULL_BYTE_IN_ASCII '\0'
#define SPACE_IN_ASCII 32

TextUtils::TextUtils(const string& inputText)
{
    this->text = inputText;
}

string TextUtils::convertToUppercase()
{
    for_each(this->text.begin(), this->text.end(), [] (char &currentTextChar) {
        if (TextUtils::checkIfCharIsTheEndOfString(currentTextChar)) {
            return;
        }

        if (TextUtils::checkIfCharIsInLowercase(currentTextChar)) {
            currentTextChar = TextUtils::transformTargetCharToUppercase(currentTextChar);
        }
    });

    return this->text;
}

string TextUtils::convertToLowercase()
{
    for_each(this->text.begin(), this->text.end(), [] (char &currentTextChar) {
        if (TextUtils::checkIfCharIsTheEndOfString(currentTextChar)) {
            return;
        }

        if (! TextUtils::checkIfCharIsASpace(currentTextChar)) {
            currentTextChar = TextUtils::transformTargetCharToLowercase(currentTextChar);
        }
    });

    return this->text;
}

string TextUtils::capitalizeFirstLetter()
{
    char * firstTextLetter = &this->text[0];

    *firstTextLetter = (char) transformTargetCharToUppercase(*firstTextLetter);

    return this->text;
}

string TextUtils::reverseAll()
{
    int originalTextTotalLength = this->getTotalTextLength();

    char *resultingReversedText = (char *) malloc(originalTextTotalLength * sizeof(char));

    int currentOriginalTextPosition = originalTextTotalLength - 1;
    int currentReversedTextPosition = 0;

    do {
        resultingReversedText[currentReversedTextPosition++] = this->text[currentOriginalTextPosition--];
    } while (currentOriginalTextPosition >= 0);

    this->text = resultingReversedText;

    return this->text;
}

bool TextUtils::checkIfCharIsInUppercase(const char &targetChar)
{
    return (targetChar >= UPPERCASE_A_IN_ASCII && targetChar <= UPPERCASE_Z_IN_ASCII);
}

bool TextUtils::checkIfCharIsInLowercase(const char &targetChar)
{
    return (targetChar >= LOWERCASE_A_IN_ASCII && targetChar <= LOWERCASE_Z_IN_ASCII);
}

bool TextUtils::checkIfCharIsASpace(const char &targetChar)
{
    return targetChar == SPACE_IN_ASCII;
}

bool TextUtils::checkIfCharIsTheEndOfString(const char &targetChar)
{
    return targetChar == NULL_BYTE_IN_ASCII;
}

char TextUtils::transformTargetCharToLowercase(const char &targetChar)
{
    char resultingChar = (char) targetChar;

    if (TextUtils::checkIfCharIsInUppercase(targetChar)){
        resultingChar += 32;
    }

    return resultingChar;
}

char TextUtils::transformTargetCharToUppercase(const char &targetChar)
{
    char resultingChar = (char) targetChar;

    if (! TextUtils::checkIfCharIsInUppercase(resultingChar)) {
        resultingChar -= 32;
    }

    return resultingChar;
}

int TextUtils::getTotalTextLength()
{
    int totalTextLength = 0;

    /***
     * NOTE::IT ISN'T THE BEST WAY TO DO THIS TALKING ABOUT PERFORMANCE, WE'RE ONLY DOING
     * THIS WITH THE PURPOSE TO DEMONSTRATE THE USE OF POINTERS
     ***/
    while (true) {
        if (TextUtils::checkIfCharIsTheEndOfString(this->text[totalTextLength])) {
            break;
        }

        totalTextLength++;
    }

    return totalTextLength;
}

string TextUtils::getText() {
    return this->text;
}
