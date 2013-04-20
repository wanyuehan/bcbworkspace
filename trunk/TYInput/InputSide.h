//---------------------------------------------------------------------------

#ifndef InputSideH
#define InputSideH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <ADODB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *INFOPANEL;
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TComboBox *BMDLIST;
        TLabel *Label2;
        TLabel *Label3;
        TComboBox *SEXCB;
        TLabel *Label4;
        TMaskEdit *GROUPID;
        TLabel *Label5;
        TButton *FILTER;
        TPanel *Panel2;
        TLabel *Label6;
	TMaskEdit *tx_cj1;
        TLabel *Label7;
	TMaskEdit *tx_cj2;
        TLabel *Label8;
	TMaskEdit *tx_xkcj;
        TButton *CancelBT;
        TADOConnection *CONN;
        TADOTable *RS1;
        TADOQuery *WORKRS;
        TWideStringField *RS1FZKH;
        TWideStringField *RS1FXM;
        TWideStringField *RS1FZWH;
        TWideStringField *RS1FBMDMC;
        TWideStringField *RS1FTYJSH;
        TWideStringField *RS1SEX;
        TWideStringField *RS1kslb;
        TWideStringField *RS1groupid;
        TWideStringField *RS1xh;
        TWideStringField *RS1bmddm;
        TFloatField *RS1XK_CJ1;
        TFloatField *RS1XK_CJ2;
        TFloatField *RS1XK_CJ;
        TFloatField *RS1XKFS;
        TFloatField *RS1CJ11;
        TFloatField *RS1CJ12;
        TFloatField *RS1CJ1;
        TFloatField *RS1FS1;
        TFloatField *RS1CJ21;
        TFloatField *RS1CJ22;
        TFloatField *RS1CJ2;
        TFloatField *RS1FS2;
        TFloatField *RS1ZF;
        TIntegerField *RS1flag;
        TButton *SAVEBT;
        TButton *Button1;
        TGroupBox *GroupBox2;
        TDBGrid *DG;
        TADOQuery *SCORERS;
        TSmallintField *SCORERSkslb;
        TFloatField *SCORERScj;
        TFloatField *SCORERSscore;
        TSmallintField *SCORERSsex;
        TDataSource *DS;
        TComboBox *XKLB;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FILTERClick(TObject *Sender);
        void __fastcall tx_cj2KeyPress(TObject *Sender, char &Key);
        void __fastcall tx_xkcjKeyPress(TObject *Sender, char &Key);
        void __fastcall tx_cj1KeyPress(TObject *Sender, char &Key);
        void __fastcall RS1AfterEdit(TDataSet *DataSet);
        void __fastcall SAVEBTClick(TObject *Sender);
        void __fastcall CancelBTClick(TObject *Sender);
        void __fastcall GROUPIDKeyPress(TObject *Sender, char &Key);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall tx_cj1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall GROUPIDKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall tx_cj2KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall tx_xkcjKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DGCellClick(TColumn *Column);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall LoadCol();
        void __fastcall SetCTL(bool state);
        void __fastcall NextRC();
         int TURNS;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
