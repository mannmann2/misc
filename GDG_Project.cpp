#include<iostream>
#include<windows.h>
#include<string.h>
#include<fstream>
#include<stdio.h>

#define black 0
#define dark_blue 1
#define green 2
#define cyan 3
#define red 4
#define dark_purple 5
#define brown 6
#define gray 7
#define dark_gray 8
#define blue 9
#define neon_green 10
#define light_blue 11
#define light_red 12
#define purple 13
#define yellow 14
#define white 15

using namespace std;

class student
{
	char name[25];
	int rollno;
	float marks[3];
	char pass[10], pass1[10], pass2[10];

public:
	void getdata();
	void putdata();
	void modify();
	void password();
	
	int getrno()
	{
		return rollno;
	}
	
} s[10];


void student::getdata()
{
	int flag=1;
	char pass1[10];
	cout<<"Enter name:\n";
	fflush(stdin);
	gets(name);
	cout<<"Enter roll no:\n";
	cin>>rollno;
	cout<<"Set password:\n";
	while(flag!=0)
	{
		fflush(stdin);
		gets(pass);
		cout<<"Confirm password:\n";
		fflush(stdin);
		gets(pass1);
		flag=strcmp(pass, pass1);
		if(flag!=0)
			cout<<"Passwords do not match. Try again.\n";
	}	
	for(int i=1; i<4; i++)
	{
		cout<<"Enter marks in subject "<<i<<endl;
		cin>>marks[i-1];
	}	
}


void student::putdata()
{
	cout<<"\nName: ";
	puts(this->name);
	cout<<"Roll No: "<<this->rollno<<endl;
	for(int i=1; i<4; i++)
		cout<<"\nMarks in subject "<<i<<": "<<this->marks[i-1];
}
 

void student::modify()
{
	int p;
	cout<<"Enter password\n";
	fflush(stdin); 
	gets(pass1);
	if(!strcmp(this->pass, pass1))
	{
		cout<<"MODIFY\n\n1. Name\n2. Roll No.\n3. Marks\n";
		cin>>p;
		switch(p)
		{
			case 1:
				cout<<"Enter new name\n";
				fflush(stdin);
				gets(this->name);
				break;
			
			case 2:
				cout<<"Enter new roll no.\n";
				cin>>this->rollno;
				break;
				
			case 3:
				for(int i=1; i<4; i++)
				{
					cout<<"Enter new marks in subject"<<i<<endl;
					cin>>marks[i-1];
				}
				break;
		}
	}
	else
		cout<<"Wrong password.\n";
}


void student::password()
{ 
	int flag=1;
	cout<<"Enter old password:\n";
	fflush(stdin);
	gets(pass1);
	if(!strcmp(this->pass, pass1))
	{
		cout<<"Change password:\n";
		while(flag!=0)
		{
			fflush(stdin);
			gets(pass1);
			cout<<"Confirm password:\n";
			fflush(stdin);
			gets(pass2);
			flag=strcmp(pass1, pass2);
			if(flag==0)
			{
				strcpy(this->pass, pass1);
				cout<<"Password changed.\n";
			}
			else
				cout<<"Passwords do not match. Enter new password again.\n";
		}	
	}
	else
		cout<<"Error. Wrong password.\n";
}


void SetColor(int ForgC)
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, ForgC | FOREGROUND_INTENSITY);
}


void SetColorAndBackground(int ForgC, int BackC) 
{
	WORD w=((BackC & 0x0F) << 4) | (ForgC & 0x0F);
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, w);
}


