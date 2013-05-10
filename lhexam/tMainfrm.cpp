// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tMainfrm.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainFrm *MainFrm;
UnicodeString subjects[2] = {"物理", "化学"};
bool isDirty = false;
int turnflag = 0, lhflag = 3,another=-1;

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
void __fastcall TMainFrm::SetEnable(bool isEnabled){
	meScore->Enabled=isEnabled;
	btAnotherSubject->Enabled=isEnabled;
	btNext->Enabled=isEnabled;
	btPrev->Enabled=isEnabled;
	btSave->Enabled=isEnabled;
	btCancel->Enabled=isEnabled;
}


void __fastcall TMainFrm::LoadCol() {

	UnicodeString tempsubject = "FLH";
	tempsubject += IntToStr(turnflag + 1);
	dbGrid->Columns->Items[2]->FieldName = tempsubject;
	dbGrid->Columns->Items[2]->Title->Caption = subjects[lhflag];
}

// ---------------------------------------------------------------------------
void __fastcall  TMainFrm::SeekRow() {
	while(dm->RS->Eof==false){
		if(dm->RS->FieldByName("FLHFLAG")->AsInteger==lhflag){
			break;
		}
		dm->RS->Next();
	}
	dm->RS->Edit();
	meScore->Text=FormatFloat("00.00",
	dm->RS->FieldByName(dbGrid->Columns->Items[2]->FieldName)->AsFloat);
	dbGrid->SelectedIndex=dm->RS->RecNo-1;
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::RestCol() {
	dbGrid->Columns->Items[2]->FieldName = "";
	dbGrid->Columns->Items[2]->Title->Caption = "";
}

// ---------------------------------------------------------------------------
__fastcall TMainFrm::TMainFrm(TComponent* Owner) : TForm(Owner) {
	pFrm = (TForm*)Owner;

}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::FormClose(TObject *Sender, TCloseAction &Action) {
	pFrm->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TMainFrm::InitData(int subject, int turns, bool isAdmin) {
	turnflag = turns;
	lhflag = subject;
	if(subject==0)another=1;
	else another=0;
	InitControl();
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
	SetEnable(true);
	dm->QRY->Active = false;
	dm->QRY->SQL->Text =
		Format("select * from lhresault where flag>%d and kddm='%s' and kcdm='%s' and flhflag=%d",
		ARRAYOFCONST((turnflag, cbKD->Items->Strings[cbKD->ItemIndex].SubString
		(2, 3), meKC->Text, lhflag)));
	dm->QRY->Active = true;
	if (dm->QRY->RecordCount > 0) {
		ShowMessage("您不是本轮的输入人员！");
		cbKD->Enabled = true;
		meKC->Enabled = true;
		return;
	}
	dm->QRY->Active = false;
	dm->RS->Active = true;
	dm->RS->Filter = Format("kddm='%s' and kcdm='%s'",
		ARRAYOFCONST((cbKD->Items->Strings[cbKD->ItemIndex].SubString(2, 3),
		meKC->Text)));
	dm->RS->Filtered = true;
	LoadCol();
	pmsg->Caption = Format("在考点 %s 参加 第 %s 次考试的学生共有 %d 人",
		ARRAYOFCONST((cbKD->Items->Strings[cbKD->ItemIndex], meKC->Text,
		dm->RS->RecordCount)));
	dm->RS->Edit();
	meScore->Text = FormatFloat("00.00",dm->RS->FieldByName(dbGrid->Columns->Items[2]->FieldName)->AsFloat);
	meScore->SetFocus();
	btEnter->Enabled = false;
	btReset->Enabled = true;
	SeekRow();
}
// ---------------------------------------------------------------------------

void __fastcall TMainFrm::btResetClick(TObject *Sender) {
	dm->RS->Active = false;
	cbKD->Enabled = true;
	meKC->Enabled = true;
	btEnter->Enabled = true;
	btReset->Enabled = false;
	RestCol();
	SetEnable(false);
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
		if(turnflag>0&&fabs(StrToFloat(meScore->Text)-dm->RS->FieldByName("FLH1")->AsFloat)>0.001){
			if(Application->MessageBoxW(L"两次输入的成绩不同，如果确认本次输入无误请按确认，否则请按取消",L"科目成绩不同提示",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL)==IDNO){
                   return;
			}
		}
		if(dm->RS->FieldByName("flag")->AsInteger==0){//第一次输入 尚未确定科目类别 则直接写入
			dm->RS->FieldByName(dbGrid->Columns->Items[2]->FieldName)->AsFloat =StrToFloat(meScore->Text);
			dm->RS->FieldByName("flag")->AsInteger = turnflag + 1;
			dm->RS->FieldByName("FLHFLAG")->AsInteger = lhflag;
		}else if(dm->RS->FieldByName("FLHFLAG")->AsInteger!=lhflag){//已输入一次科目类别 可能误输入 与当前输入类别不同
			UnicodeString t=Format("该考生已经录入了%s的成绩，无法录入%s的成绩。如果您认为你输入的是正确的，请按确定按钮，将改写数据库中原有的记录",ARRAYOFCONST((subjects[dm->RS->FieldByName("FLHFLAG")->AsInteger],subjects[lhflag])));
			if(Application->MessageBoxW(t.w_str(),L"科目类别冲突提示",MB_YESNO|MB_ICONQUESTION|MB_SYSTEMMODAL)==IDYES){
			  dm->RS->FieldByName(dbGrid->Columns->Items[2]->FieldName)->AsFloat =StrToFloat(meScore->Text);
			  dm->RS->FieldByName("flag")->AsInteger = turnflag + 1;
			  dm->RS->FieldByName("FLHFLAG")->AsInteger = lhflag;
			}
		}
		dm->RS->Next() ;
		SeekRow();
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
void __fastcall TMainFrm::InitControl() {
	if (dm == NULL)
		dm = new Tdm(this);
	LoadKD();
	lbSubject->Caption = Format("当前输入科目:《%s》第 %d 轮",ARRAYOFCONST((subjects[lhflag], turnflag + 1)));
	btAnotherSubject->Caption=Format("标记为%s考生",ARRAYOFCONST((subjects[another])));
}

void __fastcall TMainFrm::meScoreChange(TObject *Sender) {
	isDirty = true;
}
// ---------------------------------------------------------------------------
void __fastcall TMainFrm::dbGridCellClick(TColumn *Column)
{
   if(dm->RS->Active){
		dm->RS->Edit() ;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::btAnotherSubjectClick(TObject *Sender)
{
		  dm->RS->FieldByName("flhflag")->AsInteger=another;
		  btNext->Click();
}
//---------------------------------------------------------------------------


