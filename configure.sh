#!/bin/bash

print_help() {
    echo "
SYNOPSIS
  ./configure.sh [-hrdp <prefix]
OPTIONS
  -h: print this help and exit
  -p <prefix>: set the desired prefix to <prefix>
  -r: toggle release mode
  -d: toggle debug mode
" >&2
}

set_prefix() {
    sed -i "s/^PREFIX = .*$/PREFIX = $(echo "$1" | sed 's/\//\\\//g')/" Makefile
}

prepare_release() {
    sed -i 's/-ggdb/-O3/g' Makefile
}

prepare_debug() {
    sed -i 's/-O3/-ggdb/g' Makefile
}

main() {
    local opts
    while getopts "hp:rd" opts; do
        case $opts in
            h)
                print_help
                exit 0
                ;;
            p)
                set_prefix "$OPTARG"
                ;;
            r)
                prepare_release
                ;;
            d)
                prepare_debug
                ;;
        esac
    done
}

main "$@"
