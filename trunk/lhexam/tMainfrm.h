//---------------------------------------------------------------------------

#ifndef tMainfrmH
#define tMainfrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "TdataMoudle.h"
#include <ustring.h>
//---------------------------------------------------------------------------
class TMainFrm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TComboBox *cbKD;
	TLabel *Label3;
	TMaskEdit *meKC;
	TButton *btEnter;
	TButton *btReset;
	TPanel *Panel2;
	TPanel *Panel3;
	TDBGrid *dbGrid;
	TLabel *lbSubject;
	TLabel *Label5;
	TMaskEdit *meScore;
	TButton *btNext;
	TButton *btPrev;
	TButton *btSave;
	TButton *btCancel;
	TPanel *pmsg;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btEnterClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btResetClick(TObject *Sender);
private:	// User declarations
	TForm *pFrm;
	void __fastcall LoadKD();  //
	void __fastcall LoadCol();
	void __fastcall RestCol();
public:		// User declarations
	__fastcall TMainFrm(TComponent* Owner,int subject,int turns,bool isAdmin);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainFrm *MainFrm;
//---------------------------------------------------------------------------
#endif
