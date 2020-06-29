#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <vector>
#include <intrin.h>
#include "servei_estat.h"
#include "nom_usuari.h"
#include "programes_inst.h"
#include "_memoria_.h"
#include "processador_nom.h"
#include "_RAM_PERCENTATGE_.h"
#include "processador_nuclis.h"
#include "_RAM_.h"
#include "Banderes.h"
using namespace std;

vector<wchar_t> programes;

void parar_programa() {
    
}
int comparar_si(string escrit) {
    if (escrit.compare("s") == 0 || escrit.compare("S") == 0 || escrit.compare("si") == 0 || escrit.compare("sí") == 0 || escrit.compare("Sí") == 0 || escrit.compare("Si") == 0 || escrit.compare("SI") == 0 || escrit.compare("SÍ") == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
void evitar_cout(string text) {
    setlocale(LC_ALL, "en_US.UTF-8");
    cout << text << endl;
}
string evitar_cin_string() {
    string pregunta_string;
    cin >> pregunta_string;
    return pregunta_string;
}
int evitar_cin_int() {
    int pregunta_int;
    cin >> pregunta_int;
    return pregunta_int;
}
void presentacio() {
    evitar_cout("RICOH SANT CUGAT");
    evitar_cout("L2 PRINTING SOFTWARE");
    evitar_cout("by: Jordi Paré Bernadó");
}
int explicacio() {

    evitar_cout("[1] CATALÀ");
    evitar_cout("[2] ESPAÑOL");
    evitar_cout("[3] ENGLISH");
    cout << "OPCIÓ / OPCIÓN / OPTION: ";
    
    switch (evitar_cin_int()) {
    case 1:
        system("CLS");
        bandera_senyera();
        evitar_cout("------------------");
        evitar_cout("-  INTRODUCCIÓ   -");
        evitar_cout("------------------");
        evitar_cout("");
        evitar_cout("Arrel de la gran cantitat de tickets del departament de L1 i L2 d'informàtica relacionat amb printing, hem dissenyat aquest programa per");
        evitar_cout("facilitar els nostres companys la seva tasca.");
        evitar_cout("");
        evitar_cout("Cal recordar que aquest programa és unica i exclusivament dedicat a l'empresa Ricoh");
        evitar_cout("Per qualsevol dubte, podeu contectar amb el creador del programa per el següents medis: ");
        evitar_cout("Twitter: _xJPBx_");
        evitar_cout("Gmail: jparebernado@gmail.com");
        evitar_cout("Instagram: jpareb");
        evitar_cout("");
        evitar_cout("");
        evitar_cout("--------------------");
        evitar_cout("-      FUNCIÓ      -");
        evitar_cout("--------------------");
        evitar_cout("");
        evitar_cout("Aquest programa té indexada la informació relacionada amb els softwar's de PaperCut, DMNX, Equitrac i MyQ.");
        evitar_cout("En el moment que s'executa aquest programa s'inicia el procés per determinar què té instal·lat el servidor,");
        evitar_cout("fent un anàlisi dels serveis, ports i carpetes en els diferents discs durs.");
        evitar_cout("És IMPORTANT SABER QUE S'EXTREURÀN dades del servidor i s'enviaràn (si es possible) pel correu que s'indiqui.");
        evitar_cout("La informació que s'extreurà serà la següent:");
        evitar_cout("   - CARACTERÍSTIQUES INSTAL·LADES, EN CAS DE SER UN SERVIDOR");
        evitar_cout("   - PROGRAMES INSTAL·LATS");
        evitar_cout("   - SERVEIS ESSENCIALS PEL FUNCIONAMENT DELS PROGRAMES INDICATS AL PRINCIPI");
        evitar_cout("   - IP's/HOSTNAME DE LES IMPRESORES");
        evitar_cout("   - IP DEL SERVIDOR DNS");
        evitar_cout("   - IMPRESORES INSTAL·LADES");
        evitar_cout("   - PORTS HABILITATS");
        evitar_cout("   - CONNECTIVITAT ENTRE SERVIDOR-IMPRESORA");
        evitar_cout("   - LOGS DEL SOFTWARE DE RICOH QUE S'UTILITZI");
        evitar_cout("ESTÀS D'ACORD? (s/N)");

        switch (comparar_si(evitar_cin_string())) {
        case 1:
            evitar_cout("AQUEST CONSENTIMENT QUEDA REGISTRAT EN EL SISTEMA!");
            return 1;
            break;
        case 0:
            evitar_cout("PERMÍS NEGAT PER L'USUARI, ES TANCA EL PROGRAMA");
            parar_programa();
            break;
        }

        break;
    case 2:
        evitar_cout("------------------");
        evitar_cout("-  INTRODUCCIÓN  -");
        evitar_cout("------------------");
        evitar_cout("");
        evitar_cout("A raiz de la gran cantidad de tickets de los departamentos de L1 y L2 de informática relacionados con printing, ");
        evitar_cout("hemos diseñado un programa para facilitar a nuestros compañeros su tarea");
        evitar_cout("");
        evitar_cout("Cabe recordar que este programa es de uso exclusivo para la empresa de Ricoh.");
        evitar_cout("Ante cualquier duda, podéis contactar con el creador del programa mediante estos medios: ");
        evitar_cout("");
        evitar_cout("Twitter: _xJPBx_");
        evitar_cout("Gmail: jparebernado@gmail.com");
        evitar_cout("Instagram: jpareb");
        evitar_cout("");
        evitar_cout("");
        evitar_cout("--------------------");
        evitar_cout("-      FUNCIÓN     -");
        evitar_cout("--------------------");
        evitar_cout("");
        evitar_cout("Este programa tiene estructurada la información relacionada con los software's de PaperCut, DMNX, Equitrac y MyQ.");
        evitar_cout("Es IMPORTANTE SABER QUE SE EXTRAERAN los datos del servidor y si es posible se enviarán por correo indicado por el administrador.");
        evitar_cout("La información que se extrerá será la siguiente:");
        evitar_cout("   - WINDOWS ACTIVADO");
        evitar_cout("   - CARACTERÍSTICAS INSTALADAS, EN CASO DE SER UN SERVIDOR");
        evitar_cout("   - PROGRAMAS INSTALADOS");
        evitar_cout("   - SERVICIOS ESENCIALES PARA EL FUNCIONAMIENTO DE LOS PROGRAMAS INDICADOS ANTERIORMENTE");
        evitar_cout("   - IP's/HOSTNAME DE LAS IMPRESORAS");
        evitar_cout("   - IP DEL SERVIDOR DNS");
        evitar_cout("   - IMPRESORAS INSTALADAS");
        evitar_cout("   - PUERTOS HABILITADOS");
        evitar_cout("   - CONECTIVIDAD ENTRE SERVIDOR-IMPRESORA");
        evitar_cout("   - LOGS DE UNO DE LOS PROGRAMS INDICADOS ANTERIORMENTE");
        evitar_cout("¿ESTÁS DE ACUERDO? (s/N)");

        switch (comparar_si(evitar_cin_string())) {
        case 1:
            evitar_cout("¡ESTE CONSENTIMIENTO QUEDARÁ REGISTRADO EN EL SISTEMA!");
            return 1;
            break;
        case 0:
            evitar_cout("PERMISO DENEGADO POR EL USUARIO, EL PROGRAMA SE CERRARÁ");
            parar_programa();
            break;
        }

        break;
    case 3:
        evitar_cout("English :)");
        break;
    default:
        explicacio();
        break;
    }
}

void proces(int llengua) {
    int opcio_accio;
    cout << llengua;
    vector <ULARGE_INTEGER> memoria;
    double bits_total, bits_lliure;
    float bits_total_d, bits_lliure_d;
    vector<string> programes_instalats_vector, info_processador;
    switch (llengua) {
    case 1:
        system("CLS");
        evitar_cout("--------------------");
        evitar_cout("-      ACCIONS     -");
        evitar_cout("--------------------");
        evitar_cout("[1] USUARI LOGUEJAT");
        evitar_cout("[2] INFORMACIÓ DEL HARDWARE");
        evitar_cout("[3] PROGRAMES INSTAL·LATS");
        evitar_cout("[4] SERVEIS I EL SEU ESTAT");
        evitar_cout("[99] TOT");
        cout << "OPCIÓ: ";
        switch (evitar_cin_int()) {
        case 1:
            system("CLS");
            evitar_cout("--------------------");
            evitar_cout("-      USUARI      -");
            evitar_cout("--------------------");
            cout << "USUARI LOGUEJAT: " << nom_usuari();
            break;
        case 2:
            system("CLS");
            evitar_cout("--------------------");
            evitar_cout("-      HARDWARE    -");
            evitar_cout("--------------------");
            memoria = _memoria_();

            bits_total = memoria.at(0).QuadPart * 9.313225746154785 * pow(10, -10);
            bits_lliure = memoria.at(1).QuadPart * 9.313225746154785 * pow(10, -10);


            evitar_cout("");
            evitar_cout("|PROCESSADOR|");
            evitar_cout("MODEL : " + processador_nom());
            cout << "NUCLIS: " << processador_nuclis();
            evitar_cout("");
            evitar_cout("");
            evitar_cout("|DISC DUR|");
            cout << "TAMANY: " << bits_total << "GB\n";
            cout << "ESPAI LLIURE: " << bits_lliure << "GB\n";
            evitar_cout("");
            evitar_cout("|RAM|");
            cout << "TAMANY: " << _RAM_() << " GB" << endl;
            cout << "PERCENTATGE EN ÚS: " << _RAM_PERCENTATGE_() << "%" << endl;
            break;
        case 3:
            system("CLS");
            evitar_cout("--------------------");
            evitar_cout("-     PROGRAMES    -");
            evitar_cout("--------------------");
            programes_instalats_vector = programes_inst();
            for (size_t i = 0; i < programes_instalats_vector.size(); i++)
            {
                cout << "PROGRAMA [" << (i + 1) << "]: " << programes_instalats_vector.at(i) << endl;
            }
            break;
        case 4:
            LPCWSTR name;
            //MessageBox(NULL, TEXT("Goodbye, cruel world!"), TEXT("Note"), MB_OK);
            servei_estat(TEXT("SgrmBroker"));
            servei_estat(TEXT("p2psvc"));
            servei_estat(TEXT("KeyIso"));
            break;
        case 99:
            break;
        }
        evitar_cout("\n\nFER UNA ALTRE CONSULTA? S/n");
        switch (comparar_si(evitar_cin_string())) {
        case 1:
            proces(llengua);
            break;
        case 0:
            evitar_cout("EL PROGRAMA ES TANCARÀ");
            parar_programa();
            break;
        }
        break;
    case 2:
        system("CLS");
        evitar_cout("--------------------");
        evitar_cout("-      ACCIONES    -");
        evitar_cout("--------------------");
        evitar_cout("[1] USUARIO LOGUEADO");
        evitar_cout("[2] INFORMACIÓN DEL HARDWARE");
        evitar_cout("[3] PROGRMAS INSTALADOS");
        evitar_cout("[99] TODO");
        break;
    case 3:
        system("CLS");
        evitar_cout("--------------------");
        evitar_cout("-      OPTIONS     -");
        evitar_cout("--------------------");
        evitar_cout("[1] CURRENT USER LOGED");
        evitar_cout("[2] SYSTEM'S HARDWARE");
        evitar_cout("[3] INSTALLED PROGRAMS");
        evitar_cout("[99] ALL");

        break;
    }
}
void menu() {
    int llengua = explicacio();
    proces(llengua);

}



int main() {
    menu();
    int jordi;
    cin >> jordi;
}

