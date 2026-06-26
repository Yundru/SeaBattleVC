//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int a, b,c=1;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::PaintBox1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
		   a=X/50; b=Y/50;
		   if (c==0 && a<10 && b<10 ) {


		   PaintBox1->Canvas->MoveTo(a*50+1,b*50+1);
		   PaintBox1->Canvas->LineTo(a*50+49,b*50+49);

		   PaintBox1->Canvas->MoveTo(a*50+49,b*50+1);
		   PaintBox1->Canvas->LineTo(a*50+1,b*50+49);
		   c=1;
		   Label1->Caption="Player 1";
		   }
		   
}

//---------------------------------------------------------------------------


void __fastcall TForm2::PaintBox2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
         a=X/50; b=Y/50;
		   if (c==1 && a<10 && b<10) {


		   PaintBox2->Canvas->MoveTo(a*50+1,b*50+1);
		   PaintBox2->Canvas->LineTo(a*50+49,b*50+49);

		   PaintBox2->Canvas->MoveTo(a*50+49,b*50+1);
		   PaintBox2->Canvas->LineTo(a*50+1,b*50+49);
		   c=0;
		   Label1->Caption="Player 2";
		   }
}
//---------------------------------------------------------------------------


