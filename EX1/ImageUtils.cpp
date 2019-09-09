/**
 * @ATIVIDADE_PRATICA_P02_HIPERMÍDIA
 *
 * @MINISTRADO_POR Prof. Evandro Zatti, M. Eng.
 *
 * @AUTOR Leonardo Pliskieviski
 */
#include "ImageUtils.h"

using namespace std;

int ImageUtils::getBlackAndWhiteImageByteSizeEstimate() {
    return (_width * _height) / 8;
}

int ImageUtils::getGrayscaleOrPalletedImageByteSizeEstimate() {
    return _width * _height;
}

int ImageUtils::getRGBTrueColorByteSizeEstimate() {
    return (_width * _height) * 3;
}
