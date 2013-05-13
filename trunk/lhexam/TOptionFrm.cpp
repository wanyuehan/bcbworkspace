//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TOptionFrm.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOptionFrm *OptionFrm;
UnicodeString arrSubjects[2]={"����","��ѧ"};
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
  if(rgKM->ItemIndex>-1&&rgTurns->ItemIndex>-1) //������Ч
  {
	 if(MessageBox(this->Handle,UnicodeString("��ѡ�������Ŀ����:"+arrSubjects[rgKM->ItemIndex]+"\r\n������:��"+(rgTurns->ItemIndex+1)+"�֣��Ƿ���ȷ��").t_str() ,L"ϵͳ��ʾ",MB_YESNO)==IDNO)
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
  }else//������Ч
  {
	MessageBox(this->Handle,L"����δ�����в�����������������!",L"ϵͳ��ʾ",MB_OK);
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

