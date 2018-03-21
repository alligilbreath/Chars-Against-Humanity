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
    
    // create file paths for inputCards, inputWords, output, and myOutput
    stringstream testCardsPath;
    testCardsPath << TEST_FILE_RELATIVE_PATH << "/inputCards" << testNum << ".txt";
    
    ifstream testCardsFilePath;
    testCardsFilePath.open(testCardsPath.str());
    if(!testCardsFilePath.is_open())
    {
        cout << "Could not open file: " << testCardsPath.str() << endl;
        return false;
    }
    
    stringstream testWordsPath;
    testWordsPath << TEST_FILE_RELATIVE_PATH << "/inputWords" << testNum << ".txt";
    ifstream testWordsFilePath;
    testWordsFilePath.open(testWordsPath.str());
    if(!testWordsFilePath.is_open())
    {
        cout << "Could not open file: " << testWordsPath.str() << endl;
        return false;
    }
    
    //myOutput file path
    stringstream myOutputFilePath;
    myOutputFilePath << TEST_FILE_RELATIVE_PATH << "/myOutput" << testNum << ".txt";
    
    
    //output file path
    stringstream outputPath;
    outputPath << TEST_FILE_RELATIVE_PATH << "/output" << testNum << ".txt";
    
    ifstream myOutputStream;
    myOutputStream.open(myOutputFilePath.str());
    if(!myOutputStream.is_open())
    {
        cout << "Could not open file: " << myOutputFilePath.str() << endl;
        return false;
    }

    
    Chars chars(testWordsPath.str(), testCardsPath.str(), myOutputFilePath.str());

    
    ifstream outputStream;
    outputStream.open(outputPath.str());
    
    if(!outputStream.is_open())
    {
        cout << "Could not open file: " << outputPath.str() << endl;
        return false;
    }

    // Chars chars(testWordsPath.str(), testCardsPath.str(), myOutputFilePath.str());
   
    
    // read cards from the file
    // read words from the file
    chars.ReadCardsFromFile();
    chars.ReadWordsFromFile();
    
    // process the cards with the words
    chars.ProcessCards();
    
    // write the cards to the file
    chars.WriteCardsToFile();
    
    
    string currentMyOutput;
    string currentOutput;
    //compare it line-by-line with the output file provided to you.
    while(!myOutputStream.eof())
    {
        getline(myOutputStream, currentMyOutput);
        
        getline(outputStream, currentOutput);
        
        cout << "Current myOutput line: " << currentMyOutput << "\n";
        cout << "Current output line: " << currentOutput << "\n";
        if(currentMyOutput.compare(currentOutput) != 0)
        {
            myOutputStream.close();
            outputStream.close();
            return false;
        }
    }
    //to check if myOutputStream reached end of file before outputStream
//    if(myOutputStream.eof() != outputStream.eof())
//    {
//        myOutputStream.close();
//        outputStream.close();
//        return false;
//    }
    
    myOutputStream.close();
    outputStream.close();
    return true;
}
