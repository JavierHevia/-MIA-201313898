#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
/////////////// PARTICIONES /////////////////////
typedef struct particion{
    char part_status; //Activa o no
    char part_type; //partición Primaria=P o extendida E
    char part_fit; // Tipo de ajuste B=Best Fit, F=First FIt, W=worst FIT
    unsigned int part_star; // byte de inicio de la partición
    unsigned int part_size; //tamaño de partición
    char part_name[16];// ID de particion
}particion;
//////////////// PARTICIONES ///////////////////

//////////////// MBR////////////////////////////
typedef struct MasterBootRecord{
    unsigned int mbr_tamanio;
    time_t mbr_fecha_creacion;
    int mbr_disk_signature;
    particion mbr_particion_[4];
}MasterBootRecord;

///////////////////////////////////////////////

////////////////EBR////////////////////////////
typedef struct ExtendedBootRecord{
    char part_status;
    char part_fit;
    unsigned int part_start;
    unsigned int part_size;
    unsigned int part_next;
    char part_name [16];
}ExtendedBootRecord;

/////////////////////MONTADA//////////////////////////

typedef struct PartMonatar{
    char clave[110];
}PARTMONTAR;

typedef struct nparticion{
    char path[120];
    PARTMONTAR contenido[30];
}NPARTICION;


NPARTICION montada[26];
////////////////////////////////////

char Guarda[500];
char Guardar2[500];
char j[200];
char** Palabra;
char** Palabra2;

//VARIABLES PARA PARTICIONEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEES
unsigned int TAMANIOREAL=0;
///////////////////////////////////////////////////////////
int particionesPrimarias=0; int particionesextendidas=0; int ParticionesLibres=0;
///////////////////////////////////////////////////////////
int d=0;
//FILE *fp;

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
        char *linea = NULL;
        size_t longuitud = 0;
        ssize_t leer;

int estado1=0;///////////////////////////////////// cuando tiene opcional
int pp=0,ll=0,aa=0,gg=0;
   printf("\t\t\t Bienvenido a la FASE 1 Archivos \n");

FILE *archiscrip;
archiscrip = fopen("/home/javier/Documentos/archivos/script.sh","r");
if (archiscrip == NULL){
                printf("Archivo de entrada no econtrado\n");
            }

 while ((leer = getline(&linea, &longuitud, archiscrip)) != -1){

   printf("Ingrese los comandos que quiera ejecutar\n");

        fgets(Guarda,350,stdin);
        strcpy(Guarda,linea);

        //strcpy(Guarda,"fdisk -size::2 -name::\"prueba2\" -path::\"/home/javier/Documentos/prueba/prueba1.dsk\"");
        //strcpy(Guarda,"fdisk -size::1 -name::\"Primaria1\" -path::\"/home/javier/Documentos/prueba/prueba3.dsk\"");
        //strcpy(Guarda,"fdisk -size::1 +type::E -name::\"Extendida\" -path::\"/home/javier/Documentos/prueba/prueba3.dsk\"");

     //strcpy(Guarda,"mkdisk -size::3000 -name::\"prueba3.dsk\" -path::\"/home/javier/Documentos/prueba/\"");

        if (pp==0){strcpy(Guardar2, strtok(Guarda,"\n"));} //separa el \n
        Palabra = str_split(Guarda,' ');

int exit=0;
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
                }else if (strncasecmp((*(Palabra + t)), "#",1)==0){
                    break; exit=1;
                }
                else {printf(":v \n");  pp=2;  }

                   //ll=1;
               //printf("Entra %s\n",(*(Palabra + t)));
                if (pp==2 && aa==3)
                {
                    char *a=" ";
                    strcat(Guardar2,a);
                    strcat( Guardar2, strtok((*(Palabra+ t)),"\n"));
                }
            if(exit==1){break;}
            } //TERMINA EL FOOOOOOOOOOOOOR

        }ll=1;

               printf("\n VectorFINAL [%s]\n",Guardar2);
//pp=2;

