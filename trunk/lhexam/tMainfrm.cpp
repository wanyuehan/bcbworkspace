// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tMainfrm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainFrm *MainFrm;
UnicodeString subjects[2] = {"物理", "化学"};
UnicodeString csubject = "";
int turnflag = 0;

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::LoadKD() {

	dm->QRY->SQL->Text = "select * from rqkdb order by FRQKD";
	dm->QRY->Active = true;
	cbKD->Items->Clear();
	dm->QRY->First();
	while (!dm->QRY->Eof) {
		cbKD->Items->Add(dm->QRY->FieldByName("FRQKD")->AsString + "  " +
			dm->QRY->FieldByName("FKDMC")->AsString);
		dm->QRY->Next();
	}
	dm->QRY->Active = false;
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::LoadCol() {

	  UnicodeString tempsubject="";
	  if(csubject=="物理"){
			tempsubject="WL";
	  }else if(csubject=="化学"){
      		tempsubject="HX";
	  }
	  tempsubject+=IntToStr(turnflag+1);
	  dbGrid->Columns->Items[2]->FieldName=tempsubject;
	  dbGrid->Columns->Items[2]->Title->Caption=csubject;
}

// ---------------------------------------------------------------------------

void __fastcall TMainFrm::RestCol() {
	  dbGrid->Columns->Items[2]->FieldName="";
	  dbGrid->Columns->Items[2]->Title->Caption="";
}

// ---------------------------------------------------------------------------
__fastcall TMainFrm::TMainFrm(TComponent* Owner, int subject, int turns,
	bool isAdmin) : TForm(Owner) {
	pFrm = (TForm*)Owner;
	csubject = subjects[subject];
	turnflag = turns;
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::FormClose(TObject *Sender, TCloseAction &Action) {
	pFrm->Show();
	Action=caFree;

}
// ---------------------------------------------------------------------------

void __fastcall TMainFrm::btEnterClick(TObject *Sender) {
	if (StrToInt(meKC->Text) > 0 && cbKD->ItemIndex > -1) // 所有输入合法
	{
		cbKD->Enabled = false;
		meKC->Enabled = false;
		btEnter->Enabled = false;

	}
	else {
		return;
	}
	dm->RS->Active = true;
	dm->RS->Filter = Format("kddm='%s' and kcdm=%s",
		ARRAYOFCONST((cbKD->Items->Strings[cbKD->ItemIndex].SubString(2, 3),
		meKC->Text)));
	dm->RS->Filtered = true;
	LoadCol();
}
// ---------------------------------------------------------------------------

void __fastcall TMainFrm::FormCreate(TObject *Sender) {
	if (dm == NULL)
		dm = new Tdm(this);
	LoadKD();
	lbSubject->Caption = Format("当前输入科目:《%s》第 %d 轮",
		ARRAYOFCONST((csubject, turnflag + 1)));
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::btResetClick(TObject *Sender)
{
		cbKD->Enabled = true;
		meKC->Enabled = true;
		btEnter->Enabled = true;
        dm->RS->Active = false;
		RestCol() ;
}

//---------------------------------------------------------------------------

