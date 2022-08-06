#include <conio.h>
#include "MainMenu.h"
int main()
{
	MainMenu Amazer(800, 640);
	Amazer.Update();

}



//#include <iostream>
//#include <fstream>
//using namespace std;
//
//class A
//{
//private:
//    int x;
//public:
//    A()
//    {
//
//    }
//    A(int x)
//    {
//        this->x = x;
//    }
//    void Display()
//    {
//        cout << "thdsd " << x << endl;
//    }
//
//
//};
//
//
//int main(int argc, char const* argv[])
//{
//    string path = "D:\\test.bin";
//    A ob1(3);
//    A ob2(5);
//    A ob3;
//
//    ofstream o(path);
//    o.write((char*)&ob1, sizeof(ob1));
//    o.write((char*)&ob2, sizeof(ob2));
//    o.close();
//    ifstream i(path);
//    /*for (int J = 0; J < 2; J++)
//    {
//        i.read((char*)&ob3, sizeof(ob3));
//        ob3.Display();
//        cout << endl;
//    }
//        i.close();*/
//    
//    i.seekg(sizeof(ob1), ios::beg);
//    i.read((char*)&ob3, sizeof(ob3));
//    i.close();
//
//    ob3.Display();
//
//    return 0;
//}


//#include <iostream>
//#include <fstream>
//#include <string>
//#include <string.h>
//using namespace std;
//
//int main()
//{
//	string path = "C:\\Users\\Ashad Qureshi\\OneDrive - FAST National University\\Documents\\UNI\\Custom codes\\Sec\\Class Codes\\week7.cp.txt";
//	char* input = (char*)"This is input string";
//
//	ofstream o(path);
//	o.seekp(4, ios::beg);  // jump number, origin to start
//	o.write(input, strlen(input));
//
//	o.close();
//
//	ifstream i(path);
//	char* output = new char[10];
//	//i.seekg(4, ios::beg);
////	i.seekg(4, ios::end); // Starting from end .. but will give garbage as it has not any value...
//	//i.seekg(-4, ios::end); // starting from end but jump in reverse four places
////	char c = i.get();  // now pointer has been incremented to 'h'
//////	i.seekg(4, ios::beg);  // start from start
////	i.seekg(5, ios::cur); // start from current pointer 'h'
//
//
// 	i.read(output, 5);
//	for (int i = 0; i < 5; i++)
//	{
//		cout << output[i] << " ";
//	}
//	i.close();
//}



//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main(int argc, char const* argv[])
//{
//    string path = "C:\\Users\\Ashad Qureshi\\OneDrive - FAST National University\\Documents\\UNI\\Custom codes\\Sec\\Class Codes\\week7.cp.txt";
//
//    const char* input = "This is input";
//
//    ofstream o(path);
//    o.write(input, strlen(input));
//    o.close();
//    
//
//    char* output = new char[50];
//    // Read 10 characters 
//    ifstream i(path);
//    i.seekg(4, ios::beg);    // cursor pointer will be in beginnning at reads 4 characters from their...
//    i.read(output, 10);            // Means that now 4 characters excludedly the read function will read---> is input (random ascii value)
//    for (int i = 0; i < 10; i++)
//        cout << output[i] << " ";
//    cout << endl;
//
//     // cursor pointer will be in beginnning at reads 4 characters from their...
//    i.seekg(-1, ios::cur);
//    i.read(output, 10);
//    for (int i = 0; i < 10; i++)
//        cout << output[i] << " ";
//    cout << endl;
//    i.close();
//
//    return 0;
//}
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main(int argc, char const* argv[])
//{
//    string path = "C:\\Users\\Ashad Qureshi\\OneDrive - FAST National University\\Documents\\UNI\\Custom codes\\Sec\\Class Codes\\week7.cp.txt";
//
//    const char* input = "This is input";
//
//    ofstream o(path);
//    o.seekp(5, ios::beg);
//    o.write(input, strlen(input));
//    o.close();
//
//
//    char* output = new char[50];
//    // Read 10 characters 
//    ifstream i(path);
//    i.read(output, 20);            // Means that now 4 characters excludedly the read function will read---> is input (random ascii value)
//    for (int i = 0; i < 20; i++)
//        cout << output[i] << " ";
//    cout << endl;
//
//    return 0;
//}



