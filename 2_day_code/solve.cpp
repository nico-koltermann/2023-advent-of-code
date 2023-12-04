#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <math.h>

typedef std::map<std::string, int> GameColors;

void resetGame(GameColors &g) {
  g["red"] = 0;
  g["blue"] = 0;
  g["green"] = 0;
}

int main() {

  GameColors gc;

  resetGame(gc);

  std::fstream newfile;
  newfile.open("data", std::ios::in);

  std::string word;

  int amount;
  int count = 0;
  int gameNumber = 0; 

  if (newfile.is_open()) {
    std::string tp;    

    while(getline(newfile, tp)) {
      
      std::istringstream iss(tp);
      gameNumber = 0;
      
      while(iss >> word) {
        if (word == "Game") {
          iss >> word;
          gameNumber = std::stoi(word.substr(0, word.size()-1));
          iss >> word;
        }

        amount = std::stoi(word);
        iss >> word;
        if (word.substr(word.size()-1, word.size()) == "," || word.substr(word.size()-1, word.size()) ==";") {
          word = word.substr(0, word.size()-1);
        }

        gc[word] = std::max(amount, gc[word]);
        

      }
      

      count += gc["red"] * gc["blue"] * gc["green"];

      if (gc["red"] <= 12 && gc["blue"] <= 14 && gc["green"] <= 13) {

      } else  {
      }

      std::cout << amount << " Value, " << word << std::endl << gc["red"] << "R " << gc["blue"] << "B " << gc["green"] << "G " << std::endl;
      
      resetGame(gc);
      
    }
    
    newfile.close();
  }

  std::cout << count << std::endl;

}