//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

int Mx, My;
bool move;
 struct corabl{
	TRect Rect;
 }  ;
 std::vector<corabl> corabli;
 bool drag=false;
 int DragInd=-1, SX=0, SY=0;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------



 void field(){
		for (int i = 0; i <= 11; i++) {

		 Form3->PaintBox1->Canvas->MoveTo(300+0,50*i);
		 Form3 ->PaintBox1->Canvas->LineTo(300+50*10,50*i);


		 Form3->PaintBox1->Canvas->MoveTo(300+50*i,0);
		 Form3 ->PaintBox1->Canvas->LineTo(300+50*i,50*10);

	   }
 }


void __fastcall TForm3::FormCreate(TObject *Sender)
{
    this->DoubleBuffered = true;

  corabli.push_back({TRect(1,1,50,50)});
  corabli.push_back({TRect(100,1,150,50)});
  corabli.push_back({TRect(200,1,250,50)});
  corabli.push_back({TRect(1,100,50,150)});

  corabli.push_back({TRect(100,100,200,150)});
  corabli.push_back({TRect(1,200,50,300)});
  corabli.push_back({TRect(100,200,200,250)});

  corabli.push_back({TRect(200,300,250,450)});
  corabli.push_back({TRect(1,350,50,500)});

  corabli.push_back({TRect(100,300,150,500)});
}
//---------------------------------------------------------------------------

void __fastcall TForm3::PaintBox1Paint(TObject *Sender)
{
	 field();
	for (const auto& corab : corabli) {
		   PaintBox1->Canvas->Rectangle(corab.Rect);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::PaintBox1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	   for(int i= corabli.size()-1; i>=0;i--){
		  if (corabli[i].Rect.Left <=X &&
		   corabli[i].Rect.Right   >=X &&
		   corabli[i].Rect.Top    <=Y &&
		   corabli[i].Rect.Bottom>=Y)  {
			  drag=true;
			  DragInd=i;
			  SX=X;
			  SY=Y;
              break;
          }

	   }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::PaintBox1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	   if (drag && DragInd!=-1) {
		   int DeltaX=X-SX;
		   int DeltaY=Y-SY;

		   corabli[DragInd].Rect.Left+=DeltaX;
		   corabli[DragInd].Rect.Right+=DeltaX;
		   corabli[DragInd].Rect.Top+=DeltaY;
		   corabli[DragInd].Rect.Bottom+=DeltaY;

		   SX=X;
		   SY=Y;

		   PaintBox1->Invalidate();
	   }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::PaintBox1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
		 drag=false;
		 DragInd=-1;
}
//---------------------------------------------------------------------------

