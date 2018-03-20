//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "testEndToEnd.h"
#include "chars.h"

using namespace std;

void EndToEndTester::RunTests(){
    for(int i = 1; i < 11; i++){
        if(testFile(i)) cout << "File " << i << " passed." << endl;
    }
}


/*
 * @requirement pass if all lines in files are the exact same AND output files can be opened properly
 * @return pass: 1, fail: 0
 */
bool EndToEndTester::testFile(int testNum){
    
    // Chars chars(testWordsPath.str(), testCardsPath.str(), myOutputFilePath.str());
    // read cards from the file
    // read words from the file
    // process the cards with the words
    // write the cards to the file

    
    //check to see if any line is different
    
    // create file paths for input, output, and myOutput
    stringstream testInputPath;
    testInputPath << TEST_FILE_RELATIVE_PATH << "/input" << testNum + 1 << ".txt";
    
    ifstream testFilePath;
    testFilePath.open(testInputPath.str());
    if(!testFilePath.is_open())
    {
        cout << "Could not open file: " << testInputPath.str() << endl;
        return false;
    }
    
    //myOutput file path
    stringstream myOutputFilePath;
    myOutputFilePath << TEST_FILE_RELATIVE_PATH << "/myOutput" << testNum + 1 << ".txt";
    
    
    //output file path
    stringstream outputPath;
    outputPath << TEST_FILE_RELATIVE_PATH << "/output" << testNum + 1 << ".txt";
    
//
//    Chars chars(testInputPath.str(), testCardsPath.str(), myOutputFilePath.str());
//    // Read Commands
//    carSim.ReadCommandsFromFile();
//    // run the commands
//    carSim.RunAllCommands();
//    // write to file
//    carSim.WriteStateHistoryToFile();
//
    
    ifstream myOutputStream;
    myOutputStream.open(myOutputFilePath.str());
    
    ifstream outputStream;
    outputStream.open(outputPath.str());
    
    if(!myOutputStream.is_open())
    {
        cout << "Could not open file: " << myOutputFilePath.str() << endl;
        return false;
    }
    if(!outputStream.is_open())
    {
        cout << "Could not open file: " << outputPath.str() << endl;
        return false;
    }
    //compare it line-by-line with the output file provided to you.
    string currentMyOutput;
    string currentOutput;
    while(!myOutputStream.eof())
    {
        getline(myOutputStream, currentMyOutput);
        
        getline(outputStream, currentOutput);
        
        //cout << "Current myOutput line: " << currentMyOutput << "\n";
        //cout << "Current output line: " << currentOutput << "\n";
        if(currentMyOutput.compare(currentOutput) != 0)
        {
            myOutputStream.close();
            outputStream.close();
            return false;
        }
    }
    //to check if myOutputStream reached end of file before outputStream
    if(myOutputStream.eof() != outputStream.eof())
    {
        myOutputStream.close();
        outputStream.close();
        return false;
    }
    
    myOutputStream.close();
    outputStream.close();
    return true;
}
