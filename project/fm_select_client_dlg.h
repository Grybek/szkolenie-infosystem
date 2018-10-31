//---------------------------------------------------------------------------

#ifndef fm_select_client_dlgH
#define fm_select_client_dlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------

/*
* Okno dialogowe do wybrania jednego z wy�wietlonych klient�w.
*/

class TSelectClientDlg : public TForm
{
__published:	// IDE-managed Components
   TPanel *Panel1;
   TPanel *Panel2;
   TDataSource *DataSource1;
   TDBGrid *DBGrid1;
   TButton *Button1;
   TButton *Button2;
   void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TSelectClientDlg(TComponent* Owner);


   /*
   * Wy�wietlenie okna z list� klient�w do wyboru.
   * Przed wywo�aniem funkcji nale�y pod��czy� komponent DataSource1 do w�a�ciwego
   * �r�d�a danych (lista klient�w).
   * Funkcja zwraca identyfikator wybranego klienta lub -1 przy braku wyboru.
   */
   int __fastcall Select();

};

#endif
