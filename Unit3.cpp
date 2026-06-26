//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include "Unit3.h"
#include "Unit2.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
 struct corabl{
	TRect Rect;
	TRect pos=Rect;
 }  ;
 std::vector<corabl> corabli;
 bool drag=false;
 int DragInd=-1, SX=0, SY=0;
 bool nelzya[10][10]={};

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------



 void field(){
		for (int i = 0; i <= 11; i++) {

		 Form3->PaintBox1->Canvas->MoveTo(300+0,50+50*i);
		 Form3 ->PaintBox1->Canvas->LineTo(300+50*10,50+50*i);


		 Form3->PaintBox1->Canvas->MoveTo(300+50*i,50+0);
		 Form3 ->PaintBox1->Canvas->LineTo(300+50*i,50+50*10);

	   }
 }


void __fastcall TForm3::FormCreate(TObject *Sender)
{
	this->DoubleBuffered = true;

  corabli.push_back({TRect(1,50,50,100),});
  corabli.push_back({TRect(100,50,150,100)});
  corabli.push_back({TRect(200,50,250,100)});
  corabli.push_back({TRect(1,150,50,200)});

  corabli.push_back({TRect(100,150,200,200)});
  corabli.push_back({TRect(1,250,50,350)});
  corabli.push_back({TRect(100,250,200,300)});

  corabli.push_back({TRect(200,350,250,500)});
  corabli.push_back({TRect(1,400,50,550)});

  corabli.push_back({TRect(100,350,150,550)});
  field();
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
		 corabli[DragInd].Rect.Left=(corabli[DragInd].Rect.Left+25)/50;
		   corabli[DragInd].Rect.Top=(corabli[DragInd].Rect.Top+25)/50;
		   corabli[DragInd].Rect.Bottom=(corabli[DragInd].Rect.Bottom+25)/50;
		   corabli[DragInd].Rect.Right=(corabli[DragInd].Rect.Right+25)/50;
		   bool stav=true;
		   for(int i=corabli[DragInd].Rect.Left-6;i<corabli[DragInd].Rect.Right-6;i++)  {
			  for(int j=corabli[DragInd].Rect.Top-1;j<corabli[DragInd].Rect.Bottom-1;j++){
			  if(nelzya[i][j])
			  stav=false;
			  }
		   }

		   if   (corabli[DragInd].Rect.Left>=6 && corabli[DragInd].Rect.Right<=16
			   &&	 corabli[DragInd].Rect.Top>=1 && corabli[DragInd].Rect.Bottom<=11 && stav ){
		   corabli[DragInd].Rect.Right*=50;
		   corabli[DragInd].Rect.Left*=50;
		   corabli[DragInd].Rect.Bottom*=50;
		   corabli[DragInd].Rect.Top*=50;
		   }
		   else{
		   corabli[DragInd].Rect.Right=corabli[DragInd].pos.Right;
		   corabli[DragInd].Rect.Left=corabli[DragInd].pos.Left;
		   corabli[DragInd].Rect.Bottom=corabli[DragInd].pos.Bottom;
		   corabli[DragInd].Rect.Top=corabli[DragInd].pos.Top;

		   }
		   for (int i=0; i < 10; i++) {
			  for(int j=0;j<10;j++)
			   nelzya[i][j]=false;
		   }
		   for(int k= corabli.size()-1; k>=0;k--){
		  for(int i=corabli[k].Rect.Left/50-7;i<corabli[k].Rect.Right/50-5;i++)  {
			  for(int j=corabli[k].Rect.Top/50-2;j<corabli[k].Rect.Bottom/50;j++){
			   if (i<10 && i>=0 && j<10 && j>=0) {
				nelzya[i][j]=true;
			   }

			  }
		  }
	   }
		 DragInd=-1;
		 PaintBox1->Invalidate();

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
bool knopka=true;
for (int i=0; i < 10; i++) {
			  for(int j=0;j<10;j++)
			   pozcorabl1[i][j]=false;
}
 for(int k= corabli.size()-1; k>=0;k--){
		  for(int i=corabli[k].Rect.Left/50-6;i<corabli[k].Rect.Right/50-6;i++)  {
			  for(int j=corabli[k].Rect.Top/50-1;j<corabli[k].Rect.Bottom/50-1;j++){
			  if (i<10 && i>=0 && j<10 && j>=0)
				 pozcorabl1[i][j]=true;
			  else     {
				  knopka=false;
				  break;
              }

			  }
		  }
	   }
	   if(knopka){
	   Form5 ->Show();
	   Form5 ->PaintBox1->Width = 300+50*10+1;
	   Form5 ->PaintBox1->Height = 50*10+1+50;
	   Form5->PaintBox1->Repaint();
	   Form3->Close();
	   }

}
//---------------------------------------------------------------------------



void __fastcall TForm3::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   if ((Key == 'R' || Key == 'r') && drag) {
		 int x=corabli[DragInd].Rect.Right-corabli[DragInd].Rect.Left;
		 int y=corabli[DragInd].Rect.Bottom-corabli[DragInd].Rect.Top;
		 corabli[DragInd].Rect.Right+=y-x;
		 corabli[DragInd].Rect.Bottom+=x-y;
		 PaintBox1->Invalidate();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	   for(int k= corabli.size()-1; k>=0;k--){
		corabli[k].Rect.Right=corabli[k].pos.Right;
		   corabli[k].Rect.Left=corabli[k].pos.Left;
		   corabli[k].Rect.Bottom=corabli[k].pos.Bottom;
		   corabli[k].Rect.Top=corabli[k].pos.Top;
		}
		for (int i=0; i < 10; i++) {
			  for(int j=0;j<10;j++)
			   nelzya[i][j]=false;
        }
}
//---------------------------------------------------------------------------

