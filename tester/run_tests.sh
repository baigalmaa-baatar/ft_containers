#!/bin/bash

vector_path='../include/vector.hpp'
map_path='../include/map.hpp'
stack_path='../include/stack.hpp'

function title {
    echo ""
    echo -e "⛅ !!!!!! FT_CONTAINERS TESTER !!!!! ⛅"
    echo ""
}

function spinner {

    # char=(⣾⣽⣻⢿⡿⣟⣯⣷)
    char=(▌▀▐▄)
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

function testing_stack {
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅       Testing stack          🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"

    printf "\nRunning tests with the STD container -> "
    c++ -Wall -Werror -Wextra -std=c++98 -DSTD stack_tester.cpp && ./a.out > stack_std_output.log & spinner
    printf "\nRunning tests with FT container ->"
    c++ -Wall -Werror -Wextra -std=c++98 -I ${stack_path} stack_tester.cpp && ./a.out > stack_ft_output.log & spinner
    printf "\nComparing both outputs...\n"
    printf "Comparing the log files : \n"
    if diff stack_std_output.log stack_ft_output.log
    then
        printf "STACK FILES COMPARASION PASSED!✅\n"
        # rm -rf stack*.log
    else
        printf "STACK FILES COMPARASION FAILED!❌\n"
        printf "Check log files.\n"
    rm -rf a.out    
    fi
}

function testing_vector {
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅       Testing vector         🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"

    printf "\nRunning tests with the STD container -> "
    c++ -Wall -Werror -Wextra -std=c++98 -DSTD vector_tester.cpp && ./a.out > vector_std_output.log & spinner
    mv a.out std_vector.o
    printf "\nRunning tests with FT container ->"
    c++ -Wall -Werror -Wextra -std=c++98 -I ${vector_path} vector_tester.cpp && ./a.out > vector_ft_output.log & spinner
    mv a.out ft_vector.o
    printf "\nComparing both outputs...\n"
    printf "Comparing the log files : \n"
    if diff vector_std_output.log vector_ft_output.log
    then
        printf "VECTOR LOG FILES COMPARASION PASSED!✅\n"
        # rm -rf vector*.log
    else
        printf "VECTOR LOG FILES COMPARASION FAILED!❌\n"
        printf "Check log files.\n"
    rm -rf a.out
    fi
}

function testing_map {
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅       Testing map            🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"

    printf "\nRunning tests with the STD container -> "
    c++ -std=c++98 -Wall -Werror -Wextra -DSTD map_tester.cpp && ./a.out > map_std_output.log & spinner
    printf "\nRunning tests with FT container ->"
    c++ -std=c++98 -Wall -Werror -Wextra -I ${map_path} map_tester.cpp && ./a.out > map_ft_output.log & spinner
    printf "\nComparing both outputs...\n"
    printf "Comparing the log files : \n"
    if diff map_std_output.log map_ft_output.log
    then
        printf "${YELLOW}\n>>> MAP LOG FILES COMPARASION PASSED!✅\n"
        # rm -rf map*.log
    else
        printf "${YELLOW}\n>>> MAP LOG FILES COMPARASION FAILED!❌\n"
        printf "Check log files.\n"
    fi
    echo "${NORMAL}"
}

function testing_performance {
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅       Performance test       🔅🔅🔅🔅🔅🔅\n"
	printf "🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅🔅\n"

    printf "\nRunning performance test STD -> "
    time (c++ -std=c++98 -Wall -Werror -Wextra -DSTD performance.cpp && ./a.out > std_per_out.log & spinner)
    printf "\nRunning performance test FT -> "
    time (c++ -std=c++98 -Wall -Werror -Wextra -I ${map_path} performance.cpp && ./a.out > ft_per_out.log & spinner)
    printf "\nPerformance test executed\n"
}

title
if [  "$1" == "stack" ]; then
    testing_stack
elif [  "$1" == "vector" ]; then
    testing_vector
elif [  "$1" == "map" ]; then
    testing_map
elif [  "$1" == "per" ]; then
    testing_performance
else
    testing_stack
    testing_vector
    testing_map
    testing_performance    
fi
rm -f a.out
rm -rf *output.log
