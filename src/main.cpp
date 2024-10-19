#include <LiquidCrystal_I2C.h>

///////////////////////////////////////////////////////////////////////////
// Project : DisplayCharactersLCD
// Author : Loris Bousselat
// Date : 2024-October-19
// Equipment used : esp32    lcd screen
// Description :
//   Display a long parading message with a fixe one.
///////////////////////////////////////////////////////////////////////////

const int nbColumns = 16;
const int nbRows = 2;

LiquidCrystal_I2C lcd(0x27, nbColumns, nbRows);

const String staticMessage = "Loris Bousselat:";
const String scrollingMessage = "Welcome to my new project =)";

void fulFillWithBlank(String &message)
{
  for (int i = 0; i <= nbColumns - message.length(); i++)
  {
    message.concat(" ");
  }
}

void scrollMessage(int row, String message, int delayTime)
{
  int size = message.length();
  String toPrint = "";

  // The message will parade
  for (int position = 0; position < size; position++)
  {
    // the portion that can be displayed
    toPrint = message.substring(position, position + nbColumns);
    // print " " for lasting space in the screen
    if (toPrint.length() < nbColumns)
    {
      fulFillWithBlank(toPrint);
    }
    lcd.setCursor(0, row);
    lcd.print(toPrint);

    delay(delayTime);
  }
}

void setup()
{
  lcd.init();
  lcd.backlight(); // backlight on
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print(staticMessage);
  scrollMessage(1, scrollingMessage, 350);
}