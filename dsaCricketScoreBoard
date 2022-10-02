#include<iostream>
#include<string>
#include<graphics.h>
#include<fstream>
#include<time.h>
#include<windows.h>
#include<conio.h>
using namespace std;
class  Venue
{

public:
	
string matchvenue();
	string teamselects();		
	string teamselects2();
	string TossDecision();
	void datentime();

};
class display
{
	
	
	public:
		
	void display1();
	void display2();
     char* convertIntegerToChar(int N);
};
class pnode
{
	
public:
	
	string pname;
	int pscore,pout;
	pnode* nextp;
	pnode()
{
	pname="";
	pscore=0;
	pout=0;
	nextp=NULL;
}


	
};
class score:public Venue
{

int tscore,tout,overs,balls;//total score //total out //overs
pnode* head;
pnode* tail;
pnode* head2;
pnode* tail2;


public:
	
	score()
	{
		head=NULL;
		tail=NULL;
				head2=NULL;
		tail2=NULL;
		tscore=0;
tout=0;
		overs=0;
	}

string getplayers();
string getplayers2();
void dislayt();
void dislayt2();
string match();


	
};

string Venue::matchvenue()
{
	string cricketstadium[5];
	int loop = 0;
	string stadium;

	ifstream input("cricketstadium.txt");
	if (input.is_open())
	{
		while (!input.eof())
		{
			getline(input, stadium);
			cricketstadium[loop] = stadium;
			loop++;
		}
		input.close();
	}
	else
	{
		cout << "CANT OPEN FILE!!";
	}
	
	srand(time(0));
	int randindex = rand() % 4;
	//cout << "STADIUM:"<<cricketstadium[randindex];
    string s =cricketstadium[randindex] ;
 
    int n = s.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());
    setcolor(WHITE);
    outtextxy(105,115,"VENUE:");
    outtextxy(200,115,char_array);
    
	return cricketstadium[randindex];


}
string Venue::teamselects()
{

	string teamselect[10];
	int loops = 0;
	string team;
	ifstream inputs("teamselect.txt");
	if (inputs.is_open())
	{
		while (!inputs.eof())
		{
			getline(inputs, team);
			teamselect[loops] = team;
			loops++;
		}
		inputs.close();
	}
	else
	{
		cout << "Cant open File!!!";

	}
	srand(time(0));
	int randteam = rand() % 5;
    string s =teamselect[randteam] ;
 
    int n = s.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());
    setcolor(WHITE);
    outtextxy(500,115,char_array);//first team    

        setcolor(WHITE);
        outtextxy(650,115,"VS");
