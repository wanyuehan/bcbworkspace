//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InputSide.h"
#include "Unit2.h"
#include "common.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TForm2 *TURNFORM=NULL;
int xkid1=-1,xkid2=-1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
		: TForm(Owner)
{
        TURNS=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

        if(TURNFORM==NULL)TURNFORM=new TForm2(Form1);
        TURNFORM->ShowModal();
        INFOPANEL->Caption="第 "+IntToStr(TURNS)+" 轮输入操作员";
        WORKRS->Active=false;
        WORKRS->SQL->Text="SELECT FBMDMC,FBMDDM FROM BMDDMB";
        WORKRS->Active=true;
        WORKRS->First();
        BMDLIST->Clear();
        while(!WORKRS->Eof){
             BMDLIST->Items->Add(WORKRS->FieldByName("FBMDDM")->AsString+" "+WORKRS->FieldByName("FBMDMC")->AsString);
             WORKRS->Next();
        }
        WORKRS->Active=false;
        BMDLIST->SetFocus();
		tx_cj1->Text=FormatFloat(Formatstr[2],000);
		tx_cj2->Text=FormatFloat("00",00);
		tx_xkcj->Text=FormatFloat(Formatstr[0],0.0);
		XKLB->Items->Clear();
		for(int i=0;i<ChoiceCount;i++ ){
              XKLB->Items->Add(ChoiceStr[i]);
		}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FILTERClick(TObject *Sender)
{
        if(BMDLIST->ItemIndex<0||XKLB->ItemIndex<0||SEXCB->ItemIndex<0||GROUPID->Text.Trim()==""){
			  ShowMessage("必填项没有填写完整");
			  Abort();
        }
        AnsiString FilterString="fbmddm="+BMDLIST->Text.SubString(0,4);
        FilterString+=" and kslb="+IntToStr(XKLB->ItemIndex+1);
        FilterString+=" and sex="+IntToStr(SEXCB->ItemIndex+1);
        FilterString+=" and groupid="+GROUPID->Text;
        RS1->Active=false;
        RS1->Active=true;
        RS1->Filter=FilterString;
        RS1->Filtered=true;
		GroupBox2->Caption="本组学生数量 " + IntToStr(RS1->RecordCount) + "人";
        if(TURNS!=RS1->FieldByName("flag")->AsInteger+1)
        {
            ShowMessage("本组已经输入过"+RS1->FieldByName("flag")->AsString+"轮，您不是本组本轮的输入人员");
            RS1->Active=false;
			Abort();
        }
       INFOPANEL->Caption="第 "+ IntToStr(TURNS)+" 轮输入";
       LoadCol();
       tx_cj1->SetFocus();
       SetCTL(false);
}

void __fastcall TForm1::LoadCol(){


	  xkid1=Choice[XKLB->ItemIndex]/10-1;
	  xkid2=Choice[XKLB->ItemIndex]%10-1;

	  //更新选考科目录入框组件
	  Label6->Caption=Subjects[xkid1];
	  tx_cj1->EditMask=Masks[xkid1];
	  Label7->Caption=Subjects[xkid2];
	  tx_cj2->EditMask=Masks[xkid2];
	  //更新数据网格
	  TColumn *newcol=DG->Columns->Items[3];
	  newcol->Title->Caption=Subjects[xkid1];
	  newcol->FieldName="CJ1"+IntToStr(TURNS);

	  newcol->ReadOnly=false;

	  newcol=DG->Columns->Items[4];
	  newcol->Title->Caption=Subjects[xkid2];
	  newcol->FieldName="CJ2"+IntToStr(TURNS);

	  newcol->ReadOnly=false;

	  newcol=DG->Columns->Items[5];
	  newcol->Title->Caption="长跑";
	  newcol->FieldName="XK_CJ"+IntToStr(TURNS);
	  newcol->ReadOnly=false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetCTL(bool state){
        BMDLIST->Enabled=state;
        XKLB->Enabled=state;
        SEXCB->Enabled=state;
        GROUPID->Enabled=state;
        FILTER->Enabled=state;
}

void __fastcall TForm1::tx_cj2KeyPress(TObject *Sender, char &Key)
{
        RS1->Edit();
        RS1->FieldByName("flag")->AsInteger=TURNS;
		if((int)Key==13)
		{RS1->FieldByName("CJ2"+IntToStr(TURNS))->AsString=tx_cj2->Text;
				tx_xkcj->SetFocus();
        }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::tx_xkcjKeyPress(TObject *Sender, char &Key)
{
        RS1->Edit();
        RS1->FieldByName("flag")->AsInteger=TURNS;
        if((int)Key==13)
		{RS1->FieldByName("XK_CJ"+IntToStr(TURNS))->AsString=tx_xkcj->Text;
         if(!RS1->Eof)NextRC();
         }

}
//---------------------------------------------------------------------------



void __fastcall TForm1::tx_cj1KeyPress(TObject *Sender, char &Key)
{

        try{
        RS1->Edit();
		  RS1->FieldByName("flag")->AsInteger=TURNS;
        if((int)Key==13){
		RS1->FieldByName("cj1"+IntToStr(TURNS))->AsString=tx_cj1->Text;
		tx_cj2->SetFocus();
        }
        }catch(Exception &e){
				Application->MessageBoxA(L"您输入的格式不正确，请按ESC重新输入",L"格式错误",MB_ICONWARNING|MB_OK);
				Abort();

        }


}
//---------------------------------------------------------------------------
void  __fastcall TForm1::NextRC(){
       if(RS1->Eof)Abort();
        RS1->Next();
		tx_cj1->Text=RS1->FieldByName("cj1"+IntToStr(TURNS))->AsString;
		tx_cj2->Text=RS1->FieldByName("CJ2"+IntToStr(TURNS))->AsString;
		tx_xkcj->Text=RS1->FieldByName("XK_CJ"+IntToStr(TURNS))->AsString;
        RS1->Edit();
        tx_cj1->SetFocus();

}

void __fastcall TForm1::RS1AfterEdit(TDataSet *DataSet)
{
          SAVEBT->Enabled=true;
          CancelBT->Enabled=true;
}
//---------------------------------------------------------------------------







void __fastcall TForm1::SAVEBTClick(TObject *Sender)
{
		if(Application->MessageBoxA(L"是否保存本轮的输入？",L"保存操作",MB_YESNO | MB_ICONWARNING)==IDYES){
        RS1->UpdateBatch(arAll);
		ShowMessage("本轮输入保存完毕");
        RS1->Active=false;
		SetCTL(true);
		xkid1=-1;
		xkid2=-1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CancelBTClick(TObject *Sender)
{
        if(RS1->Modified)
		SetCTL(true);
		xkid1=-1;
		xkid2=-1;
        RS1->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GROUPIDKeyPress(TObject *Sender, char &Key)
{
        if((int)Key==13)FILTER->SetFocus();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        RS1->Active=false;
		SetCTL(true);
		xkid1=-1;
		xkid2=-1;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::tx_cj1KeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
        if(Key==39)Abort();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GROUPIDKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==39)Abort();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tx_cj2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==39)Abort();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tx_xkcjKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==39)Abort();        
}
//---------------------------------------------------------------------------




void __fastcall TForm1::DGCellClick(TColumn *Column)
{
        RS1->Edit();
        if(RS1->Active){
		tx_cj1->Text=RS1->FieldByName("CJ1"+IntToStr(TURNS))->AsString;
		tx_cj2->Text=RS1->FieldByName("CJ2"+IntToStr(TURNS))->AsString;
		tx_xkcj->Text=RS1->FieldByName("XK_CJ"+IntToStr(TURNS))->AsString;
        }
}
//---------------------------------------------------------------------------




