//---------------------------------------------------------------------------

#ifndef TdataMoudleH
#define TdataMoudleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class Tdm : public TDataModule
{
__published:	// IDE-managed Components
	TDataSource *GRIDDS;
	TADOQuery *QRY;
	TADOConnection *conn;
	TADOTable *RS;
	TWideStringField *RSFZKH;
	TWideStringField *RSFXM;
	TWideStringField *RSFLHJSH;
	TFloatField *RSFWL1;
	TFloatField *RSFWL2;
	TFloatField *RSFWL;
	TFloatField *RSFHX1;
	TFloatField *RSFHX2;
	TFloatField *RSFHX;
	TSmallintField *RSflag;
	TStringField *RSkddm;
	TStringField *RSkcdm;
	TStringField *RSzwh;
	TDataSource *CHKDS;
	TADOTable *CHKRS;
	TWideStringField *CHKRSFZKH;
	TWideStringField *CHKRSFXM;
	TWideStringField *CHKRSFLHJSH;
	TBCDField *CHKRSFWL1;
	TBCDField *CHKRSFWL2;
	TBCDField *CHKRSFWL;
	TBCDField *CHKRSFHX1;
	TBCDField *CHKRSFHX2;
	TFMTBCDField *CHKRSFHX;
	TSmallintField *CHKRSflag;
	TStringField *CHKRSkddm;
	TStringField *CHKRSkcdm;
	TStringField *CHKRSzwh;
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tdm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdm *dm;
//---------------------------------------------------------------------------
#endif
