#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#define MAX 4
#define MIN 0
using namespace std;
const char FINCAD = char(0);
const int MAXCAD = 20;
const char SP = ' ';
char contrasena;
int i,op2=0;
int contador=0;
typedef char TCadena[MAXCAD+1];
struct Persona_R{
    TCadena CONTRA;
};
struct USUARIO{
    char cedula[11];
    char nombre[20];
    int edad;
}jugador;
void menue();
void AgregarJ();
void VerJ();
void gotoxy( int column, int line );
int wherex();
int wherey();
int NFicheros();
void EA();
void EB();
void EC();
void maind();
void menu();
void LOGIN();
void finalizar_programa();
void borrar_pantalla();
void Ingresar_CONTRA(Persona_R &p);
void confirmar_CONTRA(Persona_R &p);
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p);
void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p);
void verificar_existencia_fichero(TCadena nombreFichero);
void verificar_existencia_de_usuario(TCadena nombreFichero);
void verificar_contrasena(TCadena nombreFichero,Persona_R &password);
void EscogerEquipo(int op);
struct Clientes{
    char cedula[11];
    char nombre[20];
    int edad;
};
struct EQUIPOS{
    char N_entrenador[20]="";
    char C_entrenador[20]="";
    int id_equipo;
    char NOM_equipo[20]="";
}equipo;
void bienvenido();
void menueA();
void AgregarJA();
void VerJA();
void MostrarA();
void menueB();
void AgregarJB();
void VerJB();
void MostrarB();
void menueC();
void AgregarJC();
void VerJC();
void MostrarC();
void inciio();
int menu(int elec);
void A_Cliente();
void V_clientes();
void M_Clientes();
void E_Clientes();
int Localizar(string CedB);
bool CambiarDatos(int ubicacion);
void programa();
void EntrarEquipo(int op);

