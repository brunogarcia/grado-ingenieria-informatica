def validate_integer(message: str) -> int:
    try:
        value = int(input(message + ': '))
    except Exception:
        raise ValueError("The " + message + " should be a number")

    return value


def validate_float(message: str) -> float:
    try:
        value = float(input(message + ': '))
    except ValueError:
        raise ValueError("The " + message + " should be a float")

    return value


def validate_file_name() -> str:
    file_name = input('File name: ')
    valid_extension = '.json'

    if len(file_name) == 0:
        raise OSError("The file name must be valid")

    if valid_extension not in file_name.lower():
        raise OSError("Must be a .json file")

    return file_name