return teamselect[randteam];

}
string Venue::teamselects2()
{

	string teamselect[10];
	int loops = 0;
	string team;
	ifstream inputs("teamselect.txt");
	if (inputs.is_open())
	{
		while (!inputs.eof())
		{
			getline(inputs, team);
			teamselect[loops] = team;
			loops++;
		}
		inputs.close();
	}
	else
	{
		cout << "Cant open File!!!";

	}


    //second team
    
selectagn:
	int randteamb = rand() % 5;
    string sb =teamselect[randteamb] ;
    
    
    // if random function selects the same team again rand again
    
    if(teamselect[randteamb]==teamselects())
    {
goto selectagn;
	}

	
    int nb = sb.length();
 
    // declaring character array
    char char_arrayb[nb + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_arrayb, sb.c_str());
    setcolor(RED);
    outtextxy(700,115,char_arrayb);
        
	return teamselect[randteamb];


}
void Venue::datentime()
{
	int date, month, year;
	int hours, minutes;
	srand(time(0));
	date = rand() % 31;
	month = rand() % 12;
	year = 2022 +(rand() % 5);
	hours = rand() % 24;
	minutes = rand() % 59;
//	cout << "DATE:" << month << "/" << date << "/" << year<<"\n";
//	cout << "TIME:" << hours << ":" << minutes;
	outtextxy(965,90,"DD/ MM/ YY");
	int m = date;
	int digit = 0;
	while (m) {

		digit++;

		m /= 10;
	}

	char* arr;

	char arr1[digit];

	arr = (char*)malloc(digit);
	int index = 0;
	while (date) {
		arr1[++index] = date % 10 + '0';

		date /= 10;
	}

	int i;
	for (i = 0; i < index; i++) {
		arr[i] = arr1[index - i];
	}

	arr[i] = '\0';

	outtextxy(965,115,arr);
	
	//month
	{
	int m = month;
	int digit = 0;
	while (m) {

		digit++;

		m /= 10;
	

	char* arr;

	char arr1[digit];

	arr = (char*)malloc(digit);
	int index = 0;
	while (month) {
		arr1[++index] = month % 10 + '0';

		month /= 10;
	}

	int i;
	for (i = 0; i < index; i++) {
		arr[i] = arr1[index - i];
	}

	arr[i] = '\0';
		setcolor(GREEN);
	outtextxy(1000,115,arr);
	}
	
		//year
	{
	int m = year;
	int digit = 0;
	while (m) 
	{

		digit++;

		m /= 10;
}

	char* arr;

	char arr1[digit];

	arr = (char*)malloc(digit);
	int index = 0;
	while (year) {
		arr1[++index] = year % 10 + '0';

		year /= 10;
	}

	int i;
	for (i = 0; i < index; i++) {
		arr[i] = arr1[index - i];
	}

	arr[i] = '\0';
		setcolor(RED);
	outtextxy(1040,115,arr);
	}
}
}

string Venue::TossDecision()
{
	string Toss[2];
	int loopt = 0;
	string toss;
	ifstream inputt("toss.txt");
	if (inputt.is_open())
	{
		while (!inputt.eof())
		{
			getline(inputt, toss);
			Toss[loopt] = toss;
			loopt++;
		}
		inputt.close();
	}
	else
	{
		cout << "Cant Open file!!!";


	}
	srand(time(0));
	int randtoss = rand() % 2;
	
	outtextxy(105,140,"TOSS WIN:");
    string s = Toss[randtoss];
 
    int n = s.length();
 

    char char_array[n + 1];
 

    strcpy(char_array, s.c_str());
    
    setcolor(GREEN);
 outtextxy(230,140,char_array);
 

	
	if(Toss[randtoss]=="(Heads)")
	{
    
    string s = teamselects();
 
    int n = s.length();
 
    char char_array[n + 1];

    strcpy(char_array, s.c_str());
    //team 1
    outtextxy(330,140,char_array);

	}
	else if(Toss[randtoss]=="(Tails)")
	{
		
		
		//string to char conversion 
    string s = teamselects2();
 
    int n = s.length();
 
    char char_arrayb[n + 1];
 

    strcpy(char_arrayb, s.c_str());
    //team 2
    outtextxy(330,140,char_arrayb);


	}
	return Toss[randtoss];
}

void display::display2()
{

setbkcolor(BLUE);
//Cricket SCORE BOARD
setcolor(WHITE);
setfillstyle(SOLID_FILL,BLACK);
rectangle(343,13,1059,90);
floodfill(344,14,WHITE);

//border1 left
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLUE);
rectangle(0,0,10,660);
floodfill(1,1,BLACK);


//border2 left
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
rectangle(11,0,20,660);
floodfill(12,1,WHITE);


//border1 right
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLUE);
rectangle(1340,0,0,660);
floodfill(1341,1,BLACK);

//border2 right
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
rectangle(1329,0,1339,660);
floodfill(1330,1,WHITE);


//TOP BORDER

setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
rectangle(21,95,1328,110);
floodfill(22,96,WHITE);

//BOTTOM BORDER

setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
rectangle(21,600,1328,615);
floodfill(22,601,BLUE);

}
void display::display1()//main window
{
	

readimagefile("sc1.jpg",0,0,1350,660);
/*rectangle(1350,50,0,10);//horizontal line top
rectangle(1350,595,0,650);//horizontal line bottom
rectangle(50,50,100,650);//vertical line left
rectangle(1250,50,1300,650);*///vertical line right
setcolor(WHITE);
setfillstyle(SOLID_FILL,BLACK);
rectangle(215,195,700,245);//MATCHES RECTANGLE
floodfill(216,196,WHITE);

setcolor(WHITE);
setfillstyle(SOLID_FILL,BLACK);//Bowler ranking
rectangle(215,265,650,315);
floodfill(216,266,WHITE);

//Bowler ranking
setcolor(WHITE);
setfillstyle(SOLID_FILL,BLACK);
rectangle(215,335,675,385);
floodfill(216,366,WHITE);

//team ranking
setcolor(WHITE);
setfillstyle(SOLID_FILL,BLACK);
rectangle(215,405,600,455);
floodfill(216,406,WHITE);



//Cricket SCORE BOARD
setcolor(WHITE);
setfillstyle(SOLID_FILL,BLACK);
rectangle(343,13,1059,90);
floodfill(344,14,WHITE);

setbkcolor(BLUE);
//Cricket SCORE BOARD
setcolor(WHITE);
setfillstyle(SOLID_FILL,BLACK);
rectangle(343,13,1059,90);
floodfill(344,14,WHITE);

//border1 left
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLUE);
rectangle(0,0,10,660);
floodfill(1,1,BLACK);


//border2 left
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
rectangle(11,0,20,660);
floodfill(12,1,WHITE);


//border1 right
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLUE);
rectangle(1340,0,0,660);
floodfill(1341,1,BLACK);

//border2 right
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
rectangle(1329,0,1339,660);
floodfill(1330,1,WHITE);


//TOP BORDER

setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
rectangle(21,95,1328,110);
floodfill(22,96,WHITE);

//BOTTOM BORDER

setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
rectangle(21,600,1328,615);
floodfill(22,601,BLUE);


setcolor(WHITE);//Score board
settextstyle(10,0,7);//score board
setbkcolor(BLUE);
outtextxy(350,20,"CRICKET SCOREBOARD");
setcolor(WHITE);//Score board
settextstyle(10,0,5);//score board
outtextxy(220,200,"(1)COMMENCE MATCHES");
outtextxy(220,270,"(2)BOWLER RANKING");
outtextxy(220,340,"(3)BATSMAN RANKING");
outtextxy(220,410,"(3)TEAM RANKING");
}
char* display:: convertIntegerToChar(int N)
 {

	int m = N;
	int digit = 0;
	while (m) {

		digit++;

		m /= 10;
	}

	char* arr;

	char arr1[digit];

	arr = (char*)malloc(digit);
	int index = 0;
	while (N) {
		arr1[++index] = N % 10 + '0';

		N /= 10;
	}

	int i;
	for (i = 0; i < index; i++) 
	{
		arr[i] = arr1[index - i];
	}

	arr[i] = '\0';
	// Return char array
	return (char*)arr;
}
                       //SCORE

