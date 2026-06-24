#!/bin/bash

echo "Subject examples"
echo 'sdxddssaaww' | ./life 5 5 0 | cat -e
echo
sleep 1
echo 'sdxssdswdxddddsxaadwxwdxwaa' | ./life 10 6 0 | cat -e
echo
sleep 1
echo 'dxss' | ./life 3 3 0 | cat -e
echo
sleep 1
echo 'dxss' | ./life 3 3 1 | cat -e
echo
sleep 1
echo 'dxss' | ./life 3 3 2 | cat -e
echo
sleep 1

echo "Still life: block (should not change)"
echo 'sdxdssd' | ./life 5 4 1 | cat -e
echo
sleep 1
echo 'sdxdssd' | ./life 5 4 10 | cat -e
echo
sleep 1

echo "Oscillator: blinker period check"
echo 'dxss' | ./life 3 3 3 | cat -e
echo
sleep 1
echo 'dxss' | ./life 3 3 4 | cat -e
echo
sleep 1

echo "Death: single cell"
echo 'x' | ./life 3 3 1 | cat -e
echo
sleep 1

echo "Death: two adjacent cells"
echo 'xd' | ./life 3 3 1 | cat -e
echo
sleep 1

echo "Birth: L-shape fills corner"
echo 'xdssd' | ./life 3 3 1 | cat -e
echo
sleep 1

echo "Boundary: blinker at top edge"
echo 'xdd' | ./life 5 3 1 | cat -e
echo
sleep 1

echo "Boundary: corner cell dies"
echo 'x' | ./life 1 1 1 | cat -e
echo
sleep 1

echo "Empty board"
echo '' | ./life 5 5 0 | cat -e
echo
sleep 1

echo "Pen: double toggle (no draw)"
echo 'xxddd' | ./life 5 1 0 | cat -e
echo
sleep 1

echo "Pen: clamp at right edge"
echo 'xdddddddd' | ./life 3 1 0 | cat -e
echo
sleep 1

echo "Pen: clamp at bottom edge"
echo 'xssssssss' | ./life 1 3 0 | cat -e
echo
sleep 1

echo "Pen: draw same cell twice"
echo 'xdadx' | ./life 3 1 0 | cat -e
echo
