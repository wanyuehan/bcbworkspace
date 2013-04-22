/***************************************************************
*                      服务器端   头文件 ServerForm.h          *
*                      作者       万越寒                       *
*                      时间       2010年5月                    *
*                      版本       2.2.9                        *
*                                                              *
****************************************************************/
//---------------------------------------------------------------------------

#ifndef ServerFormH
#define ServerFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <WYHEXCEL.H>
//---------------------------------------------------------------------------
class TSvrForm : public TForm
{
__published:	// IDE-managed Components
        TADOConnection *MAINCONN;
        TADOQuery *RS;
        TADOCommand *CMD;
        TGroupBox *GroupBox1;
        TProgressBar *T1PB;
        TLabel *F1LB;
        TLabel *T2LB;
        TProgressBar *T2PB;
        TPanel *Panel1;
        TDataSource *DS;
        TGroupBox *GroupBox2;
        TDBGrid *DBGrid1;
        TMemo *Memo1;
	TButton *btnExcSql;
	TButton *btnClrScore;
	TButton *btnChkInput;
	TButton *btnPrint;
        TTrackBar *TrackBar1;
        TLabel *Label1;
        TTimer *Timer1;
        TADOQuery *RS1;
        TLabel *Label2;
        TLabel *Label3;
        TADOQuery *SCORERS;
	TButton *btnParseScore;
	TButton *bt_PDSet;
        void __fastcall btnExcSqlClick(TObject *Sender);
        void __fastcall btnClrScoreClick(TObject *Sender);
        void __fastcall btnChkInputClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall btnParseScoreClick(TObject *Sender);
	void __fastcall btnPrintClick(TObject *Sender);
	void __fastcall bt_PDSetClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TSvrForm(TComponent* Owner);
        float __fastcall ScoreParse(int kslb,int sex,float cj);
     };
//---------------------------------------------------------------------------
extern PACKAGE TSvrForm *SvrForm;
//---------------------------------------------------------------------------
#endif
 