string score::getplayers()
{

	Venue a;
	string player;

	if (a.teamselects() == "Pakistan")
	{

		ifstream input("Pakistan.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;

				if (head == NULL)
				{
					head = ptr;
					tail = ptr;

				}
				else
				{
					tail->nextp = ptr;
					tail = ptr;


				}

			}
			input.close();
		}
		else
		{
			cout << "CANT OPEN FILE!!";
		}
	}
	else if (a.teamselects() == "India")
	{

		ifstream input("India.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;


				if (head == NULL)
				{
					head = ptr;
					tail = ptr;

				}
				else
				{
					tail->nextp = ptr;
					tail = ptr;


				}

			}
			input.close();
		}
		else
		{
			cout << "CANT OPEN FILE!!";
		}
	}

	else if (a.teamselects() == "England")
	{

		ifstream input("England.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;


				if (head == NULL)
				{
					head = ptr;
					tail = ptr;

				}
				else
				{
					tail->nextp = ptr;
					tail = ptr;


				}

			}
			input.close();
		}
	}
	else if (a.teamselects() == "Bangladesh")
	{

		ifstream input("Bangladesh.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;

				if (head == NULL)
				{
					head = ptr;
					tail = ptr;

				}
				else
				{
					tail->nextp = ptr;
					tail = ptr;


				}

			}
			input.close();
		}
		else
		{
			cout << "CANT OPEN FILE!!";
		}
	}
	else if (a.teamselects() == "Australia")
	{

		ifstream input("Australia.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;

				if (head == NULL)
				{
					head = ptr;
					tail = ptr;

				}
				else
				{
					tail->nextp = ptr;
					tail = ptr;


				}

			}
			input.close();
		}
		else
		{
			cout << "CANT OPEN FILE!!";
		}
	}
	else
	{
		cout << "ERRO!";
	}
	return player;
}
string score::getplayers2()
{

	Venue a;
	string player;

	if (a.teamselects2() == "Pakistan")
	{

		ifstream input("Pakistan.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;
	

				if (head2 == NULL)
				{
					head2 = ptr;
					tail2 = ptr;

				}
				else
				{
					tail2->nextp = ptr;
					tail2 = ptr;


				}

			}
			input.close();
		}
		else
		{
			cout << "CANT OPEN FILE!!";
		}
	}
	else if (a.teamselects2() == "India")
	{

		ifstream input("India.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;
		

				if (head2 == NULL)
				{
					head2 = ptr;
					tail2 = ptr;

				}
				else
				{
					tail2->nextp = ptr;
					tail2 = ptr;


				}

			}
			input.close();
		}
		else
		{
			cout << "CANT OPEN FILE!!";
		}
	}

	else if (a.teamselects2() == "England")
	{

		ifstream input("England.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;
			

				if (head2 == NULL)
				{
					head2 = ptr;
					tail2 = ptr;

				}
				else
				{
					tail2->nextp = ptr;
					tail2 = ptr;


				}

			}
			input.close();
		}
	}
	else if (a.teamselects2() == "Bangladesh")
	{

		ifstream input("Bangladesh.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;
			

				if (head2 == NULL)
				{
					head2 = ptr;
					tail2 = ptr;

				}
				else
				{
					tail2->nextp = ptr;
					tail2 = ptr;


				}

			}
			input.close();
		}
		else
		{
			cout << "CANT OPEN FILE!!";
		}
	}
	else if (a.teamselects2() == "Australia")
	{

		ifstream input("Australia.txt");
		if (input.is_open())
		{
			while (!input.eof())
			{
				pnode* ptr = new pnode();
				ptr->nextp = NULL;
				getline(input, player);
				ptr->pname = player;
		
				if (head2 == NULL)
				{
					head2 = ptr;
					tail2 = ptr;

				}
				else
				{
					tail2->nextp = ptr;
					tail2 = ptr;


				}

			}
			input.close();
		}
		else
		{
			cout << "CANT OPEN FILE!!";
		}
	}
	else
	{
		cout << "ERROR!";
	}
	return player;
}


