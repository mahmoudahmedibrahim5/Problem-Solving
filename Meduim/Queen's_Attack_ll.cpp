//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int up, down, right, left;
    int nearstUp = n + 1, nearstDown = 0, nearstRight = n + 1, nearstLeft = 0;

    int mainDiagonal = r_q - c_q;
    int upRight, downLeft;
    int nearstUpRight = n + 1, nearstDownLeft = 0;


    int secondaryDiagonal = r_q + c_q;
    int upLeft, downRight;
    int nearstUpLeft = 0, nearstDownRight = 0;
    if (((n + 1) - r_q) > c_q) {
        // we nearer to the left
        // we use columns
        nearstUpLeft = 0;
    }
    else {
        // we are nearer to the up
        // we use rows
        nearstUpLeft = n + 1;
    }


    if ((n + 1) - c_q > r_q) {
        // nearer to bottom
        // we use rows
        nearstDownRight = 0;
    }
    else {
        // nearer to right
        // we use columns
        nearstDownRight = n + 1;
    }

    int temp;
    for (int i = 0; i < obstacles.size(); i++) {
        if (obstacles.at(i).at(1) == c_q) {
            temp = obstacles.at(i).at(0);
            if (temp < nearstUp && temp > r_q)
                nearstUp = temp;
            if (temp > nearstDown && temp < r_q)
                nearstDown = temp;
        }

        if (obstacles.at(i).at(0) == r_q) {
            temp = obstacles.at(i).at(1);
            if (temp < nearstRight && temp > c_q)
                nearstRight = temp;
            if (temp > nearstLeft && temp < c_q)
                nearstLeft = temp;
        }

        if (obstacles.at(i).at(0) - obstacles.at(i).at(1) == mainDiagonal) {
            if (r_q > c_q) {
                // we nearer to top
                // we use rows
                temp = obstacles.at(i).at(0);
                if (temp < nearstUpRight && temp > r_q)
                    nearstUpRight = temp;
                // we nearer to left 
                // we use columns
                temp = obstacles.at(i).at(1);
                if (temp > nearstDownLeft && temp < c_q)
                    nearstDownLeft = temp;
            }
            else {
                // we nearer to right
                // we use columns
                temp = obstacles.at(i).at(1);
                if (temp < nearstUpRight && temp > c_q)
                    nearstUpRight = temp;
                // we nearer to bottom
                // we use rows
                temp = obstacles.at(i).at(0);
                if (temp > nearstDownLeft && temp < r_q)
                    nearstDownLeft = temp;
            }
        }

        if (obstacles.at(i).at(0) + obstacles.at(i).at(1) == secondaryDiagonal) {
            if (((n + 1) - r_q) > c_q) {
                // we are nearer to the left
                // we use columns
                temp = obstacles.at(i).at(1);
                if (temp > nearstUpLeft && temp < c_q)
                    nearstUpLeft = temp;
            }
            else {
                // we nearer to the top
                // we use rows
                temp = obstacles.at(i).at(0);
                if (temp < nearstUpLeft && temp > r_q)
                    nearstUpLeft = temp;
            }

            if ((n + 1) - c_q > r_q) {
                // nearer to bottom
                // we use rows
                temp = obstacles.at(i).at(0);
                if (temp > nearstDownRight && temp < r_q)
                    nearstDownRight = temp;
            }
            else {
                // nearer to right
                // we use columns
                temp = obstacles.at(i).at(1);
                if (temp < nearstDownRight && temp > c_q)
                    nearstDownRight = temp;
            }
        }
    }
    up = nearstUp - r_q - 1;
    down = r_q - nearstDown - 1;
    right = nearstRight - c_q - 1;
    left = c_q - nearstLeft - 1;

    /* Main Diagonal */
    if (r_q > c_q) {
        // we nearer to top
        // we use rows
        upRight = nearstUpRight - r_q - 1;
        // we nearer to left 
        // we use columns
        downLeft = c_q - nearstDownLeft - 1;
    }
    else {
        // we nearer to right
        // we use columns
        upRight = nearstUpRight - c_q - 1;
        // we nearer to bottom
        // we use rows
        downLeft = r_q - nearstDownLeft - 1;
    }

    /* Secondary Diagonal */
    if (((n + 1) - r_q) > c_q) {
        // we nearer to the left
        // we use columns
        upLeft = c_q - nearstUpLeft - 1;
    }
    else {
        // we are nearer to the top
        // we use rows
        upLeft = nearstUpLeft - r_q - 1;
    }

    if ((n + 1) - c_q > r_q) {
        // nearer to bottom
        // we use rows
        downRight = r_q - nearstDownRight - 1;
    }
    else {
        // nearer to right
        // we use columns
        downRight = nearstDownRight - c_q - 1;
    }
    
    return up + down + right + left + upRight + upLeft + downRight + downLeft;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
