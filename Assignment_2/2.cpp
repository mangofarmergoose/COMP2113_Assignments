// use https://www.sudoku-solutions.com/ to generate a board
// this website also supports using particular techniques to solve for a board
// from preferences, choose Naked-Singles only or partial solving
// then click "Solve Partially", you may then cross-check with your progran output

#include <iostream>

using namespace std;
/* bool noChange = true; */

int get_empty(int b[][9], int r, int c);
// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is
//             You may add other functions wherever appropriate

// get user input and store the game board in the 2D array b
void ReadBoard(int b[][9])
{
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      cin >> b[i][j];
    }
  }
}

// display the game board stored in the 2D array b
void PrintBoard(int b[][9])
{
  for (int i = 0; i < 9; ++i)
  {
    if (i == 3 || i == 6)
    {
      cout << "------+-------+-------" << endl;
    }
    for (int j = 0; j < 9; ++j)
    {
      if (b[i][j] != 0)
      {
        cout << b[i][j] << " ";
      }
      else if (b[i][j] == 0)
      {
        cout << "x ";
      }

      if (j == 2 || j == 5)
      {
        cout << "| ";
      }

      if (j == 8)
      {
        cout << endl;
      }
    }
  }
}

int get_empty(int b[][9], int r, int c)
{
  return b[r][c];
}

// linearsearch to check occurrence
bool checkposs(int result, int poss[9])
{
  for (int i = 0; i < 9; ++i)
  {
    if (poss[i] == result)
    {
      return true;
    }
  }
  return false;
}

void changeposs(int result, int poss[9])
{
  for (int i = 0; i < 9; ++i)
  {
    if (poss[i] == result)
    {
      poss[i] = 0;
    }
  }
}

void check_coord(int b[][9], int o_r, int o_c, int poss[9])
{
  //check row and col
  for (int c = 0; c < 9; ++c)
  {
    int result = b[o_r][c];
    if (result != 0 && checkposs(result, poss) == true)
    {
      changeposs(result, poss);
    }
  }

  for (int r = 0; r < 9; ++r)
  {
    int result = b[r][o_c];
    if (result != 0 && checkposs(result, poss) == true)
    {
      changeposs(result, poss);
    }
  }

  // check 3x3 grid
  int new_br = o_r - o_r%3; //starting point of 3x3 box
  int new_bc = o_c - o_c%3;
  int rbound = new_br+3;
  int cbound = new_bc+3;
  for(int r = new_br; r<rbound; ++r){
    for(int c = new_bc; c<cbound; ++c){
      int result = b[r][c];
      if (result != 0 && checkposs(result, poss) == true)
      {
      changeposs(result, poss);
      }
    }
  }
}

// check whether only one left, return 8 if so
int checkRemaining(int poss[9])
{
  int cnt = 0;
  for (int i = 0; i < 9; ++i)
  {
    if (poss[i] == 0)
    {
      cnt++;
    }
  }
  return cnt;
}

//
int getRemainingVal(int poss[9])
{
  for (int i = 0; i < 9; ++i)
  {
    if (poss[i] != 0)
    {
      return poss[i];
    }
  }
  return 0;
}

bool Checking(int b[][9])
{
  bool noChange = true;
  for (int r = 0; r < 9; ++r)
  {
    for (int c = 0; c < 9; ++c)
    {

      // get the val of coordinates
      if (b[r][c] != 0)
      {
        // ignore if not empty
        continue;
      }

      int poss[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

      // if not poss, remove from poss
      check_coord(b, r, c, poss); 

      if (checkRemaining(poss) == 8)
      {
        b[r][c] = getRemainingVal(poss);
        noChange = false;
      }
    }
  }
  return noChange;
}

// solve a game board stored in b using the Naked Single technique only
// the (partial) solution is stored in the input array b
void SolveBoard(int b[][9])
{
  while (true)
  {
    if (Checking(b))
    {
      break;
    }
  }
}

// You do not need to change anything in the main() function
int main()
{
  int board[9][9]; // the 9x9 game board

  ReadBoard(board);

  cout << "Input Sudoku board:" << endl;
  PrintBoard(board);

  // solve the board using the naked single technique only
  SolveBoard(board);

  cout << endl;
  cout << "Final Sudoku board:" << endl;
  PrintBoard(board);

  return 0;
}

/* 3 9 0 7 8 4 0 0 0
0 0 4 9 0 6 8 0 7
0 0 0 0 0 3 0 6 0
0 0 8 2 4 1 0 0 0
7 3 1 8 9 5 6 2 4
0 0 0 0 6 7 9 0 0
0 1 0 4 0 2 0 0 0
2 0 9 6 0 8 3 0 0
0 0 0 0 1 9 0 4 8 */