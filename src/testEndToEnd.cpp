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
    return false;
}
