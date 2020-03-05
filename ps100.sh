make
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
echo $ARG > arg.txt
./push_swap $ARG | cat -n