//---------------------------------------------------------------------------

#ifndef fm_login_dlgH
#define fm_login_dlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TLoginDlg : public TForm
{
__published:	// IDE-managed Components
   TLabel *Label1;
   TLabel *Label2;
   TEdit *edUser;
   TEdit *edPassw;
   TButton *btLogin;
   TButton *btCancel;
   void __fastcall btLoginClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TLoginDlg(TComponent* Owner);


   UnicodeString __fastcall GetUser();

   bool __fastcall Login();

};
//---------------------------------------------------------------------------
#endif
