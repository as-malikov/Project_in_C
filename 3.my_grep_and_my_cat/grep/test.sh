echo "OK!    test my_grep -e 111 -e 123 -e Support my_text.txt 1.txt > result.txt"
grep -e 111 -e 123 -e Support my_text.txt 1.txt > result.txt
./my_grep -e 111 -e 123 -e Support my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -i i my_text.txt 1.txt > result.txt"
grep -i I my_text.txt 1.txt > result.txt
./my_grep -i I my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -v 123 my_text.txt 1.txt > result.txt"
grep -v 123 my_text.txt 1.txt > result.txt
./my_grep -v 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -c 123 my_text.txt 1.txt > result.txt"
grep -c 123 my_text.txt 1.txt > result.txt
./my_grep -c 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l 123 my_text.txt 1.txt > result.txt"
grep -l 123 my_text.txt 1.txt > result.txt
./my_grep -l 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l 123 my_text.txt 1.txt > result.txt"
grep -l 123 my_text.txt 1.txt > result.txt
./my_grep -l 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n 123 my_text.txt 1.txt > result.txt"
grep -n 123 my_text.txt 1.txt > result.txt
./my_grep -n 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -h 123 my_text.txt 1.txt > result.txt"
grep -n 123 my_text.txt 1.txt > result.txt
./my_grep -n 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -s 123 my_text.txt 1.txt > result.txt"
grep -s 123 1.txt 21.txt > result.txt
./my_grep -s 123 1.txt 21.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -f my_-f_file.txt my_text.txt > result.txt"
grep -f my_-f_file.txt my_text.txt > result.txt
./my_grep -f my_-f_file.txt my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -o my_text.txt 1.txt > result.txt"
grep -o txt my_text.txt 1.txt > result.txt
./my_grep -o txt my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

############################# 
echo "OK!    test my_grep -e ololo -e flags my_text.txt 1.txt > result.txt"
grep -e ololo -e flags my_text.txt 1.txt > result.txt
./my_grep -e ololo -e flags my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -i -n OLOLO my_text.txt 1.txt > result.txt"
grep -i -n OLOLO my_text.txt 1.txt > result.txt
./my_grep -i -n OLOLO my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -v flags my_text.txt 1.txt > result.txt"
grep -v flags my_text.txt 1.txt > result.txt
./my_grep -v flags my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -c -n ololo my_text.txt 1.txt > result.txt"
grep -c ololo my_text.txt 1.txt > result.txt
./my_grep -c ololo my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l ololo my_text.txt 1.txt > result.txt"
grep -l ololo my_text.txt 1.txt > result.txt
./my_grep -l ololo my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l flags my_text.txt 1.txt > result.txt"
grep -l flags my_text.txt 1.txt > result.txt
./my_grep -l flags my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n flags my_text.txt 1.txt > result.txt"
grep -n flags my_text.txt 1.txt > result.txt
./my_grep -n flags my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -h make my_text.txt 1.txt > result.txt"
grep -n make my_text.txt 1.txt > result.txt
./my_grep -n make my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -s make my_text.txt asdasdasdasdt > result.txt"
grep -s make 1.txt asdasdasdasdt > result.txt
./my_grep -s make 1.txt asdasdasdasdt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n -f my_-f_file.txt my_text.txt > result.txt"
grep -f my_-f_file.txt my_text.txt > result.txt
./my_grep -f my_-f_file.txt my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -o my_text.txt 1.txt > result.txt"
grep -o develop my_text.txt 1.txt > result.txt
./my_grep -o develop my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

############################# 
echo "OK!    test my_grep -e must -e the my_text.txt 1.txt > result.txt"
grep -e must -e the my_text.txt 1.txt > result.txt
./my_grep -e must -e the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -i -l MUST my_text.txt 1.txt > result.txt"
grep -i -l MUST my_text.txt 1.txt > result.txt
./my_grep -i -l MUST my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -v -n the my_text.txt 1.txt > result.txt"
grep -v -n the my_text.txt 1.txt > result.txt
./my_grep -v -n the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -c -s ololo my_text.txt 1.txt > result.txt"
grep -c -s ololo my_text.txt 1.txt > result.txt
./my_grep -c -s ololo my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l -n the my_text.txt 1.txt > result.txt"
grep -l -n the my_text.txt 1.txt > result.txt
./my_grep -l -n the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -o -v -n the my_text.txt 1.txt > result.txt"
grep -v -n the my_text.txt 1.txt > result.txt
./my_grep -v -n the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n -e flags -e the my_text.txt 1.txt > result.txt"
grep -n -e flags -e the my_text.txt 1.txt > result.txt
./my_grep -n -e flags -e the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -h -n the my_text.txt 1.txt > result.txt"
grep -h -n the  my_text.txt 1.txt > result.txt
./my_grep -h -n the  my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -s -n the my_text.txt asdasdasdasdt > result.txt"
grep -s -n the 1.txt asdasdasdasdt > result.txt
./my_grep -s -n the 1.txt asdasdasdasdt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n -l -s -o -f my_-f_file.txt my_text.txt > result.txt"
grep -n -l -s -o -f my_-f_file.txt my_text.txt > result.txt
./my_grep -n -l -s -o -f my_-f_file.txt my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -o -n -s my_text.txt 1.txt > result.txt"
grep -o -n -s develop my_text.txt 1.txt > result.txt
./my_grep -o -n -s develop my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt


