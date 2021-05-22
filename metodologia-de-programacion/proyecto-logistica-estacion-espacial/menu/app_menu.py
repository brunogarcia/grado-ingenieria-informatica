import sys
from helpers.helper_print import print_header, print_error, print_success
from helpers.helper_validate import validate_integer, validate_float, validate_file_name


def menu() -> int:
    print('\n----------- MENU -----------')
    print('1) Add new rocket')
    print('2) Add new request')
    print('3) Add new mission')
    print('4) Create assignments')
    print('5) Simulate by days')
    print('6) General information')
    print('7) Load file')
    print('8) Save file')
    print('0) Leave the app')
    print('-----------------------------')

    try:
        option = validate_integer("menu option")
        return option
    except ValueError as error:
        print_error(str(error))


def check_dummy_data() -> None:
    """
    In order to test the assignments and the simulation by days
    without entering manually the required data
    """
    from tests.dummy_data import add_dummy_data

    if len(sys.argv) > 1 and sys.argv[1] == 'dummy-data':
        add_dummy_data()


def display_menu() -> None:
    option = -1
    check_dummy_data()

    while option != 0:
        option = menu()
        if option == 1:
            menu_add_new_rocket()
        elif option == 2:
            menu_add_new_request()
        elif option == 3:
            menu_add_new_mission()
        elif option == 4:
            menu_assign_requests_missions()
        elif option == 5:
            menu_simulate_by_days()
        elif option == 6:
            menu_general_information()
        elif option == 7:
            menu_load_file()
        elif option == 8:
            menu_save_file()
        elif option == 0:
            print("Bye!")
        elif option != 0:
            print_error('Option not valid')
            menu()


def menu_add_new_rocket() -> None:
    from app import add_new_rocket
    is_valid = False

    print_header("Add new rocket")
    while not is_valid:
        try:
            # The user introduce the data
            rocket_id = input("rocket id: ")
            rocket_payload = validate_integer("rocket payload")

            # Add the new rocket
            add_new_rocket(rocket_id, rocket_payload)
            is_valid = True
        except ValueError as error:
            print_error(str(error))


def menu_add_new_request() -> None:
    from app import add_new_request
    is_valid = False

    print_header("Add new request")
    while not is_valid:
        try:
            # The user introduce the data
            request_id = input("request id: ")
            request_description = input("request description: ")
            request_weight = validate_float("request weight")
            request_days_max = validate_integer("request days max to deliver ")

            # Add the new request
            add_new_request(request_id, request_description, request_weight, request_days_max)
            is_valid = True
        except ValueError as error:
            print_error(str(error))


def menu_add_new_mission() -> None:
    from app import add_new_mission
    is_valid = False

    print_header("Add new mission")
    while not is_valid:
        try:
            # The user introduce the data
            mission_id = input("mission id: ")
            rocket_id = input("rocket id: ")
            mission_days_max = validate_integer("mission days to arrive at station")

            # Add the new mission
            add_new_mission(mission_id, rocket_id, mission_days_max)
            is_valid = True
        except ValueError as error:
            print_error(str(error))


def menu_assign_requests_missions() -> None:
    from app import assign_requests_missions, validate_assignment_process

    exists_enough_data = validate_assignment_process()

    if exists_enough_data:
        print_header("Assignments")
        try:
            message = assign_requests_missions()
            print_success(message)
        except ValueError as error:
            print_error(str(error))
    else:
        print_error("Should exist at least one rocket,"
                    " one request, and one mission for init"
                    " the assignment process")


def menu_simulate_by_days() -> None:
    from app import simulate_by_days, get_assignments

    exists_assignments = len(get_assignments()) > 0

    if exists_assignments:
        is_valid = False
        print_header("Simulation")
        while not is_valid:
            try:
                # The user introduce the data
                days = validate_integer("days")

                # Process the simulation
                simulate_by_days(days)

                is_valid = True
            except ValueError as error:
                print('Error: ', str(error))
    else:
        print_error("Should exist at least one assignment")


def menu_general_information() -> None:
    from app import general_information

    general_information()


def menu_load_file():
    from app import load_file

    is_valid = False
    print_header("Load a JSON file")

    while not is_valid:
        try:
            file_name = validate_file_name()
            message = load_file(file_name)
            print_success(message)
            is_valid = True
        except OSError as error:
            print_error(str(error))


def menu_save_file():
    from app import save_file

    is_valid = False
    print_header("Save a JSON file")

    while not is_valid:
        try:
            file_name = validate_file_name()
            message = save_file(file_name)
            print_success(message)
            is_valid = True
        except OSError as error:
            print_error(str(error))
