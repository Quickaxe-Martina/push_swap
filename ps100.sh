make
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
echo $ARG > arg.txt
./push_swap $ARG | cat -n