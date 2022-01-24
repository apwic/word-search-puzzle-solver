#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void printHash(vector<vector<char>> puzzle, vector<vector<bool>> puzzleHash)
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
                cout << puzzle[i][j] << " ";
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

void searchHorizontalRight(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<bool>> puzzleHash)
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
            puzzleHash[p][j] = true;
        }
        printHash(puzzle, puzzleHash);
    }
}

void searchHorizontalLeft(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<bool>> puzzleHash)
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
            puzzleHash[p][j] = true;
        }
        printHash(puzzle, puzzleHash);
    }
}

void searchVerticalUp(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<bool>> puzzleHash)
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
            puzzleHash[i][q] = true;
        }
        printHash(puzzle, puzzleHash);
    }
}

void searchVerticalDown(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<bool>> puzzleHash)
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
            puzzleHash[i][q] = true;
        }
        printHash(puzzle, puzzleHash);
    }
}

void searchDiagonalRightUp(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<bool>> puzzleHash)
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
            puzzleHash[i][j] = true;
            i--;
            j++;
        }
        printHash(puzzle, puzzleHash);
    }
}

void searchDiagonalRightDown(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<bool>> puzzleHash)
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
            puzzleHash[i][j] = true;
            i++;
            j++;
        }
        printHash(puzzle, puzzleHash);
    }
}

void searchDiagonalLeftUp(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<bool>> puzzleHash)
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
            puzzleHash[i][j] = true;
            i--;
            j--;
        }
        printHash(puzzle, puzzleHash);
    }
}

void searchDiagonalLeftDown(vector<vector<char>> puzzle, int row, int col, string word, vector<vector<bool>> puzzleHash)
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
            puzzleHash[i][j] = true;
            i++;
            j--;
        }
        printHash(puzzle, puzzleHash);
    }
}