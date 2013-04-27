//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerForm.h"
#include "cjpdFrm.h"
#include <wyhexcel.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWYHEXCEL* wyhexcel=NULL;
TSvrForm *SvrForm;
TpdFrm *pdFrm=NULL;
float aNumber=0.00001;//单精度容差
UnicodeString filepath="";
long TOTAL=0,t0=0,t1=0,t2=0;

bool FloatEqual(float _x,float _y){
	return fabs(_x-_y)<aNumber;
}

AnsiString ParseNum(AnsiString num){
        AnsiString temp="";
		if(num.SubString(1,1)=="1")temp="男子";
		else  temp="女子";
		int choice=StrToInt(num.SubString(2,1));
		temp+=ChoiceStr[choice-1];
        temp+="第"+num.SubString(7,2)+"组"+"第"+num.SubString(9,2)+"位";
        return temp;
}

//---------------------------------------------------------------------------
__fastcall TSvrForm::TSvrForm(TComponent* Owner)
        : TForm(Owner)
{
	filepath=ExtractFilePath(Application->ExeName)+"\\成绩公示表.xlt";
}
//---------------------------------------------------------------------------

void __fastcall TSvrForm::btnExcSqlClick(TObject *Sender)
{
        if(Memo1->Text=="")Abort();
        RS->Active=false;
        RS->SQL=Memo1->Lines;
        RS->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TSvrForm::btnClrScoreClick(TObject *Sender)
{
 AnsiString Z=InputBox("清除某组成绩","请谨慎输入体育加试号的前8位如：12000101","00000000");
 if(Z.Trim().Length()<8)Abort();
 Memo1->Text="select * from resault where left(ftyjsh,8)='"+ Z +"' order by ftyjsh";
 btnExcSqlClick(Sender);
 CMD->CommandText=WideString("update resault set flag=0 where left(ftyjsh,8)='"+ Z +"'");
 CMD->Execute();
 RS->Active=false;
 RS->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TSvrForm::btnChkInputClick(TObject *Sender)
{
	AnsiString Z=InputBox("校验某报名点成绩","请谨慎输入四位报名点号码如：0001","0000");
	if(Z.Trim().Length()<4)Abort();
	int xkid1=-1,xkid2=-1;
	RS->Active=false;
	RS->SQL->Text="select * from resault order by ftyjsh";
	RS->Active=true;
	RS->Filter="bmddm="+Z.Trim();
	RS->Filtered=true;
	RS->First();
	while(!RS->Eof){
	if(RS->FieldByName("FLAG")->AsInteger!=2) {RS->Next();continue;}
		RS->Edit();
	Application->ProcessMessages();
		AnsiString Z="";
		int kslb=StrToInt(RS->FieldByName("kslb")->AsAnsiString)-1;
		xkid1=Choice[kslb]/10;
		xkid2=Choice[kslb]%10;
		bool x=true;
		if(!FloatEqual(RS->FieldByName("XK_CJ1")->AsFloat,RS->FieldByName("XK_CJ2")->AsFloat))
		{
		 reinput1:
			 Z="";
			 while(Z=="")Z=InputBox("两次输入成绩不一致","请谨慎输入"+ RS->FieldByName("FZKH")->AsString +" " +  RS->FieldByName("FXM")->AsString +" " +  ParseNum(RS->FieldByName("FTYJSH")->AsString) +"长跑最终体育成绩","");

			 if(!FloatEqual(Z.ToDouble(),RS->FieldByName("XK_CJ1")->AsFloat)&&!FloatEqual(Z.ToDouble(),RS->FieldByName("XK_CJ2")->AsFloat))
				if(Application->MessageBoxA(L"本次输入的成绩与其他两次均不一致，是否确认保存？",L"提示",MB_YESNO)==IDNO){x=false;goto reinput1;}

        }else
                 Z=FormatFloat(".00",RS->FieldByName("XK_CJ2")->AsFloat);
        if(x){
        RS->FieldByName("XK_CJ")->AsFloat=StrToFloat(Z);
		RS->FieldByName("XKFS")->AsFloat=ScoreParse(5,RS->FieldByName("sex")->AsInteger,RS->FieldByName("XK_CJ")->AsFloat);
        }
        x=true;
		Z="";

		if(!FloatEqual(RS->FieldByName("CJ11")->AsFloat,RS->FieldByName("CJ12")->AsFloat))
        {
			 reinput2:
			 Z="";
			 while(Z=="")Z=InputBox("两次输入成绩不一致","请谨慎输入"+ RS->FieldByName("FZKH")->AsString +" " +  RS->FieldByName("FXM")->AsString +" " + ParseNum(RS->FieldByName("FTYJSH")->AsString) + Subjects[xkid1-1] +"\n最终体育成绩","");
			 if(FloatEqual(Z.ToDouble(),RS->FieldByName("CJ11")->AsFloat)==false&&FloatEqual(Z.ToDouble(),RS->FieldByName("CJ12")->AsFloat)==false)
				if(Application->MessageBoxA(L"本次输入的成绩与其他两次均不一致，是否确认保存？",L"提示",MB_YESNO)==IDNO){x=false;goto reinput2;};
        }else
             Z=FormatFloat(".00",RS->FieldByName("CJ12")->AsFloat);
        if(x){
             RS->FieldByName("CJ1")->AsFloat=StrToFloat(Z);
			 RS->FieldByName("FS1")->AsFloat=ScoreParse(xkid1,RS->FieldByName("sex")->AsInteger,RS->FieldByName("CJ1")->AsFloat);
             }
        x=true;
        Z="";

		if(!FloatEqual(RS->FieldByName("CJ21")->AsFloat,RS->FieldByName("CJ22")->AsFloat))
        {
			 reinput3:
			 Z="";
			 while(Z=="")Z=InputBox("两次输入成绩不一致","请谨慎输入"+ RS->FieldByName("FZKH")->AsString +" " +  RS->FieldByName("FXM")->AsString + " " +  ParseNum(RS->FieldByName("FTYJSH")->AsString)+ Subjects[xkid2-1] +"\n最终体育成绩","");
			 if(!FloatEqual(Z.ToDouble(),RS->FieldByName("CJ21")->AsFloat)&& !FloatEqual(Z.ToDouble(),RS->FieldByName("CJ22")->AsFloat))
				if(Application->MessageBoxA(L"本次输入的成绩与其他两次均不一致，是否确认保存？",L"提示",MB_YESNO)==IDNO){x=false;goto reinput3;};
        }else
             Z=FormatFloat(".00",RS->FieldByName("CJ22")->AsFloat);
        if(x){
        RS->FieldByName("CJ2")->AsFloat=StrToFloat(Z);
		RS->FieldByName("FS2")->AsFloat=ScoreParse(xkid2,RS->FieldByName("sex")->AsInteger,RS->FieldByName("CJ2")->AsFloat);
       }
        Z="";
		RS->FieldByName("ZF")->AsFloat=RS->FieldByName("XKFS")->AsFloat+RS->FieldByName("FS1")->AsFloat+RS->FieldByName("FS2")->AsFloat;
		RS->FieldByName("ZF2")->AsFloat=floor(RS->FieldByName("ZF")->AsFloat * 4/3+0.5);
        RS->FieldByName("flag")->AsInteger=3;
        RS->Post();
        RS->Next();
    }
}
//---------------------------------------------------------------------------

void __fastcall TSvrForm::Timer1Timer(TObject *Sender)
{
        RS1->Active=false;
        RS1->SQL->Text="SELECT Count(*) AS TOTAL,FLAG FROM resault GROUP BY flag";
        RS1->Active=true;
        RS1->First();
        while(!RS1->Eof){
        switch(RS1->FieldByName("FLAG")->AsInteger){
                case 0:t0=RS1->FieldByName("total")->AsInteger;break;
                case 1:t1=RS1->FieldByName("total")->AsInteger;break;
                case 2:t2=RS1->FieldByName("total")->AsInteger;
        }
        RS1->Next();
        }
        if(TOTAL==0)TOTAL=t0+t1+t2;
        T1PB->Max=TOTAL;
        T1PB->Position=t1;
        T2PB->Max=TOTAL;
        T2PB->Position=t2;

		Label2->Caption=IntToStr(T1PB->Position)+" / "+   IntToStr((__int64)TOTAL) ;
		Label3->Caption=IntToStr(T2PB->Position)+" / "+   IntToStr((__int64)TOTAL) ;

}
//---------------------------------------------------------------------------

void __fastcall TSvrForm::FormCreate(TObject *Sender)
{
			Timer1->Interval=2000;
			Timer1->Enabled=true;
			MAINCONN->ConnectionString="FILE NAME="+ExtractFilePath(Application->ExeName)+"CONN.UDL";
}
//---------------------------------------------------------------------------

void __fastcall TSvrForm::TrackBar1Change(TObject *Sender)
{
         Timer1->Enabled=false; 
         Timer1->Interval=TrackBar1->Position*1000;
         Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

float __fastcall TSvrForm::ScoreParse(int kslb,int sex,float cj){

if(SCORERS->Active==false)SCORERS->Active=true;
            SCORERS->Filtered=false;
            SCORERS->Filter="KSLB="+ IntToStr(kslb)+" and sex=" + IntToStr(sex);
            SCORERS->Filtered=true;
			SCORERS->First();

            bool f=false;
            if(StrToFloat(FormatFloat(".00",cj))==0.0){return 0.0;}
			for(int i=1;i<=SCORERS->RecordCount;i++){
				 if(MaxFlag[kslb-1]){
						f=StrToFloat(FormatFloat(".00",cj))>=StrToFloat(FormatFloat(".00",SCORERS->FieldByName("CJ")->AsFloat));
                }else{
						f=StrToFloat(FormatFloat(".00",cj))<=StrToFloat(FormatFloat(".00",SCORERS->FieldByName("CJ")->AsFloat));
                }
                if(f){ return SCORERS->FieldByName("SCORE")->AsFloat;}
                SCORERS->Next();
            }
            return 0.0;
}








//---------------------------------------------------------------------------


void __fastcall TSvrForm::btnParseScoreClick(TObject *Sender)
{
	RS->Active=false;
    RS->SQL->Text="select * from resault where flag=2 and kslb<>7 order by ftyjsh ";
    RS->Active=true;
    RS->First();
	int i=0;
	int xkid1=-1,xkid2=-1;
    while(!RS->Eof){
	if(RS->FieldByName("FLAG")->AsInteger!=2) {RS->Next();continue;}
		RS->Edit();
	Application->ProcessMessages();
		int kslb=StrToInt(RS->FieldByName("kslb")->AsAnsiString)-1;
		xkid1=Choice[kslb]/10;
		xkid2=Choice[kslb]%10;
		RS->FieldByName("FS1")->AsFloat=ScoreParse(xkid1,RS->FieldByName("sex")->AsInteger,RS->FieldByName("CJ1")->AsFloat);
        RS->FieldByName("FS2")->AsFloat=ScoreParse(xkid2,RS->FieldByName("sex")->AsInteger,RS->FieldByName("CJ2")->AsFloat);
		RS->FieldByName("XKFS")->AsFloat=ScoreParse(5,RS->FieldByName("sex")->AsInteger,RS->FieldByName("XK_CJ")->AsFloat);
		RS->FieldByName("ZF")->AsFloat=RS->FieldByName("XKFS")->AsFloat+RS->FieldByName("FS1")->AsFloat+RS->FieldByName("FS2")->AsFloat;
        RS->FieldByName("ZF2")->AsFloat=floor(RS->FieldByName("ZF")->AsFloat * 4/3+0.5);
        RS->FieldByName("flag")->AsInteger=3;
		RS->Post();
        RS->Next();
}
}
//---------------------------------------------------------------------------

void __fastcall TSvrForm::btnPrintClick(TObject *Sender)
{
    AnsiString Z=InputBox("打印某报名点成绩","请谨慎输入四位报名点号码如：0001","0000");
	if(Z.Trim().Length()<4)Abort();
	RS->Active=false;
	RS->SQL->Text="select * from resault where flag<>3 AND bmddm='"+Z+"'";
	RS->Active=true;
	if(RS->RecordCount>0){
	   Application->MessageBoxA(L"该报名点有还没有录入完成或者没有校验的学生！",L"提示",MB_OK|MB_ICONWARNING);
	   return;
	}
	btnPrint->Enabled=false;
	RS->Active=false;
	RS->SQL->Text="select * from resault order by fzkh";
	RS->Active=true;
	RS->Filter="bmddm="+Z.Trim();
	RS->Filtered=true;
	RS->First();
	wyhexcel=new TWYHEXCEL(true,NULL,this);
	wyhexcel->WorkBook->AddSheet(AnsiString(filepath).c_str());//
	wyhexcel->WorkBook->ActiveSheet->AutoGrid(true);
   	char* temp="";
	for(int i=4;i<RS->RecordCount+4;i++){
		 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,1,RS->FieldByName("fzkh")->AsAnsiString.c_str());
		 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,2,RS->FieldByName("FXM")->AsAnsiString.c_str());
		 temp=(RS->FieldByName("SEX")->AsInteger==1)?"男":"女";
		 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,3,temp);
		 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,4,AnsiString(FormatFloat("0.00",RS->FieldByName("CJ1")->AsFloat)+" / "+RS->FieldByName("FS1")->AsWideString).c_str());
		 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,5,AnsiString(FormatFloat("0.00",RS->FieldByName("CJ2")->AsFloat)+" / "+RS->FieldByName("FS2")->AsWideString).c_str());
		 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,6,AnsiString(FormatFloat("0.00",RS->FieldByName("XK_CJ")->AsFloat)+" / "+RS->FieldByName("XKFS")->AsWideString).c_str());
		 if(RS->FieldByName("ZF")->AsInteger==0){
			 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,7,"------");
			 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,8,"缺考/缓考/免考");
		 }else{
			 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,7,RS->FieldByName("ZF")->AsAnsiString.c_str());
			 wyhexcel->WorkBook->ActiveSheet->SetCellsValue(i,8,RS->FieldByName("ZF2")->AsAnsiString.c_str());
		 }
		 RS->Next();
	}
	wyhexcel->WorkBook->ActiveSheet->CellReplace("{$FBMDMC}",RS->FieldByName("fbmdmc")->AsAnsiString.c_str(),false);
	wyhexcel->WorkBook->ActiveSheet->PrintPreview();
	btnPrint->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TSvrForm::bt_PDSetClick(TObject *Sender)
{
	if(pdFrm==NULL){
		pdFrm=new TpdFrm(this,MAINCONN);
	}
	pdFrm->ShowModal();
}
//---------------------------------------------------------------------------

