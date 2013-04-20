//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cjpdFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TpdFrm *pdFrm;
//---------------------------------------------------------------------------
__fastcall TpdFrm::TpdFrm(TComponent* Owner,TADOConnection *conn)
	: TForm(Owner)
{
	DBconn=conn;
	RS->Connection=conn;
	RS->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TpdFrm::FormCreate(TObject *Sender)
{
	  cbSubjects->Items->Clear();
	  for(int i=0;i<4;i++){
		   cbSubjects->Items->Add(Subjects[i]);
	  }
	  if(DBconn==NULL){
		   ShowMessage("DBConn is null");
	  } else{

	  }
}
//---------------------------------------------------------------------------
void __fastcall TpdFrm::Button1Click(TObject *Sender)
{

	UnicodeString filterString="";
	if(isMale->Checked)
		filterString="sex=1" ;
	else
		filterString="sex=2"  ;
	RS->Filter=filterString + " and kslb="+ IntToStr(cbSubjects->ItemIndex+1);
	RS->Filtered=true;
}
//---------------------------------------------------------------------------


