#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <windows.h>
#include <fstream>
using namespace std;

string nama;

int x = 3;
int y = 3;
int point = 0;
char Maps[13][18];

void kalah();
void menang();
void printHighscore();
bool checkWin();
main() 
{
	char Maps[13][18]= 
	{"[=^=^=^=^=^=^=^=]",
	 "|o|o|o|o|o|o|o|o|",
	 "<=#=#=#=#=#=#=#=>",
	 "|o|o|o|o|o|o|o|o|",
	 "<=#=#=#=#=#=#=#=>",
	 "|o|o|o|o|o|o|o|o|",
	 "<=#=#=#=#=#=#=#=>",
	 "|o|o|o|o|o|o|o|o|",
	 "<=#=#=#=#=#=#=#=>",
	 "|o|o|o|o|o|o|o|o|",
	 "(=%=%=%=%=%=%=%=)",
	 };
	
	int jalan[8][2];
	
	printHighscore();
	cout<<"Masukkan nama: ";
	cin>>nama;
	
	srand (time(NULL));
	x = rand() % 8 + 1;
	y = rand() % 5 + 1;
	Maps[y*2-1][x*2-1] = 'X';
	
	while(!checkWin()) {
		system("cls");
		
		for(int i=0; i<13; i++){
			for(int j=0; j<18; j++){
				char t=Maps[i][j];
			if(t == '=')
				cout<<char(205);
			else if(t == '|')
				cout<<char(186);
			else if(t == '#')
				cout<<char(206);
			else if(t == '^')
				cout<<char(203);
			else if(t == '<')
				cout<<char(204);
			else if(t == '>')
				cout<<char(185);
			else if(t == '%')
				cout<<char(202);
			else if(t == '[')
				cout<<char(201);
			else if(t == ']')
				cout<<char(187);
			else if(t == '(')
				cout<<char(200);
			else if(t == ')')
				cout<<char(188);
			else
				cout<<t;
	 
			}
			cout<< endl;
		}
		
		cout<<"Point: "<<point<<endl<<endl;
		
		cout<<"Daftar jalan: \n";
		//y-3>0
		int i = 0;
		if(y-2>0 && x-1>0 && Maps[(y-2)*2-1][(x-1)*2-1] == 'o') {
			jalan[i][0] = x-1;
			jalan[i][1] = y-2;
			cout<<++i<<". Posisi "<<y-2<<", "<<x-1<<endl;
		}
		if(y-2>0 && x+1 <= 8 && Maps[(y-2)*2-1][(x+1)*2-1] == 'o') {
			jalan[i][0] = x+1;
			jalan[i][1] = y-2;
			cout<<++i<<". Posisi "<<y-2<<", "<<x+1<<endl;
		}
		if(y-1>0 && x-2>0 && Maps[(y-1)*2-1][(x-2)*2-1] == 'o') {
			jalan[i][0] = x-2;
			jalan[i][1] = y-1;
			cout<<++i<<". Posisi "<<y-1<<", "<<x-2<<endl;
		}
		if (y+1<=5 && x-2>0 && Maps[(y+1)*2-1][(x-2)*2-1] == 'o'){
			jalan[i][0] = x-2;
			jalan[i][1] = y+1;
			cout<<++i<<". Posisi "<<y+1<<", "<<x-2<<endl;
		}
		if (y-1>0 && x+2<=8 && Maps[(y-1)*2-1][(x+2)*2-1] == 'o'){
			jalan[i][0] = x+2;
			jalan[i][1] = y-1;
			cout<<++i<<". Posisi "<<y-1<<", "<<x+2<<endl;
		}
		if (y+1<=5 && x+2<=8 && Maps[(y+1)*2-1][(x+2)*2-1] == 'o'){
			jalan[i][0] = x+2;
			jalan[i][1] = y+1;
			cout<<++i<<". Posisi "<<y+1<<", "<<x+2<<endl;
		}
		if (y+2<=5 && x-1>0 && Maps[(y+2)*2-1][(x-1)*2-1] == 'o'){
			jalan[i][0] = x-1;
			jalan[i][1] = y+2;
			cout<<++i<<". Posisi "<<y+2<<", "<<x-1<<endl;
		}
		if (y+2<=5 && x+1>0 && Maps[(y+2)*2-1][(x+1)*2-1] == 'o'){
			jalan[i][0] = x+1;
			jalan[i][1] = y+2;
			cout<<++i<<". Posisi "<<y+2<<", "<<x+1<<endl;	
		}
	
		int pilihan;
		cout<<"Masukkan pilihan posisi: ";
		cin>>pilihan;
		
		//Kalah
		if(i < 1) {
			kalah();
		}
		
		if(pilihan > i + 1)
			cout<<"Tidak  valid"<<endl;
		else {
			Maps[y*2-1][x*2-1] = ' ';
			
			x = jalan[pilihan-1][0];
			y = jalan[pilihan-1][1];
			
			if(Maps[y*2-1][x*2-1] == 'o')
				point++;
			
			Maps[y*2-1][x*2-1] = 'X';
		}
	}
	
	menang();
}

void printHighscore() {
	string line;
	int i = 0;
	ifstream myfile ("SCORE.txt");
	if (myfile.is_open()) {
	    while ( getline (myfile,line) ) {
	      if(i % 2 == 0) {
	      	cout<<line;
	      }
	      else {
	      	cout<<" ("<<line<<")"<<endl;
	      }
	      i++;
    	}
		myfile.close();
	}
}

void kalah() {
	cout<<"ANDA KALAH";
	ofstream myfile ("SCORE.txt", ios::app);
  	if (myfile.is_open()) {
    	myfile <<nama<<"\n";
		myfile <<point<<"\n";
		myfile.close();
	}
}

void menang() {
	cout<<"ANDA MENANG";
	ofstream myfile ("SCORE.txt", ios::app);
  	if (myfile.is_open()) {
    	myfile <<nama<<"\n";
		myfile <<point<<"\n";
		myfile.close();
	}
}

bool checkWin() {
	bool win = true;
	for(int i = 0; i < 13; i++) {
		for(int j = 0; i < 17; i++) {
			if(Maps[i][j] == 'o')
				win = false;
		}
	}
	
	return false;
}
