#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

void load_knight(int knights[][5]) {
  for(int i = 0; i < 5; i++) {
    for(int q = 0; q < 5; q++) {
      knights[i][q] = 0;
    }
  }
}

void print_knight(int knights[][5], int line){

  std::cout << "[0;0H\n";

  for(int i = 0; i < line; i++) {
    for(int q = 0; q < line; q++) {
      std::cout << knights[i][q] << " ";
    }
    std::cout << "\n";
  }
}

bool none(int knights[][5], int line) {
  for(int i = 0; i < 5; i++) {
    for(int q = 0; q < 5; q++) {
      if(knights[i][q] == 0) {
        return false;
      }
    }
  }
  return true;
}

void solve(int knights[][5], int line, int row, int col, int order) {

    if(row < 0 || col < 0 || line <= row || line <= col) {     
      return;
    }

    if(knights[row][col] > 0) {
      return;
    }

    knights[row][col] = order;
    // sleep(1);
    // print_knight(knights,line);

    solve(knights,line,row+1,col+2,order+1);
    solve(knights,line,row+1,col-2,order+1);
    solve(knights,line,row-1,col+2,order+1);
    solve(knights,line,row-1,col-2,order+1);
    solve(knights,line,row+2,col+1,order+1);
    solve(knights,line,row+2,col-1,order+1);
    solve(knights,line,row-2,col+1,order+1);
    solve(knights,line,row-2,col-1,order+1);

  if(none(knights, line)) {
    return;
  }
  
  knights[row][col] = 0;
}

int main() {
  int line = 5;
  int knights[line][5];
  load_knight(knights);
  print_knight(knights,line);
  solve(knights, line, 0, 0, 1);
  print_knight(knights,line);

}