#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver() : Cols{"123456789"}, Rows{"ABCDEFGHI"} {
  auto Cross = [](std::string String1,
                  std::string String2) -> std::vector<std::string> {
    std::vector<std::string> Result;
    std::string Concat;
    for (char C1 : String1) {
      Concat = C1;
      for (char C2 : String2) {
        Result.push_back(Concat + C2);
      }
    }
    return Result;
  };
  Squares = Cross(this->Rows, this->Cols);
  std::vector<std::vector<std::string>> UnitsList;
  for (char DigiChar : this->Cols) {
    UnitsList.push_back(Cross(this->Rows, {DigiChar}));
  }
  for (char RowChar : this->Rows) {
    UnitsList.push_back(Cross({RowChar}, this->Cols));
  }
  for (std::string RowBlock : {"ABC", "DEF", "GHI"}) {
    for (std::string ColBlock : {"123", "456", "789"}) {
      UnitsList.push_back(Cross(RowBlock, ColBlock));
    }
  }
  auto InsertOrMergeIntoPeers = [&](std::string Key,
                                    std::vector<std::string> &Value) {
    if (std::get<bool>(
            this->Peers.try_emplace(Key, Value.begin(), Value.end())) != true) {
      this->Peers.at(Key).insert(Value.begin(), Value.end());
    }
  };
  for (auto EachUnitList : UnitsList) {
    for (auto SquareInUnit : EachUnitList) {
      InsertOrMergeIntoPeers(SquareInUnit, EachUnitList);
      this->Peers.at(SquareInUnit).erase(SquareInUnit);
    }
  }
}

std::pair<bool, std::map<std::string, std::string>>
SudokuSolver::solve(std::string Puzzle) {}
