#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void printHash(vector<vector<char>> puzzle, vector<vector<int>> puzzleHash)
{
    int i, j;
    int row = puzzle.size();
    int col = puzzle[0].size();

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (puzzleHash[i][j] == 1)
            {
                cout << WHITE << puzzle[i][j] << RESET << " ";
            }

            else if (puzzleHash[i][j] == 2)
            {
                cout << BLACK << puzzle[i][j] << RESET << " ";
            }

            else if (puzzleHash[i][j] == 3)
            {
                cout << RED << puzzle[i][j] << RESET << " ";
            }

            else if (puzzleHash[i][j] == 4)
            {
                cout << GREEN << puzzle[i][j] << RESET << " ";
            }

            else if (puzzleHash[i][j] == 5)
            {
                cout << YELLOW << puzzle[i][j] << RESET << " ";
            }

            else if (puzzleHash[i][j] == 6)
            {
                cout << BLUE << puzzle[i][j] << RESET << " ";
            }

            else if (puzzleHash[i][j] == 7)
            {
                cout << MAGENTA << puzzle[i][j] << RESET << " ";
            }

            else if (puzzleHash[i][j] == 8)
            {
                cout << CYAN << puzzle[i][j] << RESET << " ";
            }

            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }

    cout << endl;
}

void savePrintHash(vector<vector<char>> puzzle, vector<vector<int>> &puzzleHash, ofstream saveFile)
{
    int i, j;
    int row = puzzle.size();
    int col = puzzle[0].size();

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (puzzleHash[i][j] == true)
            {
                saveFile << puzzle[i][j] << " ";
            }
            else
            {
                saveFile << "_ ";
            }
        }
        saveFile << endl;
    }

    saveFile << endl;
}

// void puzzleHashSaver(vector<vector<int>> &puzzleHash, int i, int j){
//     puzzleHash[i][j] = (puzzleHash[i][j]) + 1;
//     cout << puzzleHash[i][j] << endl;
// }

void searchHorizontalRight(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<int>> &puzzleHash, int wordNumber)
{
    bool found = false;
    int wordSize = word.size();
    int wordCount = 0;
    int i, j, k;
    int p, q;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            wordCount = 0;
            for (k = j; k - j < wordSize; k++)
            {
                if (k >= col)
                {
                    break;
                }

                if (puzzle[i][k] == word[k - j])
                {
                    wordCount++;
                }
                else
                {
                    break;
                }
            }

            if (wordCount == wordSize)
            {
                found = true;
                q = j;
                break;
            }
        }
        if (found)
        {
            p = i;
            break;
        }
    }

    if (found)
    {

        for (j = q; j - q < wordSize; j++)
        {
            puzzleHash[p][j] = (wordNumber % 8) + 1;
        }
    }
}

void searchHorizontalLeft(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<int>> &puzzleHash, int wordNumber)
{
    bool found = false;
    int wordSize = word.size();
    int wordCount = 0;
    int i, j, k;
    int p, q;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            wordCount = 0;
            for (k = j; j - k < wordSize; k--)
            {
                if (k < 0)
                {
                    break;
                }

                if (puzzle[i][k] == word[j - k])
                {
                    wordCount++;
                }
                else
                {
                    break;
                }
            }

            if (wordCount == wordSize)
            {
                found = true;
                q = j;
                break;
            }
        }
        if (found)
        {
            p = i;
            break;
        }
    }

    if (found)
    {

        for (j = q; q - j < wordSize; j--)
        {
            puzzleHash[p][j] = (wordNumber % 8) + 1;
        }
    }
}

void searchVerticalUp(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<int>> &puzzleHash, int wordNumber)
{
    bool found = false;
    int wordSize = word.size();
    int wordCount = 0;
    int i, j, k;
    int p, q;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            wordCount = 0;
            for (k = i; i - k < wordSize; k--)
            {
                if (k < 0)
                {
                    break;
                }

                if (puzzle[k][j] == word[i - k])
                {
                    wordCount++;
                }
                else
                {
                    break;
                }
            }

            if (wordCount == wordSize)
            {
                found = true;
                q = j;
                break;
            }
        }
        if (found)
        {
            p = i;
            break;
        }
    }

    if (found)
    {

        for (i = p; p - i < wordSize; i--)
        {
            puzzleHash[i][q] = (wordNumber % 8) + 1;
        }
    }
}

