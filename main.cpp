#include <iostream>
#include <string>

// inicializar los vectores
void inicializar_sistema(int *&ids_P, float *&pesos_P, std::string *&destinos_P, int *&prioridades_P, char *&estados_P, int &capacidad_P, int &num_elementos_P, int &indice_inicio_P, int &indice_fin_P, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C, int &num_elementos_C, int &indice_inicio_C, int &indice_fin_C);

// liberar memoria
void liberar_memoria(int *&ids_P, float *&pesos_P, std::string *&destinos_P, int *&prioridades_P, char *&estados_P, int capacidad, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C);
// agregar un paquete (encolar)
void agregar_paquete(int *&ids, float *&pesos, std::string *&destinos, int *&prioridades, char *&estados, int &capacidad, int &num_elementos, int &indice_fin, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C,int &num_elementos_C);

void redimensionar_vectores(int *&ids, float *&pesos, std::string *&destinos, int *&prioridades, char *&estados, int &capacidad, int num_elementos, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C, int num_elementos_C);

void despachar_paquete(int *ids, float *pesos, std::string *destinos, int *prioridades, char *&estados, int &indice_inicio, int indice_fin);

void procesar(int *&ids_P, float *&pesos_P, std::string *&destinos_P, int *&prioridades_P, char *&estados_P, int &capacidad_P, int &num_elementos_P, int &indice_inicio_P, int &indice_fin_P, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C, int &num_elementos_C, int &indice_inicio_C, int &indice_fin_C);

void Reporte(int *&ids_P, float *&pesos_P, std::string *&destinos_P, int *&prioridades_P, char *&estados_P, int &capacidad_P, int &num_elementos_P, int &indice_inicio_P, int &indice_fin_P, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C, int &num_elementos_C, int &indice_inicio_C, int &indice_fin_C);

//falta redimencionar

