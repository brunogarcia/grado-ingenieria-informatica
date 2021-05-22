from enums.print_colors import Colors


def print_header(text: str) -> None:
    print(Colors.HEADER + '#-----' + text + '-----#' + Colors.END)


def print_sub_header(text: str, text_id: str = '') -> None:
    print(Colors.SUB_HEADER + '-----' + text + ' ' + text_id + '-----' + Colors.END)


def print_success(text: str) -> None:
    print(Colors.GREEN + 'Success: ' + text + Colors.END)


def print_error(text: str) -> None:
    print(Colors.FAIL + 'Error: ' + text + Colors.END)


def print_warning(text: str) -> None:
    print(Colors.WARNING + text + Colors.END)
