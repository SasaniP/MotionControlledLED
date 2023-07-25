#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
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
}

int getInRange(int x){
  if (97 <= x && x < 100) {
    return 0; // Output value for range ('a' to 'c')
  } else if (100 <= x && x < 103) {
    return 1; // Output value for range ('d' to 'f')
  } else if (103 <= x && x < 106) {
    return 2; // Output value for range ('g' to 'i')
  } else if (106 <= x && x < 109) {
    return 3; // Output value for range ('j' to 'l')
  } else if (109 <= x && x < 112) {
    return 4; // Output value for range ('m' to 'o')
  } else if (112 <= x && x <= 122) {
    return 5; // Output value for range ('p' to 'z')
  }
  return -1;
}

void value0(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
void value1(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
void value2(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
void value3(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
void value4(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
}
void value5(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
}
