/**
 * @ATIVIDADE_PRATICA_P02_HIPERMÍDIA
 *
 * @MINISTRADO_POR Prof. Evandro Zatti, M. Eng.
 *
 * @AUTOR Leonardo Pliskieviski
 */
#ifndef P01_TEXT_UTILS_H
#define P01_TEXT_UTILS_H
#include <string>

using namespace std;

class ImageUtils {
    public:
        explicit ImageUtils(const int &imageWidth, const int &imageHeight): _width(imageWidth), _height(imageHeight) {};

        int getBlackAndWhiteImageByteSizeEstimate();
        int getGrayscaleOrPalletedImageByteSizeEstimate();
        int getRGBTrueColorByteSizeEstimate();

    private:
        int _width;
        int _height;
};

#endif
