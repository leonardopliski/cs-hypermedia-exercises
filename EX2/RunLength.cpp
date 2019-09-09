/**
 * @ATIVIDADE_PRATICA_P02_HIPERMÍDIA
 *
 * @MINISTRADO_POR Prof. Evandro Zatti, M. Eng.
 *
 * @AUTOR Leonardo Pliskieviski
 */
#include <string>
#include "RunLength.h"

using namespace std;

basic_string<char> RunLength::compress() {
    if(_image.empty()) {
        throw "Empty images are not allowed!!!!";
    }

    string resultingCompressedImage;

    char previousCharacter = _image[0];
    char lastImageCharacter = previousCharacter;
    int characterOccurrences = 1;

    for(unsigned long currentImageCharacterPosition = 1; currentImageCharacterPosition < _image.size(); currentImageCharacterPosition++) {

        char currentCharacter = _image[currentImageCharacterPosition];

        if (previousCharacter != currentCharacter) {
            resultingCompressedImage += previousCharacter;
            resultingCompressedImage += to_string(characterOccurrences);

            characterOccurrences = 1;
            previousCharacter = currentCharacter;
            lastImageCharacter = currentCharacter;
        } else {
            characterOccurrences++;
        }
    }

    resultingCompressedImage += lastImageCharacter;
    resultingCompressedImage += to_string(characterOccurrences);

    return resultingCompressedImage;
}
