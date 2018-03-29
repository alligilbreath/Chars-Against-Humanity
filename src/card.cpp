//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "card.h"
#include <iostream>

using namespace std;

/**
 * Description: Parse a line from a file and create a card
 *
 * @param lineFromFile A string from a file
 *
 * @requirement carriage returns "\r" and newlines "\n" must be removed
 * @requirement a valid blank is at least three consecutive underscores
 * @requirement blankLength and blankIndex are zero if a valid blank is not found
 * @requirement blankIndex is the index that makes card->GetContent()[card->blankIndex] be the first underscore
 * @requirement blankLength is the number of underscores in the blank
 *
 */
Card::Card(string lineFromFile){
    std::string newLine;
    for(unsigned int i = 0; i < lineFromFile.length(); i++)
    {
      //  cout << "i is: " << i << endl;
      //  cout << "lineFromFileCard[i] is " << lineFromFile[i] << endl;
        if(ispunct(lineFromFile[i]) || isalnum(lineFromFile[i]) || lineFromFile[i] == ' ')
        {
            newLine += lineFromFile[i];
        }
    }
    cout << "New Line Card is " << newLine << endl;
    for(unsigned int i = 0; i < newLine.length(); i++)
    {
        if(newLine[i] == '_')
        {
            if(_blankLength == 0)
            {
                 _blankIndex = i;
            }
            _blankLength++;
        }
    }
    _content = newLine;
}

/**
 * Description: Replace a blank in a card with a Word object
 *
 * @param word Word with which to replace the blank inside the card
 *
 * @requirement Card _content has its blank replaced with the _content of word
 *
 */
void Card::ReplaceBlanks(Word word){
    string newLine;
    for(unsigned int i = 0; i < _content.length(); i++)
    {
        if(i >= _blankIndex && i <= _blankIndex + _blankLength)
        {
            cout << "Word letter is: " << word.GetContent()[i] << endl;
            newLine += word.GetContent()[i];
        }
        else
        {
            cout << "Content letter is: " << _content[i] << endl;
            newLine += _content[i];
        }
    }
    _content = newLine;
    
}

/**
 * Validate Card
 *
 * @requirement blankLength must be at least 3
 *
 */
bool Card::IsValid() {
    if(_blankLength <= 3)
    {
        return false;
    }
    return true;
}

/**
 * Description: < operator overload
 *
 * @note This function allows us to compare Card objects directly such that
 * Card card1; Card card2; card1 < card2; (actually compiles)
 *
 * This allows us to call .sort() on our std::list<Card> _cards and sorting
 * is done for us
 *
 */
bool Card::operator<(const Card& rhs) const{
    return rhs.GetContent().length() > _content.length();
}
