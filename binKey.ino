#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int BIT_1 {2}, BIT_2 {3}, BIT_3 {4}, BIT_4 {5}, 
          BIT_5 {6}, BIT_6 {7}, BIT_7 {8}, BIT_8 {9},
          SUBMIT {10};

char binary[8];
int binaryLength;

unsigned long binaryToDecimal(char *binary, int length)
{
  int i;
  unsigned long decimal = 0;
  unsigned long weight = 1;
  binary += length - 1;
  weight = 1;
  for(i = 0; i < length; ++i, --binary)
  {
    if(*binary == '1')
      decimal += weight;
    weight *= 2;
  }
  
  return decimal;
}

void binaryToText(char *binary, int binaryLength, char *text, int symbolCount)
{
    int i;
    for(i = 0; i < binaryLength; i+=8, binary += 8)
    {
        char *byte = binary;
        byte[8] = '\0';
        *text++ = binaryToDecimal(byte, 8);
    }
    text -= symbolCount;
}

void formatBinary(char *input, int length, char *output)
{
    while(*input)
    {
        if(*input == '0' || *input == '1')
        {
            *output++ = *input++;
        }
        else
        {
            ++input;
            --length;
        }
    }
    output -= length;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BIT_1, INPUT);
  pinMode(BIT_2, INPUT);
  pinMode(BIT_3, INPUT);
  pinMode(BIT_4, INPUT);
  pinMode(BIT_5, INPUT);
  pinMode(BIT_6, INPUT);
  pinMode(BIT_7, INPUT);
  pinMode(BIT_8, INPUT);
  pinMode(SUBMIT, INPUT);
}

void loop() {
  int submit_state = digitalRead(SUBMIT);
  if (submit_state == 1) {
    int j = 7;
    for (int i = 2; i <= 9; i++) {
      binary[j] = digitalRead(i);
      Serial.println(j);
      Serial.println(binary[j]);
      j--;
    }
//    binaryLength = strlen(binary);
//    int symbolCount = binaryLength / 8 + 1;
//    char *text = malloc(symbolCount + 1);
//    char *formattedBinary = malloc(binaryLength + 1);
//    if(text == NULL || formattedBinary == NULL) {
//      exit(1);
//    }
//    if(binaryLength % 8 == 0) {
//      --symbolCount;  
//    }
//    formatBinary(binary, binaryLength, formattedBinary);
//    binaryToText(formattedBinary, strlen(formattedBinary), text, symbolCount);
//    Serial.println(text);
//    Serial.println(binary[0]);
    delay(1000);
  }
}
