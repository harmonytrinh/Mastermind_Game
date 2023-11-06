//
//  Score.cpp
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

    // setup a default score - all WRONG ANSWER's
    Score::Score()
    {
        for (int i = 0; i < REQUIREDLENGTH; i++)
        {
            array[i] = WRONG;
        }
    }

    // TODO comparing the played move to the answer move,
    //      build the ANSWER array of this Score
    Score::Score(Move move, Move answer)
    {
       bool tf[REQUIREDLENGTH] = { false };
       for (int i = 0; i < REQUIREDLENGTH; i++) {
           if (move.getPiece(i).getColorAsString() == answer.getPiece(i).getColorAsString()) {
               array[i] = RIGHT;
               tf[i] = true;
           }
           else {
               array[i] = WRONG;
               tf[i] = false;
           }
       }
        
    

        for (int i = 0; i < REQUIREDLENGTH; i++) {
            if (move.getPiece(i).getColorAsString() == answer.getPiece(i).getColorAsString()) {
                continue;
            }
            for (int j = 0; j < REQUIREDLENGTH; j++) {
                if (tf[j] == true) {
                    continue;
                }

            if (move.getPiece(i).getColorAsString() == answer.getPiece(j).getColorAsString()) {
                array[i] = MAYBE;
                tf[j] = true;
            }
        }
    }
        

    // bool array to keep track of matches in answer
    // initialize bool array to all false
    
    // loop  through and mark all exact matches as RIGHT, else set to WRONG
    // also mark matches to true in bool array
    
    
    // nested for loop to mark MAYBEs
    // loop through move pieces (index i):
        // if move pieces is RIGHT, continue
        // loop through answer pieces (index j):
            // if bool array is true at j, continue
            // if answer piece and move piece have the same color
            // mark index i as MAYBE
            // set bool array to true at j
   
}

// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const
{
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        if (array[i] != RIGHT) {
            return false;
        }
    }
    return true;
 
    // loop through array and return if something isn't RIGHT
    // return true
}

}

