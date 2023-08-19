//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#pragma hdrstop

#include "LoginForm.h"
#include "MemoJournalForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
__fastcall TMyLoginForm::TMyLoginForm(TComponent* Owner)
	: TForm(Owner)
{
	if((usernameEdit -> Text == "") || (passwordEdit -> Text == "")) {
		loginButton -> Enabled = 0;
	}
}

std::vector<std::string> parseComaDelimitedString(std::string line) {
	std::vector<std::string> result;
	std::stringstream s_stream(line);

	while (s_stream.good()) {
		std::string substr;
		getline(s_stream, substr, ',');
		result.push_back(substr);
	}
    return result;
}
//---------------------------------------------------------------------------
void __fastcall TMyLoginForm::loginButtonClick(TObject *Sender)
{
	fstream myFile;
	bool isUserLogedin = false;

	myFile.open("registeredUsers.txt", ios::in);
	if(myFile.is_open()) {
		std::string line;

		while(getline(myFile, line) && !isUserLogedin) {
			std::vector<std::string> parsedLine = parseComaDelimitedString(line);
			const char* username = parsedLine.at(2).c_str();

			AnsiString editUsername = usernameEdit -> Text;
			const char* usernameString = editUsername.c_str();

			if(!std::strcmp(username, usernameString)) {
				const char* password = parsedLine.at(3).c_str();

				AnsiString editPassword = passwordEdit -> Text;
				const char* passwordString = editPassword.c_str();

				if(!std::strcmp(password, passwordString)) {
				   messageLabel -> Text = "Success!";
				   isUserLogedin = true;
				   loginButton -> Enabled = 0;
				   MyMemoJournalForm -> Show();
				}
				else {
                    messageLabel -> Text = "Wrong Password!";
				}
			}
			else {
               messageLabel -> Text = "Not registered!";
            }
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TMyLoginForm::myLoginOnClose(TObject *Sender, TCloseAction &Action)

{
	usernameEdit -> Text = "";
	passwordEdit -> Text = "";
	messageLabel -> Text = "";
    loginButton -> Enabled = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMyLoginForm::myusernameOnTyping(TObject *Sender)
{
	if((usernameEdit -> Text == "") || (passwordEdit -> Text == "")) {
		loginButton -> Enabled = 0;
	}
	else {
		loginButton -> Enabled = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMyLoginForm::mypasswordEditOnTyping(TObject *Sender)
{
	if((usernameEdit -> Text == "") || (passwordEdit -> Text == "")) {
		loginButton -> Enabled = 0;
	}
	else {
		loginButton -> Enabled = 1;
	}
}
//---------------------------------------------------------------------------

