#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char Guardar[100];
char** Palabra;
int d=0;
FILE *fp;

//EJEMPLO TOMADO DE http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int convertir_char_to_int(char caracter)
{
 int auxiliar =0;
 auxiliar = caracter-18;
 printf("%d",auxiliar);
 return auxiliar;
}


int main()
{
while(d==0){

   printf("\t\t\t Bienvenido a la FASE 1 Archivos \n");
   printf("Ingrese los comandos que quiera ejecutar\n");
    //printf("Hello world! \n");
        fgets(Guardar,100,stdin);
        Palabra = str_split(Guardar,' ');

        if (Palabra)
        {
            int i;
            for (i = 0; *(Palabra + i); i++)
            {
                if(strncasecmp((*(Palabra + i)), "#",1)==0){
                printf("Comentario# \n");
                }

                if (strcasecmp((*(Palabra + i)), "mkdisk")==0)
                {
                     char *Size,*Stamanio;
                     char *Unit,*Utipo="m";
                     char *Path,*Palacena;
                     char *nombre;
                     char *l;
                     char *p;
                     bool estado;
                     int valuar;

                    printf("EntraMKdisk\n"); /////////////////////////// PRIMERA BANDERA
                    int r;
                    for (r=(i+1); *(Palabra + r); r++)
                    {

                        if(strncasecmp((*(Palabra + r)), "-size",5)==0)
                        {
                        printf("----------------------------------------\n");

                            printf("EntraSize\n");

                            Size=strtok(*(Palabra + r),"::");
                            Stamanio=strtok(NULL,"::");
                            valuar =(int) *Stamanio -48;// convertir char* a int
                            printf("LALALALALA%d \n",valuar);
                            if (valuar>=0) {printf("tamaño-Correcto\n"); estado=true;} else {printf("tamaño-Incorrecto <0\n");}
                            printf("-Size--> %s\n",Size);
                            printf("-Tamaño--> %s\n",Stamanio);
                            printf("----------------------------------------\n");

                        }else if (strncasecmp((*(Palabra + r)), "+unit",5)==0) {

                            printf("----------------------------------------\n");
                            printf("EntraUnit\n");

                            Unit=strtok(*(Palabra + r),"::");
                            Utipo=strtok(NULL,"::");
                            printf("--> %s\n",Unit);
                            printf("Unidad--> %s\n",Utipo);
                            printf("----------------------------------------\n");

                        }else if (strncasecmp((*(Palabra + r)), "-path",5)==0){
                            printf("----------------------------------------\n");

                            printf("EntraPath\n");

                            Path=strtok(*(Palabra + r),"::");
                            Palacena=strtok(NULL,"::");
                            l=strtok(Palacena,"\"");

                            printf("-Path--> %s\n",Path);
                            printf("Direccion--> %s\n",l);
                            printf("----------------------------------------\n");

                        }else if (strncasecmp((*(Palabra + r)), "\\",1)==0) {
                            printf("----------------------------------------\n");
                            printf("VieneEspacio\n");
                            printf("----------------------------------------\n");

                        }else if (strncasecmp((*(Palabra + r)), "-name",5)==0) {
                            printf("----------------------------------------\n");
                            printf("EntraName\n");

                            char *th=strtok(*(Palabra + r),"::");
                            nombre=strtok(NULL,"::");
                            p=strtok(nombre,"\"");

                            printf("--> %s\n",th);
                            printf("Nombre--> %s\n",p);
                            printf("----------------------------------------\n");

                        } else {}
                    //devo de limpiar las variables...
                     //printf("**************%s%s\n", p,l);
                     //printf("**************%s\n", l);
                    // fp = fopen ( "%s%s",p,l, "w+" );
                    // fwrite( cadena, sizeof(char), sizeof(cadena), fp );
                    }
                    int espaciobinario=0;

                        char cadena[] ="\0";
                        char *o=strcat(l,p);
                        printf("dirección-----> %s\n",o);

                        if (estado==true) {

                            if (strncasecmp(Utipo, "m",1)==0) {
                                printf(":D  m  Megabytes\n" );
                                espaciobinario=valuar*1024*1024; //COMANDO M 1024^2

                            }else if (strncasecmp(Utipo, "k",1)==0) {
                                printf(":D  k  Kilobytes\n" );
                                espaciobinario=valuar*1024; //COMANDO K 1024
                            }else {
                                printf("ERROR TIPO UNIT %s\n",Utipo );}



                        fp = fopen ( o, "w+" );
                        fwrite( "\0", espaciobinario, sizeof(cadena), fp );
                        fclose ( fp );

                        } else {printf("ERROR TAMAÑO <0 %s");}


                } //AQUÍ TERMINA MKDISK............................................


                  if (strcasecmp((*(Palabra + i)), "rmdisk")==0){

                        char *Path2,*Palacena2;
                        char *l2;
                        char *p;
                        printf("EntraMRdisk\n");

                        int r;
                        for (r=(i+1); *(Palabra + r); r++)
                            {
                                 if(strncasecmp((*(Palabra + r)), "-path",5)==0)
                                    {
                                        printf("----------------------------------------\n");

                                        printf("EntraPath\n");

                                        Path2=strtok(*(Palabra + r),"::");
                                        Palacena2=strtok(NULL,"::");
                                        l2=strtok(Palacena2,"\"");

                                        printf("Path2--> %s\n",Path2);
                                        printf("Direccion2--> %s\n",l2);
                                        printf("----------------------------------------\n");

                                    }
                            }
                           system("PAUSE");
                long tamArchivo;
                char * nomArchivo;
                FILE * archivo;
                long i;
//EJEMPLO ENCONTRADO EN http://comunidad.dragonjar.org/archive/t-7172.html
                nomArchivo = l2; /* Nombre (si esta en misma carpeta) o ruta del archivo */

                archivo = fopen(nomArchivo,"r+"); /* Abro el archivo para lectura/escritura */
                fseek(archivo,0,SEEK_END); /* Recorro el archivo hasta el final */
                tamArchivo = ftell(archivo); /* Almaceno la posicion actual en el archivo */
                rewind(archivo); /* Regreso al principio del archivo */

                for(i=0; i<tamArchivo; i++) /* Recorro cada posicion del archivo */
                {
                fprintf(archivo,"%c",'0'); /* Imprimo un 0 en la posicion */
                }

                fclose(archivo); /* Cierro el archivo */
                remove(archivo);






                    } //AQUÍ TERMINA MRDISK



            printf("Metodo=[%s]\n", *(Palabra + i));
            //free(*(Palabra + i));
            //free(Palabra);

        } free(Palabra);

    }
}







    return 0;
}
