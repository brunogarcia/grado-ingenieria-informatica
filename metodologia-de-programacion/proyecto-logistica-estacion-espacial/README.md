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

## Types

### Rockets
- Type: List of rockets


### Rocket
- Type: dictionary


|  Key | Type  |  Comments |
|---|---|---|
| id | alphanumeric | Must be unique, minimum 3 chars  |
| payload | number | Minimum: 1 |
| success | boolean | False (Default) |


### Requests
- Type: List of request
- Before assign to a mission, the app must be order the requests by `days max to deliver` and `weight`

### Request
- Type: dictionary

|  Key | Type  |  Comments |
|---|---|---|
| id | alphanumeric | Must be unique, minimum 3 chars  |
| description | alphanumeric | |
| weight | float |  Float with 3 decimals |
| daysMaxToDeliver | number | Minimum: 1 | 
| status | RequestStatus | |

### Request Status
- Type: enum
- Status
  - WAITING_FOR_ASSIGNMENT
  - ALLOCATED
  - IMPOSSIBLE_TO_FULFILL
  - DELIVERED

### Missions
- Type: List of missions
- Before assign requests, the app must order the missions by `days to arrive at station` and the `rocket id`

### Mission
- Type: dictionary

|  Key | Type  |  Comments |
|---|---|---|
| id | alphanumeric | Must be unique  |
| rocketId | alphanumeric | Must be a valid rocket id | 
| daysToArriveAtStation | number | Days to arrive at station | 
| status | MissionStatus | | 

### Mission Status
- Type: enum
- Status
  - ON_HOLD
  - ON_ROUTE
  - ON_STATION

### Assignments
- Type: List of assignments

### Assignment
- Type: dictionary

|  Key | Type  |  Comments |
|---|---|---|
| missionId | alphanumeric | Must be unique  |
| daysToArriveAtStation | number | A initial copy of the mission days to arrive at station |
| payload | number | A initial copy of the rocket payload |
| requestIds | list of strings | Contains the ids of each request | 

