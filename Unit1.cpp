//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "About.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n=3;
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
	   Form2 ->Show();
	   Form2 ->PaintBox1->Width = 50*10+1;
	   Form2 ->PaintBox1->Height = 50*10+1;
	   Form2->PaintBox1->Repaint();
	   for (int i = 0; i <= 11; i++) {

		 Form2->PaintBox1->Canvas->MoveTo(0,50*i);
		 Form2 ->PaintBox1->Canvas->LineTo(50*10,50*i);


		 Form2->PaintBox1->Canvas->MoveTo(50*i,0);
		 Form2 ->PaintBox1->Canvas->LineTo(50*i,50*10);

	   }
	   Form2 ->PaintBox2->Width = 50*10+1;
	   Form2 ->PaintBox2->Height = 50*10+1;
	   Form2->PaintBox2->Repaint();
	   for (int i = 0; i <= 11; i++) {

		 Form2->PaintBox2->Canvas->MoveTo(0,50*i);
		 Form2 ->PaintBox2->Canvas->LineTo(50*10,50*i);


		 Form2->PaintBox2->Canvas->MoveTo(50*i,0);
		 Form2 ->PaintBox2->Canvas->LineTo(50*i,50*10);

	   }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	   Form3 ->Show();
	   Form3 ->PaintBox1->Width = 300+50*10+1;
	   Form3 ->PaintBox1->Height = 50*10+1;
	   Form3->PaintBox1->Repaint();
	   for (int i = 0; i <= 11; i++) {

		 Form3->PaintBox1->Canvas->MoveTo(300+0,50*i);
		 Form3 ->PaintBox1->Canvas->LineTo(300+50*10,50*i);


		 Form3->PaintBox1->Canvas->MoveTo(300+50*i,0);
		 Form3 ->PaintBox1->Canvas->LineTo(300+50*i,50*10);

	   }
}
//---------------------------------------------------------------------------

