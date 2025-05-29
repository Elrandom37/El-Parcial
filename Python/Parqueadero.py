filas = 13
columnas = 13

mapa = [
    ['E', 'L', 'V', 'V', 'V', 'L', 'V', 'V', 'V', 'L', 'V', 'V','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L', 'V', 'L','V',],
    ['V', 'V', 'V', 'L', 'V', 'V', 'V', 'L', 'V', 'V', 'V', 'L','S',],
]

vehiculos_activos = {}
historial = []

tarifas = {
    'carro': 5000,
    'moto': 3000,
    'bicicleta': 1000
}

def mostrar_mapa():
    print("\nMapa Parqueadero:")
    for fila in mapa:
        print(' '.join(fila))
    ocupados = sum(row.count('O') for row in mapa)
    libres = sum(row.count('L') for row in mapa)
    print(f"\nEspacios ocupados: {ocupados} | Espacios libres: {libres}\n")

def asignar_espacio():
    for i in range(filas):
        for j in range(columnas):
            if mapa[i][j] == 'L':
                return i, j
    return None, None

def validar_hora(hora):
    if len(hora) != 5 or hora[2] != ':':
        return False
    hh, mm = hora.split(':')
    if not (hh.isdigit() and mm.isdigit()):
        return False
    hh, mm = int(hh), int(mm)
    return 0 <= hh < 24 and 0 <= mm < 60

def calcular_minutos(hora):
    hh, mm = map(int, hora.split(':'))
    return hh * 60 + mm

def registrar_vehiculo():
    placa = input("Ingrese placa: ").upper()
    if placa in vehiculos_activos:
        print("Vehículo ya registrado.")
        return
    tipo = input("Tipo de vehículo (carro/moto/bicicleta): ").lower()
    if tipo not in tarifas:
        print("Tipo no válido.")
        return
    hora_entrada = input("Hora de entrada (HH:MM): ")
    if not validar_hora(hora_entrada):
        print("Hora inválida.")
        return
    fila, columna = asignar_espacio()
    if fila is None:
        print("Parqueadero lleno.")
        return
    mapa[fila][columna] = 'O'
    vehiculos_activos[placa] = {
        'tipo': tipo,
        'fila': fila,
        'columna': columna,
        'hora_entrada': hora_entrada
    }
    print(f"Vehículo {placa} registrado en ({fila}, {columna}) a las {hora_entrada}.")

def retirar_vehiculo():
    placa = input("Ingrese placa: ").upper()
    if placa not in vehiculos_activos:
        print("Vehículo no encontrado.")
        return
    hora_salida = input("Hora de salida (HH:MM): ")
    if not validar_hora(hora_salida):
        print("Hora inválida.")
        return
    datos = vehiculos_activos.pop(placa)
    fila, columna = datos['fila'], datos['columna']
    tipo = datos['tipo']
    hora_entrada = datos['hora_entrada']
    
    minutos_entrada = calcular_minutos(hora_entrada)
    minutos_salida = calcular_minutos(hora_salida)
    if minutos_salida < minutos_entrada:
        print("Hora de salida no puede ser menor que la de entrada.")
        vehiculos_activos[placa] = datos
        return
    tiempo_minutos = minutos_salida - minutos_entrada
    tiempo_horas = (tiempo_minutos + 59) // 60
    costo = tarifas[tipo] * tiempo_horas
    
    mapa[fila][columna] = 'L'
    print(f"Costo a pagar: ${costo} por {tiempo_horas} hora(s).")
    
    historial.append({
        'placa': placa,
        'tipo': tipo,
        'tiempo_horas': tiempo_horas,
        'costo': costo,
        'ubicacion': (fila, columna),
        'entrada': hora_entrada,
        'salida': hora_salida
    })

def mostrar_historial():
    if not historial:
        print("Sin historial.")
        return
    print("\nHistorial de vehículos retirados:")
    for v in historial:
        print(f"{v['placa']} | {v['tipo']} | Entrada: {v['entrada']} | Salida: {v['salida']} | Tiempo: {v['tiempo_horas']}h | Costo: ${v['costo']} | Ubicación: {v['ubicacion']}")

def buscar_vehiculo():
    placa = input("Ingrese placa: ").upper()
    if placa in vehiculos_activos:
        v = vehiculos_activos[placa]
        print(f"{placa} está en ({v['fila']}, {v['columna']}) - {v['tipo']} - Entró a las {v['hora_entrada']}")
    else:
        print("No encontrado.")

def menu():
    while True:
        print("\n--- Menú ---")
        print("1. Mostrar mapa")
        print("2. Registrar vehículo")
        print("3. Retirar vehículo")
        print("4. Mostrar historial")
        print("5. Buscar vehículo")
        print("6. Salir")
        opcion = input("Opción: ")
        if opcion == '1':
            mostrar_mapa()
        elif opcion == '2':
            registrar_vehiculo()
        elif opcion == '3':
            retirar_vehiculo()
        elif opcion == '4':
            mostrar_historial()
        elif opcion == '5':
            buscar_vehiculo()
        elif opcion == '6':
            print("Saliendo...")
            break
        else:
            print("Opción inválida.")

if __name__ == "__main__":
    menu()