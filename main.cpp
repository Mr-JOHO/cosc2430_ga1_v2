#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

using namespace std;

void spiralMaker(string inputString, int matrixSideSize){
    int row = 0;
    int col = -1;

    int stringIndexVal = 0;
    int side = matrixSideSize;
    int matrixTotal = matrixSideSize * matrixSideSize;

    char** spiralMatrix = new char*[matrixTotal];

    for(int i = 0; i < matrixTotal; i++)
        spiralMatrix[i] = new char[matrixSize];

    while(stringIndexVal < matrixTotal) {
        for (int i = 0; i < matrixSideSize; i++) {
            col++;
            spiralMatrix[row][col] = inputString[stringIndexVal];
            stringIndexVal++;
        }

        matrixSideSize--;

        for (int i = 0; i < matrixSideSize; i++){
            row++;
            spiralMatrix[row][col] = inputString[stringIndexVal];
            stringIndexVal++;
        }

        for (int i = 0; i < matrixSideSize; i++){
            col--;
            spiralMatrix[row][col] = inputString[stringIndexVal];
            stringIndexVal++;
        }

        matrixSideSize--;

        for (int i = 0; i < matrixSideSize; i++){
            row--;
            spiralMatrix[row][col] = inputString[stringIndexVal];
            stringIndexVal++;
        }
    }
    for (int i = 0; i < side; i++){
        for (int j = 0; j < side; j++){
            cout << spiralMatrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");

    string inputLine = "ad";

    int matrixSideSize = inputLine.size();
    if(sqrt(matrixSideSize) - (int) sqrt(matrixSideSize) > 0)
        matrixSideSize = sqrt(matrixSideSize) + 1;
    else
        matrixSideSize = sqrt(matrixSideSize);

    int inputAllStringValue = matrixSideSize * matrixSideSize;
    for(int i = inputLine.size(); i < inputAllStringValue; i++){
        inputLine += '.';
    }

    spiralMaker(inputLine, matrixSideSize);
}
