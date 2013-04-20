//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "InputSide.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
       
}
//---------------------------------------------------------------------------


void __fastcall TForm2::L1Click(TObject *Sender)
{
        Form1->TURNS=1;
        Form1->Show();
        this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::L2Click(TObject *Sender)
{
        Form1->TURNS=2;
        Form1->Show();
        this->Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button1Click(TObject *Sender)
{
        Form1->TURNS=1;
        Form1->Show();
        Form1->RS1->Active=false;
        Form1->RS1->Active=true;
        Form1->RS1->Filtered=true;
        Form1->RS1->Filter="ZF=0";
        this->Close();
}
//---------------------------------------------------------------------------

