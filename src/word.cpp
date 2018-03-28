//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "word.h"
#include <iostream>
//#include <algorithm>

using namespace std;

/**
 * Parse a line from a file and create a word
 *
 * @param lineFromFile A string from a file
 *
 * @requirement carriage returns "\r" and newlines "\n" must be removed
 * @requirement after removal of carriage returns and newline, content of line are assigned to _content
 *
 */
Word::Word(string lineFromFile){
    string newLine;
//    unsigned int locationOfR = lineFromFile.find("\r");
//    cout << "LocationOfR: " << locationOfR << endl;
//    unsigned int locationOfN = lineFromFile.find("\n");
//    cout << "LocationOfN: " << locationOfN << endl;
    for(unsigned int i = 0; i < lineFromFile.length(); i++)
    {
        cout << "i is: " << i << endl;
       // if(i != locationOfN && i != locationOfR)
        if(ispunct(lineFromFile[i]) || isalnum(lineFromFile[i]))
        {
            cout << "lineFromFile[i] is " << lineFromFile[i] << endl;
            newLine[i] = lineFromFile[i];
        }
    }
    _content = lineFromFile;
}

/**
 * Validate Word
 *
 * @param Pointer to Word to validate
 *
 * @requirement every character in _content must pass the condition:
 * ispunct(character) || isalnum(character)
 * @requirement The Word length must be greater than 2
 *
 * @return 1 if valid, 0 otherwise
 */
bool Word::IsValid(){
   if(_content.length() < 2)
   {
       return false;
   }
    for(int i = 0; i < _content.length(); i++)
    {
        if(!ispunct(_content[i]) || !isalnum(_content[i]))
        {
            return false;
        }
    }
    return true;
}
