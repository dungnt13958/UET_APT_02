#NguyenTuanDung
#!/bin/bash
ls -la ~ > Ex4_results.txt
ls -la ~ | tail -n +2 | wc -l >> Ex4_results.txt
sed -n '3p' ../Labs/Lab1/Hello.txt | tee /dev/tty | wc -w >> Ex4_results.txt
grep -o '\bcourse\b' ../Labs/Lab1/Hello.txt | wc -l >> Ex4_results.txt
ps -e --no-headers | wc -l >> Ex4_results.txt

