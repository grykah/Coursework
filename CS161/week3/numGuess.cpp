/**********************************************************
** Author: Hailey Wilder
** Date: 10/11/16
** Description: Has user attempt to guess a number & checks answer.
**********************************************************/

#include <iostream>  

using std::cin;
using std::cout;
using std::endl;

int main() {

  int guesses,   // # guesses
      answer, // correct anwer to guess
      userGuess; // users most recent guess
  bool correct;     // T if user answer = userGuess

  // get int from user
  cout << "Enter the number for the player to guess." << endl;
  cin >> answer;

  correct = false;
  guesses = 0;

  cout << "Enter your guess." << endl;

  // until T, give feedback on guesses
  do {
    // get next guess and guesses = guesses + 1
    cin >> userGuess;
    guesses++;

    // when guess is right, loop stops
    if (userGuess == answer) {
      correct = true;
    }
    // guess < answer --> get new guess
    else if (userGuess < answer) {
      cout << "Too low - try again." << endl;
    }
    // guess > answer --> get new guess
    else {
      cout << "Too high - try again." << endl;
    }
  } while (!correct);

  // return result
  cout << "You guessed it in " << guesses
       << (guesses == 1 ? " try." : " tries.") << endl;

  return 0;
}