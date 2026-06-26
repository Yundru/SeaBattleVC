//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdlib>
#include <ctime>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
int A, B, C = 0;
bool pozvistrplayer[10][10] = {};
bool pozvistrrobot[10][10] = {};

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::PaintBox1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
		   A=X/50; B=Y/50;
		   if (C==0 && A<10 && B<10 && !pozvistrplayer[A][B]) {


		   PaintBox1->Canvas->MoveTo(A*50+1,B*50+1);
		   PaintBox1->Canvas->LineTo(A*50+49,B*50+49);

		   PaintBox1->Canvas->MoveTo(A*50+49,B*50+1);
		   PaintBox1->Canvas->LineTo(A*50+1,B*50+49);
		   pozvistrplayer[A][B] = true;
		   C=1;
		   }

}
//---------------------------------------------------------------------------

void __fastcall TForm4::PaintBox1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{       if(C==1)
		{
			srand(time(nullptr));
			int x, y;
			do
			{
				x = (rand() % (PaintBox2->Width + 1)) / 50;
				y = (rand() % (PaintBox2->Height + 1)) / 50;
			}while (pozvistrrobot[x][y] || x >10 || y >10);

		   PaintBox2->Canvas->MoveTo(x*50+1,y*50+1);
		   PaintBox2->Canvas->LineTo(x*50+49,y*50+49);

		   PaintBox2->Canvas->MoveTo(x*50+49,y*50+1);
		   PaintBox2->Canvas->LineTo(x*50+1,y*50+49);
		   pozvistrrobot[x][y] = true;
		   C=0;
		}
}
//---------------------------------------------------------------------------