string score::match()
{


	
			ofstream out("batsman.csv");
		ofstream outb("bowler.csv");

	string a="LIN";
			srand(time(0));
		int decision;//if team 1 wins
		int decision2;//if team 2 wins
		decision=rand()%3;
		decision2=rand()%3;

		//team 1 wins
	if(TossDecision()=="(Heads)")
	{
		
//team 1 bats first


		if(decision==1)
		{
			outtextxy(480,140,"WILL BAT FIRST");
			pnode*batsman=head;
			pnode*bowler=head2;
int balls1;

	while(tout<10&&overs<10)
	
	{

int outor;
outor=rand()%5;
if(outor==1)
{
	string a;//for batsman name
	int b;//for score
	
	//writing batsman data in file when wickt falls
	a=batsman->pname;
	b=batsman->pscore;
	out<<a<<","<<b<<endl;
	
	//
batsman=batsman->nextp;
batsman->pscore+=0;
bowler->pout+=1;
tout+=1;
balls1+=1;
if(balls1>=6)
{
	string c;
	int d;
	c=bowler->pname;
	d=bowler->pout;
	outb<<c<<","<<d<<endl;
	bowler=bowler->nextp;
	overs+=1;
	balls1=0;
}



}
else
{

	int randscore;
	randscore=rand()%7;
	batsman->pscore+=randscore;
balls1+=1;
	if(balls1>=6)
{
	string c;
	int d;
	c=bowler->pname;
	d=bowler->pout;
		outb<<c<<","<<d<<endl;
	bowler=bowler->nextp;
balls1=0;
	overs+=1;
	
}
	
}
		
	}
		}
		else
		{
	
				outtextxy(480,140,"WILL  BOWL FIRST");
					pnode*batsman=head2;
			pnode*bowler=head;

int balls2;

	while(tout<10&&overs<10)
	
	{

int outor;
outor=rand()%5;
if(outor==1)
{
	string a;//for batsman name
	int b;//for score
	
	//writing batsman data in file when wickt falls
	a=batsman->pname;
	b=batsman->pscore;
	out<<a<<","<<b<<endl;
	
	//
batsman=batsman->nextp;
batsman->pscore+=0;
bowler->pout+=1;
tout+=1;
balls2+=1;
if(balls2>=6)
{
	string c;
	int d;
	c=bowler->pname;
	d=bowler->pout;
	outb<<c<<","<<d<<endl;
	bowler=bowler->nextp;
	overs+=1;
	balls2=0;
}



}
else
{

	int randscore;
	randscore=rand()%7;
	batsman->pscore+=randscore;
balls2+=1;
	if(balls2>=6)
{
	string c;
	int d;
	c=bowler->pname;
	d=bowler->pout;
		outb<<c<<","<<d<<endl;
	bowler=bowler->nextp;
balls2=0;
	overs+=1;
	
}
	
}
		
	}
		}
		
	}
	
	// team 2 wins the toss
	else if(TossDecision()=="(Tails)")
	{
		
		
		
		if(decision2==1)
		{
			outtextxy(480,140,"WILL BAT FIRST");
			pnode*batsman=head2;
			pnode*bowler=head;
int balls3;

	while(tout<10&&overs<10)
	
	{

int outor;
outor=rand()%5;
if(outor==1)
{
	string a;//for batsman name
	int b;//for score
	
	//writing batsman data in file when wickt falls
	a=batsman->pname;
	b=batsman->pscore;
	out<<a<<","<<b<<endl;
	
	//
batsman=batsman->nextp;
batsman->pscore+=0;
bowler->pout+=1;
tout+=1;
balls3+=1;
if(balls3>=6)
{
	string c;
	int d;
	c=bowler->pname;
	d=bowler->pout;
	outb<<c<<","<<d<<endl;
	bowler=bowler->nextp;
	balls3=0;
	overs+=1;
}



}
else
{

	int randscore;
	randscore=rand()%7;
	batsman->pscore+=randscore;
balls3+=1;
	if(balls3>=6)
{
	string c;
	int d;
	c=bowler->pname;
	d=bowler->pout;
		outb<<c<<","<<d<<endl;
	bowler=bowler->nextp;
balls3=0;
	overs+=1;
	
}
	
}
		
	}
		}
		else
		{
	
				outtextxy(480,140,"WILL  BOWL FIRST");
					pnode*batsman=head;
			pnode*bowler=head2;

int balls4;

	while(tout<10&&overs<10)
	
	{

int outor;
outor=rand()%5;
if(outor==1)
{
	string a;//for batsman name
	int b;//for score
	
	//writing batsman data in file when wickt falls
	a=batsman->pname;
	b=batsman->pscore;
	out<<a<<","<<b<<endl;
	
	//
batsman=batsman->nextp;
batsman->pscore+=0;
bowler->pout+=1;
tout+=1;
balls4+=1;
if(balls4>=6)
{
	string c;
	int d;
	c=bowler->pname;
	d=bowler->pout;
	outb<<c<<","<<d<<endl;
	bowler=bowler->nextp;
	overs+=1;
	balls4=0;
}



}
else
{

	int randscore;
	randscore=rand()%7;
	batsman->pscore+=randscore;
balls4+=1;
	if(balls4>=6)
{
	string c;
	int d;
	c=bowler->pname;
	d=bowler->pout;
		outb<<c<<","<<d<<endl;
	bowler=bowler->nextp;
balls4=0;
	overs+=1;
	
}
	
}
		
	}
		}
		
	}

	return a;

	
}
//Team 1 display function
	void score::dislayt()
	{
		pnode* disp;
	disp = head;

	if (disp == NULL)
	{
		cout << "LIST IS EMPTY!!!";
	}
	else
	{
		while (disp != NULL)
		{
			cout << disp->pname << "->";
			disp = disp->nextp;
		}
	}
//Team 2 display function
	}
		void score::dislayt2()
	{
		pnode* disp;
	disp = head2;

	if (disp == NULL)
	{
		cout << "LIST IS EMPTY!!!";
	}
	else
	{
		while (disp != NULL)
		{
			cout << disp->pname << "->";
			disp = disp->nextp;
		}
	}

	}

	

