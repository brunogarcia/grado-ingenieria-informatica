# -*- coding: utf-8 -*-
"""
Send missions to the International Space Station (ISS)
@author: Bruno Garcia
"""
import json
from menu import app_menu
from general_information import print_data
from enums.mission_status import MissionStatus
from enums.requests_status import RequestStatus


"""
Private variables
"""

_rockets = []
_requests = []
_missions = []
_assignments = []


"""
Rockets
"""


def get_rockets() -> list:
    """
    Return the list of rockets
    :return: list
    """
    return _rockets


def update_rockets(rockets: list) -> None:
    """
    First, clear the list of rockets and then add the new ones

    :param rockets: list
    :return: None
    """
    _rockets.clear()
    _rockets.extend(rockets)


def _update_rocket_success(rocket_id: str) -> None:
    """
    Mark the rocket as a success

    :param rocket_id: str
    :return: None
    """
    for rocket in get_rockets():
        if rocket['id'] == rocket_id:
            print('Update success flag of rocket ' + rocket_id + '\n')
            rocket['success'] = True


def get_rocket(rocket_id: str) -> dict:
    """
    Find a rocket by id

    :param rocket_id: str
    :return: dict
    """
    return next((item for item in get_rockets() if item['id'] == rocket_id), None)


def add_new_rocket(rocket_id: str, payload: int) -> str:
    """
    Add a new rocket to the list of rockets

    :param rocket_id: str
    :param payload: int
    :return: str
    """
    rocket = get_rocket(rocket_id)

    if len(rocket_id) == 0:
        raise ValueError("The rocket id should not be empty")
    elif len(rocket_id) < 3:
        raise ValueError("The rocket id should have at least 3 characters")
    elif rocket is not None:
        raise ValueError("The rocket id already exists")
    elif not type(payload) is int:
        raise ValueError("The payload should be a number")
    else:
        _rockets.append({
            'id': rocket_id,
            'payload': payload,
            'success': False
        })

        return 'Rocket' + rocket_id + 'added'


"""
Requests
"""


def get_requests() -> list:
    """
    Return the list of requests

    :return: list
    """
    return _requests


def get_requests_by_status() -> dict:
    """
    Return the list of requests organized by status

    :return: dict
    """
    data = {
        RequestStatus.WAITING_FOR_ASSIGNMENT.name: [],
        RequestStatus.ALLOCATED.name: [],
        RequestStatus.IMPOSSIBLE_TO_FULFILL.name:  [],
        RequestStatus.DELIVERED.name: []
    }

    for request in get_requests():
        status = request['status']
        data[status].append(request)

    return data


def update_requests(requests: list) -> None:
    """
    First, clear the list of requests and then add the new ones

    :param requests: list
    :return: None
    """
    _requests.clear()
    _requests.extend(requests)


def _update_request_delivery(request_id: str) -> None:
    """
    Mark the request as delivered

    :param request_id: str
    :return: None
    """
    for request in get_requests():
        if request['id'] == request_id:
            print('Update delivery of request ' + request_id + '\n')
            request['status'] = RequestStatus.DELIVERED.name


def order_requests() -> None:
    """
    Order the requests by days max to deliver and weight

    :return: None
    """
    requests_ordered = sorted(get_requests(), key=lambda i: (i['daysMaxToDeliver'], i['weight']))
    update_requests(requests_ordered)


def _check_request(request_id: str) -> bool:
    """
    Check if the request-id already exists on the list of requests

    :param request_id: str
    :return: bool
    """
    request = next((item for item in get_requests() if item['id'] == request_id), None)
    result = False if request is None else True
    return result


