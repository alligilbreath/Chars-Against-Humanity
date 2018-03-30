//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "chars.h"

using namespace std;

/**
 * Description: constructor for Chars
 *
 * @param string wordsFilePath relative path of file to get Word information
 * @param string cardsFilePath relative path of file to get Card information
 * @param string outputFilePath relative path of file to write processed cards information
 *
 * @requirement assign parameters to Chars data members of similar name
 */
Chars::Chars(std::string wordsFilePath, std::string cardsFilePath, std::string outputFilePath){
    _wordFilePath = wordsFilePath;
    _cardFilePath = cardsFilePath;
    _outputFilePath = outputFilePath;

}

/**
* Description: Read Cards from a File
*
*
* @requirement output error if _cardFilePath cannot be opened
* @requirement populate _cards list in the order they are found in the file
* @requirement Every line in the _cardsFilePath is used to create a new Card object using the Card constructor
* @requirement A Card is added to the _cards list only if the Card is valid
* @requirement close the file stream when you are done.
*
*/
void Chars::ReadCardsFromFile() {
    ifstream myCardsFile;
    myCardsFile.open(_cardFilePath);
    //Command currentCommand;
    std::string currentLine;
    //Card currentCard;
    
    if(!myCardsFile.is_open())
    {
        cout << _cardFilePath << "could not be opened." << endl;
        return;
    }
    while(!myCardsFile.eof())
    {
        getline(myCardsFile, currentLine);
        Card currentCard(currentLine);
        if(currentCard.IsValid())
            {
                _cards.push_back(currentCard);
            }
    }
    
    myCardsFile.close();
    return;
    
}

/**
 * Description: Read Word from a File
 *
 *
 * @requirement output error if _wordsFilePath cannot be opened
 * @requirement populate _words list in the order they are found in the file
 * @requirement Every line in the _wordsFilePath is used to create a new Word object using the Word constructor
 * @requirement A Word is added to the _words list only if the Word is valid
 * @requirement close the file stream when you are done.
 *
 */
void Chars::ReadWordsFromFile() {
    ifstream myWordsFile;
    myWordsFile.open(_wordFilePath);
    //Command currentCommand;
    std::string currentLine;
    //Card currentCard;
    
    if(!myWordsFile.is_open())
    {
        cout << _wordFilePath << "could not be opened." << endl;
        return;
    }
    while(!myWordsFile.eof())
    {
        getline(myWordsFile, currentLine);
        Word currentWord(currentLine);
        if(currentWord.IsValid())
        {
            _words.push_back(currentWord);
        }
        
    }
    
    myWordsFile.close();
    return;
}

/**
 * Description: Uses _cards and _words lists to populate blanks inside of Card
 * objects in _cards with Word objects in _words
 *
 * @requirement attempt to fill all blanks in the Card objects in _cards with
 * the content of a Word object in _words with the same length as the blank
 * ReplaceBlanks should be used for replacing blanks
 *
 * @requirement If no Word object in _words is of the correct size for a Card object in _cards, then the Card object is removed from _cards using the erase function of the list<> type
 *
 * @requirement Once a Word in _words is used to replace a blank in a Card object in _cards, it is removed from _words using the erase function of the list<> type
 *
 */
void Chars::ProcessCards() {
    //Card currentCard;
    unsigned int currBlankLength = 0;
    bool insertedWord = false;
    std::list<Card>::iterator card = _cards.begin();// Create an iterator object
    while(card != _cards.end()){ // keep iterating until we hit the end
        currBlankLength = (*card).GetBlankLength();
        for(std::list<Word>::iterator word = _words.begin(); word != _words.end(); word++){
            if((*word).GetContent().length() == currBlankLength && insertedWord == false)
            {
                (*card).ReplaceBlanks(*word);
                _words.erase(word);
                insertedWord = true;
            }
        }
        if(insertedWord == false)
        {
            _cards.erase(card);
        }
        insertedWord = false;
        card++;
    }

}

/**
 * Description: Write Cards that have blanks filled with Words to _outputFilePath
 *
 * @requirement output error if _outputFilePath cannot be opened
 * @requirement The _cards list must be sorted according to the length of the card from shortest to longest.
 *
 * @requirement Each Card object in _cards must be output on a new line with a carriage return ("\r\n") at the end
 * @requirement close the file stream when you are done.
 *
 */
void Chars::WriteCardsToFile() {
    ofstream myOutputFile;
    myOutputFile.open(_outputFilePath);
    if(!myOutputFile.is_open())
    {
        cout << "Could not open " << _outputFilePath << endl;
    }
    //first sort all of the cards
    _cards.sort();
    //then output to file
    std::list<Card>::iterator card = _cards.begin();// Create an iterator object
    while(card != _cards.end()){ // keep iterating until we hit the end
        myOutputFile << (*card).GetContent() << "\r\n";
        card++;
    }
    

}
