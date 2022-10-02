echo "OK!    test my_cat my_text.txt > result.txt"
cat my_text.txt > result.txt
./my_cat my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -n my_text.txt > result.txt"
cat -n my_text.txt > result.txt
./my_cat -n my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -e my_text.txt > result.txt"
cat -e my_text.txt > result.txt
./my_cat -e my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txtc

echo "OK!    test my_cat -b my_text.txt > result.txt"
cat -b my_text.txt > result.txt
./my_cat -b my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -s my_text.txt > result.txt"
cat -s my_text.txt > result.txt
./my_cat -s my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -t my_text.txt > result.txt"
cat -t my_text.txt > result.txt
./my_cat -t my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat 1.txt > result.txt"
cat 1.txt > result.txt
./my_cat 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -n -s 1.txt > result.txt"
cat -n -s 1.txt > result.txt
./my_cat -n -s 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -e -n 1.txt > result.txt"
cat -e -n 1.txt > result.txt
./my_cat -e -n 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txtc

echo "OK!    test my_cat -b -s 1.txt > result.txt"
cat -b -s 1.txt > result.txt
./my_cat -b -s 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -s -t  my_text.txt > result.txt"
cat -s -t my_text.txt > result.txt
./my_cat -s -t my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -t -n my_text.txt > result.txt"
cat -t -n my_text.txt > result.txt
./my_cat -t -n my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

################################################
echo "OK!    test my_cat 1.txt > result.txt"
cat 1.txt > result.txt
./my_cat 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -n -s 1.txt > result.txt"
cat -n -s 1.txt > result.txt
./my_cat -n -s 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -e -n 1.txt > result.txt"
cat -e -n 1.txt > result.txt
./my_cat -e -n 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txtc

echo "OK!    test my_cat -b -s 1.txt > result.txt"
cat -b -s 1.txt > result.txt
./my_cat -b -s 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -s -t  my_text.txt > result.txt"
cat -s -t my_text.txt > result.txt
./my_cat -s -t my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -t -n my_text.txt > result.txt"
cat -t -n my_text.txt > result.txt
./my_cat -t -n my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt 

################################################
echo "OK!    test my_cat -b -t -s 1.txt > result.txt"
cat -b -t -s 1.txt > result.txt
./my_cat -b -t -s 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -e -n -s 1.txt > result.txt"
cat -e -n -s 1.txt > result.txt
./my_cat -e -n -s 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -e -b -s 1.txt > result.txt"
cat -e -b -s  1.txt > result.txt
./my_cat -e -b -s  1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txtc

echo "OK!    test my_cat -b -s -t 1.txt > result.txt"
cat -b -s -t 1.txt > result.txt
./my_cat -b -s -t 1.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -s -t -b my_text.txt > result.txt"
cat -s -t -b my_text.txt > result.txt
./my_cat -s -t -b my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt

echo "OK!    test my_cat -t -n -s my_text.txt > result.txt"
cat -t -n -s my_text.txt > result.txt
./my_cat -t -n -s my_text.txt > my_result.txt
diff result.txt my_result.txt
rm -f result.txt my_result.txt 