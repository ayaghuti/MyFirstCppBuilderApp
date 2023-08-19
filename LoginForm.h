//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyLoginForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *usernameEdit;
	TLabel *Label1;
	TEdit *passwordEdit;
	TLabel *Label2;
	TButton *loginButton;
	TLabel *messageLabel;
	void __fastcall loginButtonClick(TObject *Sender);
	void __fastcall myLoginOnClose(TObject *Sender, TCloseAction &Action);
	void __fastcall myusernameOnTyping(TObject *Sender);
	void __fastcall mypasswordEditOnTyping(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMyLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
#endif
