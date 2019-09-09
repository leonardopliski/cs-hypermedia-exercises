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

class RunLength {
    public:
        explicit RunLength(const string &image): _image(image) {};

        basic_string<char> compress();

    private:
        string _image;
};

#endif
