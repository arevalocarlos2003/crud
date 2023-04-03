#include <iostream>


using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
    int codigo;
    char nombres[50];
    char apellidos[50];
    int telefono;
};
void Leer();
void Crear();

int main(){
    int option = 0;
    cout<<"Que desea hacer?"<<endl;
    cout<<"option: "<<endl<<"1: Leer"<<endl<<"2: Crear"<<endl;
    cin>>option;
    switch (option){
        case 1:
            Leer();
            break;
        case 2:
            Crear();
            break;
        default:
            "no se eligio ninguna opcion valida cerrando programa...";
            break;
    }
    return 0;
}
void Leer(){
    system("clear");
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo){
        archivo = fopen(nombre_archivo, "w+b");
    }
    Estudiante estudiante;
    int id = 0; //indice de registro dentro del archivo
    fread(&estudiante, sizeof(Estudiante), 1, archivo);
    cout<<"==================================================="<<endl;
    cout<<"id"<<"|"<<"codigo"<<"|"<<"nombres"<<"|"<<"apellidos"<<"|"<<"telefono"<<endl;
    do{
        cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
        fread(&estudiante, sizeof(Estudiante), 1, archivo);
        id++;

    }while(feof(archivo)==0);
    fclose(archivo);
}
void Crear(){
    FILE* archivo = fopen(nombre_archivo, "a+b");
    char res;
    Estudiante estudiante;

    do{
        fflush(stdin);
        cout<<"Ingrese codigo: ";
        cin>>estudiante.codigo;
        cin.ignore();

        cout<<"Ingrese nombres: "<<endl;
        cin.getline(estudiante.nombres, 50);

        cout<<"Ingrese apellidos: ";
        cin.getline(estudiante.apellidos, 50);

        cout<<"Ingrese numero de telefono: ";
        cin>>estudiante.telefono;

        fwrite(&estudiante,sizeof(Estudiante), 1, archivo);

        cout<<"desea ingresar otro estudiante (s/n)"<<endl;
        cin>>res;
    }while(res == 's' || res == 'S');
    fclose(archivo);
    Leer();
}
