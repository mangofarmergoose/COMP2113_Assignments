#include <stdio.h>
#include <string.h>

void reverse_string(char cs[31], int len){
    for (int i=0; i<len/2; ++i){
        int pos = len-1-i; //get new position
        char tmp;
        //swap
        tmp = cs[i];
        cs[i] = cs[pos]; 
        cs[pos] = tmp;
    }
}
int get_s1(char cs[31], int len){
    int s1 = 0;
    int tmp = 0;
    for (int i=0; i<len; ++i){
        if(i%2 == 0){
            tmp = (int)cs[i] - 48;
            s1+=tmp;
        }
    }
    return s1;
}

int digit_sum(int ele){
    int a1 = ele/10;
    int a2 = ele%10;
    return a1+a2;
}

int get_s2(char cs[31], int s2op[31], int len){
    int s2 = 0;
    //store multiples into array
    for (int i=0; i<len; ++i){
        if(i%2 == 1){
            s2op[i] = 2*((int)cs[i] - 48); 
        }

        /* printf("%d", s2op[i]); */
    }
    for (int i=0; i<len; ++i){
        /* printf("%d\n", s2op[i]); */
        if(s2op[i] != 0){
            s2+=digit_sum(s2op[i]);
            /* printf("%d\n", s2); */
        }
    }
    return s2;
}

int valid(int s1, int s2){
    int sum = s1 + s2;
    if(sum%10 == 0){
        return 1;
    }
    return 0;
}

int main()
{
    char cs[31];
    int s1;
    int s2op[31] = {0};
    int s2;
    scanf("%s", cs);
    int len = strlen(cs);

    reverse_string(cs, len);
    printf("%s\n",cs);

    s1 = get_s1(cs, len);
    printf("%d", s1);
    printf("%s", " ");
    
    s2 = get_s2(cs, s2op, len);
    printf("%d\n", s2);

    if(valid(s1,s2) == 1){
        printf("%s\n", "valid");
    }
    else if(valid(s1,s2) == 0){
        printf("%s\n", "invalid");
    }
}
