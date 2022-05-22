#include <iostream>
#include <cstdlib>      // for calling srand(), rand()
#include <ctime>        // for calling time()


#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define NUMCARDS  5

using namespace std;
int cards[52] = {0};


void DealHand(int cards[]){
  int seed;
  cin >> seed;
  srand(seed);
  for (int i=0; i<5; ++i){
    cards[i] = rand()%52;
  }
}
void PrintHand(int cards[]){
  char actual_hands[13] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};
  for(int i=0; i<NUMCARDS; ++i){
    int tmp_floor;
    int tmp_mod;
    tmp_floor = cards[i]/13;
    tmp_mod = cards[i]%13;
    char actual_mod;
    for(int j=0; j<13; ++j){
      actual_mod = actual_hands[tmp_mod];
    }
    if(tmp_mod == 9){ //account that '10' cannot be treated as char, split 1 and 0
      if(tmp_floor == 0){
      cout<<1<<actual_mod<<SPADE<<" ";
    }
    if(tmp_floor == 1){
      cout<<1<<actual_mod<<HEART<<" ";
    }
    if(tmp_floor == 2){
      cout<<1<<actual_mod<<CLUB<<" ";
    }
    if(tmp_floor == 3){
      cout<<1<<actual_mod<<DIAMOND<<" ";
    }
    }
    else{
    if(tmp_floor == 0){
      cout<<actual_mod<<SPADE<<" ";
    }
    if(tmp_floor == 1){
      cout<<actual_mod<<HEART<<" ";
    }
    if(tmp_floor == 2){
      cout<<actual_mod<<CLUB<<" ";
    }
    if(tmp_floor == 3){
      cout<<actual_mod<<DIAMOND<<" ";
    }
  }
  }
  cout<<endl;
}
bool IsFourOfAKind(int cards[]){
  int check_mod[5] = {0};
  int cnt = 0;
  for (int i=0; i<NUMCARDS; ++i){
    check_mod[i] = cards[i]%13; 
  }
  for (int i=0; i<NUMCARDS; ++i){
    for (int j=i; j<NUMCARDS; ++j){
      if(check_mod[i] == check_mod[j]){
        cnt++;
      }
    }
  }
  if(cnt==11){ //unique cnt=11
    return true;
  }
  return false;
}   // return if the hand is a four of a kind
bool IsFullHouse(int cards[]){
  int check_mod[5] = {0};
  int cnt = 0;
  for (int i = 0; i< NUMCARDS; ++i){
    check_mod[i] = cards[i]%13;
  }
  for (int i=0; i<NUMCARDS; ++i){
    for (int j=i; j<NUMCARDS; ++j){
      if(check_mod[i] == check_mod[j]){
        cnt++;
      }
    }
  }
  if(cnt==9){
    return true;
  }
  return false;
}     // return if the hand is a full house
bool IsFlush(int cards[]){
  int check_floor[5] = {0};
  int cnt = 0;
  for (int i=0; i<NUMCARDS; ++i){
    int floor;
    floor = cards[i]/13;
    check_floor[i]=floor;
  }
  for (int i=0; i<NUMCARDS; ++i){
    for (int j=i; j<NUMCARDS; ++j){
      if(check_floor[i] == check_floor[j]){
        cnt++;
      }
    }
  }
  if(cnt == 15){
    return true;
  }
  return false;
}         // return if the hand is a flush
bool IsThreeOfAKind(int cards[]){
  int check_mod[5] = {0};
  int cnt = 0;
  for (int i = 0; i< NUMCARDS; ++i){
    check_mod[i] = cards[i]%13;
  }
  for (int i=0; i<NUMCARDS; ++i){
    for (int j=i; j<NUMCARDS; ++j){
      if(check_mod[i] == check_mod[j]){
        cnt++;
      }
    }
  }
  if(cnt==8){
    return true;
  }
  return false;
}  // return if the hand is a three of a kind
bool IsTwoPair(int cards[]){
  int check_mod[5] = {0};
  int cnt = 0;
  for (int i = 0; i< NUMCARDS; ++i){
    check_mod[i] = cards[i]%13;
  }
  for (int i=0; i<NUMCARDS; ++i){
    for (int j=i; j<NUMCARDS; ++j){
      if(check_mod[i] == check_mod[j]){
        cnt++;
      }
    }
  }
  if(cnt==7){
    return true;
  }
  return false;
}       // return if the hand is a two pair
bool IsOnePair(int cards[]){
  int check_mod[5] = {0};
  int cnt = 0;
  for (int i = 0; i< NUMCARDS; ++i){
    check_mod[i] = cards[i]%13;
  }
  for (int i=0; i<NUMCARDS; ++i){
    for (int j=i; j<NUMCARDS; ++j){
      if(check_mod[i] == check_mod[j]){
        cnt++;
      }
    }
  }
  if(cnt==6){
    return true;
  }
  return false;
}      // return if the hand is a one pair

bool IsOther(int cards[]){
  int check_mod[5] = {0};
  int cnt = 0;
  for (int i = 0; i< NUMCARDS; ++i){
    check_mod[i] = cards[i]%13;
  }
  for (int i=0; i<NUMCARDS; ++i){
    for (int j=i; j<NUMCARDS; ++j){
      if(check_mod[i] == check_mod[j]){
        cnt++;
      }
    }
  }
  if(cnt==5){
    return true;
  }
  return false;
}

void init_cards(){
  for (int i=0; i<52; ++i){
    cards[i] = i;
  }
}

int main()
{
  int hand[NUMCARDS];   // declare an array of 5 integers to store a hand
  DealHand(hand); //Deal hand
  init_cards();//initalize cards array
  PrintHand(hand);


  if(IsFourOfAKind(hand) == true){
    cout<<"four of a kind";
  }
  else if(IsFullHouse(hand) == true){
    cout<<"full house";
  }
  else if(IsFlush(hand) == true){
    cout<<"flush";
  }
  else if(IsThreeOfAKind(hand) == true){
    cout<<"three of a kind";
  }
  else if(IsTwoPair(hand) == true){
    cout<<"two pair";
  }
  else if(IsOnePair(hand) == true){
    cout<<"one pair";
  }
  else if(IsOther(hand) == true){
    cout<<"others";
  }
  cout<<endl;
  return 0;
}