def add_new_request(request_id: str, description: str, weight: float, days_max_to_deliver: int) -> str:
    """
    Add a new request to the list of requests

    :param request_id: str
    :param description: str
    :param weight: float
    :param days_max_to_deliver: int
    :return: str
    """
    exists_request = _check_request(request_id)

    if len(request_id) == 0:
        raise ValueError("The request id should not be empty")
    elif len(request_id) < 3:
        raise ValueError("The request id should have at least 3 characters")
    elif exists_request:
        raise ValueError("The request id already exists")
    elif not type(weight) is float:
        raise ValueError("The weight should be a float")
    elif not type(days_max_to_deliver) is int:
        raise ValueError("The days max to deliver should be a number")
    else:
        _requests.append({
            'id': request_id,
            'description': description,
            'weight': weight,
            'daysMaxToDeliver': days_max_to_deliver,
            'status': RequestStatus.WAITING_FOR_ASSIGNMENT.name
        })

        return 'Request' + request_id + 'added'


"""
Missions
"""


def get_missions() -> list:
    """
    Return the list of missions

    :return: list
    """
    return _missions


def get_missions_by_status() -> dict:
    """
    Return the list of missions organized by status

    :return: dict
    """
    data = {
        MissionStatus.ON_HOLD.name: [],
        MissionStatus.ON_ROUTE.name: [],
        MissionStatus.ON_STATION.name:  [],
    }

    for mission in get_missions():
        status = mission['status']
        data[status].append(mission)

    return data


def update_missions(missions: list) -> None:
    """
    First, clear the list of missions and then add the new ones

    :param missions: list
    :return: None
    """
    _missions.clear()
    _missions.extend(missions)


def _update_mission_status(mission_id: str, status: str) -> None:
    """
    First, update the mission status and then update the rocket success flag

    :param mission_id: str
    :param status: str
    :return: None
    """
    for mission in get_missions():
        if mission['id'] == mission_id:
            # 1) update mission 'status' flag
            print('Update status of mission ' + mission_id + '\n')
            mission['status'] = status

            # 2) update rocket 'success' flag
            _update_rocket_success(mission['rocketId'])


def order_missions() -> None:
    """
    Order the missions by days to arrive at station and the rocket id

    :return: None
    """
    missions_ordered = sorted(get_missions(), key=lambda i: (i['daysToArriveAtStation'], i['rocketId']))
    update_missions(missions_ordered)


def _check_mission(mission_id: str) -> bool:
    """
    Check if the mission-id already exists on the list of missions

    :param mission_id: str
    :return: bool
    """
    mission = next((item for item in get_missions() if item['id'] == mission_id), None)
    result = False if mission is None else True
    return result


def add_new_mission(mission_id: str, rocket_id: str, days_to_arrive_at_station: int) -> str:
    """
    Add a new mission to the list of missions

    :param mission_id: str
    :param rocket_id: str
    :param days_to_arrive_at_station: int
    :return: str
    """
    exists_mission = _check_mission(mission_id)
    rocket = get_rocket(rocket_id)

    if exists_mission:
        raise ValueError("The mission already exists")
    elif rocket is None:
        raise ValueError("The rocket should exist")
    elif not type(days_to_arrive_at_station) is int:
        raise ValueError("The days to arrive at station should be a number")
    else:
        _missions.append({
            'id': mission_id,
            'rocketId': rocket_id,
            'daysToArriveAtStation': days_to_arrive_at_station,
            'status': MissionStatus.ON_HOLD.name
        })

        return 'Mission' + mission_id + 'added'


"""
Assignments
"""


def get_assignments() -> list:
    """
    Return the list of assignments

    :return: list
    """
    return _assignments


def get_assignment(mission_id: str) -> dict:
    """
    Find the mission by id

    :param mission_id: str
    :return: dict
    """
    return next((item for item in get_assignments() if item['missionId'] == mission_id), None)


def update_assignments(assignments: list) -> None:
    """
    First, clear the list of assignments and then add the new ones

    :param assignments: list
    :return: None
    """
    _assignments.clear()
    _assignments.extend(assignments)


def validate_assignment_process() -> bool:
    """
    Validate if the assignment process could init

    :return: bool
    """
    exists_rockets = len(get_rockets()) > 0
    exists_requests = len(get_requests()) > 0
    exists_missions = len(get_missions()) > 0

    return exists_rockets and exists_requests and exists_missions


