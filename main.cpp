/**
 * @ATIVIDADE_PRATICA_P01_HIPERMÍDIA
 *
 * @MINISTRADO_POR Prof. Evandro Zatti, M. Eng.
 *
 * @AUTOR Leonardo Pliskieviski
 */
#include <iostream>
#include <string>
#include <fstream>
#include "TextUtils.h"

char displayOptionsMenu()
{
    char selectedUserOption;

    cout << "Cool, What do you want to do right now?" << endl;
    cout << "Select one of these options ::" << endl;

    cout << "[A] -> Convert to Uppercase" << endl;
    cout << "[B] -> Convert to Lowercase" << endl;
    cout << "[C] -> Capitalize only the first letter" << endl;
    cout << "[D] -> Invert Positions" << endl;

    cout << ":: Select one option (A-B-C-D) or type Q to (Quit)::" << endl;

    cin >> selectedUserOption;

    return selectedUserOption;
}

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

using namespace std;

int main() {
    string inputFileName;
    string outputFileName;

    cout << "What is the input filename?" << endl;
    cin >> inputFileName;

    cout << "What is the output filename?" << endl;
    cin >> outputFileName;

    string inputFileText = openFileByFilenameAndGetItsContent(inputFileName);

    char selectedUserOption = displayOptionsMenu();

    auto* inputFileTargetText = (TextUtils*) new TextUtils(inputFileText);

    switch (selectedUserOption) {
        case 'A':
            inputFileTargetText->convertToUppercase();
            break;
        case 'B':
            inputFileTargetText->convertToLowercase();
            break;
        case 'C':
            inputFileTargetText->capitalizeFirstLetter();
            break;
        case 'D':
            inputFileTargetText->reverseAll();
            break;
        case 'Q':
            return 0;
        default:
            cout << "Error! Invalid selected option" << endl;
            break;
    }

    writeContentToOutputFilename(outputFileName, inputFileTargetText->getText());

    cout << endl << "OPERATION COMPLETED!" << endl;

    return 0;
}