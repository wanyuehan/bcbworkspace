//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TOptionFrm.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOptionFrm *OptionFrm;
UnicodeString arrSubjects[2]={"物理","化学"};
//--------------------------------------------------------------------- 
__fastcall TOptionFrm::TOptionFrm(TComponent* AOwner)
	: TForm(AOwner)
{
	mainfrm=NULL;
	SvrFrm=NULL;
}
//---------------------------------------------------------------------



void __fastcall TOptionFrm::OKBtnKeyPress(TObject *Sender, System::WideChar &Key)

{
	  if(Key=='`'){
			btAdmin->Visible=! btAdmin->Visible ;
	   }
}
//---------------------------------------------------------------------------


void __fastcall TOptionFrm::FormCreate(TObject *Sender)
{
	FLAG_SUBJECT=-1;
	FLAG_TURN=0;
	FLAG_ADMIN=false;
}
//---------------------------------------------------------------------------

void __fastcall TOptionFrm::OKBtnClick(TObject *Sender)
{
  if(rgKM->ItemIndex>-1&&rgTurns->ItemIndex>-1) //输入有效
  {
	 if(MessageBox(this->Handle,UnicodeString("您选择输入科目的是:"+arrSubjects[rgKM->ItemIndex]+"\r\n轮数是:第"+(rgTurns->ItemIndex+1)+"轮，是否正确？").t_str() ,L"系统提示",MB_YESNO)==IDNO)
	 {
		return;
	 }else
	 {
		this->Hide();
		if(mainfrm!=NULL){
           mainfrm->Close();
		}
		mainfrm=new TMainFrm(this);
		mainfrm->InitData( rgKM->ItemIndex, rgTurns->ItemIndex,false);
		mainfrm->Show();
	 }
  }else//输入无效
  {
	MessageBox(this->Handle,L"您尚未将所有参数定义完整，请检查!",L"系统提示",MB_OK);
	return;
  }
}
//---------------------------------------------------------------------------

void __fastcall TOptionFrm::CancelBtnClick(TObject *Sender)
{
  this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TOptionFrm::btAdminClick(TObject *Sender)
{
		if(SvrFrm==NULL)SvrFrm=new TSvrFrm(this);
		SvrFrm->Show();
}
//---------------------------------------------------------------------------

