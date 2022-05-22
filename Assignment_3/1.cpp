#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;



struct Node
{
    int value;
    Node *next;
};

void tail_insert(Node *&head,  Node *&tail, int num);

// output the linked list
void print_list(Node *head)
{
    if (head != NULL)
    {
        print_list(head->next);
        cout << head->value << " -> ";
    }
}



void print_output_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        // process the current node, e.g., print the content
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void print_final_output(Node *head)
{
    if (head != NULL)
    {
        if(head -> next == NULL){
            print_final_output(head->next);
        }
        else if(head -> next != NULL && head->value>=0 && head->value<=9){
            
            print_final_output(head->next);
            cout<<"00";
        }
        else if(head -> next != NULL && head->value>=10 && head->value<=99){
           
            print_final_output(head->next);
            cout<<"0";
        }
        //three digits
        else{
            print_final_output(head->next);
        }
        cout << head->value;
    }
}

// output the large number stored in the linked list
void print_num(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current == head)
            cout << current->value;
        else
            cout << setw(5) << setfill('0') << current->value;
        current = current->next;
    }
}

// insert a value as a node to the head of a linked list
void head_insert(Node *&head, int v)
{
    Node *p = new Node;
    p->value = v;
    p->next = head;
    head = p;
}


// delete the head node from a linked list
void delete_head(Node *&head)
{
    if (head != NULL)
    {
        Node *p = head;
        head = head->next;
        delete p;
    }
}

// free an entire linked list
void delete_list(Node *&head)
{
    while (head != NULL)
    {
        delete_head(head);
    }
}

// double the capacity of an array
// array: input array
// size: original size of array, updated to new size of array
void grow_array(char *&array, int &size)
{
    if (array == NULL)
        return;

    int newSize = size * 2;

    // doubled the size of the array;
    char *tmp = new char[newSize];
    // copy original contents
    for (int i = 0; i < size; ++i)
        tmp[i] = array[i];

    delete[] array;

    array = tmp;
    size = newSize;
}

// get a number from a user
// by reading character by character until a space is hit
// use dynamic array to store the digits
// digits:  character array that stores the digits of the number
// numDigits: number of digits read from input
void input_num(char *&digits, int &numDigits)
{
    int arraysize = 32;
    digits = new char[arraysize];
    char c;
    int numRead = 0;

    // read each digit as a character until a white space is hit
    c = cin.get();
    while (!isspace(c))
    {
        if (numRead >= arraysize)
            grow_array(digits, arraysize);

        digits[numRead] = c;
        numRead++;

        c = cin.get();
    }

    numDigits = numRead;
}

// get a large integer from user input
// and store in a linked list of Node
// each node stores the value of a chunk of 5 digits taken from the large integer
// e.g., if the input is 43323000089500012, the linked list is
// 43 -> 32300 -> 895 -> 12 -> NULL
//
Node *create_num_list()
{
    // TASK 1a: declare a pointer pointing to the head of the link list

    Node *head = NULL; // build linked list forward
    Node *tail = NULL;

    string str;
    char *digits = NULL; // a dynamic array for storing an input number
    int numDigits;
    int val;

    // get a number from the user
    input_num(digits, numDigits);

    // scan the digits in reverse, and create a list of nodes for
    // the value of every 5 digits
    str.clear();
    for (int i = numDigits - 1; i >= 0; --i)
    {
        str = digits[i] + str;
        if (str.length() == 3)
        {
            val = atoi(str.c_str());

            // TASK 1b: insert a value as a node to the head of the linked list
            head_insert(head, val);

            str.clear();
        }
    }
    // the digits array is scanned and there are still digits
    // stored in str that are not inserted into the list yet
    if (!str.empty())
    {
        val = atoi(str.c_str());

        // TASK 1c: insert a value as a node to the head of the linked list
        head_insert(head, val);
    }

    // free the dynamic array
    if (digits != NULL)
    {
        delete[] digits;
    }

    // TASK 1d: return the pointer to the linked list
    return head;
}

