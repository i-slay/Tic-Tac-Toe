#include <iostream>
#include <vector>
#include "ttt_function.hpp"

int restart_choice = 2;

int main() {

  do {
    
    introduction();
    new_game();
    display_board();

    while (end_game()) {
      turn();
      end_game(); 
    }

    if (player == 'X' && draw == false) {
      std::cout << "Congratulations Player \"X\"! You won!" << std::endl;
    } else if (player == 'O' && draw == false) {
      std::cout << "Congratulations Player \"O\"! You won!" << std::endl;
    } else {
      std::cout << "Draw! Nobody wins!" << std::endl;
    }

    std::cout << "\nDo you want to play again?\n\n1) Yes\n2) No" << std::endl;
    std::cin >> restart_choice;
    
  } while (restart_choice != 2);
}