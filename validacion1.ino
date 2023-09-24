const int data = 11;
const int store = 12;
const int shift = 13;

unsigned long tiempo = millis();
unsigned long tiempo_2 = 0;
char verificacionValores();

int fila[8] = {0B10000000,
               0B01000000,
               0B00100000,
               0B00010000,
               0B00001000,
               0B00000100,
               0B00000010,
               0B00000001};

// contador de columnas
int j = 0;
// contador de duración ingresada por el usuario
int k;

void setup()
{
  Serial.begin(9600);
  // 74HC595
  pinMode(data, OUTPUT); // data
  pinMode(store, OUTPUT); // store
  pinMode(shift, OUTPUT); // shift 
}

void imagen(){
  int filaIng[8] = {};
  int numerol = 0;
  char comprobado;
  for(int b = 0; b < 8 ; b++){ 
    Serial.println("Ingrese la fila como desea verla, siendo 0 encendido y 1 apagado.");
    numerol = 0;
    Serial.print("Fila ");
    Serial.print(b+1);
    Serial.println(":");
    for(int i = 0; i < 8; i++){
    	while(Serial.available() == 0);
      	comprobado= verificacionValores();
      	numerol <<= 1;
    	numerol += comprobado - '0';
    }
    filaIng[b] = numerol;    
  }
   while(!Serial.available()){
     for(int i = 0; i < 8; i++){
       digitalWrite(store, LOW);
       shiftOut(data, shift, LSBFIRST, fila[i]);
       shiftOut(data, shift, LSBFIRST, filaIng[i]);
       digitalWrite(store, HIGH);
       
     }
   }
  
}

char verificacionValores(){
  char comprobado;
  while(true){
    while(!Serial.available());
    comprobado= Serial.read();
      if(comprobado==49 || comprobado==48){
      	return comprobado;
      }else{
        Serial.print("Ingresaste un valor inválido.");
      	Serial.println(" Ingresa el valor nuevamente");
      }
  }
}

void loop()
{
  imagen();
  
  
}