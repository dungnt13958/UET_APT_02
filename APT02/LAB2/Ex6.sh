#NguyenTuanDung
#!/bin/bash
read -p "Nhap N: " N
if [ $((N % 2)) -eq 0 ]; then
        echo "$N la so chan"
else
        echo "$N la so le"
fi
for ((i = 1; i <= N; i++))
do
        if [ $((i % 2)) -eq 0 ]; then
                echo "$i la so chan"
        else
                echo "$i la so le"
        fi
done
for file in ../Labs/Lab1/Hello.txt Ex4_results.txt Ex6.sh
do
        if [ -f "$file" ]; then
                echo "$file exists"
        else
                echo "$file not exist"
        fi
done
exit 0
