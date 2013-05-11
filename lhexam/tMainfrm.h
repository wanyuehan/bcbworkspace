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
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
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
	TButton *btAnotherSubject;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btEnterClick(TObject *Sender);
	void __fastcall btResetClick(TObject *Sender);
	void __fastcall btNextClick(TObject *Sender);
	void __fastcall meScoreKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall meKCKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall btSaveClick(TObject *Sender);
	void __fastcall btCancelClick(TObject *Sender);
	void __fastcall meScoreChange(TObject *Sender);
	void __fastcall dbGridCellClick(TColumn *Column);
	void __fastcall btAnotherSubjectClick(TObject *Sender);
	void __fastcall dbGridKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall dbGridMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
private:	// User declarations
	TForm *pFrm;
	void __fastcall LoadKD();  //
	void __fastcall LoadCol();
	void __fastcall RestCol();
	void __fastcall SetEnable(bool isEnabled);
	void __fastcall SeekRow();
	public:		// User declarations
	void __fastcall InitData(int subject,int turns,bool isAdmin);
	void __fastcall InitControl();
	__fastcall TMainFrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainFrm *MainFrm;
//---------------------------------------------------------------------------
#endif
