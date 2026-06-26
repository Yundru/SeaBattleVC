//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include "Unit5.h"
#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
 struct corabl{
	TRect Rect;
	TRect pos=Rect;
 }  ;
 std::vector<corabl> corabli2;
 bool drag2=false;
 int DragInd2=-1, SX2=0, SY2=0;
  bool nelzya2[10][10]={};
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
 void field2(){
		for (int i = 0; i <= 11; i++) {

		 Form5->PaintBox1->Canvas->MoveTo(300+0,50+50*i);
		 Form5 ->PaintBox1->Canvas->LineTo(300+50*10,50+50*i);


		 Form5->PaintBox1->Canvas->MoveTo(300+50*i,50+0);
		 Form5 ->PaintBox1->Canvas->LineTo(300+50*i,50+50*10);

	   }
 }
//---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender)
{
	this->DoubleBuffered = true;

  corabli2.push_back({TRect(1,50,50,100),});
  corabli2.push_back({TRect(100,50,150,100)});
  corabli2.push_back({TRect(200,50,250,100)});
  corabli2.push_back({TRect(1,150,50,200)});

  corabli2.push_back({TRect(100,150,200,200)});
  corabli2.push_back({TRect(1,250,50,350)});
  corabli2.push_back({TRect(100,250,200,300)});

  corabli2.push_back({TRect(200,350,250,500)});
  corabli2.push_back({TRect(1,400,50,550)});

  corabli2.push_back({TRect(100,350,150,550)});
  field2();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::PaintBox1Paint(TObject *Sender)
{
	 field2();
	for (const auto& corab : corabli2) {
		   PaintBox1->Canvas->Rectangle(corab.Rect);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm5::PaintBox1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	   for(int i= corabli2.size()-1; i>=0;i--){
		  if (corabli2[i].Rect.Left <=X &&
		   corabli2[i].Rect.Right   >=X &&
		   corabli2[i].Rect.Top    <=Y &&
		   corabli2[i].Rect.Bottom>=Y)  {
			  drag2=true;
			  DragInd2=i;
			  SX2=X;
			  SY2=Y;
			  break;
		  }

	   }
}
//---------------------------------------------------------------------------
void __fastcall TForm5::PaintBox1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	   if (drag2 && DragInd2!=-1) {
		   int DeltaX2=X-SX2;
		   int DeltaY2=Y-SY2;

		   corabli2[DragInd2].Rect.Left+=DeltaX2;
		   corabli2[DragInd2].Rect.Right+=DeltaX2;
		   corabli2[DragInd2].Rect.Top+=DeltaY2;
		   corabli2[DragInd2].Rect.Bottom+=DeltaY2;

		   SX2=X;
		   SY2=Y;

		   PaintBox1->Invalidate();
	   }
}
//---------------------------------------------------------------------------
void __fastcall TForm5::PaintBox1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
		 drag2=false;
		 corabli2[DragInd2].Rect.Left=(corabli2[DragInd2].Rect.Left+25)/50;
		   corabli2[DragInd2].Rect.Top=(corabli2[DragInd2].Rect.Top+25)/50;
		   corabli2[DragInd2].Rect.Bottom=(corabli2[DragInd2].Rect.Bottom+25)/50;
		   corabli2[DragInd2].Rect.Right=(corabli2[DragInd2].Rect.Right+25)/50;

		   bool stav2=true;
		   for(int i=corabli2[DragInd2].Rect.Left-6;i<corabli2[DragInd2].Rect.Right-6;i++)  {
			  for(int j=corabli2[DragInd2].Rect.Top-1;j<corabli2[DragInd2].Rect.Bottom-1;j++){
			  if(nelzya2[i][j])
			  stav2=false;
			  }
		   }

		   if   (corabli2[DragInd2].Rect.Left>=6 && corabli2[DragInd2].Rect.Right<=16
			   &&	 corabli2[DragInd2].Rect.Top>=1 && corabli2[DragInd2].Rect.Bottom<=11 && stav2){
		   corabli2[DragInd2].Rect.Right*=50;
		   corabli2[DragInd2].Rect.Left*=50;
		   corabli2[DragInd2].Rect.Bottom*=50;
		   corabli2[DragInd2].Rect.Top*=50;
		   }
		   else{
		   corabli2[DragInd2].Rect.Right=corabli2[DragInd2].pos.Right;
		   corabli2[DragInd2].Rect.Left=corabli2[DragInd2].pos.Left;
		   corabli2[DragInd2].Rect.Bottom=corabli2[DragInd2].pos.Bottom;
		   corabli2[DragInd2].Rect.Top=corabli2[DragInd2].pos.Top;

		   }

           for (int i=0; i < 10; i++) {
			  for(int j=0;j<10;j++)
			   nelzya2[i][j]=false;
		   }
		   for(int k= corabli2.size()-1; k>=0;k--){
		  for(int i=corabli2[k].Rect.Left/50-7;i<corabli2[k].Rect.Right/50-5;i++)  {
			  for(int j=corabli2[k].Rect.Top/50-2;j<corabli2[k].Rect.Bottom/50;j++){
			   if (i<10 && i>=0 && j<10 && j>=0) {
				nelzya2[i][j]=true;
			   }

			  }
		  }
	   }

		 DragInd2=-1;
		 PaintBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	if (playrobot)
	{
		Form4 ->Show();
		Form4 ->PaintBox1->Width = 50*10+1;
		Form4 ->PaintBox1->Height = 50*10+1;
		Form4->PaintBox1->Repaint();
		for (int i = 0; i <= 11; i++)
		{

			Form4->PaintBox1->Canvas->MoveTo(0,50*i);
			Form4 ->PaintBox1->Canvas->LineTo(50*10,50*i);

			Form4->PaintBox1->Canvas->MoveTo(50*i,0);
			Form4 ->PaintBox1->Canvas->LineTo(50*i,50*10);

		}
	   Form4 ->PaintBox2->Width = 50*10+1;
	   Form4 ->PaintBox2->Height = 50*10+1;
	   Form4->PaintBox2->Repaint();
	   for (int i = 0; i <= 11; i++)
	   {

		 Form4->PaintBox2->Canvas->MoveTo(0,50*i);
		 Form4 ->PaintBox2->Canvas->LineTo(50*10,50*i);


		 Form4->PaintBox2->Canvas->MoveTo(50*i,0);
		 Form4 ->PaintBox2->Canvas->LineTo(50*i,50*10);

	   }
	   Form5->Close();
	}
	else
	{
	bool knopka2=true;
    for(int k= corabli2.size()-1; k>=0;k--)
		{
			for(int i=corabli2[k].Rect.Left/50-6;i<corabli2[k].Rect.Right/50-6;i++)  {
				for(int j=corabli2[k].Rect.Top/50-1;j<corabli2[k].Rect.Bottom/50-1;j++){
				if (i<10 && i>=0 && j<10 && j>=0)
					pozcorabl2[i][j]=true;
					else{
						knopka2=false;
						break;
                    }
				}
			}
		}
		if(knopka2){
        Form2->Show();
		Form2 ->PaintBox1->Width = 50*10+1;
		Form2 ->PaintBox1->Height = 50*10+1;
		Form2->PaintBox1->Repaint();
		for (int i = 0; i <= 11; i++)
		{

			Form2->PaintBox1->Canvas->MoveTo(0,50*i);
			Form2 ->PaintBox1->Canvas->LineTo(50*10,50*i);


			Form2->PaintBox1->Canvas->MoveTo(50*i,0);
			Form2 ->PaintBox1->Canvas->LineTo(50*i,50*10);

		}
		Form2 ->PaintBox2->Width = 50*10+1;
		Form2 ->PaintBox2->Height = 50*10+1;
		Form2->PaintBox2->Repaint();
		for (int i = 0; i <= 11; i++)
		{

		 Form2->PaintBox2->Canvas->MoveTo(0,50*i);
		 Form2 ->PaintBox2->Canvas->LineTo(50*10,50*i);


		 Form2->PaintBox2->Canvas->MoveTo(50*i,0);
		 Form2 ->PaintBox2->Canvas->LineTo(50*i,50*10);
		}
		 Form5->Close();
		}
	}

}

void __fastcall TForm5::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if ((Key == 'R' || Key == 'r') && drag2) {
		 int x2=corabli2[DragInd2].Rect.Right-corabli2[DragInd2].Rect.Left;
		 int y2=corabli2[DragInd2].Rect.Bottom-corabli2[DragInd2].Rect.Top;
		 corabli2[DragInd2].Rect.Right+=y2-x2;
		 corabli2[DragInd2].Rect.Bottom+=x2-y2;
		 PaintBox1->Invalidate();
   }
}
//---------------------------------------------------------------------------

