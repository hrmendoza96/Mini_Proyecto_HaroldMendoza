#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  FILE* file;
  char ch;
  int cont_lineas, cont_palabras, cont_caracteres, cont_letras;

  if( argc == 2 ) {

      // Abrir archivo en modo lectura(read)
      file = fopen(argv[1],"r");
      cont_lineas = 0;
      cont_palabras = 0;
      cont_caracteres = 0;
      cont_letras=0;

      if (file){
       while ((ch=getc(file)) != EOF) {
          cont_caracteres++;
       	  /*Se incrementa la cantidad de letras mientras el caracter no
           sea espacio o salto de linea para luego verificar si hay palabras*/
          if (ch != ' ' && ch != '\n') {
            cont_letras++;
          }
          if (cont_letras>0) {
            if (ch == ' ' || ch == '\n') { // Se incrementan las palabras cuando hay espacio o salto de linea
               cont_palabras++;
             }
          }
         if (ch == '\n') { // Se incremeta la cantidad de lineas cuando existe salto de linea
           cont_lineas++;
         }//fin if contador chars
       }//fin while
      }else{
         printf("Error al abrir archivo\n");
      }
      printf("Lineas : %d \n", cont_lineas);
      printf("Palabras : %d \n", cont_palabras);
      printf("Caracteres : %d \n", cont_caracteres);
   }// fin if argc==2
   else if( argc == 3 ) {
     char comando[2];
     char lineas[2]= {'-','l'};
     char palabras[2]= {'-','w'};
     char caracteres[2]= {'-','c'};
     strcpy(comando, argv[1]); //Se copia el string en argv[1] en comando
     /*
     Se compara el elemento [1] de cada arreglo para verificar si son iguales
     */
     if (comando[1]==lineas[1]) {//lineas
        //printf("lineas\n");
        file = fopen(argv[2],"r");
        cont_lineas = 0;
        if (file){
         while ((ch=getc(file)) != EOF) {
           if (ch == '\n') { // Se incremeta la cantidad de lineas cuando existe salto de linea
             cont_lineas++;
           }//fin if contador chars
         }//fin while
        }else{
           printf("Error al abrir archivo\n");
        }
        printf("Lineas : %d \n", cont_lineas);
     }else if(comando[1]==palabras[1]){ //palabras
       file = fopen(argv[2],"r");
       cont_palabras = 0;
       if (file){
        while ((ch=getc(file)) != EOF) {
          if (ch != ' ' && ch != '\n') {
            cont_letras++;
          }
          if (cont_letras>0) {
            if (ch == ' ' || ch == '\n') { // Se incrementan las palabras cuando hay espacio o salto de linea
               cont_palabras++;
             }
          }
        }//fin while
       }else{
          printf("Error al abrir archivo\n");
       }
       printf("Palabras : %d \n", cont_palabras);

     }else if(comando[1]==caracteres[1]){ //caracteres
       file = fopen(argv[2],"r");
       cont_caracteres = 0;
       if (file){
        while ((ch=getc(file)) != EOF) {
          cont_caracteres++;
        }//fin while
       }else{
          printf("Error al abrir archivo\n");
       }
       printf("Caracteres : %d \n", cont_caracteres);

     }else{
       printf("Codigo Invalido, Ejemplo comando correcto: ./wc -l Archivo.txt\n");
     }

   }//fin else if(argc==3)
   else if( argc > 3 ) {
      printf("Argumentos invalidos,Ejemplo comando correcto: ./wc -l Archivo.txt .\n");
   }
   else {
      printf("Se esperaba argumento.\n");
   }

//getchar();
return(0);
}
