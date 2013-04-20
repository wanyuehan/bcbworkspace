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
	TADOTable *RS;
	TADOQuery *QRY;
	TADOConnection *conn;
	TWideStringField *RSFXM;
	TWideStringField *RSFBMDDM;
	TWideStringField *RSFBZ;
	TWideStringField *RSFLHJSH;
	TFloatField *RSFWL1;
	TFloatField *RSFWL2;
	TFloatField *RSFWL;
	TFloatField *RSFHX1;
	TFloatField *RSFHX2;
	TFloatField *RSFHX;
	TWideStringField *RSFBMDMC;
	TWideStringField *RSFZKH;
	TWideStringField *RSfkddm;
	TWideStringField *RSfsjdm;
	TWideStringField *RSfccdm;
	TWideStringField *RSfzwdm;
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tdm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdm *dm;
//---------------------------------------------------------------------------
#endif
