//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "word.h"
#include <algorithm>

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
    char chars[] = "\r\n";
    
    for (unsigned int i = 0; i < strlen(chars); ++i)
    {
        // you need include <algorithm> to use general algorithms like std::remove()
        lineFromFile.erase (std::remove(lineFromFile.begin(), lineFromFile.end(), chars[i]), lineFromFile.end());
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
    return false;
}
