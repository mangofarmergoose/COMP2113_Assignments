#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;
/* g++ -pedantic-errors -std=c++11 2.cpp -o 2
 ./2 < input2_1.txt */
struct Page
{
    int id;
    string path;
    int counter;
    Page(int id, string path)
    {
        this->id = id;
        this->path = path;
        counter = 0;
    };
};

// This function can facilitate sorting
bool operator<(const Page &a, const Page &b)
{
    //iterator points to index of first occurence of new vector element, count accumulates
    //when sorted by id
    return (a.id < b.id);

}

vector<Page> pages;

struct User
{
    int id;
    vector<string> visits;
    User(int id)
    {
        this->id = id;
    };
    void add_visit(int page_id)
    {
        Page p(page_id, "");
        vector<Page>::iterator iter = lower_bound(pages.begin(), pages.end(), p);
        if (iter->id == page_id)
            visits.push_back(iter->path);
    };
    int size() const
    {
        return visits.size();
    };
    void print_visits()
    {
        sort(visits.begin(), visits.end());
        vector<string>::iterator iter;
        for (iter = visits.begin(); iter != visits.end(); iter++)
        {
            cout << "- " << *iter << endl;
        }
    }
};

vector<User> users;

// Please implement the following function to facilitate the sorting of users
bool operator<(const User &a, const User &b)
{
    if(a.visits.size() > b.visits.size()){
        return true;
    }
    else if(a.visits.size() < b.visits.size()){
        return false;
    }
    else {
        return a.id < b.id;
    }
}



// Please implement the following function
void add_page(const Page &p)
{
    pages.push_back(p);
    sort(pages.begin(), pages.end());
}



// Please implement the following function
bool cmp_page_count(const Page &a, const Page &b)
{   
    if(a.counter > b.counter){
        return true;
    }
    if(a.counter < b.counter){
        return false;
    }
    if (a.counter == b.counter)
    {
        return a.path < b.path;
    }
   
}


// Please implement the following function
void print_pages(int number)
{
    vector<Page>::iterator itr;
    for (itr = pages.begin(); itr != pages.begin() + number; ++itr)
    {
        cout << (*itr).counter << ":" << (*itr).path << endl;
    }
}

// Please implement the following function
void add_user(User u)
{
    users.push_back(u);
    
}

// Please implement the following function
void add_visit(int page_id)
{
    User* curr_user = &users[users.size()-1];
    curr_user->add_visit(page_id);

}

// Please implement the following function
void print_users(int number)
{
    vector<User>::iterator itr;
    for (itr = users.begin(); itr != users.begin() + number; ++itr)
    {
        cout << (*itr).visits.size() << ":" << (*itr).id << endl;
        (*itr).print_visits();
    }
}


int main()
{

    string type;
    while (cin >> type)
    {
        if (type == "USER")
        {
            int user_id;
            cin >> user_id;
            User u(user_id);
            add_user(u);
        }
        else if (type == "PAGE")
        {
            int page_id;
            string page_path;
            cin >> page_id;
            cin >> page_path;
            Page p(page_id, page_path);
            add_page(p);
        }
        else if (type == "VISIT")
        {
            int page_id;
            cin >> page_id;
            Page p(page_id, "");
            vector<Page>::iterator iter = lower_bound(pages.begin(), pages.end(), p);
            if (iter->id == p.id)
            {
                iter->counter++;
            }
            add_visit(p.id);
        }
    }
    
    sort(pages.begin(), pages.end(), cmp_page_count);
    
    cout << "*** 5 most popular pages ***" << endl;
    print_pages(5);
    sort(pages.begin(), pages.end());

    

    sort(users.begin(), users.end());
    cout << "*** 5 most active users ***" << endl;
    print_users(5);

    return 0;
}
