//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormTwoU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Label1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	DefualtTimerInterval = tmrAnimate->Interval;
	Label1->Visible = false;
	GetDefaultEventBus()->RegisterSubscriber(1,this);
	GetDefaultEventBus()->RegisterMethod(2,this->EvenBusOnChangeSpeed);
}
//---------------------------------------------------------------------------
void TForm2::OnEvent (int MessageID, TEvenMessage *message) {
	tmrAnimate->Enabled = false;
	Label1->Left = this->ClientWidth - 150;
	Label1->Top = 8;
	Label1->Font->Size = 60;
	Label1->Caption = message->TagString;
	Label1->Visible = true;
	tmrAnimate->Enabled = true;
}
//---------------------------------------------------------------------------
void TForm2::EvenBusOnChangeSpeed (int MessageID, TEvenMessage *message) {
	if (message->TagBoolean)
		tmrAnimate->Interval = DefualtTimerInterval / 2;
	else
		tmrAnimate->Interval = DefualtTimerInterval;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::tmrAnimateTimer(TObject *Sender)
{
	Label1->Left -= 5;
}
//---------------------------------------------------------------------------
