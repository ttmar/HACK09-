/**
Author: Victor Nguyen, Collin Sipple
My NU ID: 02357235
CLASS: 155E
Section 250
Date Started: 10/18/2018
Date Finished: 10/18/2018
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "gameUtils.h"

void freeBoard(Move **board) {

  for(int i=0; i<3; i++) {
    free(board[i]);
  }
  free(board);
  return;
}

Move ** copyBoard(Move **board) {

  Move **copy = newBoard();
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      copy[i][j] = board[i][j];
    }
  }
// another discrepancy
  return copy;
}

Move ** newBoard() {
  Move **board = (Move **) malloc(3 * sizeof(Move*));
  for(int i=0; i<3; i++) {
    board[i] = (Move *) malloc(3 * sizeof(Move));
    for(int j=0; j<3; j++) {
      board[i][j] = NONE;
    }
  }
  return board;
}

void printBoard(Move **board) {

  printf("\n");
  for(int i=0; i<3; i++) {
    printf("  ");
    for(int j=0; j<3; j++) {
      if(board[i][j] == X) {
        printf("  X  ");
      } else if(board[i][j] == O) {
        printf("  O  ");
      } else {
        printf(" (%d) ", (i*3+j+1) );
      }
      if(j < 2) {
        printf(" | ");
      }
    }
    printf("\n");
    //Sixth discrepancy; replace 3 with 2 so it will print 2 line instead of 3
    if(i<2) {
      printf("  ------+-------+------\n");
    }
  }
  printf("\n");

  return;
}

GameMode mainMenu() {

  int choice = 0;
  while(choice < 1 || choice > 3) {
    printf("Welcome to Tic-Tac-Toe!!\n");
    printf("☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭\n");
    printf("Menu\n");
    printf("(1) 2-COMMIES game\n");
    printf("(2) 1-COMMIE game vs US computer\n");
    printf("(3) 1-COMMIE game vs SOVIET computer\n");
    scanf("%d", &choice);
  }
  return choice;
}



Status getStatus(Move **board) {

  Status s = TIE;

  if( //rows
      //first discrepancy, the board was repeating it self so I edit it to [0][2] not [0][1]
      (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == X) ||
      (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == X) ||
      (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == X) ||
      //cols
      (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == X) ||
      (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == X) ||
      (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == X) ||
      //across
      (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == X) ||
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == X)  ) {
    s = X_WINS;
  } else if(
      //rows
      (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == O) ||
      (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == O) ||
      (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == O) ||
      //cols
      (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == O) ||
      (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == O) ||
      (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == O) ||
      //across
      (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == O) ||
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == O)  ) {
    s = O_WINS;
  } else {

    //if there are any unplayed squares, keep playing
    int i, j;
    for(i=0; i<3; i++) {
      for(j=0; j<3; j++) {
        //Second discrepancy; fixing it by remove all of O and X and replace them with NONE
        if(board[i][j] == NONE) {
          s = PLAYING;
        }
      }
    }
  }
  return s;
}
