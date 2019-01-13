i="y"

while [ $i = "y" ]
do

echo "1.List of files and directories"
echo "2.Enter a directory"
echo "3.Create a Directory"
echo "4.Create a File"
echo "5.Rename file/directory"
echo "6.Delete file"
echo "7.Delete directory"
echo "8.Search a file"
echo "9.Check present directory"

echo "Enter your choice"
read ch
case $ch in
    1)ls
		echo "Do you want to go back into the previous directory?"
		read j 
		if [ $j = "y" ]
		then cd ..
		fi;;
         		
    2)echo "Enter directory name"
		read dir
		cd $dir
		
		echo "File and Directories in " $dir 
		ls	
		
		echo "Do you want to go back into the previous directory?"
		read j 
		if [ $j = "y" ]
		then cd ..
		fi;;

	3)echo "Enter the new directory name : "
		read dname
		mkdir $dname

		echo "File and Directories in " $dname
		ls	
		
		echo "Do you want to go back into the previous directory?"
		read j 
		if [ $j = "y" ]
		then cd ..
		fi;;

	4)echo "Enter the new file name with extension : "
		read fname
		gedita $fname

		echo "File and Directories in " $dname
		ls	
		
		echo "Do you want to go back into the previous directory?"
		read j 
		if [ $j = "y" ]
		then cd ..
		fi;;

	5)echo "Enter the old file name to be renamed : "
		read old_fname
		echo "Enter the new file name to be renamed : "
		read new_fname
		mv $old_fname $new_fname

		echo "File and Directories in " $dname
		ls	
		
		echo "Do you want to go back into the previous directory?"
		read j 
		if [ $j = "y" ]
		then cd ..
		fi;;

	6)echo "Enter the file name to be deleted : "
		read del_fname
		rm -f $del_fname
		echo "File and Directories in " $dname
		ls	
		
		echo "Do you want to go back into the previous directory?"
		read j 
		if [ $j = "y" ]
		then cd ..
		fi;;

	7)echo "Enter the directory to be deleted : "
		read del_dir
		rm -rf $del_dir
		echo "File and Directories in " $dname
		ls	
		
		echo "Do you want to go back into the previous directory?"
		read j 
		if [ $j = "y" ]
		then cd ..
		fi;;

	8)echo "Enter the file name to be searched : "
		read s_fname
		find . -name $s_fname
		
		
		echo "Do you want to go back into the previous directory?"
		read j 
		if [ $j = "y" ]
		then cd ..
		fi;;

	9) pwd;;

	
		
    *)
         echo "Invalid choice";;
esac
echo "Do u want to continue ?"
read i
if [ $i != "y" ]
then
    exit
fi
done   
