i=$(ls files | wc -l)
	echo $i
for file in $(find /home/hewt/framework/hadoop-common -type f -name "*.java")
	do
	echo $file
	i=$[$i+1]
	cp $file files/$i
	done
