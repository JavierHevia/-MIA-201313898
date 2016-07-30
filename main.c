#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char Guardar[100];

int d=0;

int main()
{

   printf("\t\t\t Bienvenido a la FASE 1 Archivos \n");
   printf("Ingrese los comandos que quiera ejecutar\n");
    //printf("Hello world! \n");


        fgets(Guardar,100,stdin);
        //Verificar=strtok(Guardar," "); //SEPARAR POR ESPACIOS
        //Verificar=strtok(Guardar,"::");

        char *Token1,*Token2,*Token3,*Token4;
        char *r=malloc(30);
        FILE *fp;
        //p=strtok(Guardar," ");//SEPARA POR ESPACIOS
        strcpy(r,Guardar);
        Token1=strsep(&r," ");
        Token2=strsep(&r," ");
        Token3=strsep(&r," ");
        Token4=strsep(&r," ");

        int EstadoIni= strcasecmp(Token1,"mkdisk");
        //printf("%d\n",EstadoIni);

        printf("Tok1= %s\n",Token1);
        printf("Tok2= %s\n",Token2);
        printf("Tok3= %s\n",Token3);
        printf("Tok4= %s\n",Token4);

        if (EstadoIni==0){ printf("EntraMkdisk\n");

        char *dato1,*dato2,*dato3,*dato4,*dato5,*dato6;

        dato1=strtok(Token2,"::");
        dato2=strtok(NULL,"::");
        printf("-- %s\n",dato1);
        printf("-- %s\n",dato2);

        dato3=strtok(Token3,"::");
        dato4=strtok(NULL,"::");
        printf("-+ %s\n",dato3);
        printf("-+ %s\n",dato4);

        dato5=strtok(Token4,"::");
        dato6=strtok(NULL,"::");
        printf("++ %s\n",dato5);
        printf("++ %s\n",dato6);

         int EstadoIni2= strcasecmp(dato1,"–Size"); printf("/ %d\n",EstadoIni2);
          int EstadoIni3= strcasecmp(dato3,"–Size"); printf("/ %d\n",EstadoIni3);
           int EstadoIni4= strcasecmp(dato5,"–Size"); printf("/ %d\n",EstadoIni4);

        if (EstadoIni2==0 || EstadoIni3==0 || EstadoIni4==0) {}
            fp = fopen ("/home/usuariopro/Documentos/Proyecto201313898/fichero.dsk", "w" );
            fwrite("\0", dato2, 0, fp );

        }


        free(r);





    return 0;
}
