/**
Author: Victor Nguyen, Collin Sipple
My NU ID: 02357235
CLASS: 155E
Section 250
Date Started: 10/18/2018
Date Finished: 10/18/2018
 *
 */
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#include "gameUtils.h"
#include "playerUtils.h"

int main(int argc, char **argv) {

  srandom(time(NULL));

  int gameChoice = mainMenu();
  Move **board = newBoard();
  Status s = getStatus(board);

  while(s == PLAYING) {

    //x moves
    printBoard(board);
    userMove(board, X);
    s = getStatus(board);
    if(s != PLAYING) {
      break;
    }

    //o moves
    printBoard(board);
    if(gameChoice == TWO_PLAYER) {
      //Fifth discrepancy, replace 0 with O for compatible variable
      userMove(board, O);
    } else if(gameChoice == ONE_PLAYER_RANDOM) {
      randomComputerMove(board);
    } else if(gameChoice == ONE_PLAYER_SMART) {
      smartComputerMove(board);
    }
    s = getStatus(board);

  }

  printf("Final Board:\n");
  printBoard(board);

  if(s == O_WINS) {
    printf("O Wins! (͠≖ ͜ʖ͠≖)\n");
  } else if(s == X_WINS) {
    printf("X Wins! ╭∩╮(ಠ۝ಠ)╭∩╮\n");
  } else if(s == TIE) {
    printf("TIE! ┐(´д`)┌\n");
  }

  return 0;
}
