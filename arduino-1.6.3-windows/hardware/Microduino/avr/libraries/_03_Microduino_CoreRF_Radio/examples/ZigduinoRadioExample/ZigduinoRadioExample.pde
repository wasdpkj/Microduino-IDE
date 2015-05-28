/*

Run this sketch on two Zigduinos, open the serial monitor at 9600 baud, and type in stuff
Watch the Rx Zigduino output what you've input into the serial port of the Tx Zigduino

*/

#include <ZigduinoRadio.h>

String p = "{\"STA\":\"0\",\"TY\":\"1\",\"ID\":\"999999\",\"DIR\":{\"E\":\"66\",\"W\":\"77\",\"S\":\"88\",\"N\":\"99\"},\"VIS\":{\"E\":\"0\",\"W\":\"1\",\"S\":\"0\",\"N\":\"1\"},\"CK\":\"MD\"}";
void setup()
{
  ZigduinoRadio.begin(11);
  Serial.begin(115200);

  //  ZigduinoRadio.attachError(errHandle);
  //  ZigduinoRadio.attachTxDone(onXmitDone);
  ZigduinoRadio.beginTransmission();

  for (int a = 0; a < p.length(); a++)
  {
    ZigduinoRadio.write(p[a]);
    delay(2);
  }
  ZigduinoRadio.endTransmission();

}

void loop()
{
}
