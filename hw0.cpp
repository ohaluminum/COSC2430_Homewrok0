#include <iostream>
#include <string>
#include <fstream>
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    string infilename = am.get("input");           //get the filename of argument name "input"
    string outfilename = am.get("output");
    ofstream ofs(outfilename.c_str());
    ofs << "";//create the file by writing nothing
    cout << "input: " << infilename << std::endl << "output: " << outfilename << std::endl;
}
