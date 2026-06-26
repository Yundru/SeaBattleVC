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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool playrobot=false;
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
	   playrobot=false;
	   Form3 ->Show();
	   Form3 ->PaintBox1->Width = 300+50*10+1;
	   Form3 ->PaintBox1->Height = 50*10+1+50;
	   Form3->PaintBox1->Repaint();
	   
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	   Form5 ->Show();
	   Form5 ->PaintBox1->Width = 300+50*10+1;
	   Form5 ->PaintBox1->Height = 50*10+1+50;
	   Form5->Label1->Caption="Player's field";
	   Form5->PaintBox1->Repaint();
	   playrobot = true;
	   /*
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++) {
				pozvistrplayer[i][j] = false;
				pozvistrrobot[i][j] = false;
			}
	   Form4 ->Show();
	   Form4 ->PaintBox1->Width = 50*10+1;
	   Form4 ->PaintBox1->Height = 50*10+1;
	   Form4->PaintBox1->Repaint();
	   for (int i = 0; i <= 11; i++) {

		 Form4->PaintBox1->Canvas->MoveTo(0,50*i);
		 Form4 ->PaintBox1->Canvas->LineTo(50*10,50*i);


		 Form4->PaintBox1->Canvas->MoveTo(50*i,0);
		 Form4 ->PaintBox1->Canvas->LineTo(50*i,50*10);

	   }
	   Form4 ->PaintBox2->Width = 50*10+1;
	   Form4 ->PaintBox2->Height = 50*10+1;
	   Form4->PaintBox2->Repaint();
	   for (int i = 0; i <= 11; i++) {

		 Form4->PaintBox2->Canvas->MoveTo(0,50*i);
		 Form4 ->PaintBox2->Canvas->LineTo(50*10,50*i);


		 Form4->PaintBox2->Canvas->MoveTo(50*i,0);
		 Form4 ->PaintBox2->Canvas->LineTo(50*i,50*10);

	   }
		*/
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	stat->Show();
}
//---------------------------------------------------------------------------