// return the length of a linked list
int list_length(Node *head)
{
    // TASK 3: Modify this print function to one that
    // count the number of nodes in a linked list
    int num = 0;
    Node *current = head;
    while (current != NULL)
    {
        // process the current node, e.g., print the content
        ++num;
        current = current->next;
    }

    return num;
}

int get_max(int len1, int len2)
{
    if (len1 < len2)
    {
        return len2;
    }
    else
    {
        return len1;
    }
}

int get_min(int len1, int len2)
{
    if (len1 > len2)
    {
        return len2;
    }
    else
    {
        return len1;
    }
}

void addition(Node *n1, Node *n2, Node *&head, Node *&tail)
{
    int len1 = list_length(n1);
    int len2 = list_length(n2);
    int cnt = 0;
    int min = 0;
    int max = 0;

    max = get_max(len1, len2);
    min = get_min(len1, len2);


    int *len1_idx = new int[max + 1]();
    int *len2_idx = new int[max + 1]();
    int *len3_idx = new int[max + 1]();
    // size = 4
    Node *curr1 = n1, *curr2 = n2;
    
    // create array with same index
    if (len1 > len2)
    {

        for (int i = 1; i < max + 1; ++i)
        {

            len1_idx[i] = curr1->value;
            curr1 = curr1->next;
        }
        //problem here
        for (int i = max+1-len2; i < max + 1; ++i)
        {
            
            len2_idx[i] = curr2->value;
            curr2 = curr2->next;
            
        }
        
    }

    

    else if (len1 < len2)
    {
        for (int i = 1; i < max + 1; ++i)
        {
            len2_idx[i] = curr2->value;
            curr2 = curr2->next;
        }

        for (int i = max+1-len1; i < max + 1; ++i)
        {
            
            len1_idx[i] = curr1->value;
            curr1 = curr1->next;
            
        }
    }
    else if (len1 == len2)
    {
        for (int i = 1; i < max + 1; ++i)
        {
            len1_idx[i] = curr1->value;
            len2_idx[i] = curr2->value;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    

    // write value into len3_idx
    for (int i = 0; i < max + 1; ++i)
    {
        len3_idx[i] = len1_idx[i] + len2_idx[i];
    }
    int three_digit_val = 0;
    

    for (int i = max; i >= 1; --i)
    {
        three_digit_val = len3_idx[i];
        if (three_digit_val > 999)
        {
            len3_idx[i - 1] += 1;
            three_digit_val = three_digit_val % 1000;
        }

        
        tail_insert(head,tail, three_digit_val);
        
    
    }
    // insert most significant bit
    if(len3_idx[0] != 0){
        tail_insert(head, tail, len3_idx[0]);
    }

    delete[] len1_idx;
    delete[] len2_idx;
    delete[] len3_idx;
}

void tail_insert(Node *&head, Node *&tail, int num)
{
    Node *p = new Node;
    p->value = num;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}



int main()
{
    Node *n1, *n2;
    // new node n3 
    Node *head = NULL;
    Node *tail = NULL;

    n1 = create_num_list();
    cin.get(); // skip the '>' sign
    cin.get(); // the space after the '>' sign
    n2 = create_num_list();

    int len1 = list_length(n1);
    int len2 = list_length(n2);
    

    addition(n1, n2, head, tail);


    // TASK 2: call print_list() on n1 and n2 for checking
    print_list(n1);
    cout << "NULL" << endl;
    print_list(n2);
    cout << "NULL" << endl;

    print_output_list(head);
    /* print_final_output(head); */
    print_final_output(head);
    cout << endl;
    /* cout << (*n1).value << endl; */
    // TASK 5: free the linked lists
    delete_list(n1);
    delete_list(n2);
    delete_list(head);

    return 0;
}