echo "OK!    test my_grep -e 111 -e 123 -e Support my_text.txt 1.txt > result.txt"
grep -e 111 -e 123 -e Support my_text.txt 1.txt > result.txt
./my_grep -e 111 -e 123 -e Support my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -i i my_text.txt 1.txt > result.txt"
grep -i I my_text.txt 1.txt > result.txt
./my_grep -i I my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -v 123 my_text.txt 1.txt > result.txt"
grep -v 123 my_text.txt 1.txt > result.txt
./my_grep -v 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -c 123 my_text.txt 1.txt > result.txt"
grep -c 123 my_text.txt 1.txt > result.txt
./my_grep -c 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l 123 my_text.txt 1.txt > result.txt"
grep -l 123 my_text.txt 1.txt > result.txt
./my_grep -l 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l 123 my_text.txt 1.txt > result.txt"
grep -l 123 my_text.txt 1.txt > result.txt
./my_grep -l 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n 123 my_text.txt 1.txt > result.txt"
grep -n 123 my_text.txt 1.txt > result.txt
./my_grep -n 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -h 123 my_text.txt 1.txt > result.txt"
grep -n 123 my_text.txt 1.txt > result.txt
./my_grep -n 123 my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -s 123 my_text.txt 1.txt > result.txt"
grep -s 123 1.txt 21.txt > result.txt
./my_grep -s 123 1.txt 21.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -f my_-f_file.txt my_text.txt > result.txt"
grep -f my_-f_file.txt my_text.txt > result.txt
./my_grep -f my_-f_file.txt my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -o my_text.txt 1.txt > result.txt"
grep -o txt my_text.txt 1.txt > result.txt
./my_grep -o txt my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

############################# 
echo "OK!    test my_grep -e ololo -e flags my_text.txt 1.txt > result.txt"
grep -e ololo -e flags my_text.txt 1.txt > result.txt
./my_grep -e ololo -e flags my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -i -n OLOLO my_text.txt 1.txt > result.txt"
grep -i -n OLOLO my_text.txt 1.txt > result.txt
./my_grep -i -n OLOLO my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -v flags my_text.txt 1.txt > result.txt"
grep -v flags my_text.txt 1.txt > result.txt
./my_grep -v flags my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -c -n ololo my_text.txt 1.txt > result.txt"
grep -c ololo my_text.txt 1.txt > result.txt
./my_grep -c ololo my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l ololo my_text.txt 1.txt > result.txt"
grep -l ololo my_text.txt 1.txt > result.txt
./my_grep -l ololo my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l flags my_text.txt 1.txt > result.txt"
grep -l flags my_text.txt 1.txt > result.txt
./my_grep -l flags my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n flags my_text.txt 1.txt > result.txt"
grep -n flags my_text.txt 1.txt > result.txt
./my_grep -n flags my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -h make my_text.txt 1.txt > result.txt"
grep -n make my_text.txt 1.txt > result.txt
./my_grep -n make my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -s make my_text.txt asdasdasdasdt > result.txt"
grep -s make 1.txt asdasdasdasdt > result.txt
./my_grep -s make 1.txt asdasdasdasdt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n -f my_-f_file.txt my_text.txt > result.txt"
grep -f my_-f_file.txt my_text.txt > result.txt
./my_grep -f my_-f_file.txt my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -o my_text.txt 1.txt > result.txt"
grep -o develop my_text.txt 1.txt > result.txt
./my_grep -o develop my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

############################# 
echo "OK!    test my_grep -e must -e the my_text.txt 1.txt > result.txt"
grep -e must -e the my_text.txt 1.txt > result.txt
./my_grep -e must -e the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -i -l MUST my_text.txt 1.txt > result.txt"
grep -i -l MUST my_text.txt 1.txt > result.txt
./my_grep -i -l MUST my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -v -n the my_text.txt 1.txt > result.txt"
grep -v -n the my_text.txt 1.txt > result.txt
./my_grep -v -n the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -c -s ololo my_text.txt 1.txt > result.txt"
grep -c -s ololo my_text.txt 1.txt > result.txt
./my_grep -c -s ololo my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -l -n the my_text.txt 1.txt > result.txt"
grep -l -n the my_text.txt 1.txt > result.txt
./my_grep -l -n the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -o -v -n the my_text.txt 1.txt > result.txt"
grep -v -n the my_text.txt 1.txt > result.txt
./my_grep -v -n the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n -e flags -e the my_text.txt 1.txt > result.txt"
grep -n -e flags -e the my_text.txt 1.txt > result.txt
./my_grep -n -e flags -e the my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -h -n the my_text.txt 1.txt > result.txt"
grep -h -n the  my_text.txt 1.txt > result.txt
./my_grep -h -n the  my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -s -n the my_text.txt asdasdasdasdt > result.txt"
grep -s -n the 1.txt asdasdasdasdt > result.txt
./my_grep -s -n the 1.txt asdasdasdasdt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -n -l -s -o -f my_-f_file.txt my_text.txt > result.txt"
grep -n -l -s -o -f my_-f_file.txt my_text.txt > result.txt
./my_grep -n -l -s -o -f my_-f_file.txt my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_grep -o -n -s my_text.txt 1.txt > result.txt"
grep -o -n -s develop my_text.txt 1.txt > result.txt
./my_grep -o -n -s develop my_text.txt 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt
