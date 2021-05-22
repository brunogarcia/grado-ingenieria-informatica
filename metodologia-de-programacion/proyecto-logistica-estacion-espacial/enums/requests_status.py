from enum import Enum


class RequestStatus(Enum):
    WAITING_FOR_ASSIGNMENT = 1
    ALLOCATED = 2
    IMPOSSIBLE_TO_FULFILL = 3
    DELIVERED = 4
