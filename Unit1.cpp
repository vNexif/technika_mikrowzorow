//Tomasz Lubiñski (C)2009
// http://www.algorytm.org
//Patterning - technika mikrowzorcow
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "math.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

typedef struct Pixel
{
   Byte b;
   Byte g;
   Byte r;
   Byte reserved;
} TPixel;


Byte pattern[2][3][3] =
{
   {
      {8, 3, 4},
      {6, 1, 2},
      {7, 5, 9},
   },
   {
      {1, 7, 4},
      {5, 8, 3},
      {6, 2, 9},
   }
};

void __fastcall TForm1::Button1Click(TObject *Sender)
{
int i,j,k,l,choosenPattern;
float p;
TPixel *pixelOrg, *pixelNew, white, black;

//przygotuj wartosci bialy i czarny
white.b = 255;
white.g = 255;
white.r = 255;
black.b = 0;
black.g = 0;
black.r = 0;

//przygotuj obraz wynikowy
Image2->Canvas->Brush->Color = clWhite;
Image2->Canvas->Rectangle(0, 0, Image2->Width, Image2->Height);
Image2->Picture->Bitmap->PixelFormat = pf32bit;

//przygotuj format obrazu zrodlowego
Image1->Picture->Bitmap->PixelFormat = pf32bit;

//pobierz prog
p = StrToInt(Form1->Edit1->Text);
p /= 9.0;

//pobierz wybrany wzorzec
if (cluster->Checked == true) {
        choosenPattern = 0;
}
else {
        choosenPattern = 1;
}
//zwykle progowe
for (j=0; j<Image1->Height; j++){
        for (k=0; k<3; k++) {
                pixelNew = (TPixel *)Image2->Picture->Bitmap->ScanLine[j*3 + k];
                pixelOrg = (TPixel *)Image1->Picture->Bitmap->ScanLine[j];
                for (i=0; i<Image1->Width; i++){
                        for (l=0; l<3; l++) {
                                if (p * pattern[choosenPattern][k][l] > pixelOrg->r)
                                        *pixelNew = black;
                                else
                                        *pixelNew = white;
                                pixelNew++;
                                }
                        pixelOrg++;
                        }
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label6Click(TObject *Sender)
{
 ShellExecute(Application->Handle,
             "open",
             "http://www.algorytm.org",
             NULL,
             NULL,
             SW_NORMAL);
}
//---------------------------------------------------------------------------