void ClearConsoleToColors(int ForgC, int BackC)
{
	WORD w=((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord= {0, 0};
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO c;
	SetConsoleTextAttribute(h, w);
	if(GetConsoleScreenBufferInfo(h, &c))
	{
		FillConsoleOutputCharacter(h, (TCHAR)32, c.dwSize.X*c.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(h, c.wAttributes, c.dwSize.X*c.dwSize.Y, coord, &count);
		SetConsoleCursorPosition(h, coord);
	}
	 
}


int count=0;

void search();
void del();

fstream fio;
	

int main()
{	
	SetColor(15);
	cout<<"STUDENT RECORD SYSTEM\n";

	int ch, i, flag, rn;
	long pos;

	fio.open("student.txt", ios::in|ios::out);

	while(1)
	{	
		SetColorAndBackground(1, 14);
		cout<<"\n\n1. Add student record\n2. Search\n3. Modify student record\n4. Generate Marksheet\n5. Delete student record\n6. Change Password\n7. Exit\n";
		cin>>ch;
		ClearConsoleToColors(0, 0);
		switch(ch)
		{
			case 1:
				SetColor(3);
				if(count>=10)
				{
					cout<<"Limit reached. Can't add any more student records.\n";
					break;
				}
				cout<<"Enter details for student "<<count+1<<endl;
				s[count].getdata();
				fio.write((char*) &s[count], sizeof(s[count]));
				count++;
				break;
				
			case 2:
				SetColor(10);
				search();
				break;
				
			case 3:
				SetColor(14);
				flag=0;
				cout<<"Enter roll no. of student whose record is to be modified:\n";
				cin>>rn;
				fio.seekg(0);
				i=0;
				while((!fio.eof())&&(i<10))
				{
					pos=fio.tellg();
					fio.read((char*)&s[i], sizeof(s[i]));
					if(s[i].getrno()==rn)
					{
						flag=1;
						s[i].modify();
						fio.seekp(pos);
						fio.write((char*)&s[i], sizeof(s[i]));
					}
					i++;
				}
				if(flag==0)
					cout<<"Record not found.\n";
				break;
				
			case 4:
				SetColorAndBackground(1, 15);
				flag=0;
				cout<<"Enter roll no. of student whose marksheet is to be generated:\n";
				cin>>rn;
				for(int j=0; j<10; j++)
				{
					if(s[j].getrno()==rn)
					{
						flag=1;		
						cout<<"\n MARKSHEET\n\n";
						s[j].putdata();
						break;
					}
				}
				if(flag==0)
					cout<<"Record not found.\n";
				break;		
				
			case 5: 
				SetColorAndBackground(4, 15);
				del();
				break;
				
			case 6:
				SetColorAndBackground(5, 11);
				flag=0;
				cout<<"Enter roll no. of student whose password is to be changed:\n";
				cin>>rn;
				fio.seekg(0);
				for(i=0; i<10; i++)
				while(!fio.eof())
				{
					pos=fio.tellg();
					fio.read((char*)&s[i], sizeof(s[i]));
					if(s[i].getrno()==rn)
					{	
						flag=1;
						s[i].password();
						fio.seekp(pos);
						fio.write((char*)&s[i], sizeof(s[i]));
					}
				}
				if(flag==0)
					cout<<"Record not found.\n";
				break;
				
			case 7:exit(1);
			
			default:
				cout<<"Wrong input. Please try again.\n";
		}
	}
	
	fio.close();
	return 0;
}


void search()
{
	int rn, flag=0;
	cout<<"Enter roll no. to be searched for:\n";
	cin>>rn;
	
	int i=0;
	fio.seekg(0);
	while((!fio.eof())&&(flag==0)&&(i<10))
	{
		fio.read((char*)&s[i], sizeof(s[i]));
		if(s[i].getrno()==rn)
		{
			flag=1;
			s[i].putdata();
		}
		i++;
	}
	
	if(flag==0)
		cout<<"Record not found.\n";
}
 

void del()
{
	ofstream fout;
	fout.open("temp.txt", ios::out);
	int rn, flag=0;
	cout<<"Enter roll no. to be deleted:\n";
	cin>>rn;
	fio.seekg(0);
	int i=0;
	while((!fio.eof())&&(i<10))
	{
		fio.read((char*)&s[i], sizeof(s[i]));
		if(s[i].getrno()==rn)
		{
			flag=1;
			cout<<"Record deleted\n";
			count--;
		}
		else
			fout.write((char*)&s[i], sizeof(s[i]));
		i++;
	}
	if(flag==0)
		cout<<"Record not found.\n";
	fio.close();
	fout.close();
	
	remove("student.txt");
	rename("temp.txt", "student.txt");	
	fio.open("student.txt", ios::in|ios::out);	
}
