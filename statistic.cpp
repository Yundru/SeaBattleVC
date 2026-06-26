//---------------------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <vcl.h>
#pragma hdrstop

#include "statistic.h"
#include "Unit2.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern int player1schet;
extern int player1promah;
extern int player2schet;
extern int player2promah;
extern int playerschet;
extern int playerpromah;
extern int robotschet;
extern int robotpromah;

Tstat *stat;
//---------------------------------------------------------------------------
__fastcall Tstat::Tstat(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tstat::FormActivate(TObject *Sender)
{
	Memo1->Lines->Clear();

	// ÏÐÎÂÅÐÊÀ: Áûëè ëè âîîáùå èãðû?
	int totalActions = player1schet + player1promah + player2schet + player2promah +
	                   playerschet + playerpromah + robotschet + robotpromah;

	if (totalActions == 0)
	{
		Memo1->Lines->Add("=== ÈÍÔÎÐÌÀÖÈß ===");
		Memo1->Lines->Add("Èãð åù¸ íå áûëî. Ñòàòèñòèêà íåäîñòóïíà.");
		return;
	}

	if ((playerschet + playerpromah + robotschet + robotpromah) > 0)
	{   // === ÑÒÀÒÈÑÒÈÊÀ ÏÎÑËÅÄÍÅÉ ÈÃÐÛ === \\
		// === ÈÃÐÀ Ñ ÐÎÁÎÒÎÌ ===
		Memo1->Lines->Add("=== ÑÒÀÒÈÑÒÈÊÀ ÈÃÐÛ Ñ ÐÎÁÎÒÎÌ ===");
		Memo1->Lines->Add(String("Âàø ñ÷åò: ") + playerschet);
		Memo1->Lines->Add(String("Âàøè ïðîìàõè: ") + playerpromah);
		Memo1->Lines->Add(String("Ñ÷åò Ðîáîòà: ") + robotschet);
		Memo1->Lines->Add(String("Ïðîìàõè Ðîáîòà: ") + robotpromah);
	}
	else
	{   // === ÑÒÀÒÈÑÒÈÊÀ ÏÎÑËÅÄÍÅÉ ÈÃÐÛ === \\
		// === ÈÃÐÀ ×ÅËÎÂÅÊÀ Ñ ×ÅËÎÂÅÊÎÌ ===
		Memo1->Lines->Add("=== ÑÒÀÒÈÑÒÈÊÀ: ÈÃÐÎÊ VS ÈÃÐÎÊ ===");
		Memo1->Lines->Add(String("Ñ÷åò Èãðîêà 1: ") + player1schet);
		Memo1->Lines->Add(String("Ïðîìàõè Èãðîêà 1: ") + player1promah);
		Memo1->Lines->Add(String("Ñ÷åò Èãðîêà 2: ") + player2schet);
		Memo1->Lines->Add(String("Ïðîìàõè Èãðîêà 2: ") + player2promah);
	}

	// Ñîõðàíÿåì àêòóàëüíûé ðåæèì â ôàéë
	Memo1->Lines->SaveToFile("statistics.txt");
}
//---------------------------------------------------------------------------

