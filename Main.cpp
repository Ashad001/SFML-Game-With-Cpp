#include <conio.h>
#include "Game.h"
#include <ctype.h>
int main()
{
	Game Amazer;
	Amazer.Run();
}

/*
#include <iostream>
#include <fstream>
using namespace std;

// int main(int argc, char const *argv[])
// {
//     typedef int i;
//     i var = 5;
//     cout << var;

//     return 0;
// }

// int main()
// {
//     char *word = "HELLO";
//     cout << word << endl << &word << endl;
//     cout << static_cast<void*>(word);
// }

int main(int argc, char const* argv[])
{
    string path = "D:\\test.txt"; // If created then open if not created and then open
    ofstream o(path); // writing purpose
    o.put('T');
    o.close();

    //ifstream i(path);   // Reading purpose
    //char c = i.get();
    //cout << c << endl;
    //i.close();

    ofstream o2(path); // writing purpose

    o2.write("This is" , 7);
    o2.close();

    //ifstream i(path);
    //char* outputTxt = new char[10];
    //i.read(outputTxt, 7); // 7 characters of file are in outputTxt
    //cout << outputTxt << endl;

    char c;
    ifstream i(path);
    char t;
    while (!i.eof())
    {
        i.get(t);
        if (!(t == 'x'))
            i.get(c);
        if(!i.eof())
           cout << t << c << endl;
    }
   
    i.close();

    return 0;
}
*/