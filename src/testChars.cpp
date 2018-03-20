//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <iostream>
#include "testChars.h"
#include "word.h"
#include "card.h"

using namespace std;

void CharsTester::RunTests() {
    testConstructWordWithCarriageReturn();
    testConstructWordWithNewLine();
    testIsWordValidWithSpace();
    testIsWordValidPercentSign();
    testIsWordValidShortWord();
    testConstructCardWithCarriageReturn();
    testConstructCardWithNewLine();
    testIsCardValidNoBlank();
    testIsCardValidShortBlank();
    testCorrectBlankLengthAndIndex();
    testCardIsLessThan();
}

/*
 * @requirement pass if "\r\n" is discarded by Word constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructWordWithCarriageReturn() {
    Word myWord = Word("Hello\r\n");
    if(myWord.GetContent().compare("Hello") == 0)
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if "\n" is discarded by Word constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructWordWithNewLine() {
    Word myWord = Word("Hello\n");
    if(myWord.GetContent().compare("Hello") == 0)
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if Word created using constructor with string that has a space is considered invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidWithSpace() {
    Word myWord = Word("Hello man");
    if(!myWord.IsValid())
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if Word created using constructor with string that has a percent sign is considered valid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidPercentSign() {
    Word myWord = Word("Two%");
    if(myWord.IsValid())
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if Word created using constructor with string that is less than 3 characters is considered invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidShortWord() {
    Word myWord = Word("a");
    if(!myWord.IsValid())
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if "\r\n" is discarded by Card constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructCardWithCarriageReturn() {
    Card myCard = Card("His name was ___\r\n");
    if(myCard.GetContent().compare("His name was ___") == 0)
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if "\n" is discarded by Card constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructCardWithNewLine() {
    Card myCard = Card("His name was ___\n");
    if(myCard.GetContent().compare("His name was ___") == 0)
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if Card created using constructor with string that has no underscores is invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsCardValidNoBlank() {
    Card myCard = Card("Hello");
    if(!myCard.IsValid())
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if Card created using constructor with string that has a blank that is only two characters long is invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsCardValidShortBlank() {
    Card myCard = Card("His name is __");
    if(!myCard.IsValid())
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if blankLength and blankIndex is correct in properly formatted Card object with a blank yet to be filled.
 * @return pass: true, fail: false
 */
bool CharsTester::testCorrectBlankLengthAndIndex() {
    Card myCard = Card("His name is ____");
    if(myCard.GetBlankLength() == 4 && myCard.GetBlankIndex() == 12)
    {
        return true;
    }
    return false;
}

/*
 * @requirement pass if Card with contents that have fewer characters than another Card is considered "less than"
 * @return pass: true, fail: false
 */
bool CharsTester::testCardIsLessThan() {
    Card myLongCard = Card("His name is ____ which is a really awful name.");
    Card myShortCard = Card("I ____ it");
    if(myShortCard < myLongCard)
    {
        return true;
    }
    return false;
}

