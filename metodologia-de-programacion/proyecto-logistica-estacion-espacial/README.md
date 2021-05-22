# Send missions to the International Space Station (ISS)

## Run app

```bash
python app.py
```

In order to test the assignments and the simulation by days
without entering manually the required data

```bash
python app.py dummy-data
```

## Run unit tests

```bash
python tests_unit.py
```

## Files

```
src/
├── enums/
│   ├── mission_status.py (Enum para el status de las misiones)
│   ├── print_colors.py (Enum para los colores de impresion)
│   └── requests_status.py (Enum para el status de las peticiones)
├── general_information/
│   └── print_data.py (Funciones de impresión)
├── helpers/
│   ├── helper_print.py (Helper para las funciones de impresion)
│   └── helper_validate.py (Helper para las funciones de validación)
├── menu/
│   └── app_menu.py (Menu de la app)
├── tests/
│   └── dummy_data.py (Dummy data para los tests unitarios)
└── app.py (App)
└── data.json (Datos iniciales: rockets, requests, missions, assignments)
└── README.md (Descripción del proyecto)
└── tests_unit.py (Tests unitarios de la app)
```
