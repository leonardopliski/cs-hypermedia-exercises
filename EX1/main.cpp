/**
 * @ATIVIDADE_PRATICA_P02_HIPERMÍDIA
 *
 * @MINISTRADO_POR Prof. Evandro Zatti, M. Eng.
 *
 * @AUTOR Leonardo Pliskieviski
 */
#include <iostream>
#include <string>
#include <fstream>
#include "ImageUtils.h"

using namespace std;

char displayOptionsMenu()
{
    char selectedUserOption;

    cout << "Cool, What do you want to estimate right now?" << endl;
    cout << "Select one of these options ::" << endl;

    cout << "[A] -> Black & White size" << endl;
    cout << "[B] -> Grayscale / Paletted size" << endl;
    cout << "[C] -> RGB True color size" << endl;

    cout << ":: Select one option (A-B-C) or type Q to (Quit)::" << endl;

    cin >> selectedUserOption;

    return selectedUserOption;
}

int main() {
    int imageWidth;
    int imageHeight;

    cout << "Hello! What's the image width? (W)" << endl;
    cin >> imageWidth;

    cout << "And what's the image height? (H)" << endl;
    cin >> imageHeight;

    char selectedUserOption = displayOptionsMenu();

    auto* inputFileTargetText = (ImageUtils*) new ImageUtils(imageWidth, imageHeight);

    int estimatedImageFinalByteSize = 0;

    switch (selectedUserOption) {
        case 'A':
            estimatedImageFinalByteSize = inputFileTargetText->getBlackAndWhiteImageByteSizeEstimate();
            break;
        case 'B':
            estimatedImageFinalByteSize = inputFileTargetText->getGrayscaleOrPalletedImageByteSizeEstimate();
            break;
        case 'C':
            estimatedImageFinalByteSize = inputFileTargetText->getRGBTrueColorByteSizeEstimate();
            break;
        case 'Q':
            return 0;
        default:
            cout << "Error! Invalid selected option" << endl;
            break;
    }

    cout << "The estimated final image size is: " << estimatedImageFinalByteSize << " Bytes" << endl;

    return 0;
}