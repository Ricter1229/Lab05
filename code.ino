#include <Keypad.h>
#include "SevSeg.h" 
SevSeg sevseg;
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {{'F', 'B', 'A', '0'}, {'E','3','2', '1'},
{'D', '6', '5', '4'}, {'C', '9', '8', '7'}};
// 定義 Keypad 連到 Arduino 的接腳
byte rowPins[ROWS] = {8,9,10,11};
// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {12,13,14,15};
// 連到 Keypad 的 4 個 Columns
// 建立 Keypad 物件
Keypad keypad = Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );
void setup(){
  byte numDigits= 1; 
  byte digitPins[] = {7}; 
  byte segmentPins[] = {2,3,4,5,6,16,17}; 
  sevseg.begin(COMMON_CATHODE , numDigits, digitPins, segmentPins);
  Serial.begin(9600);
}
void loop(){
  char key = keypad.getKey(); // 讀取 Keypad的輸入
    if (key != NO_KEY){
      Serial.println(key);
      if(key <= '9' && key >= '0') {
        sevseg.setNumber(key-'0'); 
      }
    }
    
  sevseg.refreshDisplay();
}
