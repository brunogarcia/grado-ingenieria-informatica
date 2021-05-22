from enums.mission_status import MissionStatus
from enums.requests_status import RequestStatus
from helpers.helper_print import print_header, print_sub_header, print_success, print_warning


def print_rockets() -> None:
    from app import get_rockets

    rockets = get_rockets()

    if len(rockets) > 0:
        print_header('ROCKETS')
        for rockets in rockets:
            rocket_id = rockets['id']
            payload = rockets['payload']
            success = rockets['success']

            print_sub_header('Rocket', rocket_id)
            print('Payload: ' + str(payload) + '\n')

            if success:
                print_success('Yes')
    else:
        print_warning('There are no rockets in the system')


def print_requests() -> None:
    from app import get_requests, get_requests_by_status

    requests = get_requests()

    if len(requests) > 0:
        requests_by_status = get_requests_by_status()

        print_requests_by_status(requests_by_status[RequestStatus.WAITING_FOR_ASSIGNMENT.name],
                                 'WAITING FOR ASSIGNMENT')
        print_requests_by_status(requests_by_status[RequestStatus.ALLOCATED.name],
                                 'ALLOCATED')
        print_requests_by_status(requests_by_status[RequestStatus.IMPOSSIBLE_TO_FULFILL.name],
                                 'IMPOSSIBLE TO FULFILL')
        print_requests_by_status(requests_by_status[RequestStatus.DELIVERED.name],
                                 'DELIVERED')
    else:
        print_warning('There are no requests in the system')


def print_requests_by_status(requests: list, title: str) -> None:
    if len(requests) > 0:
        print_header('REQUESTS ' + title)
        for request in requests:
            request_id = request['id']
            description = request['description']
            weight = request['weight']

            print_sub_header('Request', request_id)
            print('Description: ' + description + '\n')
            print('Weight: ' + str(weight) + '\n')


def print_missions() -> None:
    from app import get_missions, get_missions_by_status

    missions = get_missions()

    if len(missions) > 0:
        missions_by_status = get_missions_by_status()

        print_missions_by_status(missions_by_status[MissionStatus.ON_HOLD.name], 'ON HOLD')
        print_missions_by_status(missions_by_status[MissionStatus.ON_ROUTE.name], 'ON ROUTE')
        print_missions_by_status(missions_by_status[MissionStatus.ON_STATION.name], 'ON STATION')
    else:
        print_warning('There are no missions in the system')


def print_missions_by_status(missions: list, title: str) -> None:
    if len(missions) > 0:
        print_header('MISSIONS ' + title)
        for mission in missions:
            mission_id = mission['id']
            rocket_id = mission['rocketId']
            days_to_arrive_at_station = mission['daysToArriveAtStation']

            print_sub_header('Mission', mission_id)
            print('Rocket id: ' + rocket_id + '\n')
            print('Days to arrive at station: ' + str(days_to_arrive_at_station) + '\n')


def print_assignments() -> None:
    from app import get_assignments

    assignments = get_assignments()

    if len(assignments) > 0:
        print_header('ASSIGNMENTS')
        for assignment in assignments:
            mission_id = assignment['missionId']
            days_to_arrive_at_station = assignment['daysToArriveAtStation']
            payload = assignment['payload']
            request_ids = assignment['requestIds']

            print_sub_header('Assignment')
            print('Mission id: ' + mission_id + '\n')
            print('Days to arrive at station: ' + str(days_to_arrive_at_station) + '\n')
            print('Payload: ' + str(payload) + '\n')
            print('Request ids: ' + ' '.join(map(str, request_ids)) + '\n')
    else:
        print_warning('There are no assignments in the system')