///*
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//// int main(int argc, char const *argv[])
//// {
////     typedef int i;
////     i var = 5;
////     cout << var;
//
////     return 0;
//// }
//
//// int main()
//// {
////     char *word = "HELLO";
////     cout << word << endl << &word << endl;
////     cout << static_cast<void*>(word);
//// }
//
//int main(int argc, char const* argv[])
//{
//    string path = "D:\\test.txt"; // If created then open if not created and then open
//    ofstream o(path); // writing purpose
//    o.put('T');
//    o.close();
//
//    //ifstream i(path);   // Reading purpose
//    //char c = i.get();
//    //cout << c << endl;
//    //i.close();
//
//    ofstream o2(path); // writing purpose
//
//    o2.write("This is" , 7);
//    o2.close();
//
//    //ifstream i(path);
//    //char* outputTxt = new char[10];
//    //i.read(outputTxt, 7); // 7 characters of file are in outputTxt
//    //cout << outputTxt << endl;
//
//    char c;
//    ifstream i(path);
//    char t;
//    while (!i.eof())
//    {
//        i.get(t);
//        if (!(t == 'x'))
//            i.get(c);
//        if(!i.eof())
//           cout << t << c << endl;
//    }
//   
//    i.close();
//
//    return 0;
//}
//*/
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//
//int main() {
//    float A = 0, B = 0;
//    float i, j;
//    int k;
//    float z[1760];
//    char b[1760];
//    //printf("\x1b[2J");
//    for (;;) {
//        memset(b, 32, 1760);
//        memset(z, 0, 7040);
//        for (j = 0; j < 6.28; j += 0.07) {
//            for (i = 0; i < 6.28; i += 0.02) {
//                float c = sin(i);
//                float d = cos(j);
//                float e = sin(A);
//                float f = sin(j);
//                float g = cos(A);
//                float h = d + 2;
//                float D = 1 / (c * h * e + f * g + 5);
//                float l = cos(i);
//                float m = cos(B);
//                float n = sin(B);
//                float t = c * h * g - f * e;
//                int x = 40 + 30 * D * (l * h * m - t * n);
//                int y = 12 + 15 * D * (l * h * n + t * m);
//                int o = x + 80 * y;
//                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
//                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
//                    z[o] = D;
//                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
//                }
//            }
//        }
//        printf("\x1b[H");
//        for (k = 0; k < 1761; k++) {
//            putchar(k % 80 ? b[k] : 10);
//            A += 0.00004;
//            B += 0.00002;
//        }
//        system("cls");
//    }
//    return 0;
//}
//#include <SFML/Graphics.hpp>
//#include "MainMenu.h"
//
//using namespace std;
//
//int main()
//{
//	sf::RenderWindow MENU(sf::VideoMode(800, 640), "Main Menu", sf::Style::Default);
//	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
//
//	while (MENU.isOpen())
//	{
//		sf::Event event;
//		while (MENU.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//			{
//				MENU.close();
//			}
//			if (event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseMoved)
//			{
//				sf::Mouse::setPosition(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
//				if (event.key.code == sf::Keyboard::Up)
//				{
//					mainMenu.MoveUp();
//					break;
//				}
//				if (event.key.code == sf::Keyboard::Down)
//				{
//					mainMenu.MoveDown();
//					break;
//				}
//				if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Mouse::Left)
//				{
//					int x = mainMenu.MainMenuPressed();
//					if (x == 0)
//					{
//						sf::RenderWindow Play(sf::VideoMode(800, 600), "Amaz");
//						while (Play.isOpen())
//						{
//							MENU.close();
//							sf::Event pevent;
//							while (Play.pollEvent(pevent))
//							{
//								if (pevent.type == sf::Event::Closed)
//								{
//									Play.close();
//								}
//								if (pevent.type == sf::Event::KeyPressed)
//								{
//									if (pevent.key.code == sf::Keyboard::Escape)
//									{
//										MENU.create(sf::VideoMode(800, 600), "Main Menu", sf::Style::Default);
//										Play.close();
//									}
//								}
//							}
//							Play.clear();
//							Play.display();
//						}
//					}
//					if (x == 1)
//					{
//						sf::RenderWindow Options(sf::VideoMode(800, 600), "Options");
//						while (Options.isOpen())
//						{
//							MENU.close();
//							sf::Event pevent;
//							while (Options.pollEvent(pevent))
//							{
//								if (pevent.type == sf::Event::Closed)
//								{
//									Options.close();
//								}
//								if (pevent.type == sf::Event::KeyPressed)
//								{
//									if (pevent.key.code == sf::Keyboard::Escape)
//									{
//										MENU.create(sf::VideoMode(800, 600), "Main Menu", sf::Style::Default);
//										Options.close();
//									}
//								}
//							}
//							Options.clear();
//							Options.display();
//						}
//					}
//					if (x == 2)
//					{
//						sf::RenderWindow About(sf::VideoMode(800, 600), "About");
//						while (About.isOpen())
//						{
//							MENU.close();
//							sf::Event pevent;
//							while (About.pollEvent(pevent))
//							{
//								if (pevent.type == sf::Event::Closed)
//								{
//									About.close();
//								}
//								if (pevent.type == sf::Event::KeyPressed)
//								{
//									if (pevent.key.code == sf::Keyboard::Escape)
//									{
//										MENU.create(sf::VideoMode(800, 600), "Main Menu", sf::Style::Default);
//										About.close();
//									}
//								}
//							}
//							About.clear();
//							About.display();
//						}
//					}
//					if (x == 3)
//					{
//						MENU.close();
//					}
//				}
//			}
//		}
//		MENU.clear();
//		mainMenu.draw(MENU);
//		MENU.display();
//	}
//
//	return 0;
//}