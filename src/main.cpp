/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "main.h"

void setup(void)
{
    Serial.begin(9600);
    Serial.println("START[setup()]");
    String a = SL.sprint("A: This is a string...");
    Serial.println("A["+a+"]");
    String b = SL.sprintf("B: This is a %s...", "string");
    Serial.println("B["+b+"]");
    SL.print("C: This is a string...");
    Serial.println("NL");
    SL.printf("D: This is a %s...", "string");
    Serial.println("NL");
    SL.print("E: This is a string...");
    SL.nl();
    SL.printf("F: This is a %s...", "string");
    SL.nl();
    SL.print("G: This is a string...").nl();
    SL.printf("H: This is a %s...", "string").nl();
    SL.printf("I: This is a %s with %d replacements formatted within: %f.", "string", 3, 123.45).nl();
    //SL.abt();
    Serial.println("CLOSE[setup()]");
}

void loop(void)
{
    Serial.println("START[loop()]");
    delay(10000);
    Serial.println("CLOSE[loop()]");
}
