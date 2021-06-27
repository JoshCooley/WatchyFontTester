#include "Watchy_FontTester.h"
#include "TesterFont.h"

WatchyFontTester::WatchyFontTester(){} //constructor

void WatchyFontTester::drawWatchFace(){
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(&TesterFont);
    display.setCursor(0, 0);
    display.println();
    if(currentTime.Hour < 10){
        display.print('0');
    }
    display.print(currentTime.Hour);
    display.print(':');
    if(currentTime.Minute < 10){
        display.print('0');
    }    
    display.println(currentTime.Minute);
    display.println("abcdefghijklmnopqrstuvwxyz");
    display.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    display.println("1234567890");
    display.println("`~!@#$%^&*()-_=+[]{}\\|;':\",./<>?");
    display.println("the quick brown fox jumps over the lazy dog");
    display.println("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG");
    display.println("lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    display.println("LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT.");
}
