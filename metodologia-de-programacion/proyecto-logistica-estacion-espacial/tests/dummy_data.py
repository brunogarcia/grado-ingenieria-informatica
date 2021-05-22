import app


def add_dummy_data() -> None:
    """
    Add dummy data

    :return: None
    """
    add_rockets()
    add_requests()
    add_missions()


def add_rockets() -> None:
    """
    Add rockets

    :return: None
    """
    app.add_new_rocket('falcon1', 600)
    app.add_new_rocket('falcon9', 22800)


def add_requests() -> None:
    """
    Add requests

    :return: None
    """
    app.add_new_request('p04', 'spare parts', 20.2, 3)
    app.add_new_request('p02', 'food', 300.0, 28)
    app.add_new_request('p03', 'spare parts', 800.0, 60)
    app.add_new_request('p01', 'oxygen', 105.7, 28)


def add_missions() -> None:
    """
    Add missions

    :return: None
    """
    app.add_new_mission('m03', 'falcon9', 60)
    app.add_new_mission('m02', 'falcon1', 30)
    app.add_new_mission('m01', 'falcon1', 10)


def update_requests() -> None:
    """
    Update requests

    :return: None
    """
    app.update_requests([
        {
            'id': 'p04',
            'description': 'spare parts',
            'weight': 20.2,
            'daysMaxToDeliver': 3,
            'status': 'WAITING_FOR_ASSIGNMENT'
        },
        {
            'id': 'p05',
            'description': 'tech',
            'weight': 20.2,
            'daysMaxToDeliver': 3,
            'status': 'DELIVERED'
        },
        {
            'id': 'p02',
            'description': 'food',
            'weight': 300,
            'daysMaxToDeliver': 28,
            'status': 'ALLOCATED'
        },
        {
            'id': 'p03',
            'description': 'spare parts',
            'weight': 800,
            'daysMaxToDeliver': 60,
            'status': 'ALLOCATED'
        },
        {
            'id': 'p01',
            'description': 'oxygen',
            'weight': 105.7,
            'daysMaxToDeliver': 28,
            'status': 'IMPOSSIBLE_TO_FULFILL'
        }
    ])


def update_missions() -> None:
    """
    Update missions

    :return: None
    """
    app.update_missions([
        {'id': 'm04', 'rocketId': 'falcon9', 'daysToArriveAtStation': 90, 'status': "ON_HOLD"},
        {'id': 'm03', 'rocketId': 'falcon9', 'daysToArriveAtStation': 60, 'status': "ON_HOLD"},
        {'id': 'm02', 'rocketId': 'falcon1', 'daysToArriveAtStation': 30, 'status': "ON_ROUTE"},
        {'id': 'm01', 'rocketId': 'falcon1', 'daysToArriveAtStation': 10, 'status': "ON_STATION"}
    ])
