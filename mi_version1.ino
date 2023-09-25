const int data = 11; // Enlazamiento del bus de datos en el puerto 11
const int store = 12; // Enlazamiento del reloj en el puerto 12
const int shift = 13; // Enlazamiento del pestillo en el puerto 13

//Declaraciones de funciones
void matrizEncendida();
void patrones();
int imprimirFigura(int columna[8]);
int imprimirFiguraP(int **matriz);
void refresh();
void publik();
int TiempoIngresado();
void imagen();
char verifiacionValores();


//Declaraciones de variables
volatile unsigned long Limite=0; //Variables para manejar 
volatile unsigned long tiempoActual = 0; //el tiempo de muestreo
int k;

//Arreglo que pasa corriente a todas las filas
int fila[8] = {0b10000000,
               0b01000000,
               0b00100000,
               0b00010000,
               0b00001000,
               0b00000100,
               0b00000010,
               0b00000001};

void setup()
{
  Serial.begin(9600); //Configuración del puerto y la velocidad de transmisión
  // Configuración de los pines como salidas
  pinMode(data, OUTPUT); 
  pinMode(store, OUTPUT); 
  pinMode(shift, OUTPUT); 
  
}

void loop()
{
  publik();
}

//Función que enciende toda la matriz con punteros
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

void patron1(){
  int columna[8] = {0b11100111,
                    0b11000011,
                    0b10000001,
                    0b00000000,
                    0b00000000,
                    0b10000001,
                    0b11000011,
                    0b11100111};
  
}

void patron2(){
  int columna[8] = {0b01111110,
                    0b10111101,
                    0b11011011,
                    0b11100111,
                    0b11100111,
                    0b11011011,
                    0b10111101,
                    0b01111110};
  
  for(k = 0; k<=50; k++){
   imprimirFigura(columna);	
     }
  refresh();
}

void patron3(){
  int columna[8] = {0b00100100,
                    0b00100100,
                    0b10010010,
                    0b10010010,
                    0b00100100,
                    0b00100100,
                    0b10010010,
                    0b10010010};
  
  imprimirFigura(columna);	
  refresh();
}

void patron4(){
  int columna[8] = {0b00001111,
                    0b10000111,
                    0b11000011,
                    0b11100001,
                    0b11100001,
                    0b11000011,
                    0b10000111,
                    0b00001111};
  
  for(k = 0; k<=50; k++){
   imprimirFigura(columna);	
     }
  refresh();
}

void patrones(){
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
    shiftOut(data, shift, LSBFIRST, columna[i]);
    digitalWrite(store, HIGH);
   } 
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


void refresh(){
  for(int i = 0; i<8 ; i++){
    digitalWrite(store, LOW);
    shiftOut(data, shift, LSBFIRST, 255);
    digitalWrite(store, HIGH);
  }
}


int TiempoIngresado(){
  int tiempoEnMilisegundos=0;
  Serial.println("Ingrese la duracion en segundos");
  while(Serial.available() == 0);
  while(Serial.available()>0){
  	tiempoEnMilisegundos *= 10;
  	tiempoEnMilisegundos += Serial.read() - '0';
  }
  tiempoEnMilisegundos *= 1000;
  return tiempoEnMilisegundos;
  
}

void publik(){
  Serial.println("¡Bienvenido!");
  bool banderita=true;
  int tiempoEncendido=0;
  int tiempoApagado=0;
  int numeroSecuencia=0;
  int conteo=0;
  while(banderita){
    Serial.println("Seleccione lo que desee observar: (Ingrese el numero que corresponda)");
    Serial.println("1. Encender toda la matriz");
    Serial.println("2. Ingresar un patrón");
    Serial.println("3. Mostrar patrones de forma alternada");
    while(Serial.available()==0);
    while(Serial.available()>0){
      if(Serial.read()=='1'){
        //Colcar los prints para saber cuales son los tiempos
        tiempoEncendido= TiempoIngresado();
        tiempoApagado= TiempoIngresado();
        numeroSecuencia= convertirCharaEntero();
        do{
          Limite=millis()+tiempoEncendido;
          while(tiempoActual<= Limite){
   			matrizEncendida();
            tiempoActual= millis();
          }
          Limite=millis()+tiempoApagado;
          while(tiempoActual<=Limite){
            refresh();
          }
          conteo+=1;
        }while(conteo<numeroSecuencia);
      
      	
      }else if(Serial.read()=='2'){
      }else if(Serial.read()=='3'){
      }else{
        Serial.print("Ingresaste un valor invalido. ");
        Serial.println("Intentelo nuevamente.");
      }
    }
  }
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
  
  
int convertirCharaEntero(){
 //Escribirle el print 
  char caracter;
  int entero=0;
  while(Serial.available()==0){};
  caracter= ValidarCharaEntero();
  entero <<= 1;
  entero+= caracter -'0';
  return entero;
    
  }
  
int ValidarCharaEntero(){
  char comprobado;
  while(true){
    while(!Serial.available());
    comprobado= Serial.read();
      if(comprobado>=48 && comprobado<58){
      	return comprobado;
      }else{
        Serial.print("Ingresaste un valor inválido.");
      	Serial.println(" Ingresa el valor nuevamente");
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


