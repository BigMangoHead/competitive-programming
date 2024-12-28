cd "$1"
g++ "$(find . -name '*.cpp')" -o exec
IFS=';' read -rd '' -a v < input
IFS=';' read -rd '' -a w < want
i=0
for e in "${v[@]}"
do
    echo
    ./exec <<< "$e" > out 2> log
    echo " = OUT = "
    cat out
    echo
    echo " = EXPECTED = "
    echo "${w[$i]}"
    echo " = LOG = "
    cat log
    echo
    ((i++))
done