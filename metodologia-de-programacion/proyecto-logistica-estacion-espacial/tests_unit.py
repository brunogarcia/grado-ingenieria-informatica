# -*- coding: utf-8 -*-
"""
Unit tests for the app
@author: Bruno Garcia
"""

import unittest
import app
from tests import dummy_data


class TestExercise(unittest.TestCase):
    def tearDown(self):
        app.clear_data()

    '''
    Rockets
    '''

    def test_add_new_rockets(self):
        # arrange
        expected = [
            {'id': 'falcon1', 'payload': 600, 'success': False},
            {'id': 'falcon9', 'payload': 22800, 'success': False}
        ]

        # act
        dummy_data.add_rockets()

        # assert
        self.assertListEqual(app.get_rockets(), expected, "Must have added rockets to the list of rockets")

    def test_empty_rocket_id_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_rocket('', 200)

    def test_invalid_rocket_id_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_rocket('x', 200)

    def test_rocket_id_already_exists_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_rocket('abc', 200)
            app.add_new_rocket('abc', 200)

    def test_invalid_rocket_payload_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_rocket('123ABC', 'invalid payload')

    '''
    Requests
    '''

    def test_add_new_requests(self):
        # arrange
        expected = [
            {
                'id': 'p04',
                'description': 'spare parts',
                'weight': 20.2,
                'daysMaxToDeliver': 3,
                'status': 'WAITING_FOR_ASSIGNMENT'
            },
            {
                'id': 'p02',
                'description': 'food',
                'weight': 300,
                'daysMaxToDeliver': 28,
                'status': 'WAITING_FOR_ASSIGNMENT'
            },
            {
                'id': 'p03',
                'description': 'spare parts',
                'weight': 800,
                'daysMaxToDeliver': 60,
                'status': 'WAITING_FOR_ASSIGNMENT'
            },
            {
                'id': 'p01',
                'description': 'oxygen',
                'weight': 105.7,
                'daysMaxToDeliver': 28,
                'status': 'WAITING_FOR_ASSIGNMENT'
            }
        ]

        # act
        dummy_data.add_requests()

        # assert
        self.assertListEqual(app.get_requests(), expected, "Must have added requests to the list of requests")

    def test_get_requests_by_status(self):
        # arrange
        expected = {
            'WAITING_FOR_ASSIGNMENT': [
                {
                    'id': 'p04',
                    'description': 'spare parts',
                    'weight': 20.2,
                    'daysMaxToDeliver': 3,
                    'status': 'WAITING_FOR_ASSIGNMENT'
                }
            ],
            'ALLOCATED': [
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
                }
            ],
            'IMPOSSIBLE_TO_FULFILL': [
                {
                    'id': 'p01',
                    'description': 'oxygen',
                    'weight': 105.7,
                    'daysMaxToDeliver': 28,
                    'status': 'IMPOSSIBLE_TO_FULFILL'
                }
            ],
            'DELIVERED': [
                {
                    'id': 'p05',
                    'description': 'tech',
                    'weight': 20.2,
                    'daysMaxToDeliver': 3,
                    'status': 'DELIVERED'
                }
            ],
        }

        # act
        dummy_data.update_requests()

        # assert
        self.assertDictEqual(app.get_requests_by_status(), expected, "Must return the list of requests organized"
                                                                     " by status")

    def test_empty_request_id_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_request('', 'testing', 200, 10)

    def test_invalid_request_id_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_request('x', 'testing', 200, 10)

    def test_request_id_already_exists_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_request('abc', 'testing 1', 200, 10)
            app.add_new_request('abc', 'testing 2', 200, 10)

    def test_invalid_weight_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_request('123abc', 'testing', 'invalid weight', 10)

    def test_invalid_days_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_request('123abc', 'testing', 100.12, 'invalid days')

    '''
    Missions
    '''

    def test_add_new_missions(self):
        # arrange
        expected = [
            {'id': 'm03', 'rocketId': 'falcon9', 'daysToArriveAtStation': 60, 'status': "ON_HOLD"},
            {'id': 'm02', 'rocketId': 'falcon1', 'daysToArriveAtStation': 30, 'status': "ON_HOLD"},
            {'id': 'm01', 'rocketId': 'falcon1', 'daysToArriveAtStation': 10, 'status': "ON_HOLD"}
        ]

        # act
        dummy_data.add_rockets()
        dummy_data.add_missions()

        # assert
        self.assertListEqual(app.get_missions(), expected, "Must have added missions to the list of missions")

    def test_get_missions_by_status(self):
        # arrange
        expected = {
            'ON_HOLD': [
                {'id': 'm04', 'rocketId': 'falcon9', 'daysToArriveAtStation': 90, 'status': "ON_HOLD"},
                {'id': 'm03', 'rocketId': 'falcon9', 'daysToArriveAtStation': 60, 'status': "ON_HOLD"},
            ],
            'ON_ROUTE': [
                {'id': 'm02', 'rocketId': 'falcon1', 'daysToArriveAtStation': 30, 'status': "ON_ROUTE"},
            ],
            'ON_STATION': [
                {'id': 'm01', 'rocketId': 'falcon1', 'daysToArriveAtStation': 10, 'status': "ON_STATION"}
            ]
        }

        # act
        dummy_data.update_missions()

        # assert
        self.assertDictEqual(app.get_missions_by_status(), expected, "Must return the list of missions organized"
                                                                     " by status")

    def test_mission_id_already_exists_must_raise_value_error(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_mission('m01', 'falcon1', 10)
            app.add_new_mission('m01', 'falcon9', 20)

    def test_a_mission_should_have_a_valid_rocket_id(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_rocket('rocket_123', 200)
            app.add_new_mission('m01', 'invalid_rocket_id', 10)

    def test_a_mission_should_have_a_valid_days_to_arrive(self):
        # assert
        with self.assertRaises(ValueError):
            app.add_new_rocket('rocket_123', 200)
            app.add_new_mission('m01', 'rocket_123', 'bad_days')

    '''
    Order request by:
    - days max to deliver
    - and weight
    '''

    def test_order_requests(self):
        # arrange
        expected = [
            {
                'id': 'p04',
                'description': 'spare parts',
                'weight': 20.2,
                'daysMaxToDeliver': 3,
                'status': 'WAITING_FOR_ASSIGNMENT'
            },
            {
                'id': 'p01',
                'description': 'oxygen',
                'weight': 105.7,
                'daysMaxToDeliver': 28,
                'status': 'WAITING_FOR_ASSIGNMENT'
            },
            {
                'id': 'p02',
                'description': 'food',
                'weight': 300,
                'daysMaxToDeliver': 28,
                'status': 'WAITING_FOR_ASSIGNMENT'
            },
            {
                'id': 'p03',
                'description': 'spare parts',
                'weight': 800,
                'daysMaxToDeliver': 60,
                'status': 'WAITING_FOR_ASSIGNMENT'
            }
        ]

        # act
        dummy_data.add_requests()
        app.order_requests()

        # assert
        self.assertListEqual(app.get_requests(), expected, "Must order the requests by days max to deliver "
                                                           "and weight")

    '''
    Order missions missions by:
    - days to arrive at station and
    - the rocket id
    '''

    def test_order_missions(self):
        # arrange
        expected = [
            {'id': 'm01', 'rocketId': 'falcon1', 'daysToArriveAtStation': 10, 'status': "ON_HOLD"},
            {'id': 'm02', 'rocketId': 'falcon1', 'daysToArriveAtStation': 30, 'status': "ON_HOLD"},
            {'id': 'm03', 'rocketId': 'falcon9', 'daysToArriveAtStation': 60, 'status': "ON_HOLD"}
        ]

        # act
        dummy_data.add_rockets()
        dummy_data.add_missions()
        app.order_missions()

        # assert
        self.assertListEqual(app.get_missions(), expected, "Must order the missions by days to arrive at "
                                                           "station and the rocket id")

    '''
    Assign requests to missions
    '''

    def test_not_exists_enough_data_for_assignment_process(self):
        # assert
        with self.assertRaises(ValueError):
            app.assign_requests_missions()

    def test_assignments(self):
        # arrange
        expected = [
            {'missionId': 'm01', 'daysToArriveAtStation': 10, 'payload': 194.3, 'requestIds': ['p01', 'p02']},
            {'missionId': 'm03', 'daysToArriveAtStation': 60, 'payload': 22000.0, 'requestIds': ['p03']}
        ]

        # act
        dummy_data.add_dummy_data()
        app.assign_requests_missions()

        # assert
        self.assertListEqual(app.get_assignments(), expected, "Must apply the assignments properly")

    def test_assignments_missions(self):
        # arrange
        expected = [
            {'id': 'm01', 'rocketId': 'falcon1', 'daysToArriveAtStation': 10, 'status': "ON_ROUTE"},
            {'id': 'm02', 'rocketId': 'falcon1', 'daysToArriveAtStation': 30, 'status': "ON_HOLD"},
            {'id': 'm03', 'rocketId': 'falcon9', 'daysToArriveAtStation': 60, 'status': "ON_ROUTE"}
        ]

        # act
        dummy_data.add_dummy_data()
        app.assign_requests_missions()

        # assert
        self.assertListEqual(app.get_missions(), expected, "The missions status must be updated")

    def test_assignments_requests(self):
        # arrange
        expected = [
            {
                'id': 'p04',
                'description': 'spare parts',
                'weight': 20.2,
                'daysMaxToDeliver': 3,
                'status': 'IMPOSSIBLE_TO_FULFILL'
            },
            {
                'id': 'p01',
                'description': 'oxygen',
                'weight': 105.7,
                'daysMaxToDeliver': 28,
                'status': 'ALLOCATED'
            },
            {
                'id': 'p02',
                'description': 'food',
                'weight': 300.0,
                'daysMaxToDeliver': 28,
                'status': 'ALLOCATED'
            },
            {
                'id': 'p03',
                'description': 'spare parts',
                'weight': 800.0,
                'daysMaxToDeliver': 60,
                'status': 'ALLOCATED'
            }
        ]

        # act
        dummy_data.add_dummy_data()
        app.assign_requests_missions()

        # assert
        self.assertListEqual(app.get_requests(), expected, "The requests status must be updated")

    '''
    Simulate 5 days of flight
    The time to arrive at the station must be 5 days less
    '''

    def test_simulate_by_5_days(self):
        # arrange
        expected = [
            {'missionId': 'm01', 'daysToArriveAtStation': 5, 'payload': 194.3, 'requestIds': ['p01', 'p02']},
            {'missionId': 'm03', 'daysToArriveAtStation': 55, 'payload': 22000, 'requestIds': ['p03']}
        ]

        # act
        dummy_data.add_dummy_data()
        app.assign_requests_missions()
        app.simulate_by_days(5)

        # assert
        self.assertListEqual(app.get_assignments(), expected, "The time to arrive at the station must be 5 days less")

    '''
    Simulate 15 days of flight
    An assignment arrive at the station
    '''

    def test_assignment_arrive_at_station(self):
        # arrange
        expected = [
            {'missionId': 'm03', 'daysToArriveAtStation': 45, 'payload': 22000, 'requestIds': ['p03']}
        ]

        # act
        dummy_data.add_dummy_data()
        app.assign_requests_missions()
        app.simulate_by_days(15)

        # assert
        self.assertListEqual(app.get_assignments(), expected, "The mission m01 was removed from the assignment list")

    '''
    Simulate 15 days of flight
    A mission arrive at the station
    '''

    def test_mission_arrive_at_station(self):
        # arrange
        expected = [
            {'id': 'm01', 'rocketId': 'falcon1', 'daysToArriveAtStation': 10, 'status': "ON_STATION"},
            {'id': 'm02', 'rocketId': 'falcon1', 'daysToArriveAtStation': 30, 'status': "ON_HOLD"},
            {'id': 'm03', 'rocketId': 'falcon9', 'daysToArriveAtStation': 60, 'status': "ON_ROUTE"}
        ]

        # act
        dummy_data.add_dummy_data()
        app.assign_requests_missions()
        app.simulate_by_days(15)

        # assert
        self.assertListEqual(app.get_missions(), expected, "The mission m01 has changed its status flag"
                                                           "to on station")

    '''
    Simulate 15 days of flight
    A rocket arrive at the station
    '''

    def test_rocket_arrive_at_station(self):
        # arrange
        expected = [
            {'id': 'falcon1', 'payload': 600, 'success': True},
            {'id': 'falcon9', 'payload': 22800, 'success': False}
        ]

        # act
        dummy_data.add_dummy_data()
        app.assign_requests_missions()
        app.simulate_by_days(15)

        # assert
        self.assertListEqual(app.get_rockets(), expected, "The rocket falcon1 has changed its success flag")

    '''
    Simulate 15 days of flight
    The requests p01 amd p02 arrive at the station
    '''

    def test_requests_arrive_at_station(self):
        # arrange
        expected = [
            {
                'id': 'p04',
                'description': 'spare parts',
                'weight': 20.2,
                'daysMaxToDeliver': 3,
                'status': 'IMPOSSIBLE_TO_FULFILL'
            },
            {
                'id': 'p01',
                'description': 'oxygen',
                'weight': 105.7,
                'daysMaxToDeliver': 28,
                'status': 'DELIVERED'
            },
            {
                'id': 'p02',
                'description': 'food',
                'weight': 300.0,
                'daysMaxToDeliver': 28,
                'status': 'DELIVERED'
            },
            {
                'id': 'p03',
                'description': 'spare parts',
                'weight': 800.0,
                'daysMaxToDeliver': 60,
                'status': 'ALLOCATED'
            }
        ]

        # act
        dummy_data.add_dummy_data()
        app.assign_requests_missions()
        app.simulate_by_days(15)

        # assert
        self.assertListEqual(app.get_requests(), expected, "The requests p01 and p02 have changed the status "
                                                           "to delivered")


if __name__ == '__main__':
    unittest.main()