int main()
{
    system("color F3");
    inciio();
}
void bienvenido(){
    cout<<endl<<"\t--------------------------------------------"<<endl;
    cout<<endl<<"\t         BIENVENIDO AL PROGRAMA"<<endl;
    cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
}
void inciio(){
    system("cls");
    system("color F3");
    string n_ingreso;
    string c_ingreso;
    string N_admin="administrador";
    string C_admin="admin";
    int cont=0;
    ofstream A_inciio();
    do{
            fflush(stdin);
            system("cls");
    bienvenido();
    cout<<"\nINGRESE NOMBRE DEL ADMIN:     ";
    getline(cin,n_ingreso);
    fflush(stdin);
    cout<<"\nINGRESE CONTRASEÑA DEL ADMIN:     ";
    getline(cin,c_ingreso);
    fflush(stdin);
    if(n_ingreso == N_admin && c_ingreso==C_admin){
        cout<<"\n ADMINISTRADOR CORRECTO \n"<<"\n INGRESANDO . . . . \n";
        Sleep(1000);
        system("cls");
        LOGIN();
    }else{
        cout<<endl<<"ADMIN INCORRECTO \n\n""INTENTE NUEVAMENTE !"<<endl;
        system("pause");
        fflush(stdin);
        cont++;
    }}while(cont<3);
    fflush(stdin);
            cout<<endl<<"SIN NUMERO DE INTENTOS !! "<<endl<<"SALIENDO DEL PROGRAMA"<<endl;
        Sleep(2000);
        exit(1);
}
void LOGIN(){
    Persona_R p;
    Persona_R password;
    char opcion;
    int num, AUX2, nom2;
    bool fin,encontrado;
    TCadena nombre_usuario_registrado;
    int opcion_menu;
    bienvenido();
    M_ADMIN:
    system("cls");
    cout<<endl<<"\t--------------------------------------------"<<endl;
    cout<<endl<<"\t           MENU DEL ADMINISTRADOR"<<endl;
    cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    //cout<<"1. INICIAR SESION"<<endl;
    cout<<"1. CREAR ENTRENADOR" << endl;
    cout<<"2. INGRESAR COMO ENTREADOR "<<endl;
    cout<<"3. SALIR DEL PROGRAMA"<<endl;
    cout<<endl<<endl;
    cout<<"SELECCIONE SU OPCION:  ";
    cin>>opcion_menu;
    fflush(stdin);
    if (opcion_menu==3) {finalizar_programa();}
    if((opcion_menu<MIN)||(opcion_menu>MAX)){
    try {
            system("cls");
            cout<<"\n\n\t | ESTA OPCION  ES INCORRECTA |\n"<<endl;
            system("pause");
            system("cls");
            main();
        }
        catch(...)
        {cout << "\n UN ERROR HA OCURRIDO " << endl; } }
    switch(opcion_menu){
        case 1:
            {
                system("cls");
                EQUIPOS equipo;
                ofstream manejoequipo("EQUIPOS.txt",ios::app);
                cout<<endl<<"\t--------------------------------------------"<<endl;
                cout<<endl<<"\t            INGRESO NUEVO ENTRENADOR"<<endl;
                cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
                fflush(stdin);
                cout<<"INGRESE NOMBRE ENTRENADOR:            ";
                cin.getline(equipo.N_entrenador,20);
                fflush(stdin);
                cout<<endl<<"INGRESE CONTRASEÑA DEL ENTRENADOR:    ";
                cin.getline(equipo.C_entrenador,20);
                fflush(stdin);
                cout<<endl<<"1. EQUIPO A"<<endl<<"2. EQUIPO B"<<endl<<"3. EQUIPO C"<<endl<<"ESCRIBE EL EQUIPO:     EQUIPO ";
                cin>>equipo.id_equipo;
                op2=equipo.id_equipo;
                fflush(stdin);
                manejoequipo.write((char *)&equipo,sizeof(equipo));
                cout<<endl<<"EQUIPO AGREGADO A LA LIGA CORRECTAMENTE !!\n"<<endl;
                system("pause");
                manejoequipo.close();
                goto M_ADMIN;
            }
        case 2:{
            system("cls");
            string AUX;
            string nom;
            ifstream lec_equipos("EQUIPOS.txt");
            cout<<endl<<"\t--------------------------------------------"<<endl;
            cout<<endl<<"\t            ENTRENADOR "<<endl;
            cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
            cout<<"\nINGRESE SU NOMBRE DE USUARIO:     ";
            getline(cin,nom);
            fflush(stdin);
            lec_equipos.read((char*)&equipo,sizeof(equipo));
            while(lec_equipos && !lec_equipos.eof()){
            AUX=equipo.N_entrenador;
            if(nom==AUX){
                cout<<"ENTRENADOR ENCONTRADO... "<<equipo.N_entrenador<<endl<<endl;
                EntrarEquipo(equipo.id_equipo);
                 system("pause");
            }else{
                cout<<"\n USUIARIO NO ENCONTRADO "<<endl<<endl;
                system("pause");
                goto M_ADMIN;
            }
                lec_equipos.read((char*)&equipo,sizeof(equipo));
            }
        lec_equipos.close();

            system("cls");
            goto M_ADMIN;
        }
    }
}
void finalizar_programa(){
    system("cls");
    printf("EL PROGRAMA CERRARA EN CUALQUIER MOMENTO"); Sleep(200);
    exit(0);
}
void Ingresar_CONTRA(Persona_R &p){
    cout<<"ESCRIBA SU NUEVA CONTRASEÑA:                 ";
    cin>>p.CONTRA;
    cout<<"\nSE HA REGISTRADO CORRECTAMENTE"<<endl;
}
void confirmar_CONTRA(Persona_R &password){
    cout<<"ESCRIBA SU CONTRASENA:           ";
    cin >> password.CONTRA;
}
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p){
    ofstream out("LOGIN.txt",ios::out);
    struct Clientes persona;
    out.open(nombreFichero,ios::app);
    if(out.bad()){
            out.open(nombreFichero);
        }
    EscribePersonaFicheroTXT(out,p);
    out.write((char*)&persona,sizeof(persona));
    out.close();
}
void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p){
    fichero<<p.CONTRA<<SP;
}
void verificar_existencia_fichero(TCadena nombreFichero){
    ifstream archivo(nombreFichero);
    if (!archivo){
         cout<<endl<<"Nombre de Usuario INCORRECTO.....INTENTELO DE NUEVO"<<endl<<endl; system("pause"); system("cls");main();
     }else{
            cout<<endl<<"Nombre de Usuario CORRECTO..!!!"<<endl<<endl;
        }
}
void verificar_existencia_de_usuario(TCadena nombreFichero){
    ifstream archivo(nombreFichero);
    if (!archivo){
        cout<<"\nNombre de Usuario DISPONIBLE\n"<<endl;system("pause");
    }else{
          cout<<"\n Este Nombre de Usuario ya Existe.....INTENTELO DE NUEVO"<<endl; system("pause"); system("cls");main();
        }
}
void verificar_contrasena(TCadena nombreFichero,Persona_R &password){
    string cadena;
    string contrase;
    cout << "ESCRIBA SU CONTRASENA:           " ;
    cin >> password.CONTRA;
    ifstream fichero(nombreFichero,ios::in);
    while(!fichero.eof()) {
       fichero>>cadena;
    }
    if(cadena!=password.CONTRA){
       cout<<endl<<"CONTRASENA ES INCORRECTO ... INTENTELO DE NUEVO"<<endl<<endl;system("pause");
       fichero.close();}
    if(cadena==password.CONTRA){
       cout<<endl<<"Su CONTRASEÑA es CORRECTA..!!!"<<endl<<endl; system("pause"); system("cls");
       programa();
    }
}
int menu(int elec){
    system("cls");
    cout<<endl<<"\t--------------------------------------------"<<endl;
    cout<<endl<<"\t           MENU DEL ADMINISTRADOR"<<endl;
    cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    cout<<"1. AGREGAR JUGADORES "<<endl;
    cout<<"2. MOSTRAR JUGADORES "<<endl;
    cout<<"3. MODIFICAR JUGADORES "<<endl;
    cout<<"4. ELIMINAR JUGADORES "<<endl<<endl;
    cout<<"PRESIENE OTRO PARA VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"SELECIONE UNA OPCION: "; cin>>elec;
    return elec;
}
void A_Cliente(){
    ofstream archivoG("AGREGARJ.txt",ios::app);
    Clientes persona;
    cout<<endl<<"\t--------------------------------------------"<<endl;
    cout<<endl<<"\t            INGRESO NUEVO JUGADOR"<<endl;
    cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    fflush(stdin);
    cout<<"INGRESE CEDULA JUGADOR NUEVO: ";
    cin.getline(persona.cedula,11);
    fflush(stdin);
    cout<<endl<<"INGRESE NOMBRE JUGADOR NUEVO: ";
    cin.getline(persona.nombre,20);
    fflush(stdin);
    cout<<endl<<"INGRESE EDAD JUGADOR NUEVO: ";
    cin>>persona.edad;
    fflush(stdin);
    archivoG.write((char *)&persona,sizeof(persona));
    cout<<endl<<endl<<"JUGADOR AGREGADO CORRECTAMENTE !! "<<endl;
    system("pause");
    archivoG.close();
}
void V_clientes(){
    system("cls");
    struct Clientes persona;
    ifstream archivoM("AGREGARJ.txt");
    if(archivoM.fail()){
        cout<<endl<<"NO SE PUDO ENCONTRAR EL ARCHIVO \n";
    }else{
    archivoM.read((char*)&persona,sizeof(persona));
    cout<<endl<<"\t--------------------------------------------"<<endl;
    cout<<endl<<"\t            BASE DE DATOS"<<endl;
    cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    cout<<"\tCEDULA\t\tNOMBRE\t\t\tEDAD\t\tCATEGORIA"<<endl;
    while(archivoM && !archivoM.eof()){
        cout<<persona.cedula<<"\t\t"<<persona.nombre<<"\t\t"<<persona.edad<<"\t\t";
         if (persona.edad<=18)
                {
                    cout<<"JUVENIL"<<endl;
                }
            if (persona.edad>18 && persona.edad<=40)
                {
                    cout<<"SENIOR"<<endl;
                }
            if (persona.edad>40)
                {
                    cout<<"MASTER"<<endl;
                }
        archivoM.read((char*)&persona,sizeof(persona));
    }
    cout<<endl;
    }
    archivoM.close();
}
void M_Clientes(){
    char CedB[11];
    int ubicacion;
    system("cls");
    V_clientes();
    fflush(stdin);
    cout<<endl<<"INGRESE CEDULA A BUSCAR: ";
    cin.getline(CedB,11);
    fflush(stdin);
    ubicacion = Localizar(CedB);
    if(ubicacion>0){
        if(CambiarDatos(ubicacion)){
            cout<<endl<<"JUGADOR CAMBIADO EXITOSAMENTE"<<endl;
        }else{
            cout<<endl<<"JUGADOR NO EXISTE "<<endl;
        }
    }
}
int Localizar(string CedB){
    USUARIO JGD;
    int cont=0;
    string AUX;
    ifstream archivoM("AGREGARJ.txt");
    archivoM.read((char*)&JGD,sizeof(JGD));
    while(archivoM && !archivoM.eof()){
        cont++;
        AUX=JGD.cedula;
        if(CedB==AUX){
            cout<<"JUGADOR ENCONTRADO: "<<JGD.nombre<<endl;
            system("pause");
            return cont;
        }
        archivoM.read((char*)&JGD,sizeof(JGD));
    }
    archivoM.close();
    return 0;
}
bool CambiarDatos(int ubicacion){
    try{
    struct USUARIO persona;
    cout<<endl<<"\t--------------------------------------------"<<endl;
    cout<<endl<<"\t            ACTUALIZACION DEL JUGADOR"<<endl;
    cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    fflush(stdin);
    cout<<"INGRESE NUEVA CEDULA:  ";
    cin.getline(persona.cedula,11);
    fflush(stdin);
    cout<<endl<<"INGRESE NUEVO NOMBRE: ";
    cin.getline(persona.nombre,20);
    fflush(stdin);
    cout<<endl<<"INGRESE EDAD JUGADOR NUEVO: ";
    cin>>persona.edad;
    fstream archivoCam("AGREGARJ.txt");
    archivoCam.seekg((ubicacion-1)*sizeof(persona),ios::beg);
    archivoCam.write((char*)&persona,sizeof(persona));
    archivoCam.close();
    return true;
    }catch(exception e){
        cout<<endl<<endl<<"OCURRIO UN ERROR"<<e.what()<<endl;
        return false;
    }
}
void E_Clientes(){
    struct Clientes persona;
    ifstream salida;
    salida.open("REGISTRO.txt",ios::in);
    ofstream entrada;
    entrada.open("temporal.txt",ios::out);
    if(salida.fail()){
        cout<<"HUBO UN ERROR AL ABRIR EL ARCHIVO ";
        getch();

    }else{
        char cedulaEliminar[20];
        cout<<"INTRODUCE CEDULA DE LA PERSONA: ";
        cin>>cedulaEliminar;
        fflush(stdin);
        salida>>persona.cedula;
        while(!salida.eof()){
                salida>>persona.nombre>>persona.edad;
            if(strcmp(cedulaEliminar,persona.cedula)==0){
                cout<<endl<<"JUGADOR ELIMINADO "<<endl;
                getch();
            }else{
                entrada<<persona.cedula<<" "<<persona.nombre<<" "<<persona.edad<<endl;
            }
            salida>>persona.cedula;
        }
     entrada.close();
     salida.close();
     remove("REGISTRO.txt");
     rename("temporal.txt","REGISTRO.txt");
    }
}
void programa(){
    int op=0;
    MENU:
    system("cls");
    op=menu(op);
    switch(op){
    case 1:
        system("cls");
        A_Cliente();
        goto MENU;
    case 2:
        V_clientes();
        cout<<endl;
        system("pause");
        goto MENU;
    case 3:
        M_Clientes();
        cout<<endl;
        system("pause");
        goto MENU;
    case 4:
        E_Clientes();
        cout<<endl;
        system("pause");
        goto MENU;
    default:
        cout<<endl<<"ESPERE UN MOMENTO ... VOLVIENDO AL MENU PRINCIPAL"<<endl; Sleep(2000);
        break;
    }
}
void maind(){
    int EqA, EqB, EqC;
    if(EqA=EqA){
            EA();
       }
    if(EqB=EqB){
            EB();
       }
    if(EqC=EqC){
            EC();
       }else{
            cout<<"USUARIO NO EXISTE"<<endl<<endl;
       }
}
void menueA(){
    int opA;
    MENU:
    cout<<"1. AGREGAR NUEVOS JUGADORES"<<endl<<"2. VER LISTA DE JUGADORES"<<endl<<"3. MODIFICAR JUGADOR "<<endl<<endl<<"PRESIONE CUALQUIER NUMERO PARA RETROCEDER"<<endl<<endl<<"SELECCIONE SU OPCION: ";
    cin>>opA; cout<<endl;
    system("pause");
    system("cls");
    switch(opA){
        case 1:
            AgregarJA();
            system("pause");
            system("cls");
            goto MENU;
            break;
        case 2:
            VerJA();
            system("pause");
            system("cls");
            goto MENU;
            break;
        case 3:
            MostrarA();
            system("pause");
            system("cls");
            goto MENU;
        default:
            LOGIN();
     }
     cout<<endl<<endl;
}
void menueB(){
    int opB;
    MENU:
    cout<<"1. AGREGAR NUEVOS JUGADORES"<<endl<<"2. VER LISTA DE JUGADORES"<<endl<<"3. MODIFICAR JUGADOR "<<endl<<endl<<"PRESIONE CUALQUIER NUMERO PARA RETROCEDER"<<endl<<endl<<"SELECCIONE SU OPCION: ";
    cin>>opB; cout<<endl;
    system("pause");
    system("cls");
    switch(opB){
        case 1:
            AgregarJB();
            system("pause");
            system("cls");
            goto MENU;
            break;
        case 2:
            VerJB();
            system("pause");
            system("cls");
            goto MENU;
            break;
        case 3:
            MostrarB();
            system("pause");
            system("cls");
            goto MENU;
        default:
            LOGIN();
     }
     cout<<endl<<endl;
}
void menueC(){
    int opC;
    MENU:
    cout<<"1. AGREGAR NUEVOS JUGADORES"<<endl<<"2. VER LISTA DE JUGADORES"<<endl<<"3. MODIFICAR JUGADOR "<<endl;
    cout<<endl<<"PRESIONE CUALQUIER NUMERO PARA RETROCEDER"<<endl<<endl<<"SELECCIONE SU OPCION: ";
    cin>>opC;
    cout<<endl;
    system("pause");
    system("cls");
    switch(opC){
        case 1:
            AgregarJC();
            system("pause");
            system("cls");
            goto MENU;
            break;
        case 2:
            VerJC();
            system("pause");
            system("cls");
            goto MENU;
            break;
        case 3:
            MostrarC;
            system("pause");
            system("cls");
            goto MENU;
        default:
            LOGIN();
     }
     cout<<endl<<endl;
}
void MostrarA(){
    char CedB[11];
    int ubicacion;
    system("cls");
    VerJA();
    fflush(stdin);
    cout<<endl<<"INGRESE CEDULA A BUSCAR: ";
    cin.getline(CedB,11);
    fflush(stdin);
    ubicacion = Localizar(CedB);
    if(ubicacion>0){
        if(CambiarDatos(ubicacion)){
            cout<<endl<<"JUGADOR CAMBIADO EXITOSAMENTE"<<endl;
            system("pause");
        }else{
            cout<<endl<<"JUGADOR NO EXISTE "<<endl;
            system("pause");
        }
    }
}
void MostrarB(){
    char CedB[11];
    int ubicacion;
    system("cls");
    VerJB();
    fflush(stdin);
    cout<<endl<<"INGRESE CEDULA A BUSCAR: ";
    cin.getline(CedB,11);
    fflush(stdin);
    ubicacion = Localizar(CedB);
    if(ubicacion>0){
        if(CambiarDatos(ubicacion)){
            cout<<endl<<"JUGADOR CAMBIADO EXITOSAMENTE"<<endl;
            system("pause");
        }else{
            cout<<endl<<"JUGADOR NO EXISTE "<<endl;
            system("pause");
        }
    }
}
void MostrarC(){
    char CedB[11];
    int ubicacion;
    system("cls");
    VerJC();
    fflush(stdin);
    cout<<endl<<"INGRESE CEDULA A BUSCAR: ";
    cin.getline(CedB,11);
    fflush(stdin);
    ubicacion = Localizar(CedB);
    if(ubicacion>0){
        if(CambiarDatos(ubicacion)){
            cout<<endl<<"JUGADOR CAMBIADO EXITOSAMENTE"<<endl;
            system("pause");
        }else{
            cout<<endl<<"JUGADOR NO EXISTE "<<endl;
            system("pause");
        }
    }
}
void VerJA(){
    ifstream archivoMEA("AGREGARJA.txt");
    gotoxy(4,1); cout<<endl<<"\t---------------------------------------------------"<<endl;
    gotoxy(4,2); cout<<endl<<"\t               LISTADO DE JUGADORES"<<endl;
    gotoxy(4,3); cout<<endl<<"\t---------------------------------------------------"<<endl<<endl;
    gotoxy(0,7); cout<<"\tCEDULA\t"; fflush(stdin);
    gotoxy(23.5,7); cout<<"\tNOMBRE\t"; fflush(stdin);
    gotoxy(40,7); cout<<"\tEDAD\t"; fflush(stdin);
    gotoxy(63,7); cout<<"\tCATEGORIA\t"<<endl; fflush(stdin);
     while(archivoMEA && !archivoMEA.eof()){
        cout<<"      "<<jugador.cedula<<"\t"<<jugador.nombre<<"\t "<<jugador.edad<<"\t\t     ";
         if (jugador.edad<=18){
                    cout<<"JUVENIL"<<endl;
                }
            if (jugador.edad>18 && jugador.edad<=40){
                    cout<<"SENIOR"<<endl;
                }
            	if (jugador.edad>40){
                    cout<<"MASTER"<<endl;
                }
        archivoMEA.read((char*)&jugador,sizeof(jugador));
    }
    cout<<endl;
    archivoMEA.close();
}
void VerJB(){
    ifstream archivoMEB("AGREGARJB.txt");
    gotoxy(4,1); cout<<endl<<"\t---------------------------------------------------"<<endl;
    gotoxy(4,2); cout<<endl<<"\t               LISTADO DE JUGADORES"<<endl;
    gotoxy(4,3); cout<<endl<<"\t---------------------------------------------------"<<endl<<endl;
    gotoxy(0,7); cout<<"\tCEDULA\t"; fflush(stdin);
    gotoxy(23.5,7); cout<<"\tNOMBRE\t"; fflush(stdin);
    gotoxy(40,7); cout<<"\tEDAD\t"; fflush(stdin);
    gotoxy(63,7); cout<<"\tCATEGORIA\t"<<endl; fflush(stdin);
     while(archivoMEB && !archivoMEB.eof()){
        cout<<"      "<<jugador.cedula<<"\t"<<jugador.nombre<<"\t "<<jugador.edad<<"\t\t     ";
         if (jugador.edad<=18){
                    cout<<"JUVENIL"<<endl;
                }
            if (jugador.edad>18 && jugador.edad<=40){
                    cout<<"SENIOR"<<endl;
                }
            	if (jugador.edad>40){
                    cout<<"MASTER"<<endl;
                }
        archivoMEB.read((char*)&jugador,sizeof(jugador));
    }
    cout<<endl;
    archivoMEB.close();
}
void VerJC(){
    ifstream archivoMEC("AGREGARJC.txt");
    gotoxy(4,1); cout<<endl<<"\t---------------------------------------------------"<<endl;
    gotoxy(4,2); cout<<endl<<"\t               LISTADO DE JUGADORES"<<endl;
    gotoxy(4,3); cout<<endl<<"\t---------------------------------------------------"<<endl<<endl;
    gotoxy(0,7); cout<<"\tCEDULA\t"; fflush(stdin);
    gotoxy(23.5,7); cout<<"\tNOMBRE\t"; fflush(stdin);
    gotoxy(40,7); cout<<"\tEDAD\t"; fflush(stdin);
    gotoxy(63,7); cout<<"\tCATEGORIA\t"<<endl; fflush(stdin);
     while(archivoMEC && !archivoMEC.eof()){
        cout<<"      "<<jugador.cedula<<"\t"<<jugador.nombre<<"\t "<<jugador.edad<<"\t\t     ";
         if (jugador.edad<=18){
                    cout<<"JUVENIL"<<endl;
                }
            if (jugador.edad>18 && jugador.edad<=40){
                    cout<<"SENIOR"<<endl;
                }
            	if (jugador.edad>40){
                    cout<<"MASTER"<<endl;
                }
        archivoMEC.read((char*)&jugador,sizeof(jugador));
    }
    cout<<endl;
    archivoMEC.close();
}
void AgregarJA(){
    ofstream archivoGEA("AGREGARJA.txt",ios::app);
    gotoxy(4,1);cout<<endl<<"\t--------------------------------------------"<<endl;
    gotoxy(4,2);cout<<endl<<"\t            INGRESO DE NUEVO JUGADOR"<<endl;
    gotoxy(4,3);cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    fflush(stdin);
    cout<<"INGRESE CEDULA JUGADOR NUEVO: ";
    cin.getline(jugador.cedula,11);
    fflush(stdin);
    cout<<endl<<"INGRESE NOMBRE JUGADOR NUEVO: ";
    cin.getline(jugador.nombre,20);
    fflush(stdin);
    cout<<endl<<"INGRESE EDAD JUGADOR NUEVO: ";
    cin>>jugador.edad;
    fflush(stdin);
    archivoGEA.write((char *)&jugador,sizeof(jugador));
    cout<<endl<<endl<<"JUGADOR AGREGADO CORRECTAMENTE !! "<<endl<<endl;
    archivoGEA.close();
}
void AgregarJB(){
    ofstream archivoGEB("AGREGARJB.txt",ios::app);
    gotoxy(4,1);cout<<endl<<"\t--------------------------------------------"<<endl;
    gotoxy(4,2);cout<<endl<<"\t            INGRESO DE NUEVO JUGADOR"<<endl;
    gotoxy(4,3);cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    fflush(stdin);
    cout<<"INGRESE CEDULA JUGADOR NUEVO: ";
    cin.getline(jugador.cedula,11);
    fflush(stdin);
    cout<<endl<<"INGRESE NOMBRE JUGADOR NUEVO: ";
    cin.getline(jugador.nombre,20);
    fflush(stdin);
    cout<<endl<<"INGRESE EDAD JUGADOR NUEVO: ";
    cin>>jugador.edad;
    fflush(stdin);
    archivoGEB.write((char *)&jugador,sizeof(jugador));
    cout<<endl<<endl<<"JUGADOR AGREGADO CORRECTAMENTE !! "<<endl<<endl;
    archivoGEB.close();
}
void AgregarJC(){
    ofstream archivoGEC("AGREGARJC.txt",ios::app);
    gotoxy(4,1);cout<<endl<<"\t--------------------------------------------"<<endl;
    gotoxy(4,2);cout<<endl<<"\t            INGRESO DE NUEVO JUGADOR"<<endl;
    gotoxy(4,3);cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    fflush(stdin);
    cout<<"INGRESE CEDULA JUGADOR NUEVO: ";
    cin.getline(jugador.cedula,11);
    fflush(stdin);
    cout<<endl<<"INGRESE NOMBRE JUGADOR NUEVO: ";
    cin.getline(jugador.nombre,20);
    fflush(stdin);
    cout<<endl<<"INGRESE EDAD JUGADOR NUEVO: ";
    cin>>jugador.edad;
    fflush(stdin);
    archivoGEC.write((char *)&jugador,sizeof(jugador));
    cout<<endl<<endl<<"JUGADOR AGREGADO CORRECTAMENTE !! "<<endl<<endl;
    archivoGEC.close();
}
void gotoxy( int column, int line ){
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}
int wherex(){
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
}
int wherey(){
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
}
void EA(){
    system("cls");
    gotoxy(4,1); cout<<endl<<"\t--------------------------------------------"<<endl;
    gotoxy(4,3); cout<<endl<<"\t                EQUIPO A"<<endl;
    gotoxy(4,5); cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    menueA();
    cout<<endl<<endl;
}
void EB(){
    system("cls");
    gotoxy(4,1); cout<<endl<<"\t--------------------------------------------"<<endl;
    gotoxy(4,2); cout<<endl<<"\t                EQUIPO B"<<endl;
    gotoxy(4,3); cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    menueB();
    cout<<endl<<endl;
}
void EC(){
    system("cls");
    gotoxy(4,1); cout<<endl<<"\t--------------------------------------------"<<endl;
    gotoxy(4,2); cout<<endl<<"\t                EQUIPO C"<<endl;
    gotoxy(4,3); cout<<endl<<"\t--------------------------------------------"<<endl<<endl;
    menueC();
    cout<<endl<<endl;
}
void EntrarEquipo(int op){
     if(op==1){
         cout<<"INGRESANDO..."; Sleep(1000);
         system("cls");
         EA();
         fflush(stdin);
     if(op==2){
         cout<<"INGRESANDO..."; Sleep(1000);
         EB();
         fflush(stdin);
     if(op==3){
         cout<<"INGRESANDO..."; Sleep(1000);
         EC();
         fflush(stdin);
        }}}else{
            cout<<"\n EQUIPO NO ENCONTRADO !!";
            system("pause");
            LOGIN();
        }
}
