#include <iostream>
#include <vector>

bool draw = false;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char player = 'X';
int player_choice;

void introduction() {
  std::cout << "\n================================" << std::endl;
  std::cout << "Welcome to the Tic-Tac-Toe Game!" << std::endl;
  std::cout << "================================" << std::endl;
  std::cout << "\nIf you want to make a move just pick up a number of cell indicated below:" << std::endl;
}

void display_board() {

    std::cout << "\n";
    std::cout << "     |     |      " << std::endl;
    std::cout <<"  "<< board[0][0] <<"  |  "<< board[0][1] << "  |  " << board[0][2] << "" << std::endl;
    std::cout << "_____|_____|_____ " << std::endl;
    std::cout << "     |     |      " << std::endl;
    std::cout <<"  "<< board[1][0] <<"  |  "<< board[1][1] << "  |  " << board[1][2] << "" << std::endl;
    std::cout << "_____|_____|_____ " << std::endl;
    std::cout << "     |     |      " << std::endl;
    std::cout <<"  "<< board[2][0] <<"  |  "<< board[2][1] << "  |  " << board[2][2] << "" << std::endl;
    std::cout << "     |     |      " << std::endl;
    std::cout << "\n";
    
}

int last_move() {
    int moves = 0;
    for (int i_row = 0; i_row < 3; i_row++) {
        for (int i_column = 0; i_column < 3; i_column++) {
            if (board[i_row][i_column] != 'X' && board[i_row][i_column] != 'O') {
                moves++;
            }
        }
    }
    return moves;
}

void turn() {

  if (player == 'X') {
    std::cout << "\nPlayer \"X\" turn: ";
  } else if (player == 'O') {
    std::cout << "\nPlayer \"O\" turn: ";
  }
  
  std::cin >> player_choice;

  switch (player_choice) {
    case 1:
      row = 0;
      column = 0;
      break;
    case 2:
      row = 0;
      column = 1;
      break;
    case 3:
      row = 0;
      column = 2;
      break;
    case 4:
      row = 1;
      column = 0;
      break;
    case 5:
      row = 1;
      column = 1;
      break;
    case 6:
      row = 1;
      column = 2;
      break;
    case 7:
      row = 2;
      column = 0;
      break;
    case 8:
      row = 2;
      column = 1;
      break;
    case 9:
      row = 2;
      column = 2;
      break;
    default:
      std::cout << "Incorrect input." << std::endl;
      break;
  }

  if (board[row][column] != 'X' && board[row][column] != 'O') {
    if (player == 'X' && last_move() != 1) {
      board[row][column] = 'X';
      player = 'O';
    } else if (player == 'O' && last_move() != 1) {
      board[row][column] = 'O';
      player = 'X';
    // checking if it is last move so that the winner displays correctly 
    } else if (player == 'X') {
      board[row][column] = 'X';
    } else if (player == 'O') {
      board[row][column] = 'O';
    }
  } else {
    std::cout << "This cell is already filled! Please chose another one." << std::endl;
    turn();
  }

  display_board();

}

bool end_game() {

  //checking if the winner is by rows or columns
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return false;
    } 
  } 

  //checking if the winner is by diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
    return false;
  }

  //checking if the game should continue
  for (int i_row = 0; i_row < 3; i_row++) {
    for (int i_column = 0; i_column < 3; i_column++) {
      if (board[i_row][i_column] != 'X' && board[i_row][i_column] != 'O') {
        return true;
      }
    }
  }

  draw = true;
  return false;
}

void new_game() {
  board[0][0] = '1';
  board[0][1] = '2';
  board[0][2] = '3';
  board[1][0] = '4';
  board[1][1] = '5';
  board[1][2] = '6';
  board[2][0] = '7';
  board[2][1] = '8';
  board[2][2] = '9';
  player = 'X';
  draw = false;
}