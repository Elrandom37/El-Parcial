#include <iostream>
#include <string>
using namespace std;

struct Ataque {
    string nombre;
    int danio;
};

struct Futbolista {
    string nombre;
    string posicion;
    int vida;
    int curacionesUsadas;
    Ataque ataques[4];
    bool estaActivo;
};

string porteros[10] = {
    "Alvaro Montero", "Kevin Mier", "Camilo Vargas", "David Ospina", "Aldair Quintana",
    "Thibaut Courtois", "Marc-Andre ter Stegen", "Gianluigi Donnarumma", "Manuel Neuer", "Alisson Becker"
};

string defensas[10] = {
    "Davinson Sanchez", "Yerry Mina", "Daniel Muñoz", "Andres Román", "Andres Llinas",
    "Virgil van Dijk", "Pau Cubarsi", "Jules Kounde", "Antonio Rudiger", "Marquinhos"
};

string mediocampistas[10] = {
    "Juan Fernando Quintero", "James Rodriguez", "Macalister Silva", "Jefferson Lerma", "Richard Rios",
    "Luka Modric", "Kevin De Bruyne", "Jude Bellingham", "Federico Valverde", "Pedri"
};

string delanteros[10] = {
    "Luis Diaz", "Marino Hinestroza", "Leonardo Castro", "Jhon Durán", "Falcao",
    "Kylian Mbappe", "Cristiano Ronaldo", "Lamine Yamal", "Vinicius Jr", "Lionel Messi"
};

Ataque ataquesPortero[8] = {
    {"Atajada Rápida", 15}, {"Saque Largo", 10}, {"Estirada", 20}, {"Despeje Fuerte", 18},
    {"Bloqueo", 12}, {"Salida Rápida", 14}, {"Pase Preciso", 13}, {"Mano Segura", 16}
};

Ataque ataquesDefensa[8] = {
    {"Entrada Fuerte", 18}, {"Cabezazo", 20}, {"Despeje", 15}, {"Pase Corto", 12},
    {"Presión", 17}, {"Barrida", 13}, {"Marca Cerrada", 14}, {"Barrida", 16}
};

Ataque ataquesMediocampista[8] = {
    {"Pase Filtrado", 15}, {"Disparo Lejano", 20}, {"Regate", 18}, {"Centro Preciso", 14},
    {"Intercepción", 13}, {"Cambio de Ritmo", 16}, {"Tiro Libre", 19}, {"Pase Largo", 12}
};

Ataque ataquesDelantero[8] = {
    {"Disparo Fuerte", 22}, {"Regate Rápido", 18}, {"Chilena", 20}, {"Pase Corto", 14},
    {"Tiro Colocado", 21}, {"Volea", 19}, {"Remate Cruzado", 17}, {"Pase de Tacon", 15}
};

void asignarAtaques(Futbolista &futbolista, Ataque ataquesPos[8], int indiceJugador) {
    int inicioAtaques = indiceJugador % 5;
    for(int i = 0; i < 4; i++) {
        futbolista.ataques[i] = ataquesPos[(inicioAtaques + i) % 8];
    }
}

void mostrarListaJugadores(string lista[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << i+1 << ". " << lista[i] << endl;
    }
}

int elegirJugador(string lista[], int tam, string posicion) {
    int opcion = 0;
    do {
        cout << "Elige un " << posicion << " (1-" << tam << "): ";
        cin >> opcion;
        if(opcion < 1 || opcion > tam) cout << "Opcion invalida, intenta de nuevo.\n";
    } while(opcion < 1 || opcion > tam);
    return opcion - 1;
}

void mostrarAtaques(Futbolista &futbolista) {
    for(int i = 0; i < 4; i++) {
        cout << i+1 << ". " << futbolista.ataques[i].nombre << endl;
    }
}

int elegirAtaque(Futbolista &futbolista) {
    int opcion = 0;
    do {
        cout << "Elige ataque (1-4), 5 para llamar al equipo medico, o 6 para cambiar de jugador: ";
        cin >> opcion;
        if(opcion < 1 || opcion > 6) cout << "Opcion invalida, intenta de nuevo.\n";
    } while(opcion < 1 || opcion > 6);
    return opcion;
}

void mostrarEquipo(Futbolista equipo[], int tam) {
    for(int i = 0; i < tam; i++) {
        cout << i+1 << ". " << equipo[i].nombre << " (" << equipo[i].posicion << ")"
             << " Vida: " << equipo[i].vida;
        if(!equipo[i].estaActivo) cout << " [KO]";
        cout << endl;
    }
}

int elegirJugadorActivo(Futbolista equipo[], int tam) {
    int opcion = 0;
    bool valido = false;
    do {
        cout << "Elige jugador activo para entrar (1-" << tam << "): ";
        cin >> opcion;
        if(opcion >= 1 && opcion <= tam) {
            if(equipo[opcion-1].vida > 0) {
                valido = true;
            } else {
                cout << "Jugador derrotado, no se puede seleccionar.\n";
            }
        } else {
            cout << "Opcion invalida, intenta de nuevo.\n";
        }
    } while(!valido);
    return opcion - 1;
}

bool estaVivo(Futbolista equipo[], int tam) {
    for(int i = 0; i < tam; i++) {
        if(equipo[i].vida > 0) return true;
    }
    return false;
}

