#!bin/bash

read X; read Y;
operators=( + - \* / )
for operator in "${operators[@]}"; do
	echo "$(( $X $operator $Y ))"
done
