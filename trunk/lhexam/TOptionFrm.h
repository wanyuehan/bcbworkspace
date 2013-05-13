//----------------------------------------------------------------------------
#ifndef TOptionFrmH
#define TOptionFrmH
//----------------------------------------------------------------------------
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include "tMainfrm.h"
#include "TSvrFrm.h"
//----------------------------------------------------------------------------
class TOptionFrm : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TRadioGroup *rgKM;
	TRadioGroup *rgTurns;
	TButton *btAdmin;
	void __fastcall OKBtnKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall CancelBtnClick(TObject *Sender);
	void __fastcall btAdminClick(TObject *Sender);
private:
	int FLAG_SUBJECT;
	int FLAG_TURN;
	bool FLAG_ADMIN;
	TMainFrm *mainfrm;
	TSvrFrm *SvrFrm;
public:
	virtual __fastcall TOptionFrm(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOptionFrm *OptionFrm;

//----------------------------------------------------------------------------
#endif    
