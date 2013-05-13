//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TFrmEdit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmEdit *frmEdit;
//---------------------------------------------------------------------------
__fastcall TfrmEdit::TfrmEdit(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmEdit::btSaveClick(TObject *Sender)
{
	UnicodeString tempCol="",clearCol="";
	if(cbSubject->ItemIndex==1){
		tempCol="FHX";
		clearCol="FWL";
	}else if(cbSubject->ItemIndex==0){
		tempCol="FWL";
		clearCol="FHX";
	}
	dm->CHKRS->Edit() ;
	dm->CHKRS->FieldByName(tempCol)->AsFloat=StrToFloat(meScore->Text);
	dm->CHKRS->FieldByName(clearCol)->AsFloat=0.0;
	dm->CHKRS->FieldByName(clearCol+1)->AsFloat=0.0;
	dm->CHKRS->FieldByName(clearCol+2)->AsFloat=0.0;
	dm->CHKRS->UpdateBatch(arAll);
	this->Close() ;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEdit::FormShow(TObject *Sender)
{
	meScore->Text="0.00";
	meScore->SelectAll() ;
	cbSubject->ItemIndex=-1;
}
//---------------------------------------------------------------------------
