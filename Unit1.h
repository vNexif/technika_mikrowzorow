//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TImage *Image2;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label4;
        TUpDown *UpDown1;
        TButton *Button1;
        TLabel *Label6;
        TRadioButton *cluster;
        TRadioButton *dispersed;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Label6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
