//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *file1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *help1;
	TMenuItem *help2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button4;
	void __fastcall help2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
extern bool playrobot;
//---------------------------------------------------------------------------
#endif
