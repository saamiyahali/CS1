#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Welcome to my interactive art gallery, wonderful person" << endl;
  cout << "Here are the different exhibits you can visit: \n";
  cout << "1. Draw a stack of boxes \n"
       << "2. Draw an X \n"
       << "3. Draw a banner of letters \n"
       << "4. Exit \n";
  int userC = 0;
  cout << "Enter the number of the exhibit you would like to visit: ";
  cin >> userC;
  switch (userC) 
  {
    case 1: 
    {
      int num_boxes = 0;
      int box_width = 0;
      
      do {
        cout << "Enter how many boxes you want and their width: ";
        cin >> num_boxes >> box_width;
      } while (! (num_boxes <= 10 && num_boxes >= 3) || !(box_width <= 10 && box_width >= 3));
      
      for (int rows = 1; rows <= num_boxes; rows++) 
      {
        for (int dash = 1; dash <= box_width; dash++) 
        {
          cout << "-";
        } 
        cout << "\n|";
        for (int space = 1; space <= box_width - 2; space++)
          {
            cout << " ";
          }
        cout << "|" << endl;
      }
      for (int last_dash = 1; last_dash <= box_width; last_dash++) 
      {
        cout << "-";
      } 
      break;
    }

    case 2: 
    {
      int stem = 0;
      do {
        cout << "Enter the stem length of the X: ";
        cin >> stem;
      } while (!(stem >= 1 && stem <= 10));

      for (int row = 1; row <= stem; row++)
      {
          // inner loop to print the spaces on the left side
          for (int space = 0; space < row - 1; space++)
          {
              cout << ' ';
          }

          cout << "\\";

          for (int space_after = 2*(stem - 1) - 2*(row - 1); space_after > 0; space_after--)
          {
              cout << ' ';
          }

          cout << "/" << endl;
      }
      
      for (int row = 1; row <= stem; row++)
      {
          // inner loop to print the spaces on the left side
          for (int space = 1; space <= stem - row; space++)
           {
               cout << ' ';
           }

          cout << "/";

          for (int space_after = 0; space_after < 2*(row - 1); space_after++)
          {
              cout << ' ';  
          }

          cout << "\\" << endl;
        
      }
      break;
    }
    case 3: 
   { 
      char user_letter = ' '; 
      do {
          cout << "Enter the lowercase letter to end on: ";
          cin >> user_letter; 
      } while (!(user_letter >= 'a' && user_letter <= 'z')); 

      for (int ascii_val = 'a'; ascii_val < user_letter; ascii_val++)  
      {
        for (int j = ascii_val; j < user_letter; j++) {
          cout << char(j);  
        } 

        for (int space = 0; space < ascii_val - 'a'; space++)
        {
          cout << ' '; 
        }

        cout << user_letter << endl;
      } 
     for (int last_line = 0; last_line <= user_letter - 'a'; last_line++)
      {
         cout << user_letter;
      }
      break;
    } 

    case 4:
      {
        cout << "Thank you for visiting the art gallery, have a wonderful day!";
      }
      break;

    default: 
    {
      cout << "That's not an option :("; 
      break;   //perfect!!
    } 
  }
  
  return 0;
}