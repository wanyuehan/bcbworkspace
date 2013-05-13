//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TSvrFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSvrFrm *SvrFrm;
TfrmEdit *frmEdit;
//---------------------------------------------------------------------------
__fastcall TSvrFrm::TSvrFrm(TComponent* Owner)
	: TForm(Owner)
{
	frmEdit=new TfrmEdit(this);
}
//---------------------------------------------------------------------------
void __fastcall TSvrFrm::btCheckClick(TObject *Sender)
{
  dm->CHKRS->Active=false;
  dm->CHKRS->Active=true;
  dm->CHKRS->First() ;
  int cnt=1;
  for(int i=0;i<dm->CHKRS->RecordCount;i++){
      Application->ProcessMessages();
	  if(fabs(dm->CHKRS->FieldByName("FWL1")->AsFloat-dm->CHKRS->FieldByName("FWL2")->AsFloat)<0.001){
			dm->CHKRS->Edit();
			dm->CHKRS->FieldByName("FWL")->AsFloat=dm->CHKRS->FieldByName("FWL1")->AsFloat;
	  }else{
		 frmEdit->Caption=dm->CHKRS->FieldByName("FZKH")->AsAnsiString+"  "+dm->CHKRS->FieldByName("Fxm")->AsAnsiString;
         frmEdit->ShowModal();
		 mmo->Lines->Add(IntToStr(cnt++)+" | "+ dm->CHKRS->FieldByName("FZKH")->AsAnsiString+" | "+dm->CHKRS->FieldByName("FLHJSH")->AsAnsiString+" | 科目物理 | "+dm->CHKRS->FieldByName("kddm")->AsAnsiString);
	  }
	  if(fabs(dm->CHKRS->FieldByName("Fhx1")->AsFloat-dm->CHKRS->FieldByName("Fhx2")->AsFloat)<0.001){
			dm->CHKRS->Edit();
			dm->CHKRS->FieldByName("Fhx")->AsFloat=dm->CHKRS->FieldByName("Fhx1")->AsFloat;
	  }else{
	     frmEdit->Caption=dm->CHKRS->FieldByName("FZKH")->AsAnsiString+"  "+dm->CHKRS->FieldByName("Fxm")->AsAnsiString;
	     frmEdit->ShowModal();
		 mmo->Lines->Add(IntToStr(cnt++)+" | "+ dm->CHKRS->FieldByName("FZKH")->AsAnsiString+" | "+dm->CHKRS->FieldByName("FLHJSH")->AsAnsiString+" | 科目化学 | "+dm->CHKRS->FieldByName("kddm")->AsAnsiString);
	  }
	  dm->CHKRS->UpdateBatch(arAll);
	  dm->CHKRS->Next() ;

  }
}
//---------------------------------------------------------------------------
