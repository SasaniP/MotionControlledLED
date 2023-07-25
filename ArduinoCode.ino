#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7
#define led7 8
#define led8 9
#define led9 10
#define led10 11
int value;
char read_value;
int read_value_int;
int rangeOut;

void setup() {
  Serial.begin(9600);
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
}

void loop(){  
  if( Serial.available()){
    read_value = Serial.read();
    Serial.print(read_value);
    Serial.print("    ");
    read_value_int = int(read_value);
    Serial.print(read_value_int);
    Serial.print("    ");
    rangeOut = getInRange(read_value_int);
    Serial.println(rangeOut);
  }
    if (rangeOut == 0){
      value0();  
    }
    else if (rangeOut == 1){      
      value1();     
    }  
    else if (rangeOut == 2){
      value2();
    } 
    else if (rangeOut == 3){
      value3();
    } 
    else if (rangeOut == 4){
      value4();
    } 
    else if (rangeOut == 5){
      value5();
    } 
    else if (rangeOut == 6) {
      value6();
    } else if (rangeOut == 7) {
      value7();
    } else if (rangeOut == 8) {
      value8();
    } else if (rangeOut == 9) {
      value9();
    } else if (rangeOut == 10) {
      value10();
    }
}

int getInRange(int x){
  if (97 <= x && x < 99) {
    return 0; // Output value for range ('a' to 'b')
  } else if (99 <= x && x < 101) {
    return 1; // Output value for range ('c' to 'd')
  } else if (101 <= x && x < 103) {
    return 2; // Output value for range ('e' to 'f')
  } else if (103 <= x && x < 105) {
    return 3; // Output value for range ('g' to 'h')
  } else if (105 <= x && x < 107) {
    return 4; // Output value for range ('i' to 'j')
  } else if (107 <= x && x < 109) {
    return 5; // Output value for range ('k' to 'l')
  } else if (109 <= x && x < 111) {
    return 6; // Output value for range ('m' to 'n')
  } else if (111 <= x && x < 113) {
    return 7; // Output value for range ('o' to 'p')
  } else if (113 <= x && x < 115) {
    return 8; // Output value for range ('q' to 'r')
  } else if (115 <= x && x < 117) {
    return 9; // Output value for range ('s' to 't')
  } else if (117 <= x && x < 122) {
    return 10; // Output value for range ('u' to 'v')
  }
  return -1;
}

void value0(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value1(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value2(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value3(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value4(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value5(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value6(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value7(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value8(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
}
void value9(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, LOW);
}
void value10(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
}
