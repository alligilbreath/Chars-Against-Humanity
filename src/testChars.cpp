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
    return false;
}

/*
 * @requirement pass if "\n" is discarded by Word constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructWordWithNewLine() {
    return false;
}

/*
 * @requirement pass if Word created using constructor with string that has a space is considered invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidWithSpace() {
    return false;
}

/*
 * @requirement pass if Word created using constructor with string that has a percent sign is considered valid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidPercentSign() {
    return false;
}

/*
 * @requirement pass if Word created using constructor with string that is less than 3 characters is considered invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidShortWord() {
    return false;
}

/*
 * @requirement pass if "\r\n" is discarded by Card constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructCardWithCarriageReturn() {
    return false;
}

/*
 * @requirement pass if "\n" is discarded by Card constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructCardWithNewLine() {
    return false;
}

/*
 * @requirement pass if Card created using constructor with string that has no underscores is invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsCardValidNoBlank() {
    return false;
}

/*
 * @requirement pass if Card created using constructor with string that has a blank that is only two characters long is invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsCardValidShortBlank() {
    return false;
}

/*
 * @requirement pass if blankLength and blankIndex is correct in properly formatted Card object with a blank yet to be filled.
 * @return pass: true, fail: false
 */
bool CharsTester::testCorrectBlankLengthAndIndex() {
    return false;
}

/*
 * @requirement pass if Card with contents that have fewer characters than another Card is considered "less than"
 * @return pass: true, fail: false
 */
bool CharsTester::testCardIsLessThan() {
    return false;
}

