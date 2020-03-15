make
ARG=`ruby -e "puts (1..105).to_a.shuffle.join(' ')"`
echo $ARG > arg.txt
./push_swap $ARG
#./push_swap $ARG | ./checker $ARG