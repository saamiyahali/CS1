#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//TODO #1
//initiate functions
void map(int&, int&, int&, int&, int);
void beg_pos(int&, int&, int&, int&);
bool locHid(int&, int&, int&, int&);
void hidden_new_pos(int&, int&, int&, int&);
void move_it(int&, int&);
bool direction_valid(string);
bool bounds_valid(int, int);
bool win_game(int&, int&, int&, int&);

//function #1
//call all functions
int main() {
  srand(time(0));
  int hidden_row, hidden_col, it_row, it_col;
  int turn = 0;
  beg_pos(hidden_row, hidden_col, it_row, it_col);

  int mode = 0;
  cout << "Do you want to play in easy mode or hard mode? \nEnter 1 for easy or 0 for hard: ";
  cin >> mode;
  cin.ignore();


  while (win_game(hidden_row, hidden_col, it_row, it_col) == false)
  {
    turn++;
    cout << "\nTurn: " << turn << endl;


    if (turn % 2 == 0)
    { //Our (IT) turn + randomly moving H
      hidden_new_pos(it_row, it_col, hidden_row, hidden_col);
      map(hidden_row, hidden_col, it_row, it_col, mode);
      move_it(it_row, it_col);
      
      
    } else {
      //it locates turn + randomly moving H
      hidden_new_pos(it_row, it_col, hidden_row, hidden_col);
      map(hidden_row, hidden_col, it_row, it_col, mode);
      locHid(hidden_row, hidden_col, it_row, it_col);
    }
  } 
  
  if (win_game(hidden_row, hidden_col, it_row, it_col))
  {
    cout << "\nTurn: " << turn << endl;
    map(hidden_row, hidden_col, it_row, it_col, mode);
    cout << "You won!!! Pls give us an A" << endl;
  }

  return 0;
}

//function #2
// desc: generate map with 6 rows, 8 columns, display "it" player, display "hidden" player if in easy mode
// input: hidden player's row and column, it player's row and column, mode
// output: N/A

void map(int& hidden_row, int& hidden_col, int& it_row, int& it_col, int mode)
{
  int ROWS = 6, COLUMNS = 8;
  cout << "\n----------------------------------------\n";
  for (int row = 1; row <= ROWS; row++)
  {
      for (int col = 1; col <= COLUMNS; col++)
      {
        cout << "| ";
        if (row == it_row && col == it_col)
        {
          cout << "I |";
        }
        else if (row == hidden_row && col == hidden_col && mode == 1)
        {
          cout << "H |";
        }
        else
        {
          cout << "  |";
        }
      }
      cout << "\n----------------------------------------" << endl;
  }

}

// function #3
// desc: locate postion of hidden player and generate "sound" if "hidden" player is in the perimeter of "it"
// input: hidden player's row and column, it player's row and column
// output: true if "hidden" player is in the perimeter of "it", false if not

bool locHid(int& hidden_row, int& hidden_col, int& it_row, int& it_col)
{
  for (int row_num = -1; row_num <= 1; row_num++)
  { 
    for(int col_num = -1; col_num <= 1; col_num++)
    {
      if(it_col == hidden_col + col_num && it_row == hidden_row + row_num)
      {
        cout << "The it player makes a sound . . . they heard something move!!!\n"<< endl;
        return true;
      }
    }
  }
  cout << "The it player makes a sound . . . silence rings.\n" << endl;
  return false;
}

// function #4
// desc: randomly generate hidden/it player position on map within map bounds
// input: hidden player's row and column, it player's row and column
// output: N/A

void beg_pos(int& it_row, int& it_col, int& hidden_row, int& hidden_col)
{
  hidden_row = rand() % 6 + 1;
  hidden_col = rand() % 8 + 1;
  it_row = rand() % 6 + 1;
  it_col = rand() % 8 + 1;
}

// function #5
// desc: randomly move hidden player 1 up/down/left/right/diagonally
// input: hidden player's row and column, it player's row and column
// output: N/A

void hidden_new_pos(int& it_row, int& it_col, int& hidden_row, int& hidden_col)
{
  do
  {
    int rand_direction = 0 + rand() % (2 - 0 + 1);
    int rand_new_row = (hidden_row - 1) + rand() % ((hidden_row + 1) - (hidden_row - 1) + 1);
    int rand_new_col = (hidden_col-1) + rand() % ((hidden_col+1) - (hidden_col -1) + 1);
    if (rand_direction == 0)
    {
      hidden_row = rand_new_row;
    }
    else if (rand_direction == 1)
    {
      hidden_col = rand_new_col;
    }
    else // random move diagonally 
    {
      hidden_row = rand_new_row;
      hidden_col = rand_new_col;
    }
  } while (bounds_valid(hidden_row, hidden_col) == false);
}

//function #6
// desc: ask it user for input on where to move. if direction is valid and within bounds, move it player
// input: it player's row and column
// output: N/A

void move_it(int& it_row, int& it_col)
{  
  string user_choice;

  int temp_row = it_row;
  int temp_col = it_col;
  
  do
  {
    cout << "Which direction do you want to move in? ";
    getline(cin, user_choice);
  } while(!(direction_valid(user_choice)));

  if (user_choice == "up" && bounds_valid(--temp_row, temp_col))
  {
    it_row--;
  }
  else if (user_choice == "down" && bounds_valid(++temp_row, temp_col))
  {
    it_row++;
  }
  else if (user_choice == "left" && bounds_valid(temp_row, --temp_col))
  {
    it_col--;
  }
  else if (user_choice == "right" && bounds_valid(temp_row, ++temp_col))
  {
    it_col++;
  }
}

//function #7
// desc: validation loop for direction
// input: users choice of direction
// output: true if user's choice is valid, false if not

bool direction_valid(string user_choice)
{
  return (user_choice == "up" || user_choice == "down" || user_choice == "left" || user_choice == "right");
}

// function #8
// desc: validation loop to check if row and column is within bounds
// input: a row, a column
// output: true if row and column is within bounds, false if not

bool bounds_valid(int row, int col)
{
  return (row >= 1 && row <= 6 && col >= 1 && col <= 8);
}

//function #9
// desc: the game has won if hidden player's coordinates are same as it player's coordinates
// input: hidden player's row and column, it player's row and column
// output: true if hidden player's coordinates are same as it player's coordinates, false if not

bool win_game(int& it_row, int& it_col, int& hidden_row, int& hidden_col)
  {
    return (it_row == hidden_row && it_col == hidden_col);
  }