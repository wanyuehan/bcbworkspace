//---------------------------------------------------------------------------

#ifndef TSvrFrmH
#define TSvrFrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "TdataMoudle.h"
#include <Vcl.Mask.hpp>
#include "TFrmEdit.h"
//---------------------------------------------------------------------------
class TSvrFrm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *btCheck;
	TPanel *Panel2;
	TDBGrid *dbGrid2;
	TMemo *mmo;
	void __fastcall btCheckClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSvrFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSvrFrm *SvrFrm;
//---------------------------------------------------------------------------
#endif
