#include<iostream>
#include <math.h>	
#include<time.h>
using namespace std;


void tamanioMatriz(int& tamanio,float matriz [][15]);
void mostrarMatriz(int tamanio, float matriz [][15]);
void desviacion(int tamanio,float matriz [][15]);


int main (int argc, char *argv[]) {
	
	float matriz [15][15];
	int tamanio;
	tamanioMatriz(tamanio,matriz);
	mostrarMatriz(tamanio,matriz);
	desviacion(tamanio,matriz);
	return 0;
	
}


void tamanioMatriz(int& tamanio,float matriz [][15]){
	srand(time(NULL));
	int li,ls;
	li=-1111; //limite inferior
	ls=1111; //Limite superior
	do{
		cout<<"Ingresar el tamaño de la matriz hasta 15 "<< endl;
		cin>>tamanio;
		
	} while(tamanio <3 || tamanio>15);
	
	cout<<"La matriz ingresada es de: "<<tamanio<<endl;
	
	//Lleno la matriz
	for(int i=0; i<tamanio; i++){	
		for(int j=0;j<tamanio;j++){	 
			
			do{
				matriz[i][j]= li + rand()%((ls+1)-li); 
				
			}while(matriz[i][j]>1111 || matriz[i][j]<-1111);
			
		}
	}
}



void mostrarMatriz(int tamanio,float matriz [][15]){
	
	for(int i=0; i<tamanio; i++){
		for(int j=0;j<tamanio;j++){
			cout << matriz[i][j] << "\t";
		}
		cout << endl; 
	}
}



void desviacion(int tamanio,float matriz [][15]){
	int cant,contador=0,columna,fila,col,fil;
	float varianza=0, media=0, suma_valores=0,desv_minima=1000;
	float rojos[6],arreglo_desv[999];
	
	for(int i=0;i<tamanio;i++) { 
		
		for(int j=0;j<tamanio;j++) { 
			
			varianza=0;
			media=0;
			suma_valores=0;
			
			//1 parte superior
			if (i==0){
				if (j==0){	//superior izquierda
					rojos[0]= matriz [i][j+1];
					rojos[1]= matriz [i+1][j];
					rojos[2]= matriz [i+1][j+1];
					cant=3;
				}
				
				else if(j==tamanio-1){	//superior derecha
					rojos[0]= matriz [i][j-1];
					rojos[1]= matriz [i+1][j];
					rojos[2]= matriz [i+1][j-1];
					cant=3;
					
				}
				else if (j>0 && j<tamanio){//centro superior
					rojos[0]= matriz [i][j-1];
					rojos[1]= matriz [i][j+1];
					rojos[2]= matriz [i+1][j];
					rojos[3]= matriz [i+1][j+1];
					rojos[4]= matriz [i+1][j-1];
					cant=5;
				}
			}
			
			
			//2
			//i >0 hasta tamanioM
			if(i!=0 && i<tamanio-1 ){
				if(j==0){
					rojos[0]= matriz [i][j+1];
					rojos[1]= matriz [i-1][j+1];
					rojos[2]= matriz [i-1][j];
					rojos[3]= matriz [i+1][j+1];
					rojos[4]= matriz [i+1][j];
					cant=5;
				}
				else if(j==tamanio-1){
					rojos[0]= matriz [i][j-1];
					rojos[1]= matriz [i-1][j-1];
					rojos[2]= matriz [i-1][j];
					rojos[3]= matriz [i+1][j-1];
					rojos[4]= matriz [i+1][j];
					cant=5;
				}
				else if (j!=0 && j!=tamanio-1) {
					rojos[0]= matriz [i-1][j];
					rojos[1]= matriz [i-1][j-1];
					rojos[2]= matriz [i-1][j+1];
					rojos[3]= matriz [i+1][j];
					rojos[4]= matriz [i+1][j+1];
					rojos[5]= matriz [i+1][j-1];
					rojos[6]= matriz [i][j-1];
					rojos[7]= matriz [i][j+1];
					cant=8;
				}
			}
			
			
			//3
			if(i==tamanio-1){
				if(j==0){
					rojos[0]= matriz [i-1][j+1];
					rojos[1]= matriz [i][j+1];
					rojos[2]= matriz [i-1][j];
					
					cant=3;
				}
				else if(j==tamanio-1){
					rojos[0]= matriz [i-1][j-1];
					rojos[1]= matriz [i][j-1];
					rojos[2]= matriz [i-1][j];
					
					cant=3;
				}
				else if(j!=0 && j!= tamanio-1){
					rojos[0]= matriz [i][j-1];
					rojos[1]= matriz [i][j+1];
					rojos[2]= matriz [i-1][j];
					rojos[3]= matriz [i-1][j-1];
					rojos[4]= matriz [i-1][j+1];
					cant=5;
				}
			}
			
			
			
			columna=j;
			fila=i;
			
			
			for(int i=0;i<cant;i++){
				
				suma_valores = suma_valores + rojos[i]; //es una especie de contador. me da la suma total de los numeros ingresados 
				
			}
			
			//sacamos la media
			media= suma_valores / cant;  //la media es la suma total de los valores divido la cantidad de valores
			
			//sacamos la varianza
			for(int i=0;i<cant;i++){	
				varianza= varianza+pow((rojos[i]-media),2);   //pow es para sacar la potencia
			}
			//sacamos la desv_estandar
			arreglo_desv[contador] = sqrt(varianza/(cant));// sqrt es para sacar la raiz cuadrada
			cout<<" [ "<<fila<<" ][ "<<columna<<" ] ---> "<<arreglo_desv[contador]<<endl;
			
			
			//if que me dice cuando hay un error
			
			if(arreglo_desv[contador] ==0){
				cout << cant<<" cantidad" << endl;
				cout << matriz[i][j]<<" posicion" << endl;
				cout << matriz[i][j-1] << endl;
				cout << matriz[i][j+1] << endl;
				cout << matriz[i+1][j+1] << endl;
				cout << matriz[i-1][j+1] << endl;
				
				
				
				
				cout << suma_valores <<" suma valores"<< endl;
				cout << media <<" media"<< endl;
				cout << varianza<<" varianza" << endl;
			}
			
			
			
			
			if(arreglo_desv[contador] < desv_minima ){
				desv_minima=arreglo_desv[contador];
				col=columna;
				fil=fila;
			}
			contador++;
		}	
	}
	cout << "\n El minimo desvio estandar es:  "<<desv_minima <<" y se encuentra en la posicion: "<<"["<<fil<<"]["<<col<<"]"<<endl;	
}


