#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    //Get the filename of argument name "input" and "output"
    string input = am.get("input");           
    string output = am.get("output");

    //Test
    //string input = "input03.txt";
    //string output = "output03.txt";

    ofstream outFS(output);
    ifstream inFS(input);

    //Check if the input file is open
    if (!inFS.is_open())
    {
        return 1;
    }

    int size = 0;
    int totalNumber = 0;
    int index = 0;
    string line;

    //Read matrix size from the first line
    inFS >> size;
    totalNumber = size * size;

    //Declare a dynamic array to store numbers
    int *matrix = new int[totalNumber];

    for (int i = 0; i < totalNumber; i++)
    {
        inFS >> matrix[index];
        index++;
    }

    string condition = "";
    inFS >> condition;

    //Declare a dynamic character array
    //Copy the contents of the string to char array 
    const char* subcondition = condition.c_str();
    string conNumber;

    int counter = 0;

    for (int i = 0; i < totalNumber; i++)
    {
        if (subcondition[0] == 'e')
        {
            if ((matrix[i] % 2) == 0)
            {
                counter++;
            }

        }
        else if (subcondition[0] == 'o')
        {
            if ((matrix[i] % 2) != 0)
            {
                counter++;
            }
        }
        else if (subcondition[0] == '>')
        {
            conNumber = subcondition[1];
            if (matrix[i] > stoi(conNumber))
            {
                counter++;
            }
        }
        else if (subcondition[0] == '=')
        {
            conNumber = subcondition[1];
            if (matrix[i] == stoi(conNumber))
            {
                counter++;
            }
        }
        else if (subcondition[0] == '<')
        {
            conNumber = subcondition[1];
            if (matrix[i] < stoi(conNumber))
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

    double percentage = (double)counter / totalNumber;
    outFS << fixed << setprecision(2) << percentage;

    outFS.close();
    return 0;
}
