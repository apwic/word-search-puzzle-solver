#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "solver.cpp"
using namespace std;

vector<vector<char>> getPuzzle(ifstream &InputText)
{
    vector<vector<char>> puzzle;
    vector<char> puzzleLine;
    char input;
    int countNewLine = 0;

    while (InputText.get(input))
    {
        if (input == '\n')
        {
            countNewLine++;

            if (countNewLine == 2)
            {
                break;
            }
            puzzle.push_back(puzzleLine);
            puzzleLine = {};

            continue;
        }

        countNewLine = 0;

        if (input != ' ')
        {
            puzzleLine.push_back(input);
        }
    }

    return puzzle;
}

vector<string> getWord(ifstream &InputText)
{
    vector<string> word;
    char input;
    string text;

    while (InputText.get(input))
    {
        if (input == '\n')
        {
            word.push_back(text);
            text = "";
        }

        else
        {
            text.push_back(input);
        }
    }
    return word;
}

int main()
{
    string fileName;
    cout << "Input your file name: ";
    cin >> fileName;

    // Read from the text file
    string path;
    path = "../test/" + fileName;
    ifstream InputText(path);

    while (!InputText){
        cout << "File name doesn't exist, please try again!" << endl;
        cout << "Input your file name: ";
        cin >> fileName; 
        path = "../test/" + fileName;
        InputText.clear();
        InputText.seekg(0, InputText.beg);
        InputText.open(path);
    }

    // Get Puzzle
    vector<vector<char>> puzzle = getPuzzle(InputText);

    // Get Word
    vector<string> word = getWord(InputText);

    // Create Boolean Hash Table
    vector<vector<bool>> puzzleHash;
    for (int i = 0; i < puzzle.size(); i++)
    {
        puzzleHash.push_back({});
        for (int j = 0; j < puzzle[0].size(); j++)
        {
            puzzleHash[i].push_back(false);
        }
    }

    // Check Input
    // for (int i = 0; i < puzzle.size(); i++){
    //     for (int j = 0; j < puzzle[i].size(); j++){
    //         cout << puzzle[i][j];
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < word.size(); i++){
    //     cout << word[i] << endl;
    // }

    for (int i = 0; i < word.size(); i++)
    {
        cout << "Word " << i + 1 << ": " << endl << endl;
        searchHorizontalRight(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash);
        searchHorizontalLeft(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash);
        searchVerticalUp(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash);
        searchVerticalDown(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash);
        searchDiagonalRightUp(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash);
        searchDiagonalRightDown(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash);
        searchDiagonalLeftUp(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash);
        searchDiagonalLeftDown(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash);
    }

    InputText.close();
}