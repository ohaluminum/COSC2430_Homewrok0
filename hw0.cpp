#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    //Get the filename of argument name "input" and "output"
    string input = am.get("input");           
    string output = am.get("output");

    ofstream outFS(output);
    ifstream inFS(input);
    istringstream inSS;

    //Check if the input file is open
    if (!inFS.is_open())
    {
        return 1;
    }

    string size_str = "";
    int size = 0;
    int index = 0;
    string line;
    string word;

    //Read matrix size from the first line
    inFS >> size_str;
    size = stoi(size_str);

    //Declare a dynamic array to store numbers
    int *matrix = new int[size * size];

    for (int i = 0; i < size; i++)
    {
        getline(inFS, line);
        inSS.str(line);

        for (int i = 0; i < size; i++)
        {
            inSS >> word;
            matrix[index] = stoi(word);
            index++;
        }
        
        inSS.clear();
    }

    string condition = "";
    getline(inFS, condition);

    //Declare a dynamic character array
    //Copy the contents of the string to char array 
    const char* subcondition = condition.c_str();

    int counter = 0;

    for (int i = 0; i < size * size; i++)
    {
        if (subcondition[0] == 'e')
        {
            if (matrix[i] / 2 == 0)
            {
                counter++;
            }

        }
        else if (subcondition[0] == 'o')
        {
            if (matrix[i] / 2 != 0)
            {
                counter++;
            }
        }
        else if (subcondition[0] == '>')
        {
            if (matrix[i] > subcondition[1])
            {
                counter++;
            }
        }
        else if (subcondition[0] == '=')
        {
            if (matrix[i] == subcondition[1])
            {
                counter++;
            }
        }
        else if (subcondition[0] == '<')
        {
            if (matrix[i] < subcondition[1])
            {
                counter++;
            }
        }
        else
        {
            return 1;
        }
    }

    inFS.close();

    double percentage = counter / (size * size);
    outFS << percentage;

    outFS.close();
}
