//---------------------------------------------------------------------------

#ifndef MemoJournalFormH
#define MemoJournalFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.DateTimeCtrls.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyMemoJournalForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *textEdit;
	TEdit *subjectEdit;
	TDateEdit *DateEdit1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *addButton;
	TButton *removeButton;
	TButton *editbutton;
private:	// User declarations
public:		// User declarations
	__fastcall TMyMemoJournalForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyMemoJournalForm *MyMemoJournalForm;
//---------------------------------------------------------------------------
#endif