/////////////////////////////////////////////////////////COMIENZA LA LEIDA DE ARCHIVO
int hola;
if (pp==2 && ll==1) {
     if(exit==1){break;}
        Palabra2 = str_split2(Guardar2,' ');

        if (Palabra2)
        {
            int z;
            for (z = 0; *(Palabra2 + z); z++){

             if(strncasecmp((*(Palabra2 + z)), "#",1)==0){
                printf("Comentario# \n");
                }
//vuelve:
             if (strcasecmp((*(Palabra2 + z)), "mkdisk")==0){

                     char *Size="",*Stamanio=""; char *Unit="",*Utipo="m";
                     char *Path="",*Palacena=""; char *nombre="";char *p="";
                     char *l="";  bool estado=false; unsigned int valuar=1;

                     printf("--------------Entra MKdisk--------------\n"); /////////////////////////// PRIMERA BANDERA

                    int w;
                    for (w=(z+1); *(Palabra2 + w); w++)
                    {
                        if(strncasecmp((*(Palabra2 + w)), "-size",5)==0)
                        {   printf("----------------------------------------\n");
                            printf("EntraSize\n");
                            Size=strtok(*(Palabra2 + w),"::");
                            Stamanio=strtok(NULL,"::");
                            strcat(Stamanio,"\0");
                            //printf("NUMERO Size%d \n",valuar);
                            valuar =atoi(Stamanio);
                            if (valuar>0) {printf("tamaño-Correcto\n"); estado=true;} else {printf("tamaño-Incorrecto <0\n");}
                            printf("-> %s\n",Size);
                            printf("Tamaño--> %s\n",Stamanio);
                           //valuar=(int)Stamanio;
                            printf("----------------------------------------\n");

                         }else if (strncasecmp((*(Palabra2+ w)), "+unit",5)==0) {
                            printf("----------------------------------------\n");
                            printf("EntraUnit\n");
                            Unit=strtok(*(Palabra2 + w),"::");

                            Utipo=strtok(NULL,"::");
                            strcat(Unit,"\0");
                            printf("--> %s\n",Unit);
                            printf("Unidad--> %s\n",Utipo);
                            printf("----------------------------------------\n");

                         }else if (strncasecmp((*(Palabra2 + w)), "-path",5)==0){
                            printf("----------------------------------------\n");
                            printf("EntraPath\n");
                            Path=strtok(*(Palabra2 + w),"::");
                            Palacena=strtok(NULL,"::");
                            l=strtok(Palacena,"\"");
                            strcat(Palacena,"\0");
                            strcat(l,"\0");
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
                            strcat(p,"\0");
                            printf("--> %s\n",th);
                            printf("Nombre--> %s\n",p);
                            printf("----------------------------------------\n");

                         }else {printf("Error en los parametros \n"); break;} //IF DE ESTADOS

                    } //////////////////////////////////////////////////////////////termina FOOR DE PALABRAS

                    // COMIENZA POR EL ARCHIVO....
                        unsigned int espaciobinario=0;

                        strcat(l,p);  strncat(l,"\0",sizeof("\0"));
                        printf("FICHERO-----> %s\n",l);

                        if (estado==true){
                            if (strncasecmp(Utipo, "m",1)==0)
                            {
                                printf(":D  m  Megabytes\n" );
                                espaciobinario=valuar*1024; //COMANDO M 1024^2
                                printf(" %d Megabytes\n",valuar);
                                printf(" %d Megabytes\n",espaciobinario);
                            }
                            else if (strncasecmp(Utipo, "k",1)==0)
                            {
                                printf(":D  k  Kilobytes\n" );
                                espaciobinario=valuar; //COMANDO K 1024
                                printf(" %d Kilobytes\n",valuar);
                                printf(" %d Kilobytes\n",espaciobinario);
                            }
                            else
                            {
                                printf("ERROR TIPO UNIT %s\n",Utipo );
                                break;
                            }
                             strcpy(j,l);  strcat(j,"\0");// LIMPIAR ERRORESSSSS
                             FILE *fp;
                            fp = fopen ( j, "w+b" );

                            int flg=0;
                            if (fp==NULL) {
                              printf("FICHERO NO ENCONTRADO \n");


                            }
                            else {
                                printf("El fichero SI existe \n" );

                      /////////////////////////////////////////////////////////
                            time_t ahora;
                            struct tm *fecha;
                            time(&ahora);
                            fecha = localtime(&ahora);
                            srand (time(NULL));
                            int signature=rand() % 100;
/////////////////////////////////////////////////////////////////ESCRIBIR EL MBR///////////////////////////////////////////////
                       MasterBootRecord  mbr; //LLAMADO DE STRUCK
                        mbr.mbr_tamanio=espaciobinario;
                        mbr.mbr_fecha_creacion= time(NULL);
                        mbr.mbr_disk_signature=signature;
usleep(5);
                        // METIENDO DATOS EN LAS OTRAS PARTICIONES.....
                                 for (int d=0;d<=3;d++) {
                                mbr.mbr_particion_[d].part_status='\0';
                                     mbr.mbr_particion_[d].part_type='\0';
                                     mbr.mbr_particion_[d].part_fit='\0';
                                     mbr.mbr_particion_[d].part_star=0;
                                     mbr.mbr_particion_[d].part_size=0;
                                     for(int x=0;x<15;x++){mbr.mbr_particion_[d].part_name[x]="\0";}
                                 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                printf("Creando el archivo................................\n");
usleep(15);
                                    char letras [3]="\0";
                                      int i;
                                      for (i=0;i<=espaciobinario;i++){
                                        fseek(fp,i,SEEK_SET);
                                          fwrite(letras,1,sizeof(letras),fp);

                                      }
usleep(25);
                                            // fclose(fp);
                                printf("Archivo creado................................\n");

//                                 long long tamaArchivo[espaciobinario];  char filee[espaciobinario];
//                                 char *tama=espaciobinario;
//                                memset(filee, 0, sizeof tamaArchivo);

//                                fwrite(filee,sizeof(filee),1,fp);

                                fseek(fp,0,SEEK_SET);
                                fwrite(&mbr,sizeof(MasterBootRecord),1,fp);
                               // fclose(fp);
usleep(25);
//                                FILE *fp=fopen(j,"r+");
//                                MasterBootRecord temporal;
//                                fread(&temporal,sizeof(MasterBootRecord),1,fp);

//                                printf("signature %d , tamanio %d\n",temporal.mbr_disk_signature,temporal.mbr_tamanio);
                             if(flg!=0)
                                fclose(fp);

usleep(100);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                }

                        }
                        else {printf("ERROR TAMAÑO <0 \n");}
                        pp=0;
                        //goto vuelve; //break;
                }  //strcpy(Guardar20," "); strcpy(Palabra2, " ");  // fin MKDISK
                 // SALIR DEL MKDISK


                if (strcasecmp((*(Palabra2 + z)), "rmdisk")==0){

                        char *Path2,*Palacena2;
                        char *l2;
                        char *p;
                        printf("--------------Entra MRdisk--------------\n");

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
                                        strcat(l2,"\0");
                                        printf("Path2--> %s\n",Path2);
                                        printf("Fichero para ELIMINAR--> %s\n",l2);
                                        printf("----------------------------------------\n");

                                        ficheroEliminar = fopen( l2, "r+b" );

                                        if(ficheroEliminar!=NULL){

                                        char feliminar[200];
                                        strcat(feliminar,l2);
                                        strcat(feliminar,"\0");

                                        remove(feliminar); //////////////////////// ELIMINA FICHERO/////////////////////////
                                        printf("Fichero Eliminado->\n");
                                        }else {printf("Fichero NO Existe->\n");}

                                    }
                            }// FOOOOOOOOOOR DE MRDISK
                            break;
                }  //TERMINA MRdisk -----------------------------------------------------

                    if (strcasecmp((*(Palabra2 + z)), "fdisk")==0)
                    {printf("--------------Entra Fdisk--------------\n");
                        char *Size,*Stamanio; char *Unit,*Utipo="k";
                        char *path,*dPath; char *type, *dtype="p";
                        char *fit,*dfit="wf"; char *dele, *deleminar;
                        char *name,*dname; char *add, *dadd; bool estado; char *l2,*nm; int EstadDELETE=0; int EstadoUNIT=0;
                        unsigned int tamanioBytes; int EstadoAdd=0; unsigned int TamanioSize=1; int estadosiexiste=0;
                        unsigned int TAMANIOREAL; int estadotype=0; int estadoprimaria, estadoextendida, estadologica;
                        int extendidad=0; int log=0;


                        int q;
                        for (q=(z+1); *(Palabra2 + q); q++)
                        {

                            if(strncasecmp((*(Palabra2 + q)), "-size",5)==0)
                            {
                              printf("----------------------------------------\n");
                              printf("EntraSize\n");

                              Size=strtok(*(Palabra2 + q),"::");
                              Stamanio=strtok(NULL,"::");
                              strcat(Stamanio,"\0");
                              TamanioSize =atoi(Stamanio);  // convertir char* a int
                              if (TamanioSize>0) {printf("tamaño-Correcto\n"); estado=true;} else {printf("tamaño-Incorrecto <0\n");}
                              printf("--> %s\n",Size);
                              printf("Tamaño--> %s\n",Stamanio);
                              printf("Tamaño real--> %d\n",TamanioSize);

                              printf("----------------------------------------\n");

                            }else if (strncasecmp((*(Palabra2 + q)), "+unit",5)==0) {
                              printf("----------------------------------------\n");
                              printf("EntraUnit\n"); EstadoUNIT=1;
                              Unit=strtok(*(Palabra2 + q),"::");
                              Utipo=strtok(NULL,"::");
                              strcat(Utipo,"\0");
                              printf("--> %s\n",Unit);
                              printf("Tipo de Unidad--> %s\n",Utipo);

                              printf("----------------------------------------\n");

                            }else if (strncasecmp((*(Palabra2 + q)), "-path",5)==0) {
                                printf("----------------------------------------\n");
                                printf("EntraPath\n");

                                path=strtok(*(Palabra2 + q),"::");
                                dPath=strtok(NULL,"::");
                                l2=strtok(dPath,"\"");
                                strcat(l2,"\0");
                                printf("--> %s\n",path);

                                FILE *verificar = fopen(l2,"r+");
                                if (verificar==NULL){printf("Fichero no existe");}else{estadosiexiste=1;}
                                printf("Fichero --> %s\n",l2);

                                printf("----------------------------------------\n");

                            }else if (strncasecmp((*(Palabra2 + q)), "+type",5)==0) {
                                printf("----------------------------------------\n");
                                printf("EntraType\n");

                                type=strtok(*(Palabra2 + q),"::");
                                dtype=strtok(NULL,"::");
                                strcat(dtype,"\0");
                                printf("--> %s\n",type);
                                printf("Tipo Type --> %s\n",dtype);
                                printf("----------------------------------------\n");

                            }else if (strncasecmp((*(Palabra2 + q)), "+fit",5)==0) {
                                printf("----------------------------------------\n");
                                printf("EntraFit\n");

                                fit=strtok(*(Palabra2 + q),"::");
                                dfit=strtok(NULL,"::");
                                strcat(dfit,"\0");
                                printf("--> %s\n",fit);
                                printf("Tipo Fit --> %s\n",dfit);
                                printf("----------------------------------------\n");

                            }else if (strncasecmp((*(Palabra2 + q)), "+delete",7)==0){
                                printf("----------------------------------------\n");
                                printf("EntraDelete\n"); EstadDELETE=1;

                                dele=strtok(*(Palabra2 + q),"::");
                                deleminar=strtok(NULL,"::");
                                strcat(deleminar,"\0");
                                printf("--> %s\n",dele);
                                printf("Tipo Delete --> %s\n",deleminar);
                                printf("----------------------------------------\n");

                            }else if (strncasecmp((*(Palabra2 + q)), "-name",5)==0) {
                                printf("----------------------------------------\n");
                                printf("EntraName\n");

                                name=strtok(*(Palabra2 + q),"::");
                                dname=strtok(NULL,"::");
                                nm=strtok(dname,"\"");

                                strcat(nm,"\0");
                                printf("--> %s\n",name);
                                printf("Nombre--> %s\n",nm);

                                printf("----------------------------------------\n");

                            }else if (strncasecmp((*(Palabra2 + q)), "+add",5)==0) {
                                printf("----------------------------------------\n");
                                EstadoAdd=1; printf("EntraAdd\n");
                                add=strtok(*(Palabra2 + q),"::");
                                dadd=strtok(NULL,"::");
                                strcat(dadd,"\0");
                                unsigned int Tamanioadd =(int) *dadd -48;// convertir char* a int
                                printf("--> %s\n",add);
                                printf("#--> %s\n",dadd);
                                printf("----------------------------------------\n");

                            }

                            } // TERMINA FOR FDISK

                        if(strncasecmp(dtype, "e",1)==0){strcpy(dtype,"e"); estadotype=1; extendidad=1;
                        }else if (strncasecmp(dtype, "l",1)==0){strcpy(dtype,"l"); estadotype=1; log=1;
                        }else if(strncasecmp(dtype, "p",1)==0){ estadotype=1;

                        }else {printf("Error en Type\n");}

                            if (estado==true && estadosiexiste==1 && estadotype==1){
                                if (strncasecmp(Utipo, "m",1)==0){
                                    printf(":D  m  Megabytes\n" );
                                     tamanioBytes=TamanioSize*1024*1024; //COMANDO M 1024^2
                                    printf(" %d size\n",TamanioSize);
                                    printf(" %d Megabytes\n",tamanioBytes);
                                }else if (strncasecmp(Utipo, "b",1)==0) {
                                    printf(":D  b Bytes\n" );
                                    tamanioBytes=TamanioSize; //COMANDO M 1024^2
                                    printf(" %d size\n",TamanioSize);
                                    printf(" %d Bytes\n",tamanioBytes);
                                }else if (strncasecmp(Utipo, "k",1)==0){
                                    printf(":D  b kiloBytes\n" );
                                    tamanioBytes=TamanioSize*1024; //COMANDO M 1024^2
                                    printf(" %d size\n",TamanioSize);
                                    printf(" %d kiloBytes\n",tamanioBytes);
                                }else{printf("D: Error en Unit diferente\n" );}


                                 if (EstadDELETE==0 && EstadoAdd==0 ) {
         //////////////////////////////// LEER EL ARCHIVO PARA LEER EL MBR /////////////////////////////////////
//                                char *FICFDISK=strcat(l2,nm);
                                     strcat(l2,"\0");
///////////////////////////////////////////////////FICHERO GENERAL///////////////////////////////////////////////
                                FILE *fp2=fopen(l2,"rb+"); // ABRO PARA LECTURA Y ESCRITURA
                                MasterBootRecord LEER;


                                // MBR PARA LEER EL ARCHIVO Y DATOS ANTIGUOS
                                fread(&LEER,sizeof(MasterBootRecord),1,fp2);

                                printf("Signature %d , Tamaño Total Del disco %d , Tamaño MBr %d\n",LEER.mbr_disk_signature,LEER.mbr_tamanio, sizeof(MasterBootRecord));//DATOS DEL MBR
                                //fclose(fp2);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                               int bytesrestantes=0;
                                for (int d=0;d<=3;d++) {

                                    bytesrestantes=LEER.mbr_particion_[d].part_size + bytesrestantes;
                               }
                                TAMANIOREAL=LEER.mbr_tamanio - sizeof(MasterBootRecord) - bytesrestantes; // ESPACIO YA DISPONIBLE

                                printf("Tamaño REAL disponible---> %d\n",TAMANIOREAL);
                                int espaciolibre= LEER.mbr_tamanio-bytesrestantes-sizeof(MasterBootRecord); // ESPACIO DISPONIBLE
                                printf("Libre---> [%d]<-----\n",espaciolibre);
                                int size=tamanioBytes;
                                int start;
////////////////////////////////////////////////////// VERIFICAR CUANTAS PRIMARIAS O EXTENDIDAS HAY//////////////////////////////////////////
                              //  MasterBootRecord comparar;
                                for (int d=0;d<=3;d++) {
                                  char *compa= (LEER.mbr_particion_[d].part_type);
                                    //printf("%d\n",compa);
                                   if(compa==0){ ParticionesLibres++;

                                    }else if (compa=='p'){ particionesPrimarias++; estadoprimaria=1;

                                    }else if (compa=='e') {particionesextendidas++; estadoextendida=1;

                                    } else if (compa=='l') {estadologica=1;

                                   }else {printf("Error en Type\n");}

                                }
                                printf("ParticioLibres %d, ParticioPrima %d, ParticionesExt %d\n",ParticionesLibres,particionesPrimarias,particionesextendidas);

                                int cantidadpuesta=0;
////////////////////////////////////////////////////// VERIFICAR para poder insertar/////////////////////////////////////////////////////////////
                                if (ParticionesLibres<=4 || (particionesPrimarias<=3 && particionesextendidas==1)){

                                    if (tamanioBytes<=espaciolibre && extendidad==0 && log==0){ //HAGO LAS PRIMARIAS :d
                                        for (int p=0;p<=3;p++) {
                                            printf("Buscando particiones...................... \n");
                                            int sizze=LEER.mbr_particion_[p].part_size;
                                            if (sizze==0){

                                                LEER.mbr_particion_[p].part_status='A';
                                                LEER.mbr_particion_[p].part_type=*dtype;
                                                LEER.mbr_particion_[p].part_fit=*dfit;

                                                for (int u=0;u<=3;u++){
                                                    if (LEER.mbr_particion_[u].part_size>0){
                                                        cantidadpuesta=LEER.mbr_particion_[u].part_size+cantidadpuesta;
                                                    }else {printf("Particion vacia [%d]\n",u);}

                                                }

                                                start=sizeof(MasterBootRecord)+cantidadpuesta +1;
                                                LEER.mbr_particion_[p].part_star=start;
                                                LEER.mbr_particion_[p].part_size=tamanioBytes;
                                                strcpy(LEER.mbr_particion_[p].part_name,nm);
                                                printf("Su partición fue escrita en--> [%d]\n",p);
                                                break;
                                            }else{printf("No hay espacio para almacenar en Partición[%d]\n",p);}
                                        }//FIN DE FOR RECORRER
//////////////////////////////////////////////////////SOBRE ESCRIBIENDO EL ARCHIVO///////////////////////////////////////
                                fseek(fp2,0,SEEK_SET);
                                fwrite(&LEER,sizeof(MasterBootRecord),1,fp2);
                                //fclose(fp2);

////////////////////////////////////////////////////// ESCRIBIR DATOS NUEVOS/////////////////////////////////////////////////////////////

//                                FILE *fp3;

//                                fp3=fopen(l2,"r+");
//                                MasterBootRecord temporal;
//                                fread(&temporal,sizeof(MasterBootRecord),1,fp3);

//                                printf("signature %d , tamanio %d\n",temporal.mbr_disk_signature,temporal.mbr_tamanio);
//                                fclose(fp3);
////////////////////////////////////////////////// CREANDO LAS EXTENDIDAS /////////////////////////////////////////////
                                }else if ( particionesPrimarias<=4 || (extendidad==1 || log==1 )){

/////////////////////////////////////////////////////////////PONIENDO EXTENDIDA/////////////////////////////////////////////////////////////
                                    if (particionesextendidas==0) {
                                        if (tamanioBytes<=espaciolibre){
                                            int cantidadpuesta2=0;
                                            for (int p=0;p<=3;p++) {
                                                printf("Buscando particiones...................... \n");
                                                int sizze=LEER.mbr_particion_[p].part_size;
                                                if (sizze==0){

                                                    LEER.mbr_particion_[p].part_status='A';
                                                    LEER.mbr_particion_[p].part_type=*dtype;
                                                    LEER.mbr_particion_[p].part_fit=*dfit;

                                                    for (int u=0;u<=3;u++){
                                                        if (LEER.mbr_particion_[u].part_size>0){
                                                            cantidadpuesta2=LEER.mbr_particion_[u].part_size+cantidadpuesta2;
                                                        }else {printf("Particion vacia [%d]\n",u);}
                                                    }

                                                    start=sizeof(MasterBootRecord)+cantidadpuesta2+1;
                                                    LEER.mbr_particion_[p].part_star=start;
                                                    LEER.mbr_particion_[p].part_size=tamanioBytes;
                                                    strcpy(LEER.mbr_particion_[p].part_name,nm);
                                                    printf("Su partición fue escrita en--> [%d]\n",p);
                                                    break;
                                                }else{printf("No hay espacio para almacenar en Partición[%d]\n",p);}
                                            }//FIN DE FOR RECORRER
                                        }else {printf("No hay espacio para extendida \n");}
                                    }else {printf("Solo Una extendida puede haber \n");}
///////////////////////////////////////////////////////////////ESCRIBO MI EXTENDIDA  ////////////////////////////////
                                  fseek(fp2,0,SEEK_SET);
                                  fwrite(&LEER,sizeof(MasterBootRecord),1,fp2); //ACTUALIZO EL MBR

                                  //fseek(fp2,sizeof(MasterBootRecord)+1,SEEK_SET);

                                  printf("Escribiendo Extendida........................................ \n");
                                  char letras [2]="1";  //escribo mi extendida en el ARCHIVO....
                                    int i;
                                    for (i=1;i<=tamanioBytes+1;i++){
                                      fseek(fp2,sizeof(MasterBootRecord)+i,SEEK_SET);
                                        fwrite(letras,1,sizeof(letras),fp2);

                                    }
                                      printf("Extendida Escrita.............................................. \n");

                                  //fclose(fp2);

///////////////////////////////////////////////////////////////ESCRIBO EN EL FICHERO EBR////////////////////////////////
ExtendedBootRecord EBR;
                                    if (sizeof(ExtendedBootRecord)<=tamanioBytes) {
                                        EBR.part_status='A';
                                        EBR.part_fit=*dtype;
                                        EBR.part_start= sizeof(MasterBootRecord) +1;
                                        EBR.part_size=tamanioBytes;
                                        EBR.part_next=-1;
                                        strcpy(EBR.part_name,nm);

                                        fseek(fp2,sizeof(MasterBootRecord) +2,SEEK_SET);
                                        fwrite(&EBR,sizeof(ExtendedBootRecord),1,fp2);
                                        //fclose(fp2);

                                    }else {printf("No hay espacio en la Extendida \n");}
//////////////////////////////////////////////////   LEER EL EBR    ///////////////////////////////////////////////////////////////
      //////////////////////////////////////////// PARTICION LOGICA ////////////////////////////////////////////////////////
                                }else if (estadologica==1 && particionesextendidas==1 && particionesPrimarias<=3) {

                                    FILE *fp3=fopen(l2,"rb+"); // ABRO PARA LECTURA Y ESCRITURA
                                   ExtendedBootRecord EBRLeer;

                                    // MBR PARA LEER EL ARCHIVO Y DATOS ANTIGUOS
                                    fread(&EBRLeer,sizeof(ExtendedBootRecord),1,fp3);

                                    printf("Tamaño %d , Tamaño EBR %d\n",EBRLeer.part_size, sizeof(MasterBootRecord));//DATOS DEL MBR

                                    EBRLeer.part_status='A';
                                    EBRLeer.part_fit=*dtype;
                                    EBRLeer.part_start= sizeof(MasterBootRecord) +1;
                                    EBRLeer.part_size=tamanioBytes;
                                    EBRLeer.part_next=sizeof(MasterBootRecord)+sizeof(ExtendedBootRecord)+EBRLeer.part_size-1;
                                    strcpy(EBRLeer.part_size,nm);

                                    fseek(fp3,sizeof(MasterBootRecord)+sizeof(ExtendedBootRecord)+EBRLeer.part_size+1,SEEK_SET);
                                    fwrite(&EBRLeer,sizeof(MasterBootRecord),1,fp3);



                                    //fclose(fp3);

                                }else{printf("No hay espacio disponible en el disco\n");}

                                 // IF DE PARTICIONES

                                 }else {printf("Ya no hay particiones libres \n");}
                               fclose(fp2);
                                 }else {printf("Ya no se puede escribir mas particiones \n");}   // PARTICIONES LIBRES
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                            if (EstadDELETE==1){

                                int confirmacion=0;
                                char *fichero= strcat(l2,"\0");  //strcat(dPath,dname);
                                FILE *fp3=fopen(l2,"rb+"); // ABRO PARA LECTURA Y ESCRITURA

                                MasterBootRecord ArDELETE;
                                // MBR PARA LEER EL ARCHIVO Y DATOS ANTIGUOS
                                fread(&ArDELETE,sizeof(MasterBootRecord),1,fp3);
                                printf("Signature %d , Tamaño Total Del disco %d , Tamaño MBr %d\n",ArDELETE.mbr_disk_signature,ArDELETE.mbr_tamanio, sizeof(MasterBootRecord));//DATOS DEL MBR
                                //fclose(fp2);

                                if (strncasecmp(deleminar, "full",4)==0){
                                    printf("Partición a eliminar....%s \n",fichero);
                                    printf("\n --Desea elimnar la partición --(1.SI - 2.NO)-- \n");
                                    scanf( "%d", confirmacion );

                                    if (confirmacion==1){
                                        for (int p=0;p<=3;p++) {
                                            printf("Buscando particiones...................... \n");
                                            char* nomcomparar=ArDELETE.mbr_particion_[p].part_name;
                                            if (strcasecmp(nomcomparar,dname)==0){

                                                for (int d=0;d<=3;d++) {
                                                    ArDELETE.mbr_particion_[p].part_status='\0';
                                                    ArDELETE.mbr_particion_[p].part_type='\0';
                                                    ArDELETE.mbr_particion_[p].part_fit='\0';
                                                    ArDELETE.mbr_particion_[p].part_star=0;
                                                    ArDELETE.mbr_particion_[p].part_size=0;
                                                    for(int x=0;x<15;x++){ArDELETE.mbr_particion_[p].part_name[x]="\0";}
                                                }

                                            }else {printf("No se encontró la partición \n");}
                                        }

                                    }else {printf("Partición no Eliminada-------\n");}


                                }else if (strncasecmp(deleminar, "fast",4)==0){
                                    printf("Partición a eliminar....%s \n",fichero);
                                    printf("\n --Desea elimnar la partición --(1.SI - 2.NO)-- \n");
                                    scanf( "%d", confirmacion );

                                    if (confirmacion==1){
                                        for (int p=0;p<=3;p++) {
                                            printf("Buscando particiones...................... \n");
                                            char* nomcomparar=ArDELETE.mbr_particion_[p].part_name;
                                            if (strcasecmp(nomcomparar,dname)==0){

                                                for (int d=0;d<=3;d++) {
                                                    ArDELETE.mbr_particion_[p].part_size=0;
                                                }

                                            }else {printf("No se encontró la partición \n");}
                                        }//TERMINA EL FOR

                                    }else {printf("Partición no Eliminada-------\n");}


                                }else {printf("Parametros de error en DELETE");}



                            }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            if (EstadoAdd==1) {
                                char *fichero=strcat(dPath,dname);  strcat(fichero,"\0");
                                printf("Partición para agregar....%s",fichero); int UnidadesAdd=tamanioBytes;

                            }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                        }// IF DEL ESTADO PRINCIPAL DEL ESTADO///////////////////////
                            else {printf("Error en parametros de entrada \n");}


                    }                         memset(&Guardar2[0], 0, sizeof(Guardar2)); memset(&Guarda[0], 0, sizeof(Guarda)); ll=0,aa=0,gg=0; pp=0;  break;   //IFFFFFFFFFFFFFFFFFFFFFF FDISK

                     if (strcasecmp((*(Palabra2 + z)), "mount")==0){
                         char *nombre="";char *p="";
                         char *Path2,*Palacena2;
                         char *l2;
                         int Mdiscos = 0;int existeD = 0; int existeP = 0; // discos creados/ existedisco /existepartición

                         printf("--------------Entra MOUNT--------------\n");

                         int y;
                         for (y=(z+1); *(Palabra2 + y); y++){

                             if(strncasecmp((*(Palabra2 + y)), "-path",5)==0)
                             {
                                 FILE *ficheroparamontar;
                                 ficheroparamontar = fopen( l2, "r+b" );
                                 printf("----------------------------------------\n");
                                 if(ficheroparamontar!=NULL){

                                     printf("EntraPath\n");

                                     Path2=strtok(*(Palabra2 + y),"::");
                                     Palacena2=strtok(NULL,"::");
                                     l2=strtok(Palacena2,"\"");
                                     strcat(l2,"\0");
                                     printf("--> %s\n",Path2);
                                     printf("Fichero --> %s\n",l2);
                                     printf("----------------------------------------\n");

                                 }else {printf("Fichero NO Existe->\n");}

                             } else if (strncasecmp((*(Palabra2 + y)), "-name",5)==0) {
                                 printf("----------------------------------------\n");
                                 printf("EntraName\n");
                                 char *th=strtok(*(Palabra2 + y),"::");
                                 nombre=strtok(NULL,"::");
                                 p=strtok(nombre,"\"");
                                 strcat(p,"\0");
                                 printf("--> %s\n",th);
                                 printf("Nombre--> %s\n",p);
                                 printf("----------------------------------------\n");

                             }else {printf("Error en los parametros de entrada \n");}
                         }// FIN DEL FOR MOUNT

                        //COMENZAMOS A MONTAR LA PARTICION

                        //VERIFICA SI EXISTE EN EL VECTOR ALGUNA P.MONTADA
                         for(int b = 0; b < 26; b++){
                               if(strcmp(l2,montada[b].path)==0){
                                    existeD = 1; Mdiscos = b;

                                   printf("Si existe la partición\n");
                                break;
                               }
                           }
                         // SI NO EXISTE EL DISco LO HACE
                         if(existeD == 0){
                                 for(int z = 0; z < 26; z++){
                                     if(strcmp(montada[z].path,"")==0){ //(strcnmp(montada[z].path,p,sizeof p)
                                         strcpy(montada[z].path,l2);
                                      Mdiscos = z;
                                       printf("Creación del disco\n");
                                      break;
                                     }
                                 }
                             }

                         //VERIFICO SI FUE MONATA LA PARTICIÓN ANTERIORMENTE
                             for(int f=0; f<20; f++){
                                 if(strcmp(montada[Mdiscos].contenido[f].clave,p)==0){  //(strcnmp(montada[Mdiscos].contenido[f].clave,p,sizeof p)
                                     existeP = 1;
                                        printf("Ya existe [%s]\n",p);
                                     break;
                                 }
                             }
                            //Guardo si no existe mi partición en el vector
                             if(existeP == 0){
                                     for(int n=0; n<20; n++){
                                       if(strcmp(montada[Mdiscos].contenido[n].clave,"")==0){
                                             strcpy(montada[Mdiscos].contenido[n].clave,p);
                                           printf("partición Montada [%s]\n",p);
                                           break;
                                         }
                                     }
                                 }else{
                                    printf("Partición ya montada, no se puede volver a montar.\n");
                                 }

                        }// IF DEL MOUNT

                     else {printf("Error en los comandos de entrada \n");}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                     if (strcasecmp((*(Palabra2 + z)), "umount")==0){






                     }

            }      //FOOOOOOOOOOOOOOOOOOOR PRINCIPAL
            }  //if palabraaaa2



        } // ESTADO 2 IF

          //pp=2;
printf("\n TERMINA LEÍDA DEL ARCHIVO.... ADIOOOOOOOOOOOOOOOOOOOOOS \0 .....\n \n");
          pp=0;
    } // del whileeee


    return 0;
}

