#include <iostream>
#include <cmath>

using namespace std;

bool isProduct(int x){
    for (int i=100; i<1000; ++i){
        int n = x/i;
        int size = log10(n);
        if (x%i==0 && size==2){
            return true;
        }
    }
    return false;
}


bool isPalindrome(int x){   
    int and_gate = 1; //and logic gate, all 1 >> true ; else false
    int size = log10(x); //get power of 10 and floor it to int
    for (int i=0; i<size/2+1; ++i){      
        int left_num = x/(pow(10,(size-i))); //get lefthalf of num
        int conv = (int) pow(10,(i+1)); //convert double into int
        int right_num = x%(conv); 
        int left_comp = left_num%10;
        int right_comp = (int) right_num/(pow(10,i));
        if (left_comp == right_comp){
            and_gate*=1;
        }
        else{
            and_gate*=0;
        }
    }
    if (and_gate == 0){
            return false;
        }
    return true; 
}

int main(){
    int m, n;
    char opt;
    cin >> m >> n >> opt;
    for (int i=m; i<=n; ++i){
        bool pr_test = isProduct(i);
        bool pa_test = isPalindrome(i); 
        bool prpa_test = pr_test&&pa_test;
        if(opt == 't'){
            if(pr_test == true){
                cout<<i<<endl;
            }
        }
        else if(opt == 'p'){
            if(pa_test == true){
                cout<<i<<endl;
            }
        }
        else if(opt == 'b'){
            if(prpa_test == true){
                cout<<i<<endl;
            }
        }
    }
    return 0;
}




