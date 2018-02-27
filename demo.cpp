#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
//#include <sstream>
using namespace std;


vector<string> get();
int test(vector<string> input);



int quit( vector<string> input);
int help( vector<string> input);
int take( vector<string> input);
int inventory( vector<string> input);
int look( vector<string> input);
int attack( vector<string> input);


typedef int (*action_method) (vector<string>);
typedef unordered_map<string,action_method> action_map;
typedef unordered_map<string, action_method>::const_iterator it;

int main(int argc,  char* argv[])
{



    action_map mapping;
    //unordered_map<string,> map;

    mapping["test"] = &test;
    mapping["quit"] = &quit;
    mapping["help"] = &help;
//    map.insert({"test",test});


    initscr();

    printw(">> hello, world\n>>");
    refresh();




    while(1)
    {

    vector<string> args;
    args = get();
        
    string out = args[0];
       




//  string out = tokens[0];
//     char output[out.length()];
//     output = out.c_str();
    printw(">>%s\n" , out.c_str());

    it function_iterator =  mapping.find(out);
    if (function_iterator == mapping.end())
    {   
        printw("I don't understand the word %s!\n>>", out.c_str());
        continue;
    }
    else
    {
    auto function = mapping[out];
    function(args);
    }

    printw(">>");
    refresh();


//    sleep(1);
//    endwin();
    }
  

  sleep(1);

    endwin();


}




int test( vector<string> input )
{
    printw("you did it\n");

    return 0;
};

int quit( vector<string> input)
{
    endwin();
    exit(0);
    return 0;
};



int help( vector<string> input)
{

    printw("Welcome to ND Zork!  inspired by the game zork, ND zork recreates the essence of zork in a C++ environment for the modern computer.  lets test pout a longer sentense\n");
    return 0;

}

int attack( vector<string> input)
{
    return 0;
}


int take( vector<string> input)
{

    // put item into players inventory
    return 0;

}

int look( vector<string> input)
{

    //player.location.look_string
    return 0;
}

int inventory( vector<string> input)
{
    return 0;

};

vector<string> get()
{

       char i[80];
        getstr(i);

        string input = i;
        istringstream iss(input);
//        input.split(" ")
        vector<string> tokens;
copy(istream_iterator<string>(iss),
     istream_iterator<string>(),
     back_inserter(tokens));        
//     string out = tokens[0];

    return tokens;
//
};

class item
{


string text;
string appearence;

};



