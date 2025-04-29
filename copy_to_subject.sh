#!/bin/bash
echo -n "dir?>"
read input

mkdir -p $input \
&& cp -r src/ $input \
&& cp -r inc/ $input \
&& cp -r lib/ $input \
&& cp Makefile $input

echo "output done!"
