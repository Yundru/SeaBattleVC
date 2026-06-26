//---------------------------------------------------------------------------

#ifndef statisticH
#define statisticH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class Tstat : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	void __fastcall Memo1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tstat(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tstat *stat;
//---------------------------------------------------------------------------
#endif
