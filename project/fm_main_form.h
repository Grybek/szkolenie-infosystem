//---------------------------------------------------------------------------

#ifndef fm_main_formH
#define fm_main_formH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
   TButton *btKlientDodaj;
   TButton *btKlientAkt;
   TButton *btKlientBaza;
   TBevel *Bevel1;
   TGroupBox *GroupBox1;
   TBevel *Bevel2;
   TStaticText *stUser;
   void __fastcall btKlientDodajClick(TObject *Sender);
   void __fastcall btKlientAktClick(TObject *Sender);
   void __fastcall btKlientBazaClick(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall stUserDblClick(TObject *Sender);
private:	// User declarations

   void __fastcall updateControls();

public:		// User declarations
   __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
