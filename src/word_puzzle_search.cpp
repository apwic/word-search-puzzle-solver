#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "solver.cpp"
using namespace std::chrono;
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
    // ofstream saveFile("answer.txt");

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
    vector<vector<int>> puzzleHash;
    for (int i = 0; i < puzzle.size(); i++)
    {
        puzzleHash.push_back({});
        for (int j = 0; j < puzzle[0].size(); j++)
        {
            puzzleHash[i].push_back(0);
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

    // Start runtime
    auto start = high_resolution_clock::now();

    // Check for every iteration for every word
    for (int i = 0; i < word.size(); i++)
    {
        searchHorizontalRight(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash, i);
        searchHorizontalLeft(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash, i);
        searchVerticalUp(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash, i);
        searchVerticalDown(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash, i);
        searchDiagonalRightUp(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash, i);
        searchDiagonalRightDown(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash, i);
        searchDiagonalLeftUp(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash, i);
        searchDiagonalLeftDown(puzzle, puzzle.size(), puzzle[0].size(), word[i], puzzleHash, i);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    printHash(puzzle, puzzleHash);
    cout << "Execution Time: " << (float) (duration.count())/1000000 << " seconds" << endl;

    InputText.close();
}