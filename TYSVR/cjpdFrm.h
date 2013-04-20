//---------------------------------------------------------------------------

#ifndef cjpdFrmH
#define cjpdFrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include "../common.h"
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TpdFrm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TRadioButton *isMale;
	TRadioButton *isFemal;
	TLabel *Label2;
	TComboBox *cbSubjects;
	TDataSource *DS;
	TDBNavigator *DBNavigator1;
	TADOTable *RS;
	TSmallintField *RSkslb;
	TFloatField *RScj;
	TFloatField *RSscore;
	TSmallintField *RSsex;
	TButton *Button1;
	TDBGrid *DBGrid1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    TADOConnection *DBconn;
public:		// User declarations

	__fastcall TpdFrm(TComponent* Owner,TADOConnection *conn);

};
//---------------------------------------------------------------------------
extern PACKAGE TpdFrm *pdFrm;
//---------------------------------------------------------------------------
#endif
