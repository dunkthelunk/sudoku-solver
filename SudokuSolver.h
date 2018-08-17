#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include <utility>
//#include <variant>
#include <map>
#include <set>
#include <string>
#include <vector>

class SudokuSolver {
private:
  std::string Cols;
  std::string Rows;
  std::vector<std::string> Squares;
  std::map<std::string, std::vector<std::string>> Units;
  std::map<std::string, std::set<std::string>> Peers;

public:
  SudokuSolver();
  std::pair<bool, std::map<std::string, std::string>> solve(std::string puzzle);
  //   std::variant<bool, std::map<int, std::string>> solve(std::string puzzle);
};

#endif
