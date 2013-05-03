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

	UnicodeString tempsubject = "";
	if (csubject == "物理") {
		tempsubject = "FWL";
	}
	else if (csubject == "化学") {
		tempsubject = "FHX";
	}
	tempsubject += IntToStr(turnflag + 1);
	dbGrid->Columns->Items[2]->FieldName = tempsubject;
	dbGrid->Columns->Items[2]->Title->Caption = csubject;
}

// ---------------------------------------------------------------------------

void __fastcall TMainFrm::RestCol() {
	dbGrid->Columns->Items[2]->FieldName = "";
	dbGrid->Columns->Items[2]->Title->Caption = "";
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
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::InitData(int subject, int turns, bool isAdmin) {
	csubject = subjects[subject];
	turnflag = turns;
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::btEnterClick(TObject *Sender) {
	if (StrToInt(meKC->Text) > 0 && cbKD->ItemIndex > -1) // 所有输入合法
	{
		cbKD->Enabled = false;
		meKC->Enabled = false;

	}
	else {
		return;
	}
	dm->QRY->Active = false;
	dm->QRY->SQL->Text =
		Format("select * from lhresault where flag>%d and kddm='%s' and kcdm=%s"
		, ARRAYOFCONST((turnflag,
		cbKD->Items->Strings[cbKD->ItemIndex].SubString(2, 3), meKC->Text)));
	dm->QRY->Active = true;
	if (dm->QRY->RecordCount > 0) {
		ShowMessage("您不是本轮的输入人员！");
		cbKD->Enabled = true;
		meKC->Enabled = true;
		return;
	}
	dm->QRY->Active = false;
	dm->RS->Active = true;
	dm->RS->Filter = Format("kddm='%s' and kcdm=%s",
		ARRAYOFCONST((cbKD->Items->Strings[cbKD->ItemIndex].SubString(2, 3),
		meKC->Text)));
	dm->RS->Filtered = true;
	LoadCol();
	pmsg->Caption = Format("在考点 %s 参加 第 %s 次考试的学生共有 %d 人",
		ARRAYOFCONST((cbKD->Items->Strings[cbKD->ItemIndex], meKC->Text,
		dm->RS->RecordCount)));
	dm->RS->Edit();
	meScore->Text = FormatFloat("00.00",
		dm->RS->FieldByName(dbGrid->Columns->Items[2]->FieldName)->AsFloat);
	meScore->SetFocus();
	btEnter->Enabled = false;
	btReset->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TMainFrm::btResetClick(TObject *Sender) {
	dm->RS->Active = false;
	cbKD->Enabled = true;
	meKC->Enabled = true;
	btEnter->Enabled = true;
	btReset->Enabled = false;
	RestCol();
}

// ---------------------------------------------------------------------------

void __fastcall TMainFrm::btNextClick(TObject *Sender) {
	if (dm->RS->Active && dm->RS->Eof == false) {
		dm->RS->Next();
		meScore->Text =
			FormatFloat("00.00",
			dm->RS->FieldByName(dbGrid->Columns->Items[2]->FieldName)->AsFloat);
		dm->RS->Edit();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::meScoreKeyPress(TObject *Sender,
	System::WideChar &Key)

{
	if ((int)Key == 13) {
		dm->RS->FieldByName(dbGrid->Columns->Items[2]->FieldName)->AsFloat =
			StrToFloat(meScore->Text);
		dm->RS->FieldByName("flag")->AsInteger = turnflag + 1;
		btNext->Click();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainFrm::meKCKeyPress(TObject *Sender, System::WideChar &Key) {
	if ((int)Key == 13)
		btEnter->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TMainFrm::btSaveClick(TObject *Sender) {
	dm->RS->UpdateBatch(arAll);
	ShowMessage("数据保存成功!");
	btReset->Click();
}
// ---------------------------------------------------------------------------

void __fastcall TMainFrm::btCancelClick(TObject *Sender) {
	dm->RS->CancelBatch(arAll);
	btReset->Click();
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::FormCreate(TObject *Sender) {
   InitControl();
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::InitControl() {
      if (dm == NULL)
		dm = new Tdm(this);
	LoadKD();
	lbSubject->Caption = Format("当前输入科目:《%s》第 %d 轮",
		ARRAYOFCONST((csubject, turnflag + 1)));
}
