dir=$1
echo "Testing $1 directory"
mv ./sim.cc ./opcodes.h $1/
cd $1

sim1="simulate-1.cc"
sim2="simulate-2.cc"

echo "Compiling ${sim1}"
gcc -O3 -o sim-1 sim.cc $sim1

echo "Compiling ${sim2}"
gcc -O3 -o sim-2 sim.cc $sim2

echo "primes.bin:"
echo "Running original program:"
time ../sim ../primes.bin
echo "Running sim-1:"
time ./sim-1 ../primes.bin
echo "Running sim-2:"
time ./sim-2 ../primes.bin


echo "bubble.bin:"
echo "Running original program:"
time ../sim ../bubble.bin
echo "Running sim-1:"
time ./sim-1 ../bubble.bin
echo "Running sim-2:"
time ./sim-2 ../bubble.bin

mv opcodes.h sim.cc ../