void searchVerticalDown(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<int>> &puzzleHash, int wordNumber)
{
    bool found = false;
    int wordSize = word.size();
    int wordCount = 0;
    int i, j, k;
    int p, q;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            wordCount = 0;
            for (k = i; k - i < wordSize; k++)
            {
                if (k >= row)
                {
                    break;
                }

                if (puzzle[k][j] == word[k - i])
                {
                    wordCount++;
                }
                else
                {
                    break;
                }
            }

            if (wordCount == wordSize)
            {
                found = true;
                q = j;
                break;
            }
        }
        if (found)
        {
            p = i;
            break;
        }
    }

    if (found)
    {

        for (i = p; i - p < wordSize; i++)
        {
            puzzleHash[i][q] = (wordNumber % 8) + 1;
        }
    }
}

void searchDiagonalRightUp(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<int>> &puzzleHash, int wordNumber)
{
    bool found = false;
    int wordSize = word.size();
    int wordCount = 0;
    int i, j, k, l;
    int p, q;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            wordCount = 0;
            k = i;
            l = j;
            while (i - k < wordSize && l - j < wordSize)
            {
                if (k < 0 || l >= col)
                {
                    break;
                }

                if (puzzle[k][l] == word[i - k])
                {
                    wordCount++;
                }
                else
                {
                    break;
                }
                k--;
                l++;
            }

            if (wordCount == wordSize)
            {
                found = true;
                q = j;
                break;
            }
        }
        if (found)
        {
            p = i;
            break;
        }
    }

    if (found)
    {

        i = p;
        j = q;
        while (p - i < wordSize && j - q < wordSize)
        {
            puzzleHash[i][j] = (wordNumber % 8) + 1;
            i--;
            j++;
        }
    }
}

void searchDiagonalRightDown(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<int>> &puzzleHash, int wordNumber)
{
    bool found = false;
    int wordSize = word.size();
    int wordCount = 0;
    int i, j, k, l;
    int p, q;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            wordCount = 0;
            k = i;
            l = j;
            while (k - i < wordSize && l - j < wordSize)
            {
                if (k >= row || l >= col)
                {
                    break;
                }

                if (puzzle[k][l] == word[k - i])
                {
                    wordCount++;
                }
                else
                {
                    break;
                }
                k++;
                l++;
            }

            if (wordCount == wordSize)
            {
                found = true;
                q = j;
                break;
            }
        }
        if (found)
        {
            p = i;
            break;
        }
    }

    if (found)
    {

        i = p;
        j = q;
        while (i - p < wordSize && j - q < wordSize)
        {
            puzzleHash[i][j] = (wordNumber % 8) + 1;
            i++;
            j++;
        }
    }
}

void searchDiagonalLeftUp(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<int>> &puzzleHash, int wordNumber)
{
    bool found = false;
    int wordSize = word.size();
    int wordCount = 0;
    int i, j, k, l;
    int p, q;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            wordCount = 0;
            k = i;
            l = j;
            while (i - k < wordSize && j - l < wordSize)
            {
                if (k < 0 || l < 0)
                {
                    break;
                }

                if (puzzle[k][l] == word[i - k])
                {
                    wordCount++;
                }
                else
                {
                    break;
                }
                k--;
                l--;
            }

            if (wordCount == wordSize)
            {
                found = true;
                q = j;
                break;
            }
        }
        if (found)
        {
            p = i;
            break;
        }
    }

    if (found)
    {

        i = p;
        j = q;
        while (p - i < wordSize && q - j < wordSize)
        {
            puzzleHash[i][j] = (wordNumber % 8) + 1;
            i--;
            j--;
        }
    }
}

void searchDiagonalLeftDown(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<int>> &puzzleHash, int wordNumber)
{
    bool found = false;
    int wordSize = word.size();
    int wordCount = 0;
    int i, j, k, l;
    int p, q;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            wordCount = 0;
            k = i;
            l = j;
            while (k - i < wordSize && j - l < wordSize)
            {
                if (k >= row || l < 0)
                {
                    break;
                }

                if (puzzle[k][l] == word[j - l])
                {
                    wordCount++;
                }
                else
                {
                    break;
                }
                k++;
                l--;
            }

            if (wordCount == wordSize)
            {
                found = true;
                q = j;
                break;
            }
        }
        if (found)
        {
            p = i;
            break;
        }
    }

    if (found)
    {

        i = p;
        j = q;
        while (i - p < wordSize && q - j < wordSize)
        {
            puzzleHash[i][j] = (wordNumber % 8) + 1;
            i++;
            j--;
        }
    }
}