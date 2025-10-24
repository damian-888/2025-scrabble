#include <cctype>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

string player_1;
string player_2;
vector<char> alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<int> scores = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
string winner_msg;

int compute_scores(string player) {
  string winner;
  int score = 0;
  
  //Find value player
  //For every char in player
  for(char c : player) {
    //loop through alpha (until end) with i 
    if(isupper(c)) {
      c = tolower(c);
    }

    if(!isalpha(c)) {
      score = 0;
      break;
    }

    for(int i = 0; i < alpha.size(); i++) {
      //if the char == value at alpha index

      if(c == alpha[i]) {
        score += scores[i];
      }
    }
  }
  return score;
}

int main() {
  
  while (true) {
    cout << "Player 1: ";
    cin >> player_1;

    cout << "Player 2: ";
    cin >> player_2;

    //Will input a number as a string and player will theoretically pass. Check/ validate type
    if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
      break;
    }
  }

  int p1_score = compute_scores(player_1);
  int p2_score = compute_scores(player_2);

  //cout << p1_score << endl;
  //cout << p2_score << endl;

  //compare scores
  //if p1 higher, print "Player 1 wins!"
  //else p2 higher, print "Player 2 wins!"
  //else Tie!
  if(p1_score > p2_score) {
    cout << "Player 1 wins!\n";
    //cout << "p1: " << p1_score << " || " << "p2: " << p2_score << endl;
  } else if(p1_score < p2_score) {
    //cout << "p1: " << p1_score << " || " << "p2: " << p2_score << endl;
    cout << "Player 2 wins!\n";
  } else if(p1_score == p2_score){
    //cout << "p1: " << p1_score << " || " << "p2: " << p2_score << endl;
    cout << "Tie!\n";
  } else {
    //cout << "p1: " << p1_score << " || " << "p2: " << p2_score << endl;
    cout << "Error\n";
  }
 
  return 0;
}