int main() {
    // Vectores
    int *ids_P = nullptr;
    float *pesos_P = nullptr;
    std::string *destinos_P = nullptr;
    int *prioridades_P = nullptr;
    char *estados_P = nullptr;
    
    int *ids_C = nullptr;
    float *pesos_C = nullptr;
    std::string *destinos_C = nullptr;
    int *prioridades_C = nullptr;
    char *estados_C = nullptr;
 
    int capacidad = 0;

    int num_elementos_P = 0;
    int indice_inicio_P = 0;
    int indice_fin_P = 0;

    int num_elementos_C = 0;
    int indice_inicio_C = 0;
    int indice_fin_C = 0;

    int opcion = 0;

    std::cout << "--- Sistema de Despacho Logistico MegaEnvio (Modo Punteros) ---\n" << std::endl;
    
    // Llamar a la funcion para inicializar los vectores del sistema
    inicializar_sistema(ids_P, pesos_P, destinos_P, prioridades_P, estados_P, capacidad, num_elementos_P, indice_inicio_P, indice_fin_P, ids_C, pesos_C, destinos_C, prioridades_C, estados_C, num_elementos_C, indice_inicio_C, indice_fin_C);

    do {
        std::cout << "\nSeleccione una operacion:" << std::endl;
        std::cout << "1. Recibir Nuevo Paquete (PUSH)" << std::endl;
        std::cout << "2. Procesar Recepción (POP y ENCOLAR)" << std::endl;
        std::cout << "3. Despachar (DESENCOLAR con Prioridad)" << std::endl;
        std::cout << "4. Reporte de Estados" << std::endl;
        std::cout << "5. Salir (Liberar Memoria)" << std::endl;
        std::cout << "\nOpcion seleccionada: ";
        std::cin >> opcion;
        
        switch(opcion) {
            case 1:
                agregar_paquete(ids_P, pesos_P, destinos_P, prioridades_P, estados_P, capacidad, num_elementos_P, indice_fin_C, ids_C, pesos_C, destinos_C, prioridades_C, estados_C, num_elementos_C);
                break;
            case 2:

                procesar(ids_P, pesos_P, destinos_P, prioridades_P, estados_P, capacidad, num_elementos_P, indice_inicio_P, indice_fin_P, ids_C, pesos_C, destinos_C, prioridades_C, estados_C, num_elementos_C, indice_inicio_C, indice_fin_C);

                
                break;
            case 3:
                despachar_paquete(ids_C, pesos_C, destinos_C, prioridades_C, estados_C, indice_inicio_C, indice_fin_C);
                break;
            case 4:
                Reporte(ids_P, pesos_P, destinos_P, prioridades_P, estados_P, capacidad, num_elementos_P, indice_inicio_P, indice_fin_P, ids_C, pesos_C, destinos_C, prioridades_C, estados_C, num_elementos_C, indice_inicio_C, indice_fin_C);

                break;
            case 5:
                liberar_memoria(ids_P, pesos_P, destinos_P, prioridades_P, estados_P, capacidad, ids_C, pesos_C, destinos_C, prioridades_C, estados_C);
                std::cout << "Sistema cerrado. ¡Memoria liberada!" << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
        
    } while(opcion != 5);

    return 0;
}

void Reporte(int *&ids_P, float *&pesos_P, std::string *&destinos_P, int *&prioridades_P, char *&estados_P, int &capacidad_P, int &num_elementos_P, int &indice_inicio_P, int &indice_fin_P, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C, int &num_elementos_C, int &indice_inicio_C, int &indice_fin_C){
    for (int i = 0; i < num_elementos_P; i++){

        std::cout << "Pila: ID" << ids_P[i] << "estado: "<< estados_P[i]<< std::endl;
    }

    for (int i = 0; i < num_elementos_C; i++){

        std::cout << "Cola: ID" << ids_C[i] << "estado: "<< estados_C[i]<< std::endl;
    }
    
}

void procesar(int *&ids_P, float *&pesos_P, std::string *&destinos_P, int *&prioridades_P, char *&estados_P, int &capacidad_P, int &num_elementos_P, int &indice_inicio_P, int &indice_fin_P, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C, int &num_elementos_C, int &indice_inicio_C, int &indice_fin_C){
    int *ids_aux = new int[capacidad_P];
    float *pesos_aux = new float[capacidad_P];
    std::string *destinos_aux = new std::string[capacidad_P];
    int *prioridades_aux = new int[capacidad_P];
    char *estados_aux = new char[capacidad_P];

    estados_P[indice_fin_P]='E';


    for (int i = 0; i < indice_fin_P; i++)
    {
        ids_C[i]=ids_aux[i+1];
        pesos_C[i]=pesos_aux[i+1];
        destinos_C[i]= destinos_aux[i+1];
        prioridades_C[i]=prioridades_aux[i+1];
        estados_C[i]=estados_aux[i+1];
    }
    

    ids_P[indice_fin_P]=ids_aux[0];
    pesos_P[indice_fin_P]=pesos_aux[0];
    destinos_P[indice_fin_P]= destinos_aux[0];
    prioridades_P[indice_fin_P]=prioridades_aux[0];
    estados_P[indice_fin_P]=estados_aux[0];

    std::cout<<"ID: "<<ids_aux[0]<<" Peso: "<<pesos_aux[0]<< "destino"<<destinos_aux[0]<<" Prioridad: "<< prioridades_aux[0]<< " estado"<< estados_aux[0]<<std::endl;

    for (int i = 0; i < indice_fin_C; i++)
    {
        ids_aux[i]=ids_C[i];
        pesos_aux[i]=pesos_C[i];
        destinos_aux[i]= destinos_C[i];
        prioridades_aux[i]=prioridades_C[i];
        estados_aux[i]=estados_C[i];
    }
    indice_fin_C++;
    indice_fin_P--;

}


void despachar_paquete(int *ids, float *pesos, std::string *destinos, int *prioridades, char *&estados, int &indice_inicio, int indice_fin) {
    // Buscar el siguiente paquete en cola desde indice_inicio
    bool encontrado = false;
    int posicion = indice_inicio;
    
    while (posicion < indice_fin && !encontrado) {
        if (estados[posicion] == 'E') {
            encontrado = true;
        } else {
            posicion++;
        }
    }
    
    if (!encontrado) {
        std::cout << "\nNo hay paquetes en cola para despachar." << std::endl;
        return;
    }
    
    std::cout << "\nDespachando paquete..." << std::endl;
    std::cout << "Paquete " << ids[posicion] << " despachado con exito. Estado: 'D'." << std::endl;
    
    // estado cambiado a despachado
    estados[posicion] = 'D';
    
    // Actualizar indice_inicio para que apunte al siguiente paquete en cola
    indice_inicio = posicion + 1;
}

void redimensionar_vectores(int *&ids, float *&pesos, std::string *&destinos, int *&prioridades, char *&estados, int &capacidad, int num_elementos, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C, int num_elementos_C) {
    int nueva_capacidad = capacidad * 2;
    
    std::cout << "\nCapacidad llena. Redimensionando de " << capacidad << " a " << nueva_capacidad << " paquetes..." << std::endl;
    
    // Crear nuevos vectores con el doble de capacidad
    int *ids_aux = new int[nueva_capacidad];
    float *pesos_aux = new float[nueva_capacidad];
    std::string *destinos_aux = new std::string[nueva_capacidad];
    int *prioridades_aux = new int[nueva_capacidad];
    char *estados_aux = new char[nueva_capacidad];

    int *ids_aux_C = new int[nueva_capacidad];
    float *pesos_aux_C = new float[nueva_capacidad];
    std::string *destinos_aux_C = new std::string[nueva_capacidad];
    int *prioridades_aux_C = new int[nueva_capacidad];
    char *estados_aux_C = new char[nueva_capacidad];
    
    // Copiar los datos existentes
    for (int i = 0; i < num_elementos; i++) {
        ids_aux[i] = ids[i];
        pesos_aux[i] = pesos[i];
        destinos_aux[i] = destinos[i];
        prioridades_aux[i] = prioridades[i];
        estados_aux[i] = estados[i];


        ids_aux_C[i] = ids_C[i];
        pesos_aux_C[i] = pesos_C[i];
        destinos_aux_C[i] = destinos_C[i];
        prioridades_aux_C[i] = prioridades_C[i];
        estados_aux_C[i] = estados_C[i];
    }
    
    // Liberar memoria antigua
    delete[] ids;
    delete[] pesos;
    delete[] destinos;
    delete[] prioridades;
    delete[] estados;

    delete[] ids_C;
    delete[] pesos_C;
    delete[] destinos_C;
    delete[] prioridades_C;
    delete[] estados_C;
    
    // Asignar los nuevos vectores
    ids = ids_aux;
    pesos = pesos_aux;
    destinos = destinos_aux;
    prioridades = prioridades_aux;
    estados = estados_aux;

    ids_C = ids_aux_C;
    pesos_C = pesos_aux_C;
    destinos_C = destinos_aux_C;
    prioridades_C = prioridades_aux_C;
    estados_C = estados_aux_C;
    
    capacidad = nueva_capacidad;
    
    std::cout << "Redimensionamiento exitoso. Nueva capacidad: " << capacidad << std::endl;
}
void agregar_paquete(int *&ids, float *&pesos, std::string *&destinos, int *&prioridades, char *&estados, int &capacidad, int &num_elementos, int &indice_fin, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C,int &num_elementos_C) {
    // Verificar si necesitamos redimensionar
    if (num_elementos >= capacidad) {
        redimensionar_vectores(ids, pesos, destinos, prioridades, estados, capacidad, num_elementos, ids_C, pesos_C, destinos_C, prioridades_C, estados_C, num_elementos_C);
    }
    
    int id;
    float peso;
    std::string destino;
    int prioridad;
    
    std::cout << "\nIngrese ID: ";
    std::cin >> id;
    std::cout << "Ingrese Peso (kg): ";
    std::cin >> peso;
    std::cin.ignore(); 
    std::cout << "Ingrese Destino: ";
    getline(std::cin, destino);
    std::cout << "Ingrese Prioridad (1=Alta, 2=Media, 3=Baja): ";
    std::cin >> prioridad;
    
    // Agregar el paquete en la posición indice_fin
    ids[indice_fin] = id;
    pesos[indice_fin] = peso;
    destinos[indice_fin] = destino;
    prioridades[indice_fin] = prioridad;
    estados[indice_fin] = 'R'; 
    indice_fin++;
    num_elementos++;
    
    // Calcular paquetes en cola (estado 'R')
    int en_cola = 0;
    for (int i = 0; i < num_elementos; i++) {
        if (estados[i] == 'R') {
            en_cola++;
        }
    }
    
    std::cout << "Paquete " << id << " enpilado. Capacidad utilizada: " << num_elementos << "/" << capacidad << "." << std::endl;
    std::cout << "Paquetes en pila: " << en_cola << std::endl;
}






void liberar_memoria(int *&ids_P, float *&pesos_P, std::string *&destinos_P, int *&prioridades_P, char *&estados_P, int capacidad, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C) {
    std::cout << "\nLiberando " << capacidad << " bloques de memoria asignada..." << std::endl;
    
    delete[] ids_P;
    delete[] pesos_P;
    delete[] destinos_P;
    delete[] prioridades_P;
    delete[] estados_P;

    delete[] ids_C;
    delete[] pesos_C;
    delete[] destinos_C;
    delete[] prioridades_C;
    delete[] estados_C;
    
    ids_P = nullptr;
    pesos_P = nullptr;
    destinos_P = nullptr;
    prioridades_P = nullptr;
    estados_P = nullptr;

    ids_C = nullptr;
    pesos_C = nullptr;
    destinos_C = nullptr;
    prioridades_C = nullptr;
    estados_C = nullptr;
}

void inicializar_sistema(int *&ids_P, float *&pesos_P, std::string *&destinos_P, int *&prioridades_P, char *&estados_P, int &capacidad_P, int &num_elementos_P, int &indice_inicio_P, int &indice_fin_P, int *&ids_C, float *&pesos_C, std::string *&destinos_C, int *&prioridades_C, char *&estados_C, int &num_elementos_C, int &indice_inicio_C, int &indice_fin_C) {
    capacidad_P = 50;
    num_elementos_P = 0;
    indice_inicio_P = 0;
    indice_fin_P = 0;

    num_elementos_C = 0;
    indice_inicio_C = 0;
    indice_fin_C = 0;
    
    
    std::cout << "Inicializando sistema con capacidad para " << capacidad_P << " paquetes..." << std::endl;
    
    ids_P = new int[capacidad_P];
    pesos_P = new float[capacidad_P];
    destinos_P = new std::string[capacidad_P];
    prioridades_P = new int[capacidad_P];
    estados_P = new char[capacidad_P];
    
    ids_C = new int[capacidad_P];
    pesos_C = new float[capacidad_P];
    destinos_C = new std::string[capacidad_P];
    prioridades_C = new int[capacidad_P];
    estados_C = new char[capacidad_P];
    
    std::cout << "Capacidad actual: " << capacidad_P << ". Paquetes en cola: 0." << std::endl;
}


