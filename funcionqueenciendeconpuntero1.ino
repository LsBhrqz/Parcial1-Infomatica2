const int data = 11;
const int store = 12;
const int shift = 13;

int fila[8] = {0B10000000,
               0B01000000,
               0B00100000,
               0B00010000,
               0B00001000,
               0B00000100,
               0B00000010,
               0B00000001};


void setup()
{
  Serial.begin(9600);
  // 74HC595
  pinMode(data, OUTPUT); // data
  pinMode(store, OUTPUT); // store
  pinMode(shift, OUTPUT); // shift 
}

void matrizEncendida(){
  int **matrizencendida=new int*[8];
  for (int i=0;i < 8 ; i++){matrizencendida[i]=new int[8];}
  int high=0;
  for(int i=0; i<8; i++){
    for(int j=0;j<8;j++){
      matrizencendida[i][j]= high;
    }    
  }
  imprimirFiguraP(matrizencendida);
  for(int i=0; i<8; i++){
        delete matrizencendida[i];
    }
    delete[]matrizencendida;
}

int imprimirFiguraP(int **matriz){
   for(int i = 0; i < 8; i++)
   {
     digitalWrite(store, LOW); 
     for(int j=0; j<8; j++){
      shiftOut(data, shift, LSBFIRST, fila[i]);
      shiftOut(data, shift, LSBFIRST, matriz[i][j]);}
      digitalWrite(store, HIGH);
     } 
}

void loop()
{
  matrizEncendida();
}