//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tMainfrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainFrm *MainFrm;
//---------------------------------------------------------------------------
__fastcall TMainFrm::TMainFrm(TComponent* Owner,int subject,int turns,bool isAdmin)
	: TForm(Owner)
{
	pFrm=(TForm *)Owner;
}
//---------------------------------------------------------------------------
void __fastcall TMainFrm::FormClose(TObject *Sender, TCloseAction &Action)
{
	pFrm->Show() ;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::btEnterClick(TObject *Sender)
{
	if(cbKD->ItemIndex>0&&cbKSDATE->ItemIndex>0&& StrToInt(meKC->Text)>0)//所有输入合法
	{
	   cbKD->Enabled=false;
	   cbKSDATE->Enabled=false;
	   meKC->Enabled=false;
	   btEnter->Enabled=false;

	}else{
    	return;
	}
}
//---------------------------------------------------------------------------

