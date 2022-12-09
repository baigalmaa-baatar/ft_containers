#!/bin/bash

vector_path='..'
map_path='../map.hpp'
stack_path='..'

NORMAL=$(tput sgr0)
BLACK=$(tput setaf 0)
RED=$(tput setaf 160)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
POWDER_BLUE=$(tput setaf 153)
BLUE=$(tput setaf 4)
MAGENTA=$(tput setaf 5)
CYAN=$(tput setaf 6)
WHITE=$(tput setaf 7)
BRIGHT=$(tput bold)
BLINK=$(tput blink)
REVERSE=$(tput smso)
UNDERLINE=$(tput smul)

function title {
    echo ""
    echo -e "⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅"
    echo -e "⛅                                                  ⛅"
    echo -e "⛅             FT_CONTAINERS TESTER                 ⛅"
    echo -e "⛅                                                  ⛅"
    echo -e "⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅⛅"
    echo ""
}

function spinner {

    # char=(⣾⣽⣻⢿⡿⣟⣯⣷)
    char=(▁▂▃▄▅▆▇█▇▆▅▄▃▂▁)
    delay=0.1
    pid=$!
    i=0

    while kill -0 $pid 2>/dev/null; do
        for ((i=0; i<=3; i++)); do
            echo -n ${char[$i]}
            sleep $delay
            echo -ne '\b'
        done
    i=0
    done
    echo " "
}

function testing_vector {
    printf "${BRIGHT}${POWDER_BLUE}\n/* ************************************************************************** */\n"
	printf "/*                                  VECTOR                                    */\n"
    printf "/* ************************************************************************** */\n${NORMAL}"
    printf "\n\U1F4D8 Running tests with the STL... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -DSTL vector_tests.cpp && ./a.out > vector_stl_output.log & spinner) 
    printf "\n\U1F530 Running tests with your vector... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -I ${vector_path} vector_tests.cpp && ./a.out > vector_your_output.log & spinner) 
    printf "\n\U1F440 Comparing both outputs...\n"
    if diff vector_stl_output.log vector_your_output.log
    then
        printf "${BRIGHT}\n>>> VECTOR TESTS CLEAR \u2705\n"
        rm -rf vector*.log
    else
        printf "${BRIGHT}\n>>> VECTOR TESTS KO \u274C\n"
        printf "Compare both log files for more details.\n"
    fi
    echo "${NORMAL}"
}

function testing_stack {
    printf "${BRIGHT}${POWDER_BLUE}\n/* ************************************************************************** */\n"
	printf "/*                                   STACK                                    */\n"
    printf "/* ************************************************************************** */\n${NORMAL}"
    printf "\n\ Running tests with the STL... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -DSTL stack_tests.cpp && ./std_map.o > stack_stl_output.log & spinner) 
    printf "\n\ Running tests with your stack... "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -I ${stack_path} stack_tests.cpp && ./ft_map.o > stack_your_output.log & spinner) 
    printf "\n\U1F4D8 Comparing STD container's result with FT container's resutl"
    if comp std_map.o ft_map.o
    then
        printf "${BRIGHT}\n>>> MAP TESTS BINARY RESULTS ARE SAME \u2705\n"
    # if diff stack_stl_output.log stack_your_output.log
    # then
        printf "${BRIGHT}\n>>> STACK TESTS CLEAR \u2705\n"
        rm -rf stack*.log
    else
        printf "${BRIGHT}\n>>> STACK TESTS KO \u274C\n"
        printf "Compare both log files for more details.\n"
    fi
    echo "${NORMAL}"
}

function testing_map {
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅       Testing map            🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"

    printf "\nRunning tests with the STD container -> "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -DSTD map_tester.cpp && ./a.out > map_stl_output.log & spinner)
    mv a.out std_map.o
    printf "\nRunning tests with FT container ->"
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -I ${map_path} map_tester.cpp && ./a.out > map_ft_output.log & spinner)
    mv a.out ft_map.o
    printf "\nComparing both outputs...\n"
    if cmp -l std_map.o std_map.o
    then
        printf "${YELLOW}\n>>> MAP BINARY COMPARASION PASSED!✅\n"
        rm -rf std_map.o
        rm -rf ft_map.o
    else
        printf "${YELLOW}\n>>> MAP BINARY COMPARASION FAILED!❌\n"
    fi
    printf "Comparing the log files : \n"
    if diff map_stl_output.log map_ft_output.log
    then
        printf "${YELLOW}\n>>> MAP LOG FILES COMPARASION PASSED!✅\n"
        rm -rf map*.log
    else
        printf "${YELLOW}\n>>> MAP LOG FILES COMPARASION FAILED!❌\n"
        printf "Check log files.\n"
    fi
    echo "${NORMAL}"
}

function performance_test {
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅       Performance test            🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"

    printf "\nRunning performance test -> "
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra performance_test.cpp && ./a.out & spinner)
    mv a.out std_map.o
    printf "\nRunning tests with FT container ->"
    time (g++ -fsanitize=address -g3 -std=c++98 -Wall -Werror -Wextra -I ${map_path} performance_test.cpp && ./a.out & spinner)
    mv a.out ft_map.o
    printf "\nComparing both outputs...\n"
    if cmp -l std_map.o ft_map.o
    then
        printf "${BRIGHT}\n>>> MAP BINARY COMPARASION PASSED!✅\n"
        rm -rf std_map.o
        rm -rf ft_map.o
    else
        printf "${BRIGHT}\n>>> MAP BINARY COMPARASION FAILED!❌\n"
    fi
    printf "Comparing the log files : \n"
    if diff map_stl_output.log map_ft_output.log
    then
        printf "${BRIGHT}\n>>> MAP LOG FILES COMPARASION PASSED!✅\n"
        rm -rf map*.log
    else
        printf "${BRIGHT}\n>>> MAP LOG FILES COMPARASION FAILED!❌\n"
        printf "Check log files.\n"
    fi
    echo "${NORMAL}"
}

title
if [  "$1" == "vector" ]; then
    testing_vector
elif [  "$1" == "stack" ]; then
    testing_stack
elif [  "$1" == "map" ]; then
    testing_map
else
    testing_vector
    testing_stack
    testing_map
fi
rm -f a.out