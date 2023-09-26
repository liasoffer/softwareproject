param (
    [string]$command = 'bnr'
 )

function build {
    # TODO: Add later all file names to compile (next to main.c, utils.c, etc...).
    gcc main.c utils.c -ansi -Wall -Wextra -Werror -pedantic-errors -o main.exe
}

function bnr {
    build
    .\main.exe sym input.txt
}

if ($command -eq 'bnr') {
    bnr
}
if ($command -eq 'build') {
    build
}