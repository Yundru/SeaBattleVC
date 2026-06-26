//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdlib>
#include <ctime>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
int A, B, C = 0;
bool pozvistrplayer[10][10];
bool pozvistrrobot[10][10];
bool pozcorablplayer[10][10] = {};
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int playerschet = 0;
int playerpromah = 0;
int robotschet=0;
int robotpromah = 0;
void __fastcall TForm4::PaintBox2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
		   A=X/50; B=Y/50;
		   if (C==0 && A<10 && B<10 && !pozvistrplayer[A][B]) {

		   if (!pozcorablrobot[A][B]){
		   playerpromah++;
		   PaintBox2->Canvas->MoveTo(A*50+1,B*50+1);
		   PaintBox2->Canvas->LineTo(A*50+49,B*50+49);

		   PaintBox2->Canvas->MoveTo(A*50+49,B*50+1);
		   PaintBox2->Canvas->LineTo(A*50+1,B*50+49);

		   C=1;
		   }

		   else{
			   playerschet++;
			   PaintBox2->Canvas->Rectangle(A*50+1,B*50+1,A*50+50,B*50+50);

		   }
		   pozvistrplayer[A][B] = true;

		   if (playerschet==20){
			 ShowMessage("Player win!");
			 Close();
		   }
		   }

}
//---------------------------------------------------------------------------

void __fastcall TForm4::PaintBox2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
		while(C==1)
		{
			srand(time(nullptr));
			int x, y;
			do
			{
				x = (rand() % (500 + 1)) / 50;
				y = (rand() % (500 + 1)) / 50;
			}while (pozvistrrobot[x][y] || x >10 || y >10);
		   if (!pozcorablplayer[x][y]) {
		   robotpromah++;
		   PaintBox1->Canvas->MoveTo(x*50+1,y*50+1);
		   PaintBox1->Canvas->LineTo(x*50+49,y*50+49);

		   PaintBox1->Canvas->MoveTo(x*50+49,y*50+1);
		   PaintBox1->Canvas->LineTo(x*50+1,y*50+49);

		   C=0;
		   }
		   else{
			robotschet++;
			PaintBox1->Canvas->Rectangle(x*50+1,y*50+1,x*50+50,y*50+50);
			

			if (robotschet==20){
			 ShowMessage("Robot win!");
			 Close();
			 break;
		   }
		   }
		   pozvistrrobot[x][y] = true;
		}

}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{    playerschet = 0;
	 robotschet=0;
     for (int i=0; i < 10; i++) {
		 for(int j=0;j<10;j++){
			   pozvistrplayer[i][j] = 0;
			   pozvistrrobot[i][j] = 0;
		 }
	 }
}
//---------------------------------------------------------------------------

