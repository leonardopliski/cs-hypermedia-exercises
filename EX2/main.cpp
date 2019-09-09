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
#include "RunLength.h"

using namespace std;

string openFileByFilenameAndGetItsContent(const string &inputFilename)
{
    string fileContent;

    ifstream inputFile (inputFilename);

    if (inputFile.is_open()) {
        while (getline(inputFile, fileContent)) {}

        inputFile.close();
    } else {
        cout << "Error! Unable to open the input file" << endl;
    }

    return fileContent;
}

void writeContentToOutputFilename(const string &outputFilename, const string &content)
{
    ofstream outputFileDescriptor(outputFilename);

    outputFileDescriptor << content;

    outputFileDescriptor.close();
}

int main() {
    string inputFileName;
    string outputFileName;

    cout << "What is the input filename?" << endl;
    cin >> inputFileName;

    cout << "What is the output filename?" << endl;
    cin >> outputFileName;

    string inputFileText = openFileByFilenameAndGetItsContent(inputFileName);

    auto* inputImage = (RunLength*) new RunLength(inputFileText);

    try {

        string compressedImageOutput = inputImage->compress();

        writeContentToOutputFilename(outputFileName, compressedImageOutput);

    } catch (char const* errorMessage) {
        cout << "Error! " << errorMessage;
        return 1;
    }

    cout << "!!PROCESS COMPLETED!!" << endl;

    return 0;
}