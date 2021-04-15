#include "unity.h"
#include "connect_four.h"

//functions required by the Unity test framework
void setUp() {};
void tearDown() {};

board boardGame;
board *ptrBoardGame = &boardGame;

/* prototypes of the test functions */
void setting_up_boardgame(void);
void checking_legal_move(void);
//void checking_player_moves(void);

int main(void)
{
    /* Initiating the Unity test framework */
    UNITY_BEGIN();

    /* Run test functions */
    RUN_TEST(setting_up_boardgame);
    RUN_TEST(checking_legal_move);
    //RUN_TEST(checking_player_moves);

    /* Close the Unity test framework */
    return UNITY_END();
}

void setting_up_boardgame(void)
{
    initializeBoard(ptrBoardGame, "Jayasri", "Shruthi");
    TEST_ASSERT_EQUAL_INT(6, ptrBoardGame->numberOfRows);
    TEST_ASSERT_EQUAL_INT(7, ptrBoardGame->numberOfColumns);
    TEST_ASSERT_EQUAL_INT(4, ptrBoardGame->numToConnect);
    TEST_ASSERT_EQUAL_INT(0, ptrBoardGame->currentPlayer);
    TEST_ASSERT_EQUAL_INT(0, ptrBoardGame->winner);
    TEST_ASSERT_EQUAL_STRING("Jayasri",ptrBoardGame->playerName[0]);
    TEST_ASSERT_EQUAL_STRING("Shruthi",ptrBoardGame->playerName[1]);
    TEST_ASSERT_EQUAL_CHAR('B',ptrBoardGame->playerColour[0]);
    TEST_ASSERT_EQUAL_CHAR('R',ptrBoardGame->playerColour[1]);

    /*int arrcheck[6] = {5,5,5,5,5,5};
    TEST_ASSERT_EQUAL_INT_ARRAY( arrcheck, ptrBoardGame->currRowPlaceCoin, 6);
    
    char chararray = {' ',' ',' ',' ',' ',' ',' '};
    TEST_ASSERT_EQUAL_CHAR_ARRAY(chararray ,ptrBoardGame->boardContents[0],7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(chararray ,ptrBoardGame->boardContents[1],7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(chararray ,ptrBoardGame->boardContents[2],7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(chararray ,ptrBoardGame->boardContents[3],7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(chararray ,ptrBoardGame->boardContents[4],7);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(chararray ,ptrBoardGame->boardContents[5],7);*/
}

void checking_legal_move(void)
{
    TEST_ASSERT_EQUAL(0,isLegalMove(9,ptrBoardGame));
    TEST_ASSERT_EQUAL(0,isLegalMove(-1,ptrBoardGame));

    //ptrBoardGame->currentPlayer = 1;
    
    //dropping piece after piece in the same column
    //dropPiece(7,ptrBoardGame);
    //dropPiece(7,ptrBoardGame);
    //dropPiece(7,ptrBoardGame);
    //dropPiece(7,ptrBoardGame);
    //dropPiece(7,ptrBoardGame);

    TEST_ASSERT_EQUAL(1,isLegalMove(7,ptrBoardGame));
    //TEST_ASSERT_EQUAL(0,isLegalMove(7,ptrBoardGame));

}

/*void checking_player_moves(void)
{
    
}*/