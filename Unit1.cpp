//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "About.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "statistic.h"
#include <cstdlib>
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool playrobot=false;
bool pozcorablrobot[10][10] = {};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::help2Click(TObject *Sender)
{
       AboutBox->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	   Form3 ->Show();
	   Form3 ->PaintBox1->Width = 300+50*10+1;
	   Form3 ->PaintBox1->Height = 50*10+1+50;
	   Form3->PaintBox1->Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	   Form3 ->Show();
	   Form3 ->PaintBox1->Width = 300+50*10+1;
	   Form3 ->PaintBox1->Height = 50*10+1+50;
	   Form3->PaintBox1->Repaint();

}
bool permission(bool poz[][10], int x, int y)
{
	if (x == 0)
	{
		if (y==0){
			if (!poz[x][y] && !poz[x][y+1] && !poz[x+1][y]&& !poz[x+1][y+1])
				return true;
		}
		else if (y < 10){
			if (!poz[x][y] && !poz[x][y+1] && !poz[x][y-1] && !poz[x+1][y] && !poz[x+1][y+1] && !poz[x+1][y-1])
				return true;
		}
		else  if (!poz[x][y] && !poz[x][y-1] && !poz[x+1][y] && !poz[x+1][y-1]){
			return true;
		}
	}
	else if (x < 10)
	{
		if (y == 0){
			if (!poz[x][y] && !poz[x][y+1] && !poz[x+1][y] && !poz[x-1][y] && !poz[x+1][y+1] && !poz[x-1][y+1])
				return true;
		}
		else if (y < 10){
			if (!poz[x][y] && !poz[x][y+1] && !poz[x+1][y] && !poz[x-1][y] && !poz[x][y-1]
				&& !poz[x+1][y+1] && !poz[x-1][y+1] && !poz[x-1][y-1] && !poz[x+1][y-1])
				return true;
		}
		else if  (!poz[x][y] && !poz[x][y-1] && !poz[x-1][y] && !poz[x+1][y]
			&& !poz[x+1][y+1] && !poz[x-1][y+1])
			return true;
	}
	else
	{
		if (y == 0){
			if (!poz[x][y] && !poz[x][y+1] && !poz[x-1][y]  && !poz[x-1][y+1])
				return true;
		}
		else if (y < 10){
			if (!poz[x][y] && !poz[x][y+1] && !poz[x-1][y+1] && !poz[x-1][y] && !poz[x-1][y-1] && !poz[x][y-1])
				return true;
		}
		else if  (!poz[x][y] && !poz[x][y-1] && !poz[x-1][y] && !poz[x-1][y-1])
			return true;
	}
	return false;
}
void setcorablirobot(int lengh)
{
	bool corablset = false;
	srand(time(nullptr));
	int x, y;
	int templengh = 1;
	if (rand()%2==0 || rand()%3==0)
	{
		while(!corablset)
		{
			do
			{
				x = (rand() % (500 + 1)) / 50;
				y = (rand() % (500 + 1)) / 50;
			}while (x > 10 - lengh || y > 10);
			if (lengh == 1)
			{
				if (permission(pozcorablrobot, x, y)) {
					pozcorablrobot[x][y] = true;
					corablset = true;
				}
			}
			else
			{
				while (permission(pozcorablrobot, x, y) && templengh != lengh)
				{
					templengh++;
					x++;
				}
				if (lengh == templengh)
				{
					for (int i = 0; i < lengh; i++)
					{
						pozcorablrobot[x][y] = true;
						x--;
					}
					corablset = true;
				}
			}
		}
	}
	else
	{
		while(!corablset)
		{
			do{
				x = (rand() % (500 + 1)) / 50;
				y = (rand() % (500 + 1)) / 50;
			}while (x > 10  || y > 10-lengh);
			if (lengh == 1)
			{
				if (permission(pozcorablrobot, x, y)) {
					pozcorablrobot[x][y] = true;
					corablset = true;
				}
			}
			else
			{
				while (permission(pozcorablrobot, x, y) && templengh != lengh)
				{
					templengh++;
					y++;
				}
				if (lengh == templengh)
				{
					for (int i = 0; i < lengh; i++)
					{
						pozcorablrobot[x][y] = true;
						y--;
					}
					corablset = true;
				}
			}
		}
	}
}

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	   Form5 ->Show();
	   Form5 ->PaintBox1->Width = 300+50*10+1;
	   Form5 ->PaintBox1->Height = 50*10+1+50;
	   Form5->Label1->Caption="Player's field";
	   Form5->PaintBox1->Repaint();
	   playrobot = true;

	   for (int i=0; i < 10; i++)
				for(int j=0;j<10;j++)
					pozcorablrobot[i][j]=false;
	   for(int i = 4; i > 0; i--)
		   for(int j = 0; j < 5-i; j++)
			setcorablirobot(i);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	stat->Show();
}
//---------------------------------------------------------------------------

