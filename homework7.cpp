#include <cctype>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

/*******************************************************************************
 * Function prototypes
 *******************************************************************************/

vector<vector<char>> createRailFence(const char[], const int, int);
void decrypt(const char[], char[], const unsigned);
void displayRequirements();
void encrypt(const vector<vector<char>> &, char[]);
void menuLoop();
bool verify(const char[], const int, unsigned &);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls the other functions to begin the loop.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer that signals the exit code to the operating system (OS)
 *******************************************************************************/

int main() {
  // start the loop
  displayRequirements();
  menuLoop();

  // terminate
  return 0;
}

/*******************************************************************************
 * Description:
 * Displays the password requirements to the screen for the user.
 *
 * Input:
 * N/A
 *
 * Output:
 * N/A
 *******************************************************************************/

void displayRequirements() {
  const char FILL = '+';
  const int WIDTH = 60;

  cout << setfill(FILL) << setw(WIDTH) << "" << endl;
  cout << "Welcome to my password verifier and strength score program!\n";
  cout << "Your password must meet all of the following conditions:\n";
  cout << "\t1. Contain at least twelve characters\n";
  cout << "\t2. Contain at least one lowercase letter\n";
  cout << "\t3. Contain at least one uppercase letter\n";
  cout << "\t4. Contain at least one digit\n";
  cout << "\t5. Contain at least one punctuation mark\n";
  cout << "\t6. Cannot contain any whitespace\n";
  cout << setfill(FILL) << setw(WIDTH) << "" << endl;
  cout << endl << endl;
}

/*******************************************************************************
 * Description:
 * Gets input from the user and stores it in a C-string. Checks if that input
 * meets the password requirements and the strength of the password. Encrypts
 * and decrypts the password using the rail fence cipher.
 *
 * Input:
 * N/A
 *
 * Output:
 * N/A
 *******************************************************************************/

void menuLoop() {
  const int MAX_PASSWORD_SIZE = 31;
  char password[MAX_PASSWORD_SIZE];
  unsigned strength = 0;
  bool vFlag = false;

  do {
    cout << "Enter your password: ";
    cin.getline(password, MAX_PASSWORD_SIZE);
    if (cin.fail()) {
      cin.clear();
      cin.ignore(4096, '\n');
    }
    vFlag = verify(password, strlen(password), strength);

    if (!vFlag) {
      cout << "The password is not valid, try again!\n";
      strength = 0;
    }
  } while (!vFlag);

  cout << "You entered a valid password!\n";
  cout << "Password strength: " << strength << endl;

  int n = 0;
  cout << "\nNext, my program is going to encrypt your password using the rail "
          "fence cipher.\n";
  do {
    cout << "Enter the number of rails to use: ";
    cin >> n;
  } while (!(n >= 2 && n <= 10));

  vector<vector<char>> railFence =
      createRailFence(password, strlen(password), n);

  char ciphertext[MAX_PASSWORD_SIZE * 2];

  encrypt(railFence, ciphertext);
  cout << "\nYour encrypted password is: " << ciphertext << endl;


  char plaintext[MAX_PASSWORD_SIZE];
  cout << "\nFinally, my program is going to decrypt the ciphertext to get "
          "back your password.\n";

  decrypt(ciphertext, plaintext, strlen(ciphertext));
  cout << "\nYour decrypted password is: " << plaintext << endl;

}

/*******************************************************************************
 * Description: Gets passwords from the user and checks if it meets the
 *requirements
 Input: Gets user's password as cstring, the size of the password,
 *and the strength of the password
 Output: Returns true if the password meets
 *the requirements, false otherwise
 ******************************************************************************/
