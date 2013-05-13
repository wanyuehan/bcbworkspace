//---------------------------------------------------------------------------

#ifndef TFrmEditH
#define TFrmEditH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include "TdataMoudle.h"
//---------------------------------------------------------------------------
class TfrmEdit : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMaskEdit *meScore;
	TButton *btSave;
	TComboBox *cbSubject;
	void __fastcall btSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmEdit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEdit *frmEdit;
//---------------------------------------------------------------------------
#endif
