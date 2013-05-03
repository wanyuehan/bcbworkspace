//---------------------------------------------------------------------------


#pragma hdrstop

#include "TdataMoudle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
Tdm *dm;
//---------------------------------------------------------------------------
__fastcall Tdm::Tdm(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tdm::DataModuleCreate(TObject *Sender)
{
	conn->ConnectionString="file name=./connection.udl";
	conn->Connected;
}
//---------------------------------------------------------------------------