int main()
{
	

 int x,y;
 
display a;

	initwindow(1350,660);//window
	abx:
	cleardevice();

a.display1();



while (!ismouseclick(WM_LBUTTONDOWN))
    {
  //triangle(maxx/divisor, maxy/divisor);
Venue b;
Venue bb;
score c;
score cc;

  delay(500);
   
    getmouseclick(WM_LBUTTONDOWN, x, y);
    cout << "The mouse was clicked at: ";
    cout << "x=" << x;
    cout << " y=" << y << endl;
    if(x>=220 && x<=694 && y>=200 && y<=240)//match
    {
    	cleardevice();
readimagefile("sc2.jpg",0,0,1350,660);
a.display2();
			setcolor(WHITE);//Score board


settextstyle(10,0,7);//score board
setbkcolor(BLUE);
outtextxy(350,20,"CRICKET SCOREBOARD");
outtextxy(1190,600,"HOME");

settextstyle(10,0,3);
b.matchvenue();
b.datentime();
b.teamselects();
b.teamselects2();
c.getplayers();
c.getplayers2();
b.TossDecision();
c.match();



	}
	else if(x>=220 && x<=644 && y>=270 && y<=310)//BOWLER
	{
			cleardevice();
			readimagefile("bowler.jpg",0,0,1350,660);
			
			a.display2();
			setcolor(WHITE);//Score board
settextstyle(10,0,7);//score board
setbkcolor(BLUE);
outtextxy(350,20,"CRICKET SCOREBOARD");
outtextxy(1190,600,"HOME");
setcolor(WHITE);//Score board


			
	}
		else if(x>=220 && x<=668 && y>=339 && y<=378)//BATSMAN
	{
			cleardevice();
			readimagefile("batman.jpg",0,0,1350,660);
				a.display2();
			setcolor(WHITE);//Score board
            settextstyle(10,0,7);//score board
            setbkcolor(BLUE);
            outtextxy(350,20,"CRICKET SCOREBOARD");
            outtextxy(1190,600,"HOME");
            setcolor(WHITE);//Score board
	}
		else if(x>=220 && x<=594 && y>=410 && y<=447)//TEAM
	{
			cleardevice();
			readimagefile("sc5.jpg",0,0,1350,660);
				a.display2();
			setcolor(WHITE);//Score board
            settextstyle(10,0,7);//score board
            setbkcolor(BLUE);
            outtextxy(350,20,"CRICKET SCOREBOARD");
            outtextxy(1190,600,"HOME");
            setcolor(WHITE);//Score board
            
	}
	else if(x>=1189 && x<=1345 && y>=601 && y<=660)//HOME
	{
		
		goto abx;
	}

    }




system("pause");
}
Footer
