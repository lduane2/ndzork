#include <ncurses.h>
#include <unistd.h>

//#include <sstream>
//using namespace std;


int main(int argc,  char* argv[])
{
    initscr();

    printw(">> hello, world\n>>");
    refresh();

    while(1)
    {

    
        char i[80];
        getstr(i);
        if (i[0] == 'q')
        {

            endwin();
        }
        else
        {
            printw(">>you printed  %s\n>>", i);
            refresh();
        }
    }
    sleep(1);

    endwin();


}