"""
Assign requests and missions
"""


def assign_requests_missions() -> str:
    """
    Assign requests and missions

    :return: str
    """
    exists_enough_data = validate_assignment_process()

    if exists_enough_data:
        # 1) order requests
        order_requests()

        # 2) order missions
        order_missions()

        # 3) init the assignment process
        init_assignment_process()

        return 'The assignments were processed'
    else:
        raise ValueError('Should exist at least one rocket, '
                         'one request, and one mission for init the assignment process')


def init_assignment_process() -> None:
    """
    Init the assignment process

    :return: None
    """
    new_assignments = []

    # process missions
    process_missions_for_assignment(new_assignments)

    # update assignments
    update_assignments(new_assignments)


def process_missions_for_assignment(assignments: list) -> None:
    """
    Process missions for assignment

    :param assignments: list
    :return: None
    """
    for mission in get_missions():
        is_mission_on_hold = mission['status'] == MissionStatus.ON_HOLD.name

        if is_mission_on_hold:
            process_requests_for_assignment(mission, assignments)


def process_requests_for_assignment(mission: dict, assignments: list) -> None:
    """
    Process requests for assignment

    :param mission: dict
    :param assignments: list
    :return: None
    """
    for request in get_requests():
        is_request_waiting_for_assignment = request['status'] == RequestStatus.WAITING_FOR_ASSIGNMENT.name

        if is_request_waiting_for_assignment:
            validate_mission_and_request_days(mission, request, assignments)


def validate_mission_and_request_days(mission: dict, request: dict, assignments: list) -> None:
    """
    Validate mission and request days

    :param mission: dict
    :param request: dict
    :param assignments: list
    :return: None
    """
    mission_will_arrive_at_time = mission['daysToArriveAtStation'] <= request['daysMaxToDeliver']

    if mission_will_arrive_at_time:
        assign_request_to_mission(mission, request, assignments)
    else:
        request['status'] = RequestStatus.IMPOSSIBLE_TO_FULFILL.name


def assign_request_to_mission(mission: dict, request: dict, assignments: list) -> None:
    """
    Assign request to mission

    :param mission: dict
    :param request: dict
    :param assignments: list
    :return: None
    """
    assignment = next((item for item in assignments if item['missionId'] == mission['id']), None)
    is_new_assignment = assignment is None

    if is_new_assignment:
        add_new_assignment(mission, request, assignments)
    else:
        update_assignment(mission, request, assignment)


def add_new_assignment(mission: dict, request: dict, assignments: list) -> None:
    """
    Add new assignment

    :param mission: dict
    :param request: dict
    :param assignments: list
    :return: None
    """
    # get the rocket
    rocket = get_rocket(mission['rocketId'])

    # the rocket payload must be greater than or equal to the request weight
    has_rocket_valid_payload = rocket['payload'] >= request['weight']

    if has_rocket_valid_payload:
        # update the mission status
        mission['status'] = MissionStatus.ON_ROUTE.name

        # update the request status
        request['status'] = RequestStatus.ALLOCATED.name

        # create a new assignment
        new_assignment = create_new_assignment(rocket, request, mission)

        # add the new assignment to the list of local assignments
        assignments.append(new_assignment)


def create_new_assignment(rocket: dict, request: dict, mission: dict) -> dict:
    """
    Create a new assignment

    :param rocket: dict
    :param request: dict
    :param mission: dict
    :return: dict
    """
    mission_id = mission['id']
    days = mission['daysToArriveAtStation']
    payload = rocket['payload'] - request['weight']
    request_id = request['id']

    return {
        'missionId': mission_id,
        'daysToArriveAtStation': days,
        'payload': payload,
        'requestIds': [request_id]
    }


