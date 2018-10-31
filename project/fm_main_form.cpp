//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fm_main_form.h"
#include "dm_database_module.h"
#include "fm_login_dlg.h"
#include "fm_person_dlg.h"
#include "fm_seek_client_dlg.h"
#include "fm_browser_dlg.h"
#include "user_info.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::updateControls()
{
   bool logged = DatabaseModule->IsUserLogged();

   btKlientDodaj->Enabled = logged;
   btKlientAkt->Enabled   = logged;
   btKlientBaza->Enabled  = logged;

   klienci::UserInfo user(DatabaseModule->GetUser());

   switch(user.Status)
   {
      case klienci::UserInfo::ustActive:
         stUser->Caption = user.Name;
         break;

      case klienci::UserInfo::ustBlocked:
         stUser->Caption = _T("<zablokowany> ") + user.Name;
         break;

      case klienci::UserInfo::ustSuspended:
         stUser->Caption = _T("<zawieszony> ") + user.Name;
         break;

      case klienci::UserInfo::ustErased:
         stUser->Caption = _T("<wykre�lony> ") + user.Name;
         break;
   }
}
//------------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
   updateControls();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::stUserDblClick(TObject *Sender)
{
   std::auto_ptr<TLoginDlg> dlg(new TLoginDlg(this));

   dlg->Login();

   updateControls();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btKlientDodajClick(TObject *Sender)
{
   klienci::UserInfo user(DatabaseModule->GetUser());

   if(user.Status != klienci::UserInfo::ustActive)
   {
      ShowMessage(_T("Zalogowany operator nie jest czynny."));

      return;
   }

   if(!user.checkRight(klienci::UserInfo::uacAdd))
   {
      ShowMessage(_T("Brak uprawnienia do dodawania nowych klient�w."));

      return;
   }

   PersonDlg->Append();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btKlientAktClick(TObject *Sender)
{
   klienci::UserInfo user(DatabaseModule->GetUser());

   if(user.Status != klienci::UserInfo::ustActive)
   {
      ShowMessage(_T("Zalogowany operator nie jest czynny."));

      return;
   }

   if(!user.checkRight(klienci::UserInfo::uacEdit))
   {
      ShowMessage(_T("Brak uprawnienia do aktualizowania danych klient�w."));

      return;
   }

   int client_id;

   client_id = SeekClientDlg->Display();

   if(client_id > 0)
   {
      if(SeekClientDlg->GetClientKind() != _T("F"))
      {
         // ta wersje obs�uguje tylko osoby fizyczne; obs�uga firm w kolejnej wersji

         ShowMessage(_T("Nieobs�ugiwany rodzaj klienta: '") + SeekClientDlg->GetClientKind() + _T("'"));
      }
      else
      {
         PersonDlg->Edit(client_id);
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::btKlientBazaClick(TObject *Sender)
{
   klienci::UserInfo user(DatabaseModule->GetUser());

   if(user.Status != klienci::UserInfo::ustActive)
   {
      ShowMessage(_T("Zalogowany operator nie jest czynny."));

      return;
   }

   if(!user.checkRight(klienci::UserInfo::uacBrowse))
   {
      ShowMessage(_T("Brak uprawnienia dost�pu do bazy klient�w."));

      return;
   }

   BrowserDlg->ShowModal();
}
//---------------------------------------------------------------------------
