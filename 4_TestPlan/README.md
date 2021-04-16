# TEST PLAN:

## High level test plan

| **Test ID** | **Description**  | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |
|-------------|------------------|-------------|-------------|----------------|------------------|  
| H_01        | Testing the user interface | user choice | creates a new game/ exting the application| PASS | Scenario based|
| H_02        | Testing the create game function | user choice | initializing a new boardgame | PASS | Technical |
| H_03        | Testing the working of the game controlling modules | user move | updating the board, declaring the winner, terminating the game if the board is full | PASS | Scenario based, technical |

## Low level test plan

| **Test ID** | **Description**  | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |  
|-------------|------------------|-------------|-------------|----------------|------------------|  
| L_01        | calling the function initializeBoard() to check if the board contents have been initialized properly | user choice 1 | board object is initialized | PASS | Scenario based |
| L_02        | calling the function isLegalMove() to check if the system is able to detect illegal moves correctly | column number that is not between 1 and 7 | flags the illegal move | illegal move is flagged | Boundary based |
| L_03        | calling function isLegalMove() to check if system is able to detect illegal moves correctly | column that has already been filled | flags illegal move | illegal move is flagged | scenario, boundary based |
| L_04      | calling the function dropPiece() | column number | updation of the content of a particular cell in the game board | content of cell is updated | requirement based |
| L_05      | checking the various aspects of the function playerMove() | a player move that results in a connect 4 horizontally | the connect is detected, the winner is declared and the game is terminated | PASS | scenario based |
| L_06      | checking the various aspects of the function playerMove() | a player move that results in a connect 4 vertically | the connect is detected, the winner is declared and the game is terminated | PASS | scenario based |
| L_07      | checking the various aspects of the function playerMove() | a player move that results in a connect 4 diagonally | the connect is detected, the winner is declared and the game is terminated | PASS | scenario based |
| L_08      | checking the various aspects of the function playerMove() | a player move that results in a full grid with no more moves available | the lack of moves is detected and the game is terminated without declaring a winner | PASS | scenario based |