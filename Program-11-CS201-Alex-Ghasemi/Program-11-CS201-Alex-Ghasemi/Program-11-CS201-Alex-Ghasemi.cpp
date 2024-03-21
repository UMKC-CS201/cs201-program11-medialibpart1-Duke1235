// Program-11-CS201-Alex-Ghasemi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Media.h"
using namespace std;


int main()
{
    string data;
    ifstream inFile("mediaList.txt");
    ofstream outErrorFile("Errors.txt");
    ofstream outFile("output.txt");
    vector<Media> totalMedia;
    if (!inFile.is_open()) {
        cout << "Failed to open mediaList.txt" << endl;
        return 1; // Return an error code
    }
    readMediaList(inFile, outErrorFile, totalMedia);
    inFile.close();
    ifstream ninFile("mediaCommands.txt"); 
    while (getline(ninFile, data)) {
        if (data[0] == 'M') {
            printMovieList(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'B') {
            printBookList(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'A') {
            printAllMedia(data, outFile, outErrorFile, totalMedia);
            printTotals(outFile,totalMedia);
        }
        else if (data[0] == 'S') {
            printSongList(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'N') {
            addNewMedia(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'Q') {
        break;
        }
        else {
            outErrorFile << "The command : " << data[0] << " is invalid." << endl << endl;
        }
    }
    
    
    
    
    

}
