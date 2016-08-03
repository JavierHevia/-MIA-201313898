#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


char Guardar[500];
char Guardar20[500];
char** Palabra;
char** Palabra2;

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



//EJEMPLO TOMADO DE http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
char** str_split2(char* a_str2, const char a_delim2)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str2;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim2;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim2 == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str2 + strlen(a_str2) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str2, delim);

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
int estado1=0;///////////////////////////////////// cuando tiene opcional
int pp=0,ll=0,aa=0,gg=0;
   printf("\t\t\t Bienvenido a la FASE 1 Archivos \n");
while(d==0){


   printf("Ingrese los comandos que quiera ejecutar\n");
    //printf("Hello world! \n");
        fgets(Guardar,300,stdin);

        if (pp==0){strcpy(Guardar20, strtok(Guardar,"\n"));} //separa el \n
        Palabra = str_split(Guardar,' ');

        if (Palabra)
        {
            int t;
            for (t = 0; *(Palabra + t); t++)
            {
                if (aa==0) {} else {pp=2; ll=1;}

                if(strncasecmp((*(Palabra + t)), "\\",1)==0)
                {
                    printf("Tiene opcional \n");
                    pp=1;
                    ll=1;
                    aa=3;

                }else if (strncasecmp((*(Palabra + t)), "\n",1)==0) {
                printf(":D \n");
                }else {printf(":v \n");  pp=2;  }

                   //ll=1;
               //printf("Entra %s\n",(*(Palabra + t)));
                if (pp==2 && aa==3)
                {
                    char *a=" ";
                    strcat(Guardar20,a);
                    strcat( Guardar20, strtok((*(Palabra+ t)),"\n"));
                }
            } //TERMINA EL FOOOOOOOOOOOOOR

        }ll=1;

               printf("\n VectorFINAL [%s]\n",Guardar20);
//pp=2;

/////////////////////////////////////////////////////////COMIENZA LA LEIDA DE ARCHIVO

if (pp==2 && ll==1) {
        Palabra2 = str_split2(Guardar20,' ');

        if (Palabra2)
        {
            int z;
            for (z = 0; *(Palabra2 + z); z++){

             if(strncasecmp((*(Palabra2 + z)), "#",1)==0){
                printf("Comentario# \n");
                }

             if (strcasecmp((*(Palabra2 + z)), "mkdisk")==0){

                     char *Size,*Stamanio; char *Unit,*Utipo="m";
                     char *Path,*Palacena; char *nombre;
                     char *l; char *p; bool estado; int valuar=1;

                     printf("EntraMKdisk\n"); /////////////////////////// PRIMERA BANDERA

                    int w;
                    for (w=(z+1); *(Palabra2 + w); w++)
                    {
                        if(strncasecmp((*(Palabra2 + w)), "-size",5)==0)
                        {   printf("----------------------------------------\n");
                            printf("EntraSize\n");
                            Size=strtok(*(Palabra2 + w),"::");
                            Stamanio=strtok(NULL,"::");
                            //printf("NUMERO Size%d \n",valuar);
                            valuar =(int) *Stamanio -48;// convertir char* a int
                            if (valuar>=0) {printf("tamaño-Correcto\n"); estado=true;} else {printf("tamaño-Incorrecto <0\n");}
                            printf("-> %s\n",Size);
                            printf("Tamaño--> %s\n",Stamanio);
                            printf("----------------------------------------\n");

                         }else if (strncasecmp((*(Palabra2+ w)), "+unit",5)==0) {
                            printf("----------------------------------------\n");
                            printf("EntraUnit\n");
                            Unit=strtok(*(Palabra2 + w),"::");
                            Utipo=strtok(NULL,"::");
                            printf("--> %s\n",Unit);
                            printf("Unidad--> %s\n",Utipo);
                            printf("----------------------------------------\n");

                         }else if (strncasecmp((*(Palabra2 + w)), "-path",5)==0){
                            printf("----------------------------------------\n");
                            printf("EntraPath\n");
                            Path=strtok(*(Palabra2 + w),"::");
                            Palacena=strtok(NULL,"::");
                            l=strtok(Palacena,"\"");
                            printf("-Path--> %s\n",Path);
                            printf("Direccion--> %s\n",l);

                            char ficher[180]= "mkdir -p '";
                            strcat(ficher,l);
                            strcat(ficher,"'");
                            printf("Fichero Creado---> %s\n",ficher);
                            system(ficher);


                            printf("----------------------------------------\n");

                         }else if (strncasecmp((*(Palabra2 + w)), "\\",1)==0) {
                            printf("----------------------------------------\n");
                            printf("VieneEspacio\n");
                            printf("----------------------------------------\n");

                         }else if (strncasecmp((*(Palabra2 + w)), "-name",5)==0) {
                            printf("----------------------------------------\n");
                            printf("EntraName\n");
                            char *th=strtok(*(Palabra2 + w),"::");
                            nombre=strtok(NULL,"::");
                            p=strtok(nombre,"\"");
                            printf("--> %s\n",th);
                            printf("Nombre--> %s\n",p);
                            printf("----------------------------------------\n");

                         }else {} //IF DE ESTADOS

                    } //////////////////////////////////////////////////////////////termina FOOR DE PALABRAS

                    // COMIENZA POR EL ARCHIVO....
                        int espaciobinario=0;
                        char cadena[] ="\0";
                        char *o=strcat(l,p);
                        printf("FICHERO-----> %s\n",o);

                        if (estado==true)
                        {
                            if (strncasecmp(Utipo, "m",1)==0)
                            {
                                printf(":D  m  Megabytes\n" );
                                espaciobinario=valuar*1024*1024; //COMANDO M 1024^2
                                printf(" %d Megabytes\n",valuar);
                                printf(" %d Megabytes\n",espaciobinario);
                            }
                            else if (strncasecmp(Utipo, "k",1)==0)
                            {
                                printf(":D  k  Kilobytes\n" );
                                espaciobinario=valuar*1024; //COMANDO K 1024
                                printf(" %d Megabytes\n",valuar);
                                printf(" %d Megabytes\n",espaciobinario);
                            }
                            else
                            {
                                printf("ERROR TIPO UNIT %s\n",Utipo );
                            }


                            fp = fopen ( o, "w+b" );

                            if (fp==NULL) {
                            printf("FICHERO NO ENCONTRADO \n");


                            }else { printf("El fichero SI existe \n" );

                           fwrite( "0", espaciobinario, sizeof(cadena), fp );
                           fclose ( fp );

                                }

                        }
                        else {printf("ERROR TAMAÑO <0 %s\n");}
                        break;
                }  //strcpy(Guardar20," "); strcpy(Palabra2, " ");  // fin MKDISK
                 // SALIR DEL MKDISK


                if (strcasecmp((*(Palabra2 + z)), "rmdisk")==0){

                        char *Path2,*Palacena2;
                        char *l2;
                        char *p;
                        printf("EntraMRdisk\n");

                         int y;
                        for (y=(z+1); *(Palabra2 + y); y++)
                            {
                                 if(strncasecmp((*(Palabra2 + y)), "-path",5)==0)
                                    {
                                        FILE *ficheroEliminar;
                                        printf("----------------------------------------\n");

                                        printf("EntraPath\n");

                                        Path2=strtok(*(Palabra2 + y),"::");
                                        Palacena2=strtok(NULL,"::");
                                        l2=strtok(Palacena2,"\"");

                                        printf("Path2--> %s\n",Path2);
                                        printf("Fichero para ELIMINAR--> %s\n",l2);
                                        printf("----------------------------------------\n");

                                        ficheroEliminar = fopen( l2, "r+b" );

                                        if(ficheroEliminar!=NULL){

                                        char feliminar[200];
                                        strcat(feliminar,l2);

                                        remove(feliminar); //////////////////////// ELIMINA FICHERO
                                        printf("Fichero Eliminado->\n");
                                        }else {printf("Fichero NO Existe->\n");}

                                    }
                            }// FOOOOOOOOOOR DE MRDISK

                } //TERMINA MRdisk -----------------------------------------------------

                    if (strcasecmp((*(Palabra2 + z)), "fdisk")==0)
                    {

                        int q;
                        for (q=(z+1); *(Palabra2 + q); q++)
                        {

                            if(strncasecmp((*(Palabra2 + q)), "-size",5)==0)
                            {

                            }else if (strncasecmp((*(Palabra2 + q)), "+unit",5)==0) {

                            }else if (strncasecmp((*(Palabra2 + q)), "-path",5)==0) {

                            }else if (strncasecmp((*(Palabra2 + q)), "+type",5)==0) {

                            }else if (strncasecmp((*(Palabra2 + q)), "+fit",5)==0) {

                            }else if (strncasecmp((*(Palabra2 + q)), "+delete",7)==0) {

                            }



                            } // TERMINA FOR FDISK






                //printf("Metodo=[%s]\n", *(Palabra2 + z));
             }      //FOOOOOOOOOOOOOOOOOOOR PRINCIPAL
            }  //if palabraaaa2



        } // ESTADO 2 IF

  pp=2;


    } // del whileeee


    return 0;
}
