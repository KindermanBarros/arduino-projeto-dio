#include <LiquidCrystal.h>
#define sLuz A0
#define sPresenca 7
#define sTemp A1
#define sGas A2
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16, 2);
  pinMode(sPresenca, INPUT);
}

void loop() {
  nivelLuz();
  limparTela();
  presenca();
  limparTela();
  temperatura();
  limparTela();
  gas();
  limparTela();
}
void limparTela(){
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  delay(1000);
}

void nivelLuz(){
  int luz = analogRead(sLuz);
  luz=map(luz,0,471,0,10);
  lcd.setCursor(0,0);
  lcd.print("Nivel de luz:");
  delay(500);
  lcd.setCursor(0,1);
  lcd.print(luz);
  delay(200);
  lcd.print("   ");
}

void presenca(){
  int presenca = digitalRead(sPresenca);
  if(presenca==1){
    lcd.setCursor(0,0);
    lcd.print("Sensor presenca:");
	lcd.setCursor(0,1);
    lcd.print("Estado: presente");
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("Sensor presenca:");
	lcd.setCursor(0,1);
    lcd.print("Estado: Ausente");
  }
}

void temperatura(){
  float temp=analogRead(sTemp)*5;
  float tempC=((temp/1023)-0.5)*100;
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.setCursor(0,1);
  lcd.print("No momento ");
  lcd.print(tempC);
}

void gas(){
  int gas = analogRead(sGas);
  gas = map(gas,300,750,0,100);
  lcd.setCursor(0,0);
  lcd.print("Nivel do Gas:");
  lcd.setCursor(0,1);
  lcd.print("Atual: ");
  lcd.print(gas);
  delay(200);
  
}



