#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void selection_sort(string [], int);
void second_sort(string [], int);
void swap(int&, int&);

int main(){
    const int arrsize = 30;
    int cnt=0;
    string pokemons[arrsize]; //array for pokemon
    //handle user input
    for (int i=0; i<arrsize; ++i){
        string tmp;
        cin>>tmp;
        if(tmp != "???"){
            cnt++;
            pokemons[i] = tmp;
        }
        else{
            break;
        }
    }
    selection_sort(pokemons, cnt);
    second_sort(pokemons, cnt);
    for (int i=0; i<cnt; ++i){
        cout<< pokemons[i]<< endl;
    }
}


void selection_sort(string pokemons[], int size){
    int i, j, idx;
    int max;
    for (int i=0; i<size; ++i){
        max = pokemons[i].length(); 
        idx = i;

        for (int j=i+1; j<size; ++j){
            if(pokemons[j].length()>max){
                max = pokemons[j].length();
                idx = j;
            }

            
        }
    
    if( idx != i ){
        string tmp = pokemons[i];
        pokemons[i] = pokemons[idx];
        pokemons[idx] = tmp;
    }
    }
}

void second_sort(string pokemons[], int size){
    int i,j,idx;
    for (int i=0; i<size; ++i){
        idx = i;
        for (int j=i+1; j<size; ++j){

            if(pokemons[i].length()==pokemons[j].length()){
                for(int k=0; k<pokemons[j].length();++k){
                  

                    char ik_value = pokemons[i][k];
                    char jk_value = pokemons[j][k];

                    if(ik_value>='A' && ik_value<='Z'){
                        ik_value+=32;
                    }
                    if(jk_value>='A' && jk_value<='Z'){
                        jk_value+=32;
                    }
                    if(jk_value<ik_value){
                        
                        idx = j;
                        swap(pokemons[i], pokemons[idx]);
                        break;
                    }
                    if(jk_value==ik_value){
                        continue;
                    }
                    else if(jk_value>ik_value){
                        
                        break;
                    }

                }
            }
        }
    }
}

void swap(string &a, string &b){
    string tmp = a;
    a = b;
    b = tmp;
}