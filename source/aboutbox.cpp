//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "aboutbox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

String GetFullAppName(void);
TAboutBoxForm * AboutBoxForm;
//---------------------------------------------------------------------------
__fastcall TAboutBoxForm::TAboutBoxForm(TComponent* Owner)
    : TForm(Owner)
{
  Caption = GetFullAppName() + " [" + __DATE__ + "]";
}
//---------------------------------------------------------------------------
void __fastcall TAboutBoxForm::LabelClick(TObject * Sender)
{
  switch( ((TLabel *)Sender)->Tag )
  {
    case 1: ShellExecute(GetDesktopWindow(), "open",
            ((TLabel *)Sender)->Caption.c_str(), NULL, NULL, SW_SHOWNORMAL);
    break;
    case 2: ShellExecute(GetDesktopWindow(), "open",
            (AnsiString("mailto:") + ((TLabel *)Sender)->Caption).c_str(), NULL, NULL, SW_SHOWNORMAL);
    break;
  }
}
//---------------------------------------------------------------------------