int main() {
    const int TAM = 4;
    Futbolista equipo1[TAM], equipo2[TAM];
    int i;

    cout << "=== Selecciona tu equipo (Jugador 1) ===\n";
    mostrarListaJugadores(porteros, 10);
    i = elegirJugador(porteros, 10, "Portero");
    equipo1[0] = {porteros[i], "Portero", 100, 0, {}, true};
    asignarAtaques(equipo1[0], ataquesPortero, i);

    mostrarListaJugadores(defensas, 10);
    i = elegirJugador(defensas, 10, "Defensa");
    equipo1[1] = {defensas[i], "Defensa", 100, 0, {}, true};
    asignarAtaques(equipo1[1], ataquesDefensa, i);

    mostrarListaJugadores(mediocampistas, 10);
    i = elegirJugador(mediocampistas, 10, "Mediocampista");
    equipo1[2] = {mediocampistas[i], "Mediocampista", 100, 0, {}, true};
    asignarAtaques(equipo1[2], ataquesMediocampista, i);

    mostrarListaJugadores(delanteros, 10);
    i = elegirJugador(delanteros, 10, "Delantero");
    equipo1[3] = {delanteros[i], "Delantero", 100, 0, {}, true};
    asignarAtaques(equipo1[3], ataquesDelantero, i);

    cout << "\n=== Selecciona el equipo del Jugador 2 ===\n";
    mostrarListaJugadores(porteros, 10);
    i = elegirJugador(porteros, 10, "Portero");
    equipo2[0] = {porteros[i], "Portero", 100, 0, {}, true};
    asignarAtaques(equipo2[0], ataquesPortero, i);

    mostrarListaJugadores(defensas, 10);
    i = elegirJugador(defensas, 10, "Defensa");
    equipo2[1] = {defensas[i], "Defensa", 100, 0, {}, true};
    asignarAtaques(equipo2[1], ataquesDefensa, i);

    mostrarListaJugadores(mediocampistas, 10);
    i = elegirJugador(mediocampistas, 10, "Mediocampista");
    equipo2[2] = {mediocampistas[i], "Mediocampista", 100, 0, {}, true};
    asignarAtaques(equipo2[2], ataquesMediocampista, i);

    mostrarListaJugadores(delanteros, 10);
    i = elegirJugador(delanteros, 10, "Delantero");
    equipo2[3] = {delanteros[i], "Delantero", 100, 0, {}, true};
    asignarAtaques(equipo2[3], ataquesDelantero, i);

    int turno = 1;
    int jugadorActual = 0;
    int posicionActual1 = 0;
    int posicionActual2 = 0;

    while(estaVivo(equipo1, TAM) && estaVivo(equipo2, TAM)) {
        cout << "\nTurno del jugador " << (jugadorActual + 1) << endl;
        Futbolista *equipo = (jugadorActual == 0) ? equipo1 : equipo2;
        Futbolista *equipoRival = (jugadorActual == 0) ? equipo2 : equipo1;
        int &posicionActual = (jugadorActual == 0) ? posicionActual1 : posicionActual2;

        if(equipo[posicionActual].vida <= 0) {
            cout << equipo[posicionActual].nombre << " esta derrotado. Debes seleccionar otro jugador.\n";
            mostrarEquipo(equipo, TAM);
            posicionActual = elegirJugadorActivo(equipo, TAM);
        }

        cout << "Jugador activo: " << equipo[posicionActual].nombre << " (" << equipo[posicionActual].posicion << ") Vida: " << equipo[posicionActual].vida << endl;

        cout << "Ataques:\n";
        mostrarAtaques(equipo[posicionActual]);
        cout << "5. Llamar al equipo medico (max 2 veces)\n";
        cout << "6. Solicitar un cambio para tu jugador\n";

        int accion = elegirAtaque(equipo[posicionActual]);
        if(accion == 5) {
            if(equipo[posicionActual].curacionesUsadas < 2) {
                equipo[posicionActual].vida += 30;
                if(equipo[posicionActual].vida > 100) equipo[posicionActual].vida = 100;
                equipo[posicionActual].curacionesUsadas++;
                cout << equipo[posicionActual].nombre << " llamo al equipo medico y recupero 30 de vida.\n";
            } else {
                cout << "Ya llamaste al equipo medico 2 veces.\n";
            }
            continue;
        }
        if(accion == 6) {
            cout << "Cambiando de jugador...\n";
            mostrarEquipo(equipo, TAM);
            int nuevo = elegirJugadorActivo(equipo, TAM);
            posicionActual = nuevo;
            continue;
        }
        else {
            int danio = equipo[posicionActual].ataques[accion - 1].danio;
            cout << equipo[posicionActual].nombre << " uso " << equipo[posicionActual].ataques[accion - 1].nombre << endl;

            int posicionRival = (jugadorActual == 0) ? posicionActual2 : posicionActual1;

            if(equipoRival[posicionRival].vida > 0) {
                equipoRival[posicionRival].vida -= danio;
                if(equipoRival[posicionRival].vida <= 0) {
                    equipoRival[posicionRival].vida = 0;
                    cout << equipoRival[posicionRival].nombre << " fue derrotado!\n";
                }
                cout << equipoRival[posicionRival].nombre << " recibio daño. Vida actual: " << equipoRival[posicionRival].vida << endl;
            } else {
                cout << equipoRival[posicionRival].nombre << " ya esta derrotado, no puede recibir daño.\n";
            }
        }

        jugadorActual = 1 - jugadorActual;
    }

    cout << "\n¡El Arbitro indica el final de este partido!\n";
    if(estaVivo(equipo1, TAM)) cout << "Victoria para el Jugador 1\n";
    else cout << "Victoria para el Jugador 2\n";

    return 0;
}