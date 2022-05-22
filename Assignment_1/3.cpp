#include <iostream>

using namespace std;

const int MAXLEN = 50; // max length for input sequence of characters
const int MAXKEY = 10; // max length for key
const char UC[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const char LC[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char SC[32] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '[', '{', ']', '}', '\\', '|', ';', ':', '"', '\'', ',', '<', '.', '>', '/', '?'};
const char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
// to get the value of x of each char in text
void get_xs(char text[], int xs[], int text_length, int check_UC[], int check_num[])
{
  for (int i = 0; i < text_length; ++i)
  {
    // step1: calc x

    int x;

    if (check_num[i] == 1)
    {
      for (int j=0; j<10; ++j){
        if(text[i] == nums[j]){
          x = j;
        }
      }
    }
    else
    {
      for (int j = 0; j < 26; ++j)
      {
        if (text[i] == UC[j] && check_num[i] == 0)
        {
          x = j;
          check_UC[i] = 1;
        }
        if (text[i] == LC[j] && check_num[i] == 0)
        {
          if (text[i] == LC[j])
          {
            x = j;
          }
        }
      }

      for (int j = 0; j < 32; ++j)
      {
        if (text[i] == SC[j])
        {
          x = j + 100;
        }
      }
    }

    xs[i] = x;
  }
}

void get_ks(char key[], int ks[])
{

  for (int i = 0; i < MAXKEY; ++i)
  {
    int k;
    for (int j = 0; j < 26; ++j)
    {
      if (key[i] == UC[j])
      {
        k = j;
      }
    }
    ks[i] = k;
  }
}

void check_nums(char text[], int check_num[],int text_length){
  for (int i = 0; i < text_length; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      if (text[i] == nums[j])
      {
        check_num[i] = 1;
      }
    }
  }
}

int main()
{
  // to store user inputs
  char s;               // 'e' for encryption, 'd' for decryption
  char text[MAXLEN];    // the sequence of characters to encrypt/decrypt
  char key[MAXKEY];     // the key
  int xs[MAXLEN] = {0}; // store x's value
  int ks[MAXKEY] = {0}; // store k's value
  int key_length;
  int text_length = 0;         // stores how many input are actually there in text
  int check_num[MAXLEN] = {0}; // check whether input is number
  cin >> s;

  // storing first line inputs into text array
  for (int i = 0; i < MAXLEN; ++i)
  {
    char temp;
    cin >> temp;
    if (temp != '!')
    {
      text[i] = temp;
      text_length++;
    }
    else if (temp == '!')
    {
      break;
    }
  }
  cin >> key_length;

  // storing second line input into key array
  for (int i = 0; i < key_length; ++i)
  {
    cin >> key[i];
  }
  int UC_check[MAXLEN] = {0};

  // check nums
  check_nums(text, check_num, text_length);
  // get xs value
  get_xs(text, xs, text_length, UC_check, check_num);
  // get ks value
  get_ks(key, ks);


  int new_ks[MAXLEN];

  for (int i = 0; i < key_length; ++i)
  {
    new_ks[i] = ks[i];
  }

  // make array of k repeat until it reaches same length as new_xs
  int updated_ks[MAXLEN] = {0};
  for (int i = 0; i < key_length; ++i)
  {
    for (int j = i; j < text_length; j = j + key_length)
    {
      updated_ks[j] = new_ks[i];
    }
  }

  int ys[MAXLEN];

  if (s == 'e')
  {
    for (int i = 0; i < text_length; ++i)
    {
      if (xs[i] < 100 && check_num[i] == 0)
      {
        if (xs[i] + (updated_ks[i] % 26) >= 26)
        {
          ys[i] = xs[i] + (updated_ks[i] % 26) - 26;
        }
        else
        {
          ys[i] = xs[i] + (updated_ks[i] % 26);
        }
      }
      else
      {
        ys[i] = xs[i];
      }
    }
  }
  else if (s == 'd')
  {
    for (int i = 0; i < text_length; ++i)
    {
      if (xs[i] < 100 && check_num[i] == 0)
      {
        if (xs[i] - (updated_ks[i] % 26) >= 0)
        {
          ys[i] = xs[i] - (updated_ks[i] % 26);
        }
        else
        {
          ys[i] = 26 + (xs[i] - (updated_ks[i] % 26));
        }
      }
      else
      {
        ys[i] = xs[i];
      }
    }
  }
  // output array
  char output[MAXLEN];
  for (int i = 0; i < text_length; ++i)
  {
    for (int j = 0; j < 26; ++j)
    {
      if (ys[i] == j && UC_check[i] == 1 && check_num[i]==0)
      {
        output[i] = LC[j];
      }
      else if (ys[i] == j && UC_check[i] == 0 && check_num[i]==0)
      {
        output[i] = UC[j];
      }
      else if(check_num[i]==1){
        output[i] = text[i];
      }
    }
    for (int j = 0; j < 32; ++j)
    {
      if (ys[i] == j + 100 && check_num[i]==0)
      {
        output[i] = SC[j];
      }
    }
  }
  
  // final output
  for (int i = 0; i < text_length; ++i)
  {
    cout << output[i];
  }
  cout << "!";
  cout<<endl;
  return 0;
}