def update_assignment(mission: dict, request: dict, assignment: dict) -> None:
    """
    Update assignment

    :param mission: dict
    :param request: dict
    :param assignment: dict
    :return: None
    """
    has_assignment_valid_payload = assignment['payload'] >= request['weight']

    if has_assignment_valid_payload:
        # update mission status
        mission['status'] = MissionStatus.ON_ROUTE.name

        # update request status
        request['status'] = RequestStatus.ALLOCATED.name

        # update the assignment payload
        assignment['payload'] = assignment['payload'] - request['weight']

        # add the new request id to the assignment
        assignment['requestIds'].append(request['id'])


"""
Simulate by days
"""


def simulate_by_days(days: int) -> None:
    """
    Simulate by days

    :param days: int
    :return: None
    """
    if not type(days) is int:
        raise ValueError("The days should be a number")
    elif days <= 0:
        raise ValueError("The days for simulation should be greater than zero")
    elif len(get_assignments()) == 0:
        raise ValueError("Should exist at least one assignment")
    else:
        _init_simulation(days)


def _init_simulation(days: int) -> None:
    """
    Init simulation

    :param days: int
    :return: None
    """
    assignments = []
    _process_assignments_simulation(days, assignments)
    update_assignments(assignments)


def _process_assignments_simulation(days: int, assignments: list) -> None:
    """
    Process assignments simulation

    :param days: int
    :param assignments: list
    :return: None
    """
    for assignment in get_assignments():
        # 1) update the days needed to arrive at the station
        assignment['daysToArriveAtStation'] = assignment['daysToArriveAtStation'] - days

        # 2) check if the assignment arrived at the station
        is_assignment_on_station = assignment['daysToArriveAtStation'] <= 0

        if is_assignment_on_station:
            # 3) process the assignment that arrived at the station
            _assignment_arrive_at_station(assignment)
        else:
            # 4) in any other case: add assignment to the list
            assignments.append(assignment)


def _assignment_arrive_at_station(assignment: dict) -> None:
    """
    First, update mission status and
    then update the requests delivery flag

    :param assignment: dict
    :return: None
    """
    mission_id = assignment['missionId']
    request_ids = assignment['requestIds']

    # 1) update mission status
    _update_mission_status(mission_id, MissionStatus.ON_STATION.name)

    # 2) update requests delivery
    for request_id in request_ids:
        _update_request_delivery(request_id)


"""
General information
"""


def general_information() -> None:
    """
    Print general information: rockets, requests, missions and assignments

    :return: None
    """
    # Rockets
    print_data.print_rockets()

    # Request
    print_data.print_requests()

    # Missions
    print_data.print_missions()

    # Assignments
    print_data.print_assignments()


"""
Files
"""


def load_file(file_name: str) -> str:
    """
    Read the JSON file and store the data in memory

    :return: str
    """
    try:
        json_file = open(file_name, 'r')
    except OSError:
        raise OSError("The file " + file_name + " does not exist")

    with json_file:
        # Read JSON file
        data = json.load(json_file)

        # Get the rockets and add them to the system
        rockets = data['rockets']
        update_rockets(rockets)

        # Get the requests and add them to the system
        requests = data['requests']
        update_requests(requests)

        # Get the missions and add them to the system
        missions = data['missions']
        update_missions(missions)

        # Get the  assignments and add them to the system
        assignments = data['assignments']
        update_assignments(assignments)

        # Display a success message
        return 'The file data has been read and stored properly'


def save_file(file_name: str) -> str:
    """
    Read the data from memory
    and write it on the required JSON file

    :return: str
    """
    # read data from memory
    data = {
        'rockets': get_rockets(),
        'requests': get_requests(),
        'missions': get_missions(),
        'assignments': get_assignments(),
    }

    # write the data on the required file
    try:
        with open(file_name, 'w') as outfile:
            json.dump(data, outfile, indent=1)
        return 'The data was saved properly on the file ' + file_name
    except OSError:
        raise OSError("It seems the system is not able to save the file " + file_name)


"""
Helpers
"""


def clear_data() -> None:
    """
    Clear the global data of the app

    :return: None
    """
    _rockets.clear()
    _requests.clear()
    _missions.clear()
    _assignments.clear()


if __name__ == '__main__':
    app_menu.display_menu()
