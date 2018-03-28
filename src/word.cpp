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
    std::string newLine;
 //   cout << "Entire line is: " << lineFromFile << endl;
    for(unsigned int i = 0; i < lineFromFile.length(); i++)
    {
      cout << "i is: " << i << endl;
                cout << "lineFromFile[i] is " << lineFromFile[i] << endl;
        if(ispunct(lineFromFile[i]) || isalnum(lineFromFile[i]))
        {

            newLine[i] = lineFromFile[i];
            newLine += lineFromFile[i];
   //         cout << "New Line [i] is: " << newLine[i] << endl;
    //        cout << "New line total is: " << newLine << endl;
        }
        if(lineFromFile[i] == ' ')
        {
            break;
        }
    }
  //  cout << "New line is: " << newLine << endl;
    cout << "New Line is " << newLine << endl;
    _content = newLine;
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
    cout << _content << endl;
   if(_content.length() < 2)
   {
       return false;
   }
    for(unsigned int i = 0; i < _content.length(); i++)
    {
        cout << "Content i is: " << _content[i] << endl;
        if(ispunct(_content[i]) == 0 && isalnum(_content[i]) == 0)
        {
            cout << "Content i in if is: " << _content[i] << endl;
            return false;
        }
    }
    return true;
}
