const int data = 11;
const int store = 12;
const int shift = 13;

unsigned long tiempo;
unsigned long tiempo_2 = 0;
int enc = 0;
int apa = 0;
int k;

void patrones();
int imprimirFigura(int columna[8]);
void refresh();

int fila[8] = {B10000000,
               B01000000,
               B00100000,
               B00010000,
               B00001000,
               B00000100,
               B00000010,
               B00000001};

// contador de columnas
int j = 0;

void setup()
{
  Serial.begin(9600);
  // 74HC595
  pinMode(data, OUTPUT); // data
  pinMode(store, OUTPUT); // store
  pinMode(shift, OUTPUT); // shift
  
}

void patron1(){
  int columna[8] = {B11100111,
                    B11000011,
                    B10000001,
                    B00000000,
                    B00000000,
                    B10000001,
                    B11000011,
                    B11100111};
  tiempo = millis();
  tiempo_2 = tiempo;
  while(tiempo-tiempo_2 <= enc){
   imprimirFigura(columna);	
   j = 0; 
   tiempo = millis();
    }
  refresh();
}

void patron2(){
  int columna[8] = {B01111110,
                    B10111101,
                    B11011011,
                    B11100111,
                    B11100111,
                    B11011011,
                    B10111101,
                    B01111110};
  
  for(k = 0; k<=50; k++){
   imprimirFigura(columna);	
   j = 0;
     }
  refresh();
}

void patron3(){
  int columna[8] = {B00100100,
                    B00100100,
                    B10010010,
                    B10010010,
                    B00100100,
                    B00100100,
                    B10010010,
                    B10010010};
  
  for(k = 0; k<=50; k++){
   imprimirFigura(columna);	
   j = 0;
  }
  refresh();
}

void patron4(){
  int columna[8] = {B00001111,
                    B10000111,
                    B11000011,
                    B11100001,
                    B11100001,
                    B11000011,
                    B10000111,
                    B00001111};
  
  for(k = 0; k<=50; k++){
   imprimirFigura(columna);	
   j = 0;
     }
  refresh();
}

void loop()
{
  Serial.println("Bienvenido a nuestro sistema de luces.");

  patrones();
}


void patrones(){
  ingTiempo();
  patron1();
  patron2();
  patron3();
  patron4();
  
}


int imprimirFigura(int columna[8]){
   for(int i = 0; i < 8; i++)
   {
    digitalWrite(store, LOW);
    shiftOut(data, shift, LSBFIRST, fila[i]);
    shiftOut(data, shift, LSBFIRST, columna[j]);
    digitalWrite(store, HIGH);
    j++;
   } 
}

void refresh(){
  for(int i = 0; i<8 ; i++){
    digitalWrite(store, LOW);
    shiftOut(data, shift, LSBFIRST, 1);
    digitalWrite(store, HIGH);
  }
}


void ingTiempo(){
  Serial.println("Ingrese el tiempo de duración");
  while(Serial.available() == 0);
  while(Serial.available()){
  	enc *= 10;
  	enc += Serial.read() - '0';
  }
  enc *= 1000;
  
}

void publik(){
  
}