bool verify(const char PWD[], const int SIZE, unsigned &score) {
  int length = strlen(PWD);
  score = 0;
  if (length < 12)
    return false;
  bool hasLower = false;
  bool hasUpper = false;
  bool hasDigit = false;
  bool hasPunct = false;
  bool hasSpace = false;
  for (int i = 0; i < SIZE; i++) {
    if (islower(PWD[i]))
      hasLower = true;
  }
  for (int i = 0; i < SIZE; i++) {
    if (isupper(PWD[i])) {
        hasUpper = true;
    }
  }
  for (int i = 0; i < SIZE; i++) {
    if (isdigit(PWD[i])) {
      hasDigit = true;
    }
  }
  for (int i = 0; i < SIZE; i++) {
    if (ispunct(PWD[i])) {
      hasPunct = true;
    }
  }
  for (int i = 0; i < SIZE; i++) {
    if (isspace(PWD[i])) {
      hasSpace = true;
    }
  }

  //Score calculation
  for (int i = 0; i < SIZE; i++){
    score++;

    if((i > 0 && (islower(PWD[i]) != islower(PWD[i-1]))) || (isupper(PWD[i]) != isupper(PWD[i-1])) || (isdigit(PWD[i]) != isdigit(PWD[i-1])) || (ispunct(PWD[i]) != ispunct(PWD[i-1])) || (isspace(PWD[i]) != isspace(PWD[i-1]))){
      score++;
    }
  }

  return (hasLower && hasUpper && hasDigit && hasPunct && !hasSpace);

};

/*******************************************************************************
 * Description:
 * gets password from user, prints it in the rail fence pattern and saves to a vector
 *
 * Input:
 * users password, password size, number of rails
 *
 * Output:
 * vector
 *******************************************************************************/
vector<vector<char>> createRailFence(const char PLAINTEXT[], const int SIZE, int n)
{
  vector<vector<char>> fence(n, vector<char> (SIZE, ' '));

  int row = 0;
  bool down = false;

  for (int i = 0; i < SIZE; i++)
  {
    if (row == 0 || row == n - 1)
    {
      down = !down;
    }
    fence.at(row).at(i) = PLAINTEXT[i];
    if (down)
    {
      row++;
    }
    else
    {
      row--;
    }
  }

  for (vector<char> row : fence)
  {
    for (char c : row)
    {
      cout << c << ' ';
    }
    cout << endl;
  }

  return fence;
}


void encrypt(const vector<vector<char>>& RAIL_FENCE, char ciphertext[]) {
    int index = 0;
    for (unsigned i = 0; i < RAIL_FENCE.size(); i++) {
        for (unsigned j = 0; j < RAIL_FENCE.at(i).size(); j++) {
            char x = RAIL_FENCE.at(i).at(j);
            if (x != ' ') {
                ciphertext[index++] = x;
            }
        }
        ciphertext[index++] = ' ';
    }
    ciphertext[index] = '\0';
}

void decrypt(const char CIPHERTEXT[], char plaintext[], const unsigned SIZE)
{
  char WOSpace[SIZE];
  strcpy(WOSpace, CIPHERTEXT);

  int numSpaces = 0, cpyIndex = 0;
  for (int i = 0; i < SIZE; i++) {
    if (isspace(CIPHERTEXT[i])) {
      numSpaces++;
    }
    else {
      WOSpace[cpyIndex] = CIPHERTEXT[i];
      cpyIndex++;
    }
  }
  WOSpace[SIZE - numSpaces] = '\0';
  cout << WOSpace << endl;

  int rails = 1 + numSpaces;
  int index = 0;
  int decrease = (2*rails) - 3;

  vector<vector<char>> fence(rails, vector<char> (strlen(WOSpace)));

  for (unsigned row = 1; row < rails; row++)
  {
    if (row != 1)
    {
      for (unsigned i = 1; i < row; i++)
      {
        fence.at(row-1).at(i-1) = ' ';
      }
    }
    for (unsigned col = 1; col < strlen(WOSpace); col++)
    {
      fence.at(row-1).at(col-1) = WOSpace[index];
      index++;
      for(unsigned midSpace = 1; midSpace < (2*rails) - 3; midSpace++)
      {
        if (row > rails || col > strlen(WOSpace))
        {
          break;
        }
        else
        {
          fence.at(row - 1).at(col- 1) = ' ';
          col++;
        }
        decrease-=2;
      }
    }
    cout << endl;
  }
  for (vector<char> row : fence)
  {
    for (char c : row)
    {
      cout << c << ' ';
    }
    cout << endl;
  }
}


  // vector<vector<char>> fence(n, vector<char> (SIZE, ' '));

 //